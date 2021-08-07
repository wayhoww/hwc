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
    int32_t size;                               /* in bytes */
    std::vector<int32_t> initValue;                         /* 可能没有初始化 */
    std::string identifier;
    bool isArray = false;
};

struct Argument {
    // dims.empty(): scalar
    // 否则：数组
    // dims[0] == -1，因为形参不指定最高维度大小
    Argument(const std::vector<int32_t>& dims): dims(dims) {};
    Argument(){}
    std::vector<int32_t> dims;
};

// i.e. 定义的时候用，不会被引用
struct FunctionDef {
    int entrance;  /* 入口四元式编号  */
    std::string identifier;
    bool returnVoid;
    bool declarationOnly = false; /* 只有定义，i.e. 外部函数 */
    std::vector<Argument> arguments;
};

struct Var {
    int32_t varID;
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
            int32_t value;     // for immediate & imCodeID
        };
    };

    Operator op;
    Oprand src1;    /* 不可能是中间代码编号 */
    Oprand src2;    /* 不可能是中间代码编号 */
    Oprand dest;    /* 不可能是立即数 */
    std::vector<int32_t> arguments;    /* call */
};

struct ImProgram {
    std::vector<ImCode>     imcodes;
    std::vector<GlobalVarDef>  globalVars;
    std::vector<FunctionDef>   functions;
    int startFunction; // 入口函数的函数编号
};

void codegen(const ImProgram& program, const std::string&, const std::string&);

/* 中间代码数据结构 END */


/* 工具函数 BEGIN */

std::string format(ImCode::Operator op);
std::string format(const ImCode::Oprand& oprand);
std::string format(const std::vector<int32_t>& vec);

/* 工具函数 END */


/* DRIVER BEGIN */

// 因为有各种正交，所以就不再分出来了
struct symbol_info {
    int scoop_depth;                        /* 字面意思 */
    std::string identifier = "";            /* 标志符号 */

    int32_t size;                          /* 大小。常数也要设置大小。以机器字为单位  */
    std::vector<int32_t> dims;             /* 维度。如果是常数，dims.empty()       */          
    std::vector<int32_t> init_value;        /* 是冗余的，初始化数值，如果是数组，则取 init_value[0]. */
    std::vector<std::shared_ptr<expr>> init_expr;

    bool is_const = false;                          
    bool is_temp = false;
    bool need_init = false;       

    // !is_const: 需要运行时辅助初始化
    bool is_static = false; // is_const 表达的是语义， is_static 表达的是进入 main 函数之前的事实            
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
    int32_t var_id;
    nonterm_integer(int32_t var_id): var_id(var_id) {}
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
    
    void backpatch(const std::vector<int>& ids, int value) {
        for(auto i: ids) imcodes()[i].dest.value = value;
    }

    void compile() { compile(syntax_tree); }
    std::shared_ptr<nonterm_info> compile(const shared_ptr<comp_unit_t>& comp_unit);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<comp_unit_item_t>& ptr);

    // 作用域管理
    int enter_scoop(){
        return ++current_depth;
    }

    int exit_scoop(){
        while(!symbols.empty() 
            && symbols.rbegin()->scoop_depth == current_depth) {
            symbols.pop_back();
        }
        return --current_depth;
    }

    // 符号管理

    // 不要调用 entry
    // 添加函数调用 add_var, 自动判断是否是global的函数，并自动添加到全局变量表和符号表中
    int32_t entry(const std::string& ident, const std::vector<int32_t>& dims, bool is_const_var, const std::vector<int32_t>& init_value);
    int32_t add_function(const std::string& ident, int32_t entrance, bool returnVoid, const std::vector<Argument>& arguments);
    int32_t query_function(const std::string& ident) ;
    int32_t add_var(const std::string& ident, const std::vector<int32_t>& dims, bool is_const, const std::vector<int32_t>& init_value) ;
    int32_t query_var(const std::string& ident);
    int32_t add_temp();

    // 类型转换
    std::shared_ptr<nonterm_boolean> to_nonterm_boolean(const shared_ptr<nonterm_info>& info);
    std::shared_ptr<nonterm_integer> to_nonterm_integer(const std::shared_ptr<nonterm_info>& info, std::shared_ptr<nonterm_integer> store_place = nullptr);


    // 中间代码生成
    void gen_imcode(ImCode::Operator op, 
                        const std::shared_ptr<nonterm_info>& src1,
                        const std::shared_ptr<nonterm_info>& src2,
                        int dest);
    void gen_imcode(ImCode::Operator op, 
                            const std::shared_ptr<nonterm_info>&    src1, 
                            const std::shared_ptr<nonterm_info>&    src2, 
                            const std::shared_ptr<nonterm_info>&    dest);
    ImCode::Oprand get_oprand(const std::shared_ptr<nonterm_info>& info);

    // 

    // 表达式解析
    std::shared_ptr<nonterm_info> compile(const shared_ptr<expr>& root, std::shared_ptr<nonterm_integer> store_place = nullptr);
    std::shared_ptr<nonterm_info> compile_offset(const ptr_list_of<expr>& exps, const std::vector<int32_t> dims);

    // 语句
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_t>& stmt);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_if_t>& stmt);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_return_t>& stmt);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_while_t>& stmt);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_assign_t>& stmt);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_block_t>& stmt);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_continue_t>& stmt);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_exp_t>& stmt);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<stmt_break_t>& stmt);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<block_t>& block, bool enter_new_scoop = true);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<block_item_t>& item);

    // 声明
    std::shared_ptr<nonterm_info> compile(const shared_ptr<decl_t>& decl);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<var_decl_t>& decl);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<var_def_t>& def);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<var_def_only_t>& def_only);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<var_def_init_t>& def_init);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<const_decl_t>& decl);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<const_def_t>& constdef);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<func_def_t>& funcdef, bool decl = true, bool define = true);
    std::shared_ptr<nonterm_info> compile(const shared_ptr<func_f_param_t>& param, int param_index);

    // 常量与变量初始化
    void flatten(shared_ptr<init_val_t> init_val, std::vector<std::shared_ptr<expr>>& vec);
    std::vector<std::shared_ptr<expr>> flatten(shared_ptr<init_val_t> init_val);

    void flatten(shared_ptr<const_init_val_t> init_val, std::vector<std::shared_ptr<expr>>& vec);
    std::vector<std::shared_ptr<expr>> flatten(shared_ptr<const_init_val_t> init_val);

    void recursive_evaluate(shared_ptr<const_init_val_t> init_val, std::vector<int32_t> dims, 
            int layer, int layer_size, int offset, std::vector<int32_t>& buffer);
    void recursive_compile(shared_ptr<init_val_t> init_val, std::vector<int32_t> dims, 
            int layer, int layer_size, int offset, std::vector<std::shared_ptr<expr>>& buffer);


    // 静态分析
    std::pair<int32_t, std::vector<int32_t>> static_array_dims(const ptr_list_of<expr>& dimsdef);
    std::pair<bool, int32_t> static_eval_offset(const ptr_list_of<expr> indices, 
                                                const std::vector<int32_t>& dims);
    std::pair<bool, int32_t> static_eval(shared_ptr<expr> root, bool for_init = false);
};

#endif