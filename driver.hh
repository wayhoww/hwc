#ifndef HWC_DRIVER_H
#define HWC_DRIVER_H

#include "parser.hh"
#include <list>
#include <string>
#include <memory>
#include <cassert>
#include <set>
#include <vector>

#define YY_DECL \
    yy::parser::symbol_type yylex (driver& drv)
YY_DECL;

#define yyterminate() return yy::parser::make_YYEOF();

/**
 * driver 中的符号表要支持两项功能：
 * 1. 作用域管理
 * 2. 根据名称查找当前作用域中的变量示例
 * 
 * 使用 enter_scoop 进入新的作用域
 * 使用 exit_scoop 退出作用域
 * 
 * 类变量 current_depth 记录当前作用域深度。根作用域的深度是 0
 * 
 * 暂时使用一个 list 来存储符号表。使用 map + list 可以
 * 做到 O(logN) 的时间复杂度
 **/



using std::dynamic_pointer_cast;
using std::shared_ptr;

struct GlobalVarDef {
    uint64_t size;                               /* in bytes */
    std::vector<uint64_t> initValue;                         /* 可能没有初始化 */
    std::string identifier;
};
// i.e. 定义的时候用，不会被引用
struct FunctionDef {
    uint64_t entrance;  /* 入口四元式编号  */
    std::string identifier;
    bool returnVoid;
};

struct Var {
    uint64_t varID;
    bool isTemp;
};

// 中间代码
struct ImCode {
    // 其中的 DASET 是指针赋值，DAGET 是指针读取
    // DA: Displacement Addressing
    enum Operator {
        PLUS, MINUS, MULTIPLY, DIVIDE, MODULE,               
        JUMP, JLT, JLE, JGT, JGE, JEQ, JNE, CALL, RET,      
        ALLOC,  // 分配内存，dest 是指针位置， src1 是以字节计算的大小
        DASET,  // displacement addressing set， src1 目的地指针， src2 偏移地址（以byte），dest：实际上的src数字
        DAGET,  // displacement addressing get， 同上
        MARK,   // mark
        ASSIGN  // 赋值         
    };

    struct Oprand {
        // 可能是三种情况：
        // 0. 该字段留空
        // 1. 变量 （包括临时变量）
        // 2. 立即数
        // 3. 中间代码编号
        // 4. 函数编号 (call)
        // 5. 参数编号 （从前往后数，从0开始）
        enum Type { INVALID, VAR, IMMEDIATE, IMCODEID, FUNCID, PARAMID };

        Type type = INVALID;
        union {
            Var var;            // for Var
            uint64_t value;     // for immediate & imCodeID
        };
    };

    Operator op;
    Oprand src1;    /* 不可能是中间代码编号 */
    Oprand src2;    /* 不可能是中间代码编号 */
    Oprand dest;    /* 不可能是立即数 */
    std::vector<uint64_t> arguments;    /* call */
};

struct ImProgram {
    std::vector<ImCode>     imCodes;
    std::vector<GlobalVarDef>  globalVars;
    std::vector<FunctionDef>   functions;
    int startFunction; // 入口函数的函数编号
};

void codegen(const ImProgram& program);

struct symbol_info {
    int scoop_depth;
    std::string identifier = "";
    uint64_t size;
    std::vector<uint64_t> dims;
    bool is_const;
    bool is_temp = false;
    std::vector<uint64_t> init_value; // 冗余
};

struct nonterm_info {
    // TC, FC, CHAIN
    int var_id;
    int trueChain;
    int falseChain;
    int back;
};

