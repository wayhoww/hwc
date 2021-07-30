#include "driver.hh"


std::shared_ptr<nonterm_info> driver::compile_offset(const ptr_list_of<expr>& indices, const std::vector<uint64_t> dims) {
        // 暂时不做边界检查
    auto offset = nonterm_integer::newsp(add_temp());
    int index = 1;
    for(auto exp: indices) {
        auto dim = compile(exp);
        gen_imcode(ImCode::PLUS, offset, dim, offset);
        if(index < dims.size()) {
            gen_imcode(ImCode::MULTIPLY, offset, nonterm_constant::newsp(dims[index++]), offset);
        }
    }
    return offset;
}

std::shared_ptr<nonterm_controlflow> driver::to_nonterm_controlflow(const shared_ptr<nonterm_info>& origin) {
    assert(!dynamic_pointer_cast<nonterm_void>(origin));
    if(auto info = dynamic_pointer_cast<nonterm_controlflow>(origin)) {
        return info;
    }else {
        gen_imcode(ImCode::JNE, origin, nonterm_constant::newsp(0), 0);
        gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), 0);
        return nonterm_controlflow::newsp({nxq() - 2}, {nxq() - 1});
    }
}

std::shared_ptr<nonterm_integer> driver::to_nonterm_integer(const std::shared_ptr<nonterm_info>& info) {
    if(auto s1 = dynamic_pointer_cast<nonterm_integer>(info)) {
        return s1;
    } else if(auto s2 = dynamic_pointer_cast<nonterm_constant>(info)) {
        auto rtn = nonterm_integer::newsp(add_temp());
        gen_imcode(ImCode::ASSIGN, info, nonterm_void::newsp(), rtn);
        return rtn;
    } else if(auto s = dynamic_pointer_cast<nonterm_controlflow>(info)) {
        auto temp = nonterm_integer::newsp(add_temp());
        backpatch(s->true_exits, nxq());
        gen_imcode(ImCode::ASSIGN, nonterm_constant::newsp(1), nonterm_void::newsp(), temp);
        gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), nxq() + 1);
        backpatch(s->false_exits, nxq());
        gen_imcode(ImCode::ASSIGN, nonterm_constant::newsp(1), nonterm_void::newsp(), temp);
        return temp;
    } else {
        assert(false);
    }
}

std::vector<int> operator+ (std::vector<int>& s1, const std::vector<int>& s2) {
    for(auto s: s2) s1.emplace_back(s);
    return s1;
}

std::shared_ptr<nonterm_info> driver::compile(const shared_ptr<expr>& root, std::shared_ptr<nonterm_integer> store_place) {
    if(store_place == nullptr) {
        store_place = nonterm_integer::newsp(add_temp());
    }

    if(auto [static_ok, static_value] = static_eval(root); static_ok) {
        return nonterm_constant::newsp(static_value);
    }

    // cannot be static below
    // TODO type checking
    if(auto r = dynamic_pointer_cast<logical_not_expr>(root)) {
        auto info = to_nonterm_controlflow(compile(r->src));
        std::swap(info->true_exits, info->false_exits);
        return info;
    }else if(auto r = dynamic_pointer_cast<negative_expr>(root)) {
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
            gen_imcode(op, compile(r->src1), compile(r->src2), store_place);
            return store_place;
        }else if(type == 1) {    
            gen_imcode(op, compile(r->src1), compile(r->src2), 0);
            gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), 0);
            return nonterm_controlflow::newsp({nxq() - 2}, {nxq() - 1});
        }else{
            if(r->op.type == operator_t::LOGICAL_AND) {
                auto c1 = to_nonterm_controlflow(compile(r->src1));
                backpatch(c1->true_exits, nxq());
                auto c2 = to_nonterm_controlflow(compile(r->src2));
                return nonterm_controlflow::newsp(c2->true_exits, c1->false_exits + c2->false_exits);
            } else if(r->op.type == operator_t::LOGICAL_OR) { // logical_or, asserted before
                auto c1 = to_nonterm_controlflow(compile(r->src1));
                backpatch(c1->false_exits, nxq());
                auto c2 = to_nonterm_controlflow(compile(r->src2));
                return nonterm_controlflow::newsp(c1->true_exits + c2->true_exits, c2->false_exits);
            } else {
                assert(false);
            }
        }
    }else if(auto r = dynamic_pointer_cast<l_val_t>(root)) {
        auto var_id = query_var(r->ident);
        auto sym = symbols[var_id];
        if(sym.dims.empty()) {
            return nonterm_integer::newsp(var_id);
        } else {
            auto offset = compile_offset(r->exps, sym.dims);
            gen_imcode(ImCode::MULTIPLY, offset, nonterm_constant::newsp(8), offset);
            gen_imcode(ImCode::DAGET, nonterm_integer::newsp(var_id), offset, store_place);
            return store_place;
        }
    }else if(auto r = dynamic_pointer_cast<number_literal_t>(root)) {
        // 应该不会出现这个情况
        // 被 static analysis 了
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
            rst = store_place;
        }
        code.dest = get_oprand(rst);
    
        auto exps = r->params->exps;    
        for(auto exp: exps){
            auto var = to_nonterm_integer(compile(exp));
            code.arguments.push_back(var->var_id);
        }

        return rst;
    }else{
        assert(false);
    }
}
