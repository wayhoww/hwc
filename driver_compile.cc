#include "driver.hh"


std::shared_ptr<nonterm_info> driver::compile_offset(const ptr_list_of<expr>& indices, const std::vector<int32_t> dims) {
        // 暂时不做边界检查
    auto offset = nonterm_integer::newsp(add_temp());
    gen_imcode(ImCode::ASSIGN, nonterm_constant::newsp(0), nonterm_void::newsp(), offset);
    int index = 1;
    for(auto exp: indices) {
        auto dim = compile(exp);
        gen_imcode(ImCode::PLUS, offset, dim, offset);
        if(index < indices.size()) {
            gen_imcode(ImCode::MULTIPLY, offset, nonterm_constant::newsp(dims[index++]), offset);
        }
    }
    return offset;
}

std::shared_ptr<nonterm_boolean> driver::to_nonterm_boolean(const shared_ptr<nonterm_info>& origin) {
    if(dynamic_pointer_cast<nonterm_void>(origin)) {
        exit(80); assert(false);
    }
    if(auto info = dynamic_pointer_cast<nonterm_boolean>(origin)) {
        return info;
    }else {
        gen_imcode(ImCode::JNE, origin, nonterm_constant::newsp(0), 0);
        gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), 0);
        return nonterm_boolean::newsp({nxq() - 2}, {nxq() - 1});
    }
}

std::shared_ptr<nonterm_integer> driver::to_nonterm_integer(
        const std::shared_ptr<nonterm_info>& info, 
        std::shared_ptr<nonterm_integer> store_place) {
    if(auto s1 = dynamic_pointer_cast<nonterm_integer>(info)) {
        return s1;
    } else if(auto s2 = dynamic_pointer_cast<nonterm_constant>(info)) {
        if(store_place == nullptr) store_place = nonterm_integer::newsp(add_temp());
        gen_imcode(ImCode::ASSIGN, info, nonterm_void::newsp(), store_place);
        return store_place;
    } else if(auto s = dynamic_pointer_cast<nonterm_boolean>(info)) {
        if(store_place == nullptr) store_place = nonterm_integer::newsp(add_temp());
        backpatch(s->true_exits, nxq());
        gen_imcode(ImCode::ASSIGN, nonterm_constant::newsp(1), nonterm_void::newsp(), store_place);
        int after_end = nxq() + 2;
        gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), after_end);
        backpatch(s->false_exits, nxq());
        gen_imcode(ImCode::ASSIGN, nonterm_constant::newsp(0), nonterm_void::newsp(), store_place);
        return store_place;
    } else {
        exit(81); assert(false);
    }
}

std::vector<int> operator+ (std::vector<int>& s1, const std::vector<int>& s2) {
    for(auto s: s2) s1.emplace_back(s);
    return s1;
}


std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<stmt_if_t>& stmt) {
    
    auto info = nonterm_controlflow::newsp({}, {});
    
    // TODO check 一下做法对不对
    auto c = to_nonterm_boolean(compile(stmt->cond));
    backpatch(c->true_exits, nxq());
    if(auto r = dynamic_pointer_cast<nonterm_controlflow>(compile(stmt->stmt_if_true))){
        info->break_exits = info->break_exits + r->break_exits;
        info->continue_exits = info->continue_exits + r->continue_exits;
    }  
    if(stmt->stmt_if_false) gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), 0);
    auto need_update = nxq() - 1;
    backpatch(c->false_exits, nxq());

    if(stmt->stmt_if_false) {
        if(auto r = dynamic_pointer_cast<nonterm_controlflow>(compile(stmt->stmt_if_false))){
            info->break_exits = info->break_exits + r->break_exits;
            info->continue_exits = info->continue_exits + r->continue_exits;
        }  
        imcodes()[need_update].dest.value = nxq();
    } 

    return info;
}