class driver {
    // 为了避免 multiple def 暂时放这儿
    std::string format(ImCode::Operator op) {
        switch (op) {
        case ImCode::Operator::ALLOC :      return "alloc";
        case ImCode::Operator::ASSIGN :     return "=";
        case ImCode::Operator::CALL :       return "call";
        case ImCode::Operator::DAGET :      return "*get";
        case ImCode::Operator::DASET :      return "*set";
        case ImCode::Operator::DIVIDE :     return "/";
        case ImCode::Operator::JEQ :        return "j==";
        case ImCode::Operator::JGE :        return "j>=";
        case ImCode::Operator::JGT :        return "j>";
        case ImCode::Operator::JLE :        return "j<=";
        case ImCode::Operator::JLT :        return "j<";
        case ImCode::Operator::JNE :        return "j!=";
        case ImCode::Operator::JUMP :       return "jmp";
        case ImCode::Operator::MARK :       return "mark";
        case ImCode::Operator::MINUS :      return "-";
        case ImCode::Operator::MODULE :     return "%";
        case ImCode::Operator::MULTIPLY :   return "*";
        case ImCode::Operator::PLUS :       return "+";
        case ImCode::Operator::RET :        return "ret";
        default:
            assert(false);
            return "error";
        }
    }


    std::string format(const ImCode::Oprand& oprand) {
        char buffer[1025];
        switch (oprand.type) {
        case ImCode::Oprand::FUNCID:
            sprintf(buffer, "func %d", oprand.value);
            break;
        case ImCode::Oprand::IMCODEID:
            sprintf(buffer, "imcode %d", oprand.value);
            break;
        case ImCode::Oprand::IMMEDIATE:
            sprintf(buffer, "#%d", oprand.value);
            break;
        case ImCode::Oprand::PARAMID:
            sprintf(buffer, "param %d", oprand.value);
            break;
        case ImCode::Oprand::VAR:
            if(oprand.var.isTemp) {
                sprintf(buffer, "$%d (tmp)", oprand.var.varID);
            }else{
                sprintf(buffer, "$%d", oprand.var.varID);
            }
            break;
        case ImCode::Oprand::INVALID:
            sprintf(buffer, "");
            break;
        default:
            sprintf(buffer, "");
            assert(false);
            break;
        }
        return std::string(buffer);
    }

    std::string format(const std::vector<uint64_t>& vec) {
        std::string str = "[";
        for(auto item: vec) {
            str.append(std::to_string(item));
            str.append(", ");
        }
        str.append("]");
        return str;
    }

protected:
    int current_depth = 0;                  //   当前深度（见注释）
    std::vector<symbol_info> symbols;       //   符号表 

    ImProgram imProgram;

    std::vector<FunctionDef>& functions() {
        return imProgram.functions;
    }

    std::vector<GlobalVarDef>& globalVars() {
        return imProgram.globalVars;
    }   
     
    std::vector<ImCode>& imCodes() {
        return imProgram.imCodes;
    }

public:
    void dumpTo(FILE* file) {
        fprintf(file, "Global Variables\n\n");
        fprintf(file, "%-20s%-20s%-20s\n", "VarID", "Identifier", "Size (in bytes)");
        fprintf(file, "------------------------------------------------------------\n");
        for(int i = 0; i < globalVars().size(); i++) {
            auto var = globalVars()[i];
            fprintf(file, "%-20d%-20s%-20d\n", i, var.identifier.c_str(), var.size);
        }        
        fprintf(file, "\n\n");

        fprintf(file, "Functions\n\n");
        fprintf(file, "%-20s%-20s%-20s%-20s\n", "Function ID", "Function Name", "Entrance", "Start Function");
        fprintf(file, "--------------------------------------------------------------------------------\n");
        for(int i = 0; i < functions().size(); i++) {
            auto func = functions()[i];
            fprintf(file, "%-20d%-20s%-20d%-20s\n", i, func.identifier.c_str(), func.entrance, imProgram.startFunction == i ? "YES" : "");
        }
        fprintf(file, "\n\n");

        fprintf(file, "Immediate Code\n\n");
        fprintf(file, "%-20s%-20s%-20s%-20s%-20s\n", "ImCode ID", "Operator", "Src1", "Src2", "Dest", "Arguments");
        fprintf(file, "----------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i < imCodes().size(); i++) {
            auto code = imCodes()[i];
            fprintf(file, "%-20d%-20s%-20s%-20s%-20s\n", i, format(code.op).c_str(), format(code.src1).c_str(), format(code.src2).c_str(), format(code.dest).c_str(), format(code.arguments).c_str());
        }
    }

