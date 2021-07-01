#ifndef HWC_SYNTAX_TREE_H
#define HWC_SYNTAX_TREE_H

#include <list>
#include <string>
#include <memory>

struct construct{};

/**
 * 该部分数据结构是用于构造语法“树”的。
 * 
 * 该部分内容来自于 “SysY 语言的文法”，并按如下约定做修改
 * 0. 为identifier进行一层嵌套；其他都分装为同一个类型；
 * 1. 将类似于 A -> Ab | c 的结构表示为列表
 * 2. 非终结符号 NonTerminal 的结构体名称为 non_terminal_t
 * 3. 所有类的最终父类是 construct, 
 *    取自术语 language construct（语言构造/语言元素）
 * 4. 如果有一个产生式 A -> alpha | beta | ... 
 *    那么有结构体 a_x_t, a_y_t, 他们都继承自 a_t。
 *    x, y 是适当的名字
 *    在构造的时候，无需构造 a_t. 
 * 5. 如果有一个产生式是 A -> alpha(beta|gamma) 的格式，则拆开。
 *     给 beta|gamma 命名以适当的名字。之后参照规则 4 处理
 * 6. 例外情况会给出注释。
 * 
 * 关于 shared_ptr：
 * 经过某些优化的语法树可能呈现图结构，但该图应当是DAG。
 * 基于语法“树”中不会出现环的假设，这里使用 shared_ptr 智能指针
 * 
 **/

struct construct;

struct comp_unit_t;
struct comp_unit_item_t; // Decl | FuncDef
struct comp_unit_item_decl_t; 
struct comp_unit_item_func_def_t; 

struct decl_t;
struct decl_const_decl_t;
struct decl_var_decl_t;

struct const_decl_t;

struct const_def_t;
struct const_init_val_t;
struct const_init_val_scalar_t;
struct const_init_val_array_t;

struct var_decl_t;
struct var_def_t;
struct var_def_only_t;
struct var_def_init_t;

struct init_val_t;
struct init_val_scalar_t;
struct init_val_array_t;

struct func_def_t;

struct func_f_params_t;
struct func_f_param_t;

struct block_t;
struct block_item_t;
struct block_item_decl_t;
struct block_item_stmt_t;

struct stmt_t;
struct stmt_assign_t;
struct stmt_exp_t;
struct stmt_block_t;
struct stmt_if_t;
struct stmt_while_t;
struct stmt_break_t;
struct stmt_continue_t;
struct stmt_return_t;

struct exp_t;
struct exp_add_t;

struct cond_t;
struct cond_l_or_t;

struct l_val_t;

struct primary_exp_t;
struct primary_exp_exp_t;
struct primary_exp_l_val_t;
struct primary_exp_number_t;

struct number_t;

struct unary_exp_t;
struct unary_exp_primary_exp_t;
struct unary_exp_func_call_t;
struct unary_exp_applied_t; // UnaryOp UnaryExp

struct func_r_params_t;

struct mul_exp_t;
struct mul_exp_unary_t;
struct mul_exp_applied_t; 

struct add_exp_t;
struct add_exp_mul_t;
struct add_exp_applied_t; 

struct rel_exp_t;
struct rel_exp_add_t;
struct rel_exp_applied_t; 

struct eq_exp_t;
struct eq_exp_rel_t;
struct eq_exp_applied_t; 

struct l_and_exp_t;
struct l_and_exp_eq_t;
struct l_and_exp_applied_t; 

struct l_or_exp_t;
struct l_or_exp_and_t;
struct l_or_exp_applied_t; 

// 这里遵照了语言规范中的定义
// const 与否要在语义分析中分析，语法分析不能保证其 const 性
// 当然也可以给 const 类型定义特殊的一套非终结符号
// 把这个检查留到语义分析部分，可能也可以更容易得提供准确的报错信息。
struct const_exp_t;
struct const_exp_add_t;

struct construct{};
struct terminal_wrapper: public construct{};

// 下面是终结符号的包装
struct b_type_t: public terminal_wrapper {
    enum Type {INT};
    Type type;
};

struct func_type_t: public terminal_wrapper {
    enum Type {VOID, INT};
    Type type;
};

struct ident_t: public terminal_wrapper {
    std::string name;
};

struct int_const_t: public terminal_wrapper {
    long long value;
}