std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<expr>& root, std::shared_ptr<nonterm_integer> store_place) {
    if(auto [static_ok, static_value] = static_eval(root); static_ok) {
        if(store_place) {
            gen_imcode(ImCode::ASSIGN, nonterm_constant::newsp(static_value), nonterm_void::newsp(), store_place);
            return store_place;
        }
        return nonterm_constant::newsp(static_value);
    }

    // cannot be static below
    // TODO type checking
    if(auto r = dynamic_pointer_cast<logical_not_expr>(root)) {
        auto info = to_nonterm_boolean(compile(r->src));
        std::swap(info->true_exits, info->false_exits);
        return info;
    }else if(auto r = dynamic_pointer_cast<negative_expr>(root)) {
        if(store_place == nullptr)  store_place = nonterm_integer::newsp(add_temp());
        // 构建表达式树的时候已经去除了 - - - - - 1 这种
        auto info = to_nonterm_integer(compile(r->src));
        gen_imcode(ImCode::MINUS, nonterm_constant::newsp(0), info, store_place);
        return store_place;
    }else if(auto r = dynamic_pointer_cast<binary_expr>(root)) {
        ImCode::Operator op;
        int type = 0;
        if(r->op.type == operator_t::PLUS) {
            op = ImCode::PLUS;
        } else if(r->op.type == operator_t::MINUS) {
            op = ImCode::MINUS;
        } else if(r->op.type == operator_t::MULTIPLY) {
            op = ImCode::MULTIPLY;
        } else if(r->op.type == operator_t::DIVIDE) {
            op = ImCode::DIVIDE;
        } else if(r->op.type == operator_t::MODULE) {
            op = ImCode::MODULE;
        } else {
            type = 1;
            if(r->op.type == operator_t::EQUAL) {
                op = ImCode::JEQ;
            } else if(r->op.type == operator_t::NOT_EQUAL) {
                op = ImCode::JNE;
            } else if(r->op.type == operator_t::GREATER) {
                op = ImCode::JGT;
            } else if(r->op.type == operator_t::GREATER_EQUAL) {
                op = ImCode::JGE;
            } else if(r->op.type == operator_t::LESS) {
                op = ImCode::JLT;
            } else if(r->op.type == operator_t::LESS_EQUAL) {
                op = ImCode::JLE;
            } else {
                type = 2;
            }
        }
        if(type == 0) {
            // TODO a = b + c 优化
            if(store_place == nullptr)  store_place = nonterm_integer::newsp(add_temp());
            gen_imcode(op, compile(r->src1), compile(r->src2), store_place);
            return store_place;
        }else if(type == 1) {    
            gen_imcode(op, compile(r->src1), compile(r->src2), 0);
            gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), 0);
            return nonterm_boolean::newsp({nxq() - 2}, {nxq() - 1});
        }else{
            if(r->op.type == operator_t::LOGICAL_AND) {
                auto c1 = to_nonterm_boolean(compile(r->src1));
                backpatch(c1->true_exits, nxq());
                auto c2 = to_nonterm_boolean(compile(r->src2));
                return nonterm_boolean::newsp(c2->true_exits, c1->false_exits + c2->false_exits);
            } else if(r->op.type == operator_t::LOGICAL_OR) { // logical_or, asserted before
                auto c1 = to_nonterm_boolean(compile(r->src1));
                backpatch(c1->false_exits, nxq());
                auto c2 = to_nonterm_boolean(compile(r->src2));
                return nonterm_boolean::newsp(c1->true_exits + c2->true_exits, c2->false_exits);
            } else {
                exit(82); assert(false);
            }
        }
    }else if(auto r = dynamic_pointer_cast<l_val_t>(root)) {
        auto var_id = query_var(r->ident);
        auto sym = symbols[var_id];
        if(r->exps.empty()) {
            if(store_place != nullptr) {
                gen_imcode(ImCode::ASSIGN, nonterm_integer::newsp(var_id), nonterm_void::newsp(), store_place);
                return store_place;
            }else{
                return nonterm_integer::newsp(var_id);
            }
        } else {
            if(store_place == nullptr)  store_place = nonterm_integer::newsp(add_temp());
            auto offset = compile_offset(r->exps, sym.dims);
            
            if(r->exps.size() == sym.dims.size()) {
                gen_imcode(ImCode::MULTIPLY, offset, nonterm_constant::newsp(4), offset);
                gen_imcode(ImCode::DAGET, nonterm_integer::newsp(var_id), offset, store_place);
                return store_place;
            }else{
                int mul = 4;
                for(int i = r->exps.size(); i < sym.dims.size(); i++) {
                    mul *= sym.dims[i];
                }
                gen_imcode(ImCode::MULTIPLY, offset, nonterm_constant::newsp(mul), offset);
                gen_imcode(ImCode::GETADD,  nonterm_integer::newsp(var_id), nonterm_void::newsp(), store_place);
                gen_imcode(ImCode::PLUS, store_place, offset, store_place);
                return store_place;
            }
        }
    }else if(auto r = dynamic_pointer_cast<number_literal_t>(root)) {
        // 应该不会出现这个情况
        // 被 static analysis 了
        if(store_place) {
            gen_imcode(ImCode::ASSIGN, nonterm_constant::newsp(r->value), nonterm_void::newsp(), store_place);
            return store_place;
        }
        return nonterm_constant::newsp(r->value);
    }else if(auto r = dynamic_pointer_cast<func_call_t>(root)) {
        ImCode code;
        code.op = ImCode::CALL;
        code.src1.type = ImCode::Oprand::FUNCID;
        code.src1.value = query_function(r->ident);

        std::shared_ptr<nonterm_info> rst;
        if(functions()[code.src1.value].returnVoid) {
            rst = nonterm_void::newsp();
        }else{
            if(store_place == nullptr)  store_place = nonterm_integer::newsp(add_temp());
            rst = store_place;
        }
        code.dest = get_oprand(rst);
    
        auto exps = r->params->exps;    
        for(auto exp: exps){
            auto var = to_nonterm_integer(compile(exp));
            code.arguments.push_back(var->var_id);
        }

        imcodes().push_back(code);

        return rst;
    }else{
        exit(83); assert(false);
    }
}



    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<comp_unit_t>& comp_unit){
        // predefined library function
        functions()[add_function("starttime", -1, false, {})].declarationOnly = true;
        functions()[add_function("stoptime", -1, false, {})].declarationOnly = true;
        functions()[add_function("getint", -1, false, {})  ].declarationOnly = true;
        functions()[add_function("getch", -1, false, {})   ].declarationOnly = true;
        functions()[add_function("getarray", -1, false, {Argument({-1})})].declarationOnly = true;

        functions()[add_function("putint", -1, true, {Argument()} )   ].declarationOnly = true;
        functions()[add_function("putch", -1, true, {Argument()})    ].declarationOnly = true;
        functions()[add_function("putarray", -1, true, { Argument(), Argument({-1})})].declarationOnly = true;

        for(auto child: comp_unit->children) {
            if(auto r = dynamic_pointer_cast<comp_unit_item_func_def_t>(child)) {
                compile(r->func_def, true, false);
            } else if(auto r = dynamic_pointer_cast<comp_unit_item_decl_t>(child)) {
                compile(r->decl);
            } else { 
                exit(84); assert(false);
            }
        }
        
        for(auto child: comp_unit->children) {
            if(auto r = dynamic_pointer_cast<comp_unit_item_func_def_t>(child)) {
                compile(r->func_def, false, true);
            }
        }

        // ensure all internal functions are defined, and find the main function
        int main_id = -1;
        for(int i = 0; i < functions().size(); i++){
            auto func = functions()[i];
            if(!(func.entrance >= 0 || func.declarationOnly)) {
                exit(85); assert(false);
            }
            if(func.identifier == "main") {
                main_id = i;
            }
        }
        if(main_id >= 0 && !functions()[main_id].returnVoid) {
            // generate a starter function
            auto funcid = add_function("__hwc_start", nxq(), false, {});
            imProgram.startFunction = funcid;

            // init global vars
            for(int i = 0; i < global_vars().size(); i++){
                auto& var = global_vars()[i];
                auto& sym = symbols[i];
                if(!sym.is_const && sym.need_init) {
                    sym.is_static = true;
                    if(!sym.dims.empty()){
                        // size ? size / 4 ?
                        sym.init_value = std::vector<int32_t>(sym.size / 4, 0);
                        for(int j = 0; j < sym.init_expr.size(); j++) {
                            auto exp = sym.init_expr[j];
                            if(exp) {
                                auto [static_ok, static_val] = static_eval(exp, true);
                                if(static_ok) {
                                    sym.init_value[j] = static_val;
                                }else{
                                    sym.is_static = false;
                                    gen_imcode(ImCode::DASET, nonterm_integer::newsp(i), nonterm_constant::newsp(4 * j), compile(exp));
                                }
                            }else{
                                sym.init_value[j] = 0;
                            }
                        }
                    }else{
                        sym.init_value = std::vector<int32_t>(1, 0);
                        if(auto exp = sym.init_expr[0]) {
                            auto [static_ok, static_val] = static_eval(exp, true);
                            if(static_ok) sym.init_value[0] = static_val;
                            else {
                                sym.is_static = false;
                                compile(exp, nonterm_integer::newsp(i));
                            }
                        } // else do nothing
                    }
                }
                var.initValue = sym.init_value;
            }
            
            // call main 并返回 main 的返回值
            auto func_rtn = nonterm_integer::newsp(add_temp());
            ImCode code;
            code.op = ImCode::CALL;
            code.src1.type = ImCode::Oprand::FUNCID;
            code.src1.value = main_id;
            code.dest = get_oprand(func_rtn);
            imcodes().push_back(code);

            gen_imcode(ImCode::RET, func_rtn, nonterm_void::newsp(), nonterm_void::newsp());
        }else{
            // TODO
            // when to init if main does not exist
        }
        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<func_def_t>& funcdef, bool decl, bool define) {
        auto type = funcdef->func_type->type;
        auto funcname = funcdef->ident;
        if(decl){
            std::vector<Argument> argu;
            for(auto param: funcdef->params->params) {
                auto [size, dims] = static_array_dims(param->array_dims);
                argu.push_back(Argument(dims));
            }
            auto funcid = add_function(funcname, -1, funcdef->func_type->type == b_type_t::VOID, argu);
        }

        if(define){

            // 逻辑要搞清楚
            // 多次调用、递归调用同一个函数，对每一个局部变量得到的 var id 必定是
            // 一样的。这不是实现问题，是逻辑问题
            // 在开始生成其代码之前 enter scoop，在生成结束之后 exit scoop，恰好没问题
            // 一个函数知会被生成一次代码

            auto func = query_function(funcname);
            functions()[func].entrance = nxq();
            enter_scoop();
            
            // 参数
            int i = 0;
            for(auto param: funcdef->params->params) {
                compile(param, i++);
            }

            compile(funcdef->block, false);

            // 结尾自动 return 
            
            gen_imcode(ImCode::RET, nonterm_void::newsp(), nonterm_void::newsp(), nonterm_void::newsp());

            exit_scoop();
        }

        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<block_t>& block, bool enter_new_scoop) {
    //    if(enter_new_scoop) enter_scoop();

        auto info = nonterm_controlflow::newsp({}, {});

        for(auto child: block->children) {
            if(auto r = dynamic_pointer_cast<nonterm_controlflow>(compile(child))){
                for(auto x: r->break_exits) info->break_exits.push_back(x);
                for(auto x: r->continue_exits) info->continue_exits.push_back(x);
            }
        }

    //    if(enter_new_scoop) exit_scoop();


        return info;
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<block_item_t>& item) {
        auto decl = dynamic_pointer_cast<block_item_decl_t>(item);
        auto stmt = dynamic_pointer_cast<block_item_stmt_t>(item);
        if(decl){
            return compile(decl->decl);
        } else if(stmt){
            return compile(stmt->stmt);
        } else {
            exit(86); assert(false);
        }
        // todo
        return nonterm_void::newsp();
    }



    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<func_f_param_t>& param, int param_index) {
        if(param->b_type->type != b_type_t::INT) {
            exit(87); assert(false);
        }
        
    // 不需要 const ？ 去看一下语义
    //    auto [size, dims] = static_array_dims(param->array_dims);
        std::vector<int32_t> dims;
        auto dimexps = param->array_dims;
        for(auto exp: dimexps) {
            if(exp) {
                auto [ok, val] = static_eval(exp);
                if(!ok) {
                    exit(88); assert(false);
                }
                dims.push_back(val);
            } else {
                dims.push_back(0);
            }
        }

        auto id = entry(param->ident, dims, false, {});
        ImCode code;
        code.op = ImCode::MARK;
        code.src1.type = ImCode::Oprand::PARAMID;
        code.src1.value = param_index;
        code.dest.type = ImCode::Oprand::VAR;
        code.dest.var.isTemp = false;
        code.dest.var.varID = id;
        imcodes().push_back(code);

        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<stmt_t>& stmt) {
        auto s_if        = dynamic_pointer_cast<stmt_if_t>(stmt);
        auto s_return    = dynamic_pointer_cast<stmt_return_t>(stmt);
        auto s_while     = dynamic_pointer_cast<stmt_while_t>(stmt);
        auto s_assign    = dynamic_pointer_cast<stmt_assign_t>(stmt);
        auto s_block     = dynamic_pointer_cast<stmt_block_t>(stmt);
        auto s_continue  = dynamic_pointer_cast<stmt_continue_t>(stmt);
        auto s_exp       = dynamic_pointer_cast<stmt_exp_t>(stmt);
        auto s_break     = dynamic_pointer_cast<stmt_break_t>(stmt);
        if(s_if      )  {  return compile(s_if        );  }  
        if(s_return  )  {  return compile(s_return    );  }  
        if(s_while   )  {  return compile(s_while     );  }  
        if(s_assign  )  {  return compile(s_assign    );  }  
        if(s_block   )  {  return compile(s_block     );  }  
        if(s_continue)  {  return compile(s_continue  );  }  
        if(s_exp     )  {  return compile(s_exp       );  }  
        if(s_break   )  {  return compile(s_break     );  } 
        if(!stmt     )  {  return nonterm_void::newsp();  }  
        exit(89); assert(false);
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<stmt_return_t>& stmt) {
        ImCode code;
        code.op = ImCode::RET;
        if(stmt->exp) {
            code.src1 = get_oprand(compile(stmt->exp));
        }
        imcodes().push_back(code);

        return nonterm_void::newsp();
    }
    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<stmt_while_t>& stmt) {
        auto continue_entrance = nxq();
        auto cond_im = to_nonterm_boolean(compile(stmt->cond));
        auto stmt_extrance = nxq();
        auto stmt_im = compile(stmt->stmt);
        gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), continue_entrance);
        auto break_entrance = nxq();
        backpatch(cond_im->true_exits, stmt_extrance);
        backpatch(cond_im->false_exits, break_entrance);
        if(auto s = dynamic_pointer_cast<nonterm_controlflow>(stmt_im)) {
            backpatch(s->break_exits, break_entrance);
            backpatch(s->continue_exits, continue_entrance);
        }
        return nonterm_void::newsp();
    }
    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<stmt_assign_t>& stmt) {
        auto ident = stmt->l_val->ident;
        auto dest = nonterm_integer::newsp(query_var(ident));

        auto dims = symbols[dest->var_id].dims;
        if(stmt->l_val->exps.size() != dims.size()) {
            exit(90); assert(false);
        }
        
       
        if(dims.size() == 0) {
            to_nonterm_integer(compile(stmt->exp, dest), dest);
            return nonterm_void::newsp();
        } else {
            auto rval = compile(stmt->exp);
            auto offset = compile_offset(stmt->l_val->exps, dims);
            gen_imcode(ImCode::MULTIPLY, offset, nonterm_constant::newsp(4), offset);
            gen_imcode(ImCode::DASET, nonterm_integer::newsp(dest->var_id), offset, rval);
            return nonterm_void::newsp();
        }
    }


    void driver::gen_imcode(ImCode::Operator op, 
                        const std::shared_ptr<nonterm_info>& src1,
                        const std::shared_ptr<nonterm_info>& src2,
                        int dest){
        ImCode code;
        code.op = op;
        code.src1 = get_oprand(src1);
        code.src2 = get_oprand(src2);
        code.dest.type = ImCode::Oprand::IMCODEID;
        code.dest.value = dest;
        imcodes().push_back(code);
    }

    void driver::gen_imcode(ImCode::Operator op, 
                            const std::shared_ptr<nonterm_info>&    src1, 
                            const std::shared_ptr<nonterm_info>&    src2, 
                            const std::shared_ptr<nonterm_info>&    dest) {
        ImCode code;
        code.op = op;
        code.src1 = get_oprand(src1);
        code.src2 = get_oprand(src2);
        code.dest = get_oprand(dest);
        // 除非是 DASET/RET，不然 dest 必须是 integer

        if(!( dynamic_pointer_cast<nonterm_integer>(dest) ||
                (code.op == ImCode::RET && dynamic_pointer_cast<nonterm_void>(dest)) ||
                (code.op == ImCode::DASET && dynamic_pointer_cast<nonterm_constant>(dest)))){
                    exit(91); assert(false);
                }
        imcodes().push_back(code);
    } 

    ImCode::Oprand driver::get_oprand(const std::shared_ptr<nonterm_info>& info) {
        ImCode::Oprand op;
        
        auto variable = dynamic_pointer_cast<nonterm_integer>(info);
        if(variable){
            auto sym = symbols[variable->var_id];
            op.type = ImCode::Oprand::VAR;
            op.var.isTemp = sym.is_temp;
            op.var.varID = variable->var_id;
            return op;
        }
         
        auto constant = dynamic_pointer_cast<nonterm_constant>(info);
        if(constant){
            op.type = ImCode::Oprand::IMMEDIATE;
            op.value = constant->value;
            return op;
        }

        if(auto boolean = dynamic_pointer_cast<nonterm_boolean>(info)){
            auto variable = to_nonterm_integer(boolean);
            auto sym = symbols[variable->var_id];
            op.type = ImCode::Oprand::VAR;
            op.var.isTemp = sym.is_temp;
            op.var.varID = variable->var_id;
            return op;
        }
        
        if(dynamic_pointer_cast<nonterm_void>(info) || dynamic_pointer_cast<nonterm_controlflow>(info)){
            op.type = ImCode::Oprand::INVALID;
            return op;
        }
        
        exit(92); assert(false);
    }


    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<stmt_block_t>& stmt) {
        auto block = stmt->block;
        return compile(block, true);
    }
    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<stmt_continue_t>& stmt) {
        auto rtn = nonterm_controlflow::newsp({}, {nxq()});
        gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), 0);
        return rtn;
    }
    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<stmt_exp_t>& stmt) {
        return compile(stmt->exp);
    }
    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<stmt_break_t>& stmt) {
        auto rtn = nonterm_controlflow::newsp({nxq()}, {});
        gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), 0);
        return rtn;
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<decl_t>& decl) {
        auto const_decl = dynamic_pointer_cast<decl_const_decl_t>(decl);
        auto var_decl = dynamic_pointer_cast<decl_var_decl_t>(decl);
        if(var_decl) {
            return compile(var_decl->var_decl);
        }else if(const_decl) {
            return compile(const_decl->const_decl);
        }else{
            exit(93); assert(false);
        }

        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<var_decl_t>& decl) {
        if(decl->b_type->type != b_type_t::INT) {
            exit(94); assert(false);
        }
        for(auto def: decl->var_defs) {
            compile(def);
        }

        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<var_def_t>& def) {
        auto defonly = dynamic_pointer_cast<var_def_only_t>(def);
        auto definit = dynamic_pointer_cast<var_def_init_t>(def);
        if(defonly) {
            return compile(defonly);
        } else if(definit) {
            return compile(definit);
        } else {
            exit(95); assert(false);
        }
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<var_def_only_t>& def_only) {
        auto [size, dims] = static_array_dims(def_only->array_dims);
        auto id = add_var(def_only->ident, dims, false, {});
        if(!dims.empty() && current_depth > 0) {
            gen_imcode(ImCode::ALLOC, nonterm_constant::newsp(size * 4), nonterm_void::newsp(), nonterm_integer::newsp(id));
        }

        return nonterm_void::newsp();
    }    
    
    
    void driver::flatten(shared_ptr<init_val_t> init_val, std::vector<std::shared_ptr<expr>>& vec) {
        if (auto r = dynamic_pointer_cast<init_val_scalar_t>(init_val)) {
            vec.push_back(r->exp);
        } else if (auto r = dynamic_pointer_cast<init_val_array_t>(init_val)) {
            for(auto sub: r->array_elements) {
                flatten(sub, vec);
            }
        }
    }

    std::vector<std::shared_ptr<expr>> driver::flatten(shared_ptr<init_val_t> init_val) {
        std::vector<std::shared_ptr<expr>> vec;
        flatten(init_val, vec);
        return vec;
    }


    // [3, 5]
    void driver::recursive_compile(
            shared_ptr<init_val_t> init_val, 
            std::vector<int32_t> dims, 
            int layer, 
            int layer_size,
            int offset,
            std::vector<std::shared_ptr<expr>>& buffer) {
        if (auto r = dynamic_pointer_cast<init_val_scalar_t>(init_val)) {
            buffer[offset] = r->exp;
        } else if (auto r = dynamic_pointer_cast<init_val_array_t>(init_val)) {
            if(r->array_elements.size() == 0) {
                for(int i = 0; i < layer_size; i++) {
                    buffer[offset + i] = nullptr;
                }
            } else if(auto flat = flatten(init_val); flat.size() == layer_size) {
                for(int i = 0; i < layer_size; i++) {
                    buffer[offset + i] = flat[i];
                }
            } else {
                int new_layer_size = layer_size / dims[layer];
                int delta_bias = new_layer_size;
                int bias = 0;
                for(auto exp: r->array_elements) {
                    recursive_compile(exp, dims, layer + 1, new_layer_size, offset + bias, buffer);
                    if( dynamic_pointer_cast<init_val_scalar_t>(exp) ) {
                        bias += 1;
                    }else{
                        bias += delta_bias;
                    }
                }
                for(int i = bias; i < layer_size; i++){
                    buffer[offset + i] = nullptr;
                }
            }
        }
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<var_def_init_t>& def_init) {
        auto [size, dims] = static_array_dims(def_init->array_dims);
        // 取init的时候要用到dims和size
        // TODO init
        auto id = add_var(def_init->ident, dims, false, {});
        symbols[id].need_init = true;
        if(!dims.empty()) {
            
            if(current_depth > 0) {
                gen_imcode(ImCode::ALLOC, nonterm_constant::newsp(size * 4), nonterm_void::newsp(), nonterm_integer::newsp(id));        
                auto index = nonterm_integer::newsp(add_temp());
                gen_imcode(ImCode::ASSIGN, nonterm_constant::newsp(0), nonterm_void::newsp(), index);
                std::vector<std::shared_ptr<expr>> buffer(size, nullptr);
                recursive_compile(def_init->init_val, dims, 0, size, 0, buffer);
            
                for(int i = 0; i < size; i++){
                    auto val = buffer[i] ? compile(buffer[i]) : nonterm_constant::newsp(0);
                    gen_imcode(ImCode::DASET, nonterm_integer::newsp(id), index, val);
                    if(i < size - 1) {
                        gen_imcode(ImCode::PLUS, index, nonterm_constant::newsp(4), index);
                    }
                }
            }else{
                std::vector<std::shared_ptr<expr>> buffer(size, nullptr);
                recursive_compile(def_init->init_val, dims, 0, size, 0, buffer);
                symbols[id].init_expr = buffer;
            }
        
        } else {
            if(auto r = dynamic_pointer_cast<init_val_scalar_t>(def_init->init_val)) {
                if(current_depth > 0) {
                    auto rst = nonterm_integer::newsp(id);
                    to_nonterm_integer(compile(r->exp, rst), rst);
                }else {
                    symbols[id].init_expr = { r->exp };
                }
            } else {
                exit(96); assert(false);
            }
        }

        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<const_decl_t>& decl) {
        if(decl->b_type->type != b_type_t::INT) {
            exit(97); assert(false);
        }
        for(auto def: decl->const_defs) {
            compile(def);
        }
        return nonterm_void::newsp();
    }

    void driver::flatten(shared_ptr<const_init_val_t> init_val, std::vector<std::shared_ptr<expr>>& vec) {
        if (auto r = dynamic_pointer_cast<const_init_val_scalar_t>(init_val)) {
            vec.push_back(r->const_exp);
        } else if (auto r = dynamic_pointer_cast<const_init_val_array_t>(init_val)) {
            for(auto sub: r->array_elements) {
                flatten(sub, vec);
            }
        }
    }

    std::vector<std::shared_ptr<expr>> driver::flatten(shared_ptr<const_init_val_t> init_val) {
        std::vector<std::shared_ptr<expr>> vec;
        flatten(init_val, vec);
        return vec;
    }

    // [3, 5]
    void driver::recursive_evaluate(
            shared_ptr<const_init_val_t> init_val, 
            std::vector<int32_t> dims, 
            int layer, 
            int layer_size,
            int offset,
            std::vector<int32_t>& buffer) {
        if (auto r = dynamic_pointer_cast<const_init_val_scalar_t>(init_val)) {
            auto [ok, val] = static_eval(r->const_exp);
            if(!ok) {
                exit(98); assert(false);
            }
            buffer[offset] = val;
        } else if (auto r = dynamic_pointer_cast<const_init_val_array_t>(init_val)) {
            if(r->array_elements.size() == 0) {
                for(int i = 0; i < layer_size; i++) {
                    buffer[offset + i] = 0;
                }
            } else if(auto flat = flatten(init_val); flat.size() == layer_size) {
                for(int i = 0; i < layer_size; i++) {
                    auto [ok, val] = static_eval(flat[i]);
                    if(!ok) {
                        exit(99); assert(false);
                    }
                    buffer[offset + i] = val;
                }
            } else {
                int new_layer_size = layer_size / dims[layer];
                int delta_bias = new_layer_size;
                int bias = 0;
                for(auto exp: r->array_elements) {
                    recursive_evaluate(exp, dims, layer + 1, new_layer_size, offset + bias, buffer);
                    if( dynamic_pointer_cast<const_init_val_scalar_t>(exp) ) {
                        bias += 1;
                    }else{
                        bias += delta_bias;
                    }
                }
                for(int i = bias; i < layer_size; i++){
                    buffer[offset + i] = 0;
                }
            }
        }
    }

    std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<const_def_t>& constdef) {
        auto [size, dims] = static_array_dims(constdef->array_dims);

        std::vector<int32_t> init(size, 0);
        recursive_evaluate(constdef->const_init_val, dims, 0, size, 0, init);
        auto varid = add_var(constdef->ident, dims, true, init);
        symbols[varid].need_init = true;
        
        return nonterm_void::newsp();
    }

    std::pair<int32_t, std::vector<int32_t>> driver::static_array_dims(const ptr_list_of<expr>& dimsdef) {
        int32_t size = 1;
        std::vector<int32_t> dims;
        for(auto dim: dimsdef) {
            if(dim == nullptr) {
                dims.push_back(-1);
                size *= 0;
            }else {
                auto [ok, val] = static_eval(dim);
                if(!ok) {
                    exit(100); assert(false);
                }
                size *= val;
                dims.push_back(val);
            }
        }
        return std::make_pair(size, dims);      
    }