    int enter_scoop(){
        return ++current_depth;
    }

    int exit_scoop(){
        // 先弹出当前作用域的符号。
        // TODO: 或许还要做一些额外的处理
        while(!symbols.empty() 
            && symbols.rbegin()->scoop_depth == current_depth) {
            symbols.pop_back();
        }
        return --current_depth;
    }

    uint64_t entry(const std::string& ident, const std::vector<uint64_t>& dims, bool is_const_var) {
        for(int i = symbols.size() - 1; i >= 0; i--) {
            if(symbols[i].scoop_depth < current_depth) {
                break;
            }
            if(symbols[i].identifier == ident){
                assert(false);
            }
        }
        symbol_info sym;
        sym.identifier = ident;
        sym.scoop_depth = current_depth;
        sym.is_const = is_const_var;
        sym.dims = dims;
        sym.size = 8;
        for(auto dim: dims) sym.size *= dim;
        symbols.push_back(sym);
        return symbols.size() - 1;
    }

    uint64_t query(const std::string& ident) {
        for(int i = symbols.size() - 1; i >= 0; i--) {
            if(symbols[i].identifier == ident){
                return i;
            }
        }
        assert(false);
        return 0;
    }

    uint64_t add_function(const std::string& ident, uint64_t entrance) {
        for(int i = 0; i < functions().size(); i++) {
            if(functions()[i].identifier == ident){
                assert(false);
            }
        }
        for(int i = 0; i < globalVars().size(); i++) {
            if(globalVars()[i].identifier == ident) {
                assert(false);
            }
        }
        FunctionDef func;
        func.entrance = entrance;
        func.identifier = ident;
        functions().push_back(func);
        return functions().size() - 1;
    }

    uint64_t query_function(const std::string& ident) {
        for(int i = 0; i < functions().size(); i++) {
            auto func = functions()[i];
            if(func.identifier == ident) {
                return i;
            }
        }
        assert(false);
        return 0;
    }


    uint64_t add_var(const std::string& ident, const std::vector<uint64_t>& dims, bool is_const, const std::vector<uint64_t>& init_value) {
        if(current_depth == 0) {
            for(int i = 0; i < functions().size(); i++) {
                if(functions()[i].identifier == ident){
                    assert(false);
                }
            }
            for(int i = 0; i < globalVars().size(); i++) {
                if(globalVars()[i].identifier == ident) {
                    assert(false);
                }
            }
        }
        uint64_t size = 8;
        for(auto dim: dims)
            size *= dim;
        
        if(current_depth == 0) {
            GlobalVarDef var;
            var.identifier = ident;
            var.size = size;
            // var.initValue = 
            globalVars().push_back(var);
        }
        
        auto varID = entry(ident, dims, is_const);
        return varID;
    }

    uint64_t add_temp() {
        symbol_info sym;
        sym.size = 8;
        sym.is_const = false;
        sym.scoop_depth = current_depth;
        sym.is_temp = true;
        symbols.push_back(sym);
        return symbols.size() - 1;
    }

    int compile(const shared_ptr<comp_unit_t>& comp_unit){
        printf("IMCODE GEN\n\n");
        for(auto child: comp_unit->children) {
            compile(child);
        }
        dumpTo(stdout);
        codegen(imProgram);
        return 0;
    }

    void compile(const shared_ptr<comp_unit_item_t>& ptr){
        auto decl = dynamic_pointer_cast<comp_unit_item_decl_t>(ptr);  
        auto func_def = dynamic_pointer_cast<comp_unit_item_func_def_t>(ptr);  
        if(decl) { compile(decl->decl); return; }
        if(func_def) { compile(func_def->func_def); return; }
        assert(false);
        return;
    }

