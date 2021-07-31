#ifndef HWC_DRIVER_H
#define HWC_DRIVER_H

#include "parser.hh"
#include <list>
#include <string>
#include <memory>
#include <cassert>
#include <set>
#include <vector>
#include <map>

#define YY_DECL \
    yy::parser::symbol_type yylex (driver& drv)
YY_DECL;

#define yyterminate() return yy::parser::make_YYEOF();


using std::dynamic_pointer_cast;
using std::shared_ptr;

/* 中间代码数据结构 BEGIN */

struct GlobalVarDef {
    uint32_t size;                               /* in bytes */
    std::vector<int32_t> initValue;                         /* 可能没有初始化 */
    std::string identifier;
};
// i.e. 定义的时候用，不会被引用
struct FunctionDef {
    uint32_t entrance;  /* 入口四元式编号  */
    std::string identifier;
    bool returnVoid;
};

struct Var {
    uint32_t varID;
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
            uint32_t value;     // for immediate & imCodeID
        };
    };

    Operator op;
    Oprand src1;    /* 不可能是中间代码编号 */
    Oprand src2;    /* 不可能是中间代码编号 */
    Oprand dest;    /* 不可能是立即数 */
    std::vector<uint32_t> arguments;    /* call */
};

struct ImProgram {
    std::vector<ImCode>     imcodes;
    std::vector<GlobalVarDef>  globalVars;
    std::vector<FunctionDef>   functions;
    int startFunction; // 入口函数的函数编号
};

void codegen(const ImProgram& program);

/* 中间代码数据结构 END */


/* 工具函数 BEGIN */

std::string format(ImCode::Operator op);
std::string format(const ImCode::Oprand& oprand);
std::string format(const std::vector<uint32_t>& vec);

/* 工具函数 END */


/* DRIVER BEGIN */

// 因为有各种正交，所以就不再分出来了
struct symbol_info {
    int scoop_depth;                        /* 字面意思 */
    std::string identifier = "";            /* 标志符号 */

    uint32_t size;                          /* 大小。常数也要设置大小。以机器字为单位  */
    std::vector<uint32_t> dims;             /* 维度。如果是常数，dims.empty()       */          
    std::vector<int32_t> init_value;        /* 是冗余的，初始化数值，如果是数组，则取 init_value[0]. */

    bool is_const = false;                          
    bool is_temp = false;                   
};

// 因为是完全不交叉的，所以分成子类
struct nonterm_info {
    virtual ~nonterm_info() = default;
};

// literal: 目前仅仅支持 integer
struct nonterm_constant: nonterm_info {
    int32_t value;
    nonterm_constant(int32_t value): value(value) {}
    static std::shared_ptr<nonterm_constant> newsp(int32_t val) {
        return std::make_shared<nonterm_constant>(val);
    }
};

struct nonterm_boolean: nonterm_info {
    std::vector<int> true_exits;
    std::vector<int> false_exits;
    nonterm_boolean(const std::vector<int>& true_exits,
                        const std::vector<int>& false_exits)
                    :true_exits(true_exits), false_exits(false_exits) {}
    static std::shared_ptr<nonterm_boolean> newsp(
                        const std::vector<int>& true_exits,
                        const std::vector<int>& false_exits) {
        return std::make_shared<nonterm_boolean>(true_exits, false_exits);
    }
};

struct nonterm_controlflow: nonterm_info {
    std::vector<int> break_exits;
    std::vector<int> continue_exits;;
    nonterm_controlflow(const std::vector<int>& break_exits,
                        const std::vector<int>& continue_exits)
                    :break_exits(break_exits), continue_exits(continue_exits) {}
    static std::shared_ptr<nonterm_controlflow> newsp(
                        const std::vector<int>& break_exits,
                        const std::vector<int>& continue_exits) {
        return std::make_shared<nonterm_controlflow>(break_exits, continue_exits);
    }
};

struct nonterm_integer: nonterm_info {
    uint32_t var_id;
    nonterm_integer(uint32_t var_id): var_id(var_id) {}
    static std::shared_ptr<nonterm_integer> newsp(int32_t val) {
        return std::make_shared<nonterm_integer>(val);
    }
};

struct nonterm_void: nonterm_info {
    static std::shared_ptr<nonterm_void> newsp() {
        return std::make_shared<nonterm_void>();
    }
};

class driver {
    // 为了避免 multiple def 暂时放这儿
protected:
    int current_depth = 0;                  //   当前深度（见注释）
    std::vector<symbol_info> symbols;       //   符号表,  symbols 的下标就是 var_id
    std::map<shared_ptr<expr>, std::pair<bool, int32_t>> static_eval_cache; 
    int nxq() {
        return imcodes().size();
    }