// ; , { } ( ) 等和语义无关的符号未列出
struct operator_t: public terminal_wrapper {
    enum Type { 
        POSITIVE,
        NEGATIVE,
        
        MULTIPLY,
        DIVIDE,
        MODULE,

        GREATER,
        LESS,
        GREATER_EQUAL,
        LESS_EQUAL,
        EQUAL,
        NOT_EQUAL,

        LOGICAL_NOT,
        LOGICAL_AND,
        LOGICAL_OR,
    };

    Type type;
};

// 非终结符号类型的定义

template <typename T>
using ptr_list_of = std::list<std::shared_ptr<T>>;

struct comp_unit_t: public construct {
    ptr_list_of<comp_unit_item_t> children;
};

struct comp_unit_item_t: public construct {}; // Decl | FuncDef
struct comp_unit_item_decl_t: public comp_unit_item_t {
    std::shared_ptr<decl_t> decl;
}; 
struct comp_unit_item_func_def_t: public comp_unit_item_t {
    std::shared_ptr<func_def_t> func_def;
}; 

struct decl_t: public construct {};
struct decl_const_decl_t: public decl_t {
    std::shared_ptr<const_decl_t> const_decl;
};
struct decl_var_decl_t: public decl_t {
    std::shared_ptr<var_decl_t> var_decl;
};

struct const_decl_t: public construct {
    std::shared_ptr<b_type_t> b_type;
    ptr_list_of<const_def_t> const_defs;
};

struct const_def_t: public construct {
    std::shared_ptr<ident_t> ident;
    ptr_list_of<const_exp_t> array_dims;
    std::shared_ptr<const_init_val_t> const_init_val;    
};

struct const_init_val_t: public construct {};
struct const_init_val_scalar_t: public const_init_val_t {
    std::shared_ptr<const_exp_t> const_exp;
};
struct const_init_val_array_t: public const_init_val_t {
    ptr_list_of<const_init_val_t> array_elements;
};

struct var_decl_t: public construct {
    std::shared_ptr<b_type_t> b_type;
    ptr_list_of<var_def_t> var_defs;
};

struct var_def_t: public construct {};
struct var_def_only_t: public var_def_t {
    std::shared_ptr<ident_t> ident_t;
    ptr_list_of<const_exp_t> array_indices;
};
struct var_def_init_t: public var_def_t {
    std::shared_ptr<ident_t> ident;
    ptr_list_of<const_exp_t> array_indices;
    std::shared_ptr<init_val_t> init_val;
};

struct init_val_t: public construct {};
struct init_val_scalar_t: public init_val_t {
    std::shared_ptr<exp_t> exp;
};
struct init_val_array_t: public init_val_t {
    ptr_list_of<init_val_t> array_elements; 
}; 



struct func_def_t: public construct {
    std::shared_ptr<func_type_t> func_type;
    std::shared_ptr<ident_t> ident;
    std::shared_ptr<func_f_params_t> params;
    std::shared_ptr<block_t> block; 
};

struct func_f_params_t: public construct {
    ptr_list_of<func_f_param_t> params;
};
struct func_f_param_t: public construct {
    std::shared_ptr<b_type_t> b_type;
    std::shared_ptr<ident_t> ident;
    // 做高维的留空，填 -1
    ptr_list_of<exp_t> array_dims;
};

struct block_t: public construct {
    ptr_list_of<block_item_t> children;
};
struct block_item_t: public construct {};
struct block_item_decl_t: public block_item_t {
    std::shared_ptr<decl_t> decl;
};
struct block_item_stmt_t: public block_item_t {
    std::shared_ptr<stmt_t> stmt;
};

struct stmt_t: public construct {};
struct stmt_assign_t: public stmt_t {
    std::shared_ptr<l_val_t> l_val;
    std::shared_ptr<exp_t> exp;
};
struct stmt_exp_t: public stmt_t {
    std::shared_ptr<exp_t> exp;
};
struct stmt_block_t: public stmt_t {
    std::shared_ptr<block_t> block;
};
struct stmt_if_t: public stmt_t {
    std::shared_ptr<cond_t> cond;
    std::shared_ptr<stmt_t> stmt_if_true;
    std::shared_ptr<stmt_t> stmt_if_false;
};
struct stmt_while_t: public stmt_t {
    std::shared_ptr<cond_t> cond;
    std::shared_ptr<stmt_t> stmt;
};
struct stmt_break_t: public stmt_t {};
struct stmt_continue_t: public stmt_t {};
struct stmt_return_t: public stmt_t {
    std::shared_ptr<exp_t> exp;
};