    void compile(const shared_ptr<func_def_t>& funcdef) {
        auto type = funcdef->func_type->type;
        auto funcname = funcdef->ident->name;

        // 逻辑要搞清楚
        // 多次调用、递归调用同一个函数，对每一个局部变量得到的 var id 必定是
        // 一样的。这不是实现问题，是逻辑问题
        // 在开始生成其代码之前 enter scoop，在生成结束之后 exit scoop，恰好没问题
        // 一个函数知会被生成一次代码

        auto entrance = imCodes().size();
        auto funcid = add_function(funcname, entrance);
        if(funcname == "main") {
            this->imProgram.startFunction = funcid;
        }
        
        enter_scoop();
        
        // 参数
        int i = 0;
        for(auto param: funcdef->params->params) {
            compile(param, i++);
        }

        compile(funcdef->block, false);

        exit_scoop();

    }

    void compile(const shared_ptr<block_t>& block, bool enter_new_scoop = true) {
        if(enter_new_scoop) enter_scoop();

        for(auto child: block->children) {
            compile(child);
        }

        if(enter_new_scoop) exit_scoop();
    }

    void compile(const shared_ptr<block_item_t>& item) {
        auto decl = dynamic_pointer_cast<block_item_decl_t>(item);
        auto stmt = dynamic_pointer_cast<block_item_stmt_t>(item);
        if(decl){
            compile(decl->decl);
            return;
        }
        if(stmt){
            compile(stmt->stmt);
            return;
        }
        assert(false);
    }




    void compile(const shared_ptr<func_f_param_t>& param, int param_index) {
        assert(param->b_type->type == b_type_t::INT);
        
    // 不需要 const ？ 去看一下语义
    //    auto [size, dims] = static_array_dims(param->array_dims);
        std::vector<uint64_t> dims;
        auto id = entry(param->ident->name, dims, false);
        ImCode code;
        code.op = ImCode::MARK;
        code.src1.type = ImCode::Oprand::PARAMID;
        code.src1.value = param_index;
        code.dest.type = ImCode::Oprand::VAR;
        code.dest.var.isTemp = false;
        code.dest.var.varID = id;
        imCodes().push_back(code);
    }

    void compile(const shared_ptr<construct>& funcdef) {
        assert(false);
    }

    void compile(const shared_ptr<stmt_t>& stmt) {
        auto s_if        = dynamic_pointer_cast<stmt_if_t>(stmt);
        auto s_return    = dynamic_pointer_cast<stmt_return_t>(stmt);
        auto s_while     = dynamic_pointer_cast<stmt_while_t>(stmt);
        auto s_assign    = dynamic_pointer_cast<stmt_assign_t>(stmt);
        auto s_block     = dynamic_pointer_cast<stmt_block_t>(stmt);
        auto s_continue  = dynamic_pointer_cast<stmt_continue_t>(stmt);
        auto s_exp       = dynamic_pointer_cast<stmt_exp_t>(stmt);
        auto s_break     = dynamic_pointer_cast<stmt_break_t>(stmt);
        if(s_if      )  {  compile(s_if        ); return; }  
        if(s_return  )  {  compile(s_return    ); return; }  
        if(s_while   )  {  compile(s_while     ); return; }  
        if(s_assign  )  {  compile(s_assign    ); return; }  
        if(s_block   )  {  compile(s_block     ); return; }  
        if(s_continue)  {  compile(s_continue  ); return; }  
        if(s_exp     )  {  compile(s_exp       ); return; }  
        if(s_break   )  {  compile(s_break     ); return; }  
        assert(false);
    }

    nonterm_info compile(const shared_ptr<cond_t>& cond) {
        auto lor = dynamic_pointer_cast<cond_l_or_t>(cond);
        assert(lor);
        auto lorexp = lor->l_or_exp;
        auto s1 = dynamic_pointer_cast<l_or_exp_applied_t>(lorexp);
        auto s2 = dynamic_pointer_cast<l_or_exp_and_t>(lorexp);
        nonterm_info info;
        if(s1) {

        }else if(s2) {
            
        }else {
            assert(false);
        }
        return info;
    }