    std::vector<FunctionDef>& functions() {
        return imProgram.functions;
    }

    std::vector<GlobalVarDef>& global_vars() {
        return imProgram.globalVars;
    }   
     
    std::vector<ImCode>& imcodes() {
        return imProgram.imcodes;
    }

public:
    std::shared_ptr<comp_unit_t> syntax_tree = nullptr;

    ImProgram imProgram;

    void dump_to(FILE* file);

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

    // 不要调用 entry
    // 添加函数调用 add_var, 自动判断是否是global的函数，并自动添加到全局变量表和符号表中

    uint32_t entry(const std::string& ident, const std::vector<uint32_t>& dims, bool is_const_var, const std::vector<int32_t>& init_value);
    
    uint32_t add_function(const std::string& ident, uint32_t entrance, bool returnVoid) ;

    uint32_t query_function(const std::string& ident) ;

    uint32_t add_var(const std::string& ident, const std::vector<uint32_t>& dims, bool is_const, const std::vector<int32_t>& init_value) ;
    
    uint32_t query_var(const std::string& ident);

    uint32_t add_temp();

    void compile() {
        compile(syntax_tree);
    }

    std::shared_ptr<nonterm_info> compile_offset(const ptr_list_of<expr>& exps, const std::vector<uint32_t> dims);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<expr>& root, std::shared_ptr<nonterm_integer> store_place = nullptr);

    std::shared_ptr<nonterm_boolean> to_nonterm_boolean(const shared_ptr<nonterm_info>& info);
    std::shared_ptr<nonterm_integer> to_nonterm_integer(const std::shared_ptr<nonterm_info>& info, std::shared_ptr<nonterm_integer> store_place = nullptr);

    void backpatch(const std::vector<int>& ids, int value) {
        for(auto i: ids) imcodes()[i].dest.value = value;
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<comp_unit_t>& comp_unit){
        printf("IMCODE GEN\n\n");
        for(auto child: comp_unit->children) {
            compile(child);
        }
        dump_to(stdout);
        codegen(imProgram);
        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<comp_unit_item_t>& ptr){
        auto decl = dynamic_pointer_cast<comp_unit_item_decl_t>(ptr);  
        auto func_def = dynamic_pointer_cast<comp_unit_item_func_def_t>(ptr);  
        if(decl) {  return compile(decl->decl); }
        else if(func_def) { return compile(func_def->func_def); }
        else { assert(false); }


        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<construct>& funcdef) {
        assert(false);
        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<func_def_t>& funcdef) {
        auto type = funcdef->func_type->type;
        auto funcname = funcdef->ident;

        // 逻辑要搞清楚
        // 多次调用、递归调用同一个函数，对每一个局部变量得到的 var id 必定是
        // 一样的。这不是实现问题，是逻辑问题
        // 在开始生成其代码之前 enter scoop，在生成结束之后 exit scoop，恰好没问题
        // 一个函数知会被生成一次代码

        auto entrance = imcodes().size();
        auto funcid = add_function(funcname, entrance, funcdef->func_type->type == b_type_t::VOID);
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

        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<block_t>& block, bool enter_new_scoop = true) {
        if(enter_new_scoop) enter_scoop();

        auto info = nonterm_controlflow::newsp({}, {});

        for(auto child: block->children) {
            if(auto r = dynamic_pointer_cast<nonterm_controlflow>(compile(child))){
                for(auto x: r->break_exits) info->break_exits.push_back(x);
                for(auto x: r->continue_exits) info->continue_exits.push_back(x);
            }
        }

        if(enter_new_scoop) exit_scoop();


        return info;
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<block_item_t>& item) {
        auto decl = dynamic_pointer_cast<block_item_decl_t>(item);
        auto stmt = dynamic_pointer_cast<block_item_stmt_t>(item);
        if(decl){
            return compile(decl->decl);
        } else if(stmt){
            return compile(stmt->stmt);
        } else {
            assert(false);
        }
        // todo
        return nonterm_void::newsp();
    }



    std::shared_ptr<nonterm_info> compile(const shared_ptr<func_f_param_t>& param, int param_index) {
        assert(param->b_type->type == b_type_t::INT);
        
    // 不需要 const ？ 去看一下语义
    //    auto [size, dims] = static_array_dims(param->array_dims);
        std::vector<uint32_t> dims;
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

    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_t>& stmt) {
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
        assert(false);
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_if_t>& stmt);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_return_t>& stmt) {
        ImCode code;
        code.op = ImCode::RET;
        if(stmt->exp) {
            code.src1 = get_oprand(compile(stmt->exp));
        }
        imcodes().push_back(code);

        return nonterm_void::newsp();
    }
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_while_t>& stmt) {
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
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_assign_t>& stmt) {
        auto ident = stmt->l_val->ident;
        auto dest = nonterm_integer::newsp(query_var(ident));

        auto dims = symbols[dest->var_id].dims;
        assert(stmt->l_val->exps.size() == dims.size());
        
       
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


    void gen_imcode(ImCode::Operator op, 
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

    void gen_imcode(ImCode::Operator op, 
                            const std::shared_ptr<nonterm_info>&    src1, 
                            const std::shared_ptr<nonterm_info>&    src2, 
                            const std::shared_ptr<nonterm_info>&    dest) {
        ImCode code;
        code.op = op;
        code.src1 = get_oprand(src1);
        code.src2 = get_oprand(src2);
        code.dest = get_oprand(dest);
        // 除非是 DASET，不然 dest 必须是 integer

        assert( dynamic_pointer_cast<nonterm_integer>(dest) ||
                (code.op == ImCode::DASET && dynamic_pointer_cast<nonterm_constant>(dest)));
        imcodes().push_back(code);
    } 

    ImCode::Oprand get_oprand(const std::shared_ptr<nonterm_info>& info) {
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
        
        if(dynamic_pointer_cast<nonterm_void>(info)){
            op.type = ImCode::Oprand::INVALID;
            return op;
        }
        
        assert(false);
    }


    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_block_t>& stmt) {
        auto block = stmt->block;
        return compile(block, true);
    }
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_continue_t>& stmt) {
        auto rtn = nonterm_controlflow::newsp({}, {nxq()});
        gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), 0);
        return rtn;
    }
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_exp_t>& stmt) {
        return compile(stmt->exp);
    }
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_break_t>& stmt) {
        auto rtn = nonterm_controlflow::newsp({nxq()}, {});
        gen_imcode(ImCode::JUMP, nonterm_void::newsp(), nonterm_void::newsp(), 0);
        return rtn;
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<decl_t>& decl) {
        auto const_decl = dynamic_pointer_cast<decl_const_decl_t>(decl);
        auto var_decl = dynamic_pointer_cast<decl_var_decl_t>(decl);
        if(var_decl) {
            return compile(var_decl->var_decl);
        }else if(const_decl) {
            return compile(const_decl->const_decl);
        }else{
            assert(false);
        }

        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<var_decl_t>& decl) {
        assert(decl->b_type->type == b_type_t::INT);
        for(auto def: decl->var_defs) {
            compile(def);
        }

        return nonterm_void::newsp();
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<var_def_t>& def) {
        auto defonly = dynamic_pointer_cast<var_def_only_t>(def);
        auto definit = dynamic_pointer_cast<var_def_init_t>(def);
        if(defonly) {
            return compile(defonly);
        } else if(definit) {
            return compile(definit);
        } else {
            assert(false);
        }
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<var_def_only_t>& def_only) {
        auto [size, dims] = static_array_dims(def_only->array_dims);
        auto id = add_var(def_only->ident, dims, false, {});
        if(!dims.empty() && current_depth > 0) {
            gen_alloc(id, size * 4);
        }

        return nonterm_void::newsp();
    }    
    
    
    void flatten(shared_ptr<init_val_t> init_val, std::vector<std::shared_ptr<expr>>& vec) {
        if (auto r = dynamic_pointer_cast<init_val_scalar_t>(init_val)) {
            vec.push_back(r->exp);
        } else if (auto r = dynamic_pointer_cast<init_val_array_t>(init_val)) {
            for(auto sub: r->array_elements) {
                flatten(sub, vec);
            }
        }
    }

    std::vector<std::shared_ptr<expr>> flatten(shared_ptr<init_val_t> init_val) {
        std::vector<std::shared_ptr<expr>> vec;
        flatten(init_val, vec);
        return vec;
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<var_def_init_t>& def_init) {
        auto [size, dims] = static_array_dims(def_init->array_dims);
        // 取init的时候要用到dims和size
        // TODO init
        auto id = add_var(def_init->ident, dims, false, {});
        if(!dims.empty() && current_depth > 0) {
            gen_alloc(id, size * 4);
            auto flat_exps = flatten(def_init->init_val);
            auto index = nonterm_integer::newsp(add_temp());
            gen_imcode(ImCode::ASSIGN, nonterm_constant::newsp(0), nonterm_void::newsp(), index);
            if(flat_exps.size() == size) {
                for(int i = 0; i < size; i++){
                    gen_imcode(ImCode::DASET, nonterm_integer::newsp(id), index, compile(flat_exps[i]));
                    if(i < size) {
                        gen_imcode(ImCode::PLUS, index, nonterm_constant::newsp(4), index);
                    }
                }
            } else {
                // TODO
                assert(false);
            }
        } else {
            if(auto r = dynamic_pointer_cast<init_val_scalar_t>(def_init->init_val)) {
                compile(r->exp, nonterm_integer::newsp(id));
            } else {
                assert(false);
            }
        }

        return nonterm_void::newsp();
    }

    void gen_alloc(int id, uint32_t size) {
        ImCode code;
        code.op = ImCode::ALLOC;
        code.src1.type  = ImCode::Oprand::IMMEDIATE;
        code.src1.value = size;
        code.dest.type = ImCode::Oprand::VAR;
        code.dest.var.isTemp = false;
        code.dest.var.varID = id;
        imcodes().push_back(code); 
    }

    std::shared_ptr<nonterm_info> compile(const shared_ptr<const_decl_t>& decl) {
        assert(decl->b_type->type == b_type_t::INT);
        for(auto def: decl->const_defs) {
            compile(def);
        }
        return nonterm_void::newsp();
    }

    void flatten(shared_ptr<const_init_val_t> init_val, std::vector<std::shared_ptr<expr>>& vec) {
        if (auto r = dynamic_pointer_cast<const_init_val_scalar_t>(init_val)) {
            vec.push_back(r->const_exp);
        } else if (auto r = dynamic_pointer_cast<const_init_val_array_t>(init_val)) {
            for(auto sub: r->array_elements) {
                flatten(sub, vec);
            }
        }
    }

    std::vector<std::shared_ptr<expr>> flatten(shared_ptr<const_init_val_t> init_val) {
        std::vector<std::shared_ptr<expr>> vec;
        flatten(init_val, vec);
        return vec;
    }

    // [3, 5]
    void recursive_evaluate(
            shared_ptr<const_init_val_t> init_val, 
            std::vector<uint32_t> dims, 
            int layer, 
            int layer_size,
            int offset,
            std::vector<int32_t>& buffer) {
        if (auto r = dynamic_pointer_cast<const_init_val_scalar_t>(init_val)) {
            auto [ok, val] = static_eval(r->const_exp);
            assert(ok);
            buffer[offset] = val;
        } else if (auto r = dynamic_pointer_cast<const_init_val_array_t>(init_val)) {
            if(r->array_elements.size() == 0) {
                for(int i = 0; i < layer_size; i++) {
                    buffer[offset + i] = 0;
                }
            } else if(auto flat = flatten(init_val); flat.size() == layer_size) {
                for(int i = 0; i < layer_size; i++) {
                    auto [ok, val] = static_eval(flat[i]);
                    assert(ok);
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

    std::shared_ptr<nonterm_info> compile(const shared_ptr<const_def_t>& constdef) {
        auto [size, dims] = static_array_dims(constdef->array_dims);

        std::vector<int32_t> init(size, 0);
        recursive_evaluate(constdef->const_init_val, dims, 0, size, 0, init);
        //auto flat_init = flatten(constdef->const_init_val);
        /*
        if(flat_init.size() == size) {
            for(int i = 0; i < flat_init.size(); i++) {
                auto [ok, val] = static_eval(flat_init[i]);
                assert(ok);
                init[i] = val;
            }
        } else {
            // TODO
            assert(false);
        }*/


        auto varid = add_var(constdef->ident, dims, true, init);
        
        return nonterm_void::newsp();
    }

    std::pair<uint32_t, std::vector<uint32_t>> static_array_dims(const ptr_list_of<expr>& dimsdef) {
        uint32_t size = 1;
        std::vector<uint32_t> dims;
        for(auto dim: dimsdef) {
            auto [ok, val] = static_eval(dim);
            assert(ok);
            size *= val;
            dims.push_back(val);
        }
        return std::make_pair(size, dims);      
    }
    

    /* static evaluation (for integer) */
    /* { true, val } 有静态数值          */
    /* { false, _} 反之                 */
    /*  考虑先用记忆化解决问题             */
    std::pair<bool, int32_t> static_eval_offset(const ptr_list_of<expr> indices, 
                                                const std::vector<uint32_t>& dims);
    std::pair<bool, int32_t> static_eval(shared_ptr<expr> root);
};

#endif