struct exp_t: public construct {};
struct exp_add_t: public exp_t {
    std::shared_ptr<add_exp_t> add_exp;
};

struct cond_t: public construct {};
struct cond_l_or_t: public cond_t {
    std::shared_ptr<l_or_exp_t> l_or_exp;
};

struct lval_t: public construct {
    std::shared_ptr<ident_t> ident;
    ptr_list_of<exp_t> exps;
};

struct primary_exp_t: public construct {};
struct primary_exp_exp_t: public primary_exp_t {
    std::shared_ptr<exp_t> exp;
};
struct primary_exp_l_val_t: public primary_exp_t {
    std::shared_ptr<l_val_t> l_val;
};
struct primary_exp_number_t: public primary_exp_t {
    std::shared_ptr<number_t> number;
};

struct number_t: public construct {
    std::shared_ptr<int_const_t> int_const;
};

struct unary_exp_t: public construct{};
struct unary_exp_primary_exp_t: public unary_exp_t {
    std::shared_ptr<primary_exp_t> primary_exp;
};
struct unary_exp_func_call_t: public unary_exp_t {
    std::shared_ptr<ident_t> ident;
    std::shared_ptr<func_r_params_t> params;
};
struct unary_exp_applied_t: public unary_exp_t {  // UnaryOp UnaryExp
    std::shared_ptr<operator_t> unary_op;
    std::shared_ptr<unary_exp_t> unary_exp;
};

struct func_r_params_t: public construct {
    ptr_list_of<exp_t> exps;
};

struct mul_exp_t: public construct {};
struct mul_exp_unary_t: public mul_exp_t {
    std::shared_ptr<unary_exp_t> unary_exp;
};
struct mul_exp_applied_t: public mul_exp_t {
    std::shared_ptr<mul_exp_t> mul_exp;
    std::shared_ptr<unary_exp_t> unary_exp;
}; 

struct add_exp_t: public construct {};
struct add_exp_mul_t: public add_exp_t {
    std::shared_ptr<mul_exp_t> mul_exp;
};
struct add_exp_applied_t: public add_exp_t {
    std::shared_ptr<add_exp_t> add_exp;
    std::shared_ptr<mul_exp_t> mul_exp;
}; 

struct rel_exp_t: public construct {};
struct rel_exp_add_t: public rel_exp_t {
    std::shared_ptr<add_exp_t> add_exp;
};
struct rel_exp_applied_t: public rel_exp_t {
    std::shared_ptr<rel_exp_t> rel_exp;
    std::shared_ptr<add_exp_t> add_exp;
}; 

struct eq_exp_t: public construct {};
struct eq_exp_rel_t: public eq_exp_t {
    std::shared_ptr<rel_exp_t> rel_exp;
};
struct eq_exp_applied_t: public eq_exp_t {
    std::shared_ptr<eq_exp_t> eq_exp;
    std::shared_ptr<rel_exp_t> rel_exp;
}; 

struct l_and_exp_t: public construct {};
struct l_and_exp_eq_t: public l_and_exp_t {
    std::shared_ptr<eq_exp_t> eq_exp;
};
struct l_and_exp_applied_t: public l_and_exp_t {
    std::shared_ptr<l_and_exp_t> l_and_exp;
    std::shared_ptr<eq_exp_t> eq_exp;
}; 

struct l_or_exp_t: public construct {};
struct l_or_exp_and_t: public l_or_exp_t {
    std::shared_ptr<l_and_exp_t> l_and_exp;
};
struct l_or_exp_applied_t: public l_or_exp_t {
    std::shared_ptr<l_or_exp_t> l_or_exp;
    std::shared_ptr<l_and_exp_t> l_and_exp;
}; 

// 这里遵照了语言规范中的定义
// const 与否要在语义分析中分析，语法分析不能保证其 const 性
// 当然也可以给 const 类型定义特殊的一套非终结符号
// 把这个检查留到语义分析部分，可能也可以更容易得提供准确的报错信息。
struct const_exp_t: public construct {};
struct const_exp_add_t: public const_exp_t {
    std::shared_ptr<add_exp_t> add_exp;
};



#endif