    void compile(const shared_ptr<stmt_if_t>& stmt) {

    }
    void compile(const shared_ptr<stmt_return_t>& stmt) {
        ImCode code;
        code.op = ImCode::RET;
        if(stmt->exp) {
            code.src1 = get_oprand_var(compile(stmt->exp).var_id);
        }
        imCodes().push_back(code);
    }
    void compile(const shared_ptr<stmt_while_t>& stmt) {

    }
    void compile(const shared_ptr<stmt_assign_t>& stmt) {
        auto ident = stmt->l_val->ident->name;
        auto varid = query(ident);

        auto dims = symbols[varid].dims;
        assert(stmt->l_val->exps.size() == dims.size());
        
        auto rval = compile(stmt->exp);

        if(dims.size() == 0) {
            ImCode code;
            code.op = ImCode::ASSIGN;
            code.src1 = get_oprand_var(rval.var_id);
            code.dest = get_oprand_var(varid);
            imCodes().push_back(code);
            return;
        }
        auto offset = compile_for_index(stmt->l_val->exps, dims).var_id;

        gen_arithmetic_ri(ImCode::MULTIPLY, offset, 8, offset);
        gen_arithmetic_rr(ImCode::DASET, varid, offset, rval.var_id);
    }

    nonterm_info compile_for_index(const ptr_list_of<exp_t>& exps, const std::vector<uint64_t> dims) {
        // 暂时不做边界检查
        auto offset = add_temp();

        int index = 1;
        for(auto exp: exps) {
            auto dim = compile(exp).var_id;
            gen_arithmetic_rr(ImCode::PLUS, offset, dim, offset);
            if(index < dims.size()) {
                gen_arithmetic_ri(ImCode::MULTIPLY, offset, dims[index++], offset);
            }
        }
        nonterm_info info;
        info.var_id = offset;
        return info;
    }

    nonterm_info compile(const shared_ptr<exp_t>& exp) {
        nonterm_info info;
        auto a = dynamic_pointer_cast<exp_add_t>(exp);
        if(a) { return compile(a->add_exp); }
        assert(false);
        return info;
    }

    nonterm_info compile(const shared_ptr<add_exp_t>& exp) {
        // TODO 即便是 a + 1, 1 也会被作为一个变量存储。 这需要改进。
        nonterm_info info;
        auto s1 = dynamic_pointer_cast<add_exp_applied_t>(exp);
        auto s2 = dynamic_pointer_cast<add_exp_mul_t>(exp);
        if(s1) { 
            auto var1 = compile(s1->add_exp).var_id;
            auto var2 = compile(s1->mul_exp).var_id;
            auto dest = add_temp();
            info.var_id = dest;
            gen_arithmetic_rr(get_operator(s1->op->type), var1, var2, dest);
            return info;
        } else if (s2) {
            return compile(s2->mul_exp);
        }
        assert(false);
        return info;
    }    

    void gen_arithmetic_rr(ImCode::Operator op, int var1, int var2, int dest) {
        ImCode code;
        code.op = op;
        code.src1 = get_oprand_var(var1);
        code.src2 = get_oprand_var(var2);
        code.dest = get_oprand_var(dest);
        imCodes().push_back(code);
    } 

    void gen_arithmetic_ri(ImCode::Operator op, int var1, int64_t var2, int dest) {
        ImCode code;
        code.op = op;
        code.src1 = get_oprand_var(var1);
        code.src2.type = ImCode::Oprand::IMMEDIATE;
        code.src2.value = var2;
        code.dest = get_oprand_var(dest);
        imCodes().push_back(code);
    } 
    
    void gen_arithmetic_ir(ImCode::Operator op, int64_t var1, int var2, int dest) {
        ImCode code;
        code.op = op;
        code.src1.type = ImCode::Oprand::IMMEDIATE;
        code.src1.value = var1;
        code.src2 = get_oprand_var(var2);
        code.dest = get_oprand_var(dest);
        imCodes().push_back(code);
    } 

    ImCode::Oprand get_oprand_var(int varID) {
        assert(varID < symbols.size());
        auto sym = symbols[varID];
        ImCode::Oprand op;
        op.type = ImCode::Oprand::VAR;
        op.var.isTemp = sym.is_temp;
        op.var.varID = varID;
        return op;
    }
    
    nonterm_info compile(const shared_ptr<mul_exp_t>& exp) {
        nonterm_info info;
        auto s1 = dynamic_pointer_cast<mul_exp_applied_t>(exp);
        auto s2 = dynamic_pointer_cast<mul_exp_unary_t>(exp);
        if(s1) { 
            auto var1 = compile(s1->mul_exp).var_id;
            auto var2 = compile(s1->unary_exp).var_id;
            auto dest = add_temp();
            info.var_id = dest;
            gen_arithmetic_rr(get_operator(s1->op->type), var1, var2, dest);
            return info;
        } else if (s2) {
            return compile(s2->unary_exp);
        }
        assert(false);
        return info;
    }

    ImCode::Operator get_operator(operator_t::Type op){
        switch(op) {
            case operator_t::PLUS: return ImCode::PLUS;
            case operator_t::MINUS: return ImCode::MINUS;
            case operator_t::MULTIPLY: return ImCode::MULTIPLY;
            case operator_t::DIVIDE: return ImCode::DIVIDE;
            case operator_t::MODULE: return ImCode::MODULE;
            default: 
            assert(false);
            return ImCode::PLUS;
        }
    }

    nonterm_info compile(const shared_ptr<unary_exp_t>& exp) {
        nonterm_info info;
        auto s1 = dynamic_pointer_cast<unary_exp_applied_t>(exp);
        auto s2 = dynamic_pointer_cast<unary_exp_primary_exp_t>(exp);
        auto s3 = dynamic_pointer_cast<unary_exp_func_call_t>(exp);
        
        if(s1) {
            auto subvar = compile(s1->unary_exp);
            if(s1->op->type == operator_t::NEGATIVE) {
                // temp = 0 - var
                info.var_id = add_temp(); 
                gen_arithmetic_ir(ImCode::MINUS, 0, subvar.var_id, info.var_id);
                return info;
            } else {
                return subvar;
            }
        } else if(s2) {
            return compile(s2->primary_exp);
        } else if(s3) {
            auto temp = add_temp();
            ImCode code;
            code.op = ImCode::CALL;
            code.src1.type = ImCode::Oprand::FUNCID;
            code.src1.value = query_function(s3->ident->name);
            info.var_id = -1;
            if(!functions()[code.src1.value].returnVoid) {
                code.dest.type = ImCode::Oprand::VAR;
                code.dest.value = add_temp();
                info.var_id = code.dest.value;
            }
            auto exps = s3->params->exps;
            
            for(auto exp: exps){
                auto varid = compile(exp).var_id;
                code.arguments.push_back(varid);
            }

            return info;
        } else {
            assert(false);
            return info;
        }
    }

    nonterm_info compile(const shared_ptr<primary_exp_t>& exp) {
        nonterm_info info;
        auto s1 = dynamic_pointer_cast<primary_exp_number_t>(exp);
        auto s2 = dynamic_pointer_cast<primary_exp_exp_t>(exp);
        auto s3 = dynamic_pointer_cast<primary_exp_l_val_t>(exp);
        if(s1) {
            auto value = s1->number->int_const->value;
            info.var_id = add_temp();
            ImCode code;
            code.op = ImCode::ASSIGN;
            code.src1.type = ImCode::Oprand::IMMEDIATE;
            code.src1.value = value;
            code.dest = get_oprand_var(info.var_id);
            imCodes().push_back(code);
            return info;
        } else if(s2) {
            return compile(s2->exp);
        } else if(s3) {
            auto lval = s3->l_val;
            auto varid = query(lval->ident->name);
            auto dims = lval->exps;
            if(dims.empty()) {
                info.var_id = varid;
            } else {
                info.var_id = add_temp();
                auto offset = compile_for_index(dims, symbols[varid].dims).var_id;
                gen_arithmetic_ri(ImCode::MULTIPLY, offset, 8, offset);
                gen_arithmetic_ri(ImCode::DAGET, varid, offset, info.var_id);
            }
            return info;
        } else {
            assert(false);
            return info;
        }
    }

    void compile(const shared_ptr<stmt_block_t>& stmt) {
        auto block = stmt->block;
        compile(block, true);
    }
    void compile(const shared_ptr<stmt_continue_t>& stmt) {

    }
    nonterm_info compile(const shared_ptr<stmt_exp_t>& stmt) {
        return compile(stmt->exp);
    }
    void compile(const shared_ptr<stmt_break_t>& stmt) {

    }

    void compile(const shared_ptr<decl_t>& decl) {
        auto const_decl = dynamic_pointer_cast<decl_const_decl_t>(decl);
        auto var_decl = dynamic_pointer_cast<decl_var_decl_t>(decl);
        if(var_decl) {
            compile(var_decl->var_decl);
            return;
        }
        if(const_decl) {
            compile(const_decl->const_decl);
            return;
        }
        assert(false);
        return;
    }

    void compile(const shared_ptr<var_decl_t>& decl) {
        assert(decl->b_type->type == b_type_t::INT);
        for(auto def: decl->var_defs) {
            compile(def);
        }
    }

    void compile(const shared_ptr<var_def_t>& def) {
        auto defonly = dynamic_pointer_cast<var_def_only_t>(def);
        auto definit = dynamic_pointer_cast<var_def_init_t>(def);
        if(defonly) {
            compile(defonly);
            return;
        }
        if(definit) {
            compile(definit);
            return;
        }
        assert(false);
    }

    void compile(const shared_ptr<var_def_only_t>& def_only) {
        auto [size, dims] = static_array_dims(def_only->array_dims);
        auto id = add_var(def_only->ident->name, dims, false, std::vector<uint64_t>());
        if(dims.empty() && current_depth > 0) {
            gen_alloc(id, size * 8);
        }
    }    
    
    void compile(const shared_ptr<var_def_init_t>& def_init) {
        auto [size, dims] = static_array_dims(def_init->array_dims);
        // 取init的时候要用到dims和size
        // TODO init
        auto id = add_var(def_init->ident->name, dims, false, std::vector<uint64_t>());
        if(dims.empty() && current_depth > 0) {
            gen_alloc(id, size * 8);
        }
    }

    void gen_alloc(int id, uint64_t size) {
        ImCode code;
        code.op = ImCode::ALLOC;
        code.src1.type  = ImCode::Oprand::IMMEDIATE;
        code.src1.value = size;
        code.dest.type = ImCode::Oprand::VAR;
        code.dest.var.isTemp = false;
        code.dest.var.varID = id;
        imCodes().push_back(code); 
    }

    void compile(const shared_ptr<const_decl_t>& decl) {
        assert(decl->b_type->type == b_type_t::INT);
        for(auto def: decl->const_defs) {
            compile(def);
        }
    }

    std::pair<uint64_t, std::vector<uint64_t>> static_array_dims(const ptr_list_of<const_exp_t>& dimsdef) {
        uint64_t size = 1;
        std::vector<uint64_t> dims;
        for(auto dim: dimsdef) {
            auto val = static_eval(dim);
            size *= val;
            dims.push_back(val);
        }
        return std::make_pair(size, dims);      
    }

    void compile(const shared_ptr<const_def_t>& constdef) {
        auto [size, dims] = static_array_dims(constdef->array_dims);

        // TODO 暂时不做 initialization
        // constdef->const_init_val
        auto varid = add_var(constdef->ident->name, dims, true, std::vector<uint64_t>());
        symbols[varid].init_value = std::vector<uint64_t>(size, 0);
    }

    int64_t static_eval(const shared_ptr<const_exp_t>& constexp) {
        auto exp = dynamic_pointer_cast<const_exp_add_t>(constexp);
        assert(exp);
        return static_eval(exp);
    }

    int64_t static_eval(const shared_ptr<const_exp_add_t>& exp) {
        return static_eval(exp->add_exp);
    }

    int64_t static_eval(const shared_ptr<add_exp_t>& add_exp) {
        auto mul_exp = dynamic_pointer_cast<add_exp_mul_t>(add_exp);
        auto applied_exp = dynamic_pointer_cast<add_exp_applied_t>(add_exp);
        if(mul_exp) return static_eval(mul_exp->mul_exp);
        if(applied_exp) {
            int op = applied_exp->op->type == operator_t::PLUS ? 1 : -1;
            return static_eval(applied_exp->add_exp) + op * static_eval(applied_exp->mul_exp);
        }
        assert(false);
    }

    int64_t static_eval(const shared_ptr<mul_exp_t>& mul_exp) {
        auto unary_exp = dynamic_pointer_cast<mul_exp_unary_t>(mul_exp);
        auto applied_exp = dynamic_pointer_cast<mul_exp_applied_t>(mul_exp);
        if(unary_exp) return static_eval(unary_exp->unary_exp);
        if(applied_exp && applied_exp->op->type == operator_t::MULTIPLY)
            return static_eval(applied_exp->mul_exp) * static_eval(applied_exp->unary_exp);
        if(applied_exp && applied_exp->op->type == operator_t::DIVIDE)
            return static_eval(applied_exp->mul_exp) / static_eval(applied_exp->unary_exp); 
        if(applied_exp && applied_exp->op->type == operator_t::MODULE)
            return static_eval(applied_exp->mul_exp) % static_eval(applied_exp->unary_exp); 
        assert(false);
    }

    int64_t static_eval(const shared_ptr<unary_exp_t>& exp) {
        auto applied_exp = dynamic_pointer_cast<unary_exp_applied_t>(exp);
        auto primary_exp = dynamic_pointer_cast<unary_exp_primary_exp_t>(exp);
        if(applied_exp){
            auto oprand = static_eval(applied_exp->unary_exp);
            switch (applied_exp->op->type) {
            case operator_t::POSITIVE:
                return oprand;
                break;
            case operator_t::NEGATIVE:
                return -oprand;
                break;
            // case operator_t::LOGICAL_NOT:
            //     return !oprand;
            //     break;
            default:
                break;
            }
        }
        if(primary_exp) {
            return static_eval(primary_exp->primary_exp);
        }
        assert(false);
    }

    int64_t static_eval(const shared_ptr<primary_exp_t>& exp) {
        // TODO: 暂时不考虑 funcall
        auto number = dynamic_pointer_cast<primary_exp_number_t>(exp);
        if(number) return static_eval(number->number);
        auto lval = dynamic_pointer_cast<primary_exp_l_val_t>(exp);

        if(lval) {
            auto varid = query(lval->l_val->ident->name);
            if(!symbols[varid].is_const) assert(false);
            auto exps = lval->l_val->exps;
            
            int offset = 0;
            int index = 1;
            for(auto exp: exps) {
                offset += static_eval(exp);
                if(index != exps.size() - 1) {
                    offset *= symbols[varid].dims[index++];
                }
            }
            return symbols[varid].init_value[index];
        }
        assert(false);
    }

    int64_t static_eval(const shared_ptr<exp_t>& exp) {
        auto s = dynamic_pointer_cast<exp_add_t>(exp);
        assert(s);
        return static_eval(s->add_exp);
    }

    int64_t static_eval(const shared_ptr<number_t>& number) {
        return number->int_const->value;
    }

};

#endif