%require "3.2"
%language "c++"

%defines
%define api.token.constructor
%define api.value.type variant

%param { driver& drv }

%code requires {
    class driver;
    #include "constructs.hh"
}

%code {
    #include <iostream>
    #include "driver.hh"
    
    void yy::parser::error (const std::string& m) {
        std::cerr << m << '\n';
    }
}

%%

%token YYEOF   0  "end of file";
%token <long long>   INT_CONST  "integer";
%token <std::string> IDENT      "identifier";

%token
    VOID            "void"              
    INT             "int"               
    CONST           "const"             
    IF              "if"                
    WHILE           "while"             
    BREAK           "break"             
    CONTINUE        "continue"          
    RETURN          "return"            
    GE              ">="                
    LE              "<="                
    EQ              "=="                
    NE              "!="                
    AND             "&&"                
    OR              "||"                
    GT              ">"                 
    LT              "<"                 
    ASSIGN          "="                 
    NOT             "!"                 
    ADD             "+"                 
    SUB             "-"                 
    MUL             "*"                 
    DIV             "/"                 
    MOD             "%"                 
    COMMA           ","                 
    SEMI            ";"                 
    LEFT_PAREN      "("                 
    RIGHT_PAREN     ")"                 
    LEFT_BRACKET    "["                 
    RIGHT_BRACKET   "]"                 
    LEFT_BRACE      "{"
    RIGHT_BRACE     "}"                 
;

%nterm <std::shared_ptr<comp_unit_t>> start_symbol;
start_symbol: comp_unit {
    drv.compile($1);
};

/* >=1 个 comp_unit_item */
%nterm <std::shared_ptr<comp_unit_t>> comp_unit;
comp_unit:
    comp_unit_item           { $$ = std::make_shared<comp_unit_t>(); $$->children.push_back($1);          }
  | comp_unit comp_unit_item { $$ = $1; $$->children.push_back($2); }
;

%nterm <std::shared_ptr<comp_unit_item_t>>  comp_unit_item;
comp_unit_item: 
    func_def    { $$ = std::make_shared<comp_unit_item_func_def_t>($1); } 
  | decl        { $$ = std::make_shared<comp_unit_item_decl_t>($1);     }
;

%nterm <std::shared_ptr<decl_t>> decl;
decl: 
    const_decl_stmt { $$ = std::make_shared<decl_const_decl_t>($1); }
  | var_decl   { $$ = std::make_shared<decl_var_decl_t>($1);   }
;


%nterm <std::shared_ptr<const_decl_t>> const_decl;
const_decl:
    "const" b_type const_def { $$ = std::make_shared<const_decl_t>(); $$->b_type = $2; $$->const_defs.push_back($3); }
  | const_decl "," const_def { $$ = $1; $$->const_defs.push_back($3);}

%nterm <std::shared_ptr<const_decl_t>> const_decl_stmt;
const_decl_stmt: const_decl ";" { $$ = $1; } ;

%nterm <std::shared_ptr<b_type_t>> b_type;
b_type:
    "int" { $$ = std::make_shared<b_type_t>(b_type_t::INT); }
  | "void" { $$ = std::make_shared<b_type_t>(b_type_t::VOID); }
;

%nterm <std::shared_ptr<const_def_t>> const_def;
const_def: ident array_dims "=" const_init_val {
    $$ = std::make_shared<const_def_t>($1, $2, $4);
};

%nterm <ptr_list_of<const_exp_t>> array_dims;
array_dims:
    %empty {}
  | array_dims "[" const_exp "]" { $$ = $1; $$.push_back($3); }
;

%nterm <std::shared_ptr<const_init_val_t>> const_init_val;
const_init_val:
    const_exp { $$ = std::make_shared<const_init_val_scalar_t>($1); }
  | "{" const_array_elements "}" { $$ = std::make_shared<const_init_val_array_t>($2); }
;

%nterm <ptr_list_of<const_init_val_t>> const_array_elements;
const_array_elements: 
    %empty {}
  | const_array_elements "," const_init_val { $$ = $1; $$.push_back($3); }
;

%nterm <std::shared_ptr<var_decl_t>> var_decl;
var_decl: 
    b_type var_def_list ";" {
        $$ = std::make_shared<var_decl_t>($1, $2);
    }
;

%nterm <ptr_list_of<var_def_t>> var_def_list; 
var_def_list:
    var_def { $$.push_back($1); }
  | var_def_list "," var_def { $$ = $1; $$.push_back($3); }
;

%nterm <std::shared_ptr<var_def_t>> var_def;
var_def: 
    ident array_dims                { $$ = std::make_shared<var_def_only_t>($1, $2); }
  | ident array_dims "=" init_val   { $$ = std::make_shared<var_def_init_t>($1, $2, $4); }
;

%nterm <std::shared_ptr<init_val_t>> init_val;
init_val:
    exp { $$ = std::make_shared<init_val_scalar_t>($1); }
  | "{" init_array_elements "}" {{ $$ = std::make_shared<init_val_array_t>($2); }}

%nterm <ptr_list_of<init_val_t>> init_array_elements;
init_array_elements: 
    %empty {}
  | init_array_elements init_val { $$ = $1; $$.push_back($2); }
;

%nterm <std::shared_ptr<func_def_t>> func_def;
func_def: b_type ident "(" func_f_params ")" block {
    $$ = std::make_shared<func_def_t>();
    $$->func_type = $1;
    $$->ident = $2;
    $$->params = $4;
    $$->block = $6;
};

%nterm <std::shared_ptr<func_f_params_t>> func_f_params;
func_f_params:
    %empty { $$ = std::make_shared<func_f_params_t>(); }
  | real_func_f_params { $$ = $1; }
;

%nterm <std::shared_ptr<func_f_params_t>> real_func_f_params;
real_func_f_params:
    real_func_f_params "," func_f_param { $$ = $1; $$->params.push_back($3); }
  | func_f_param { $$ = std::make_shared<func_f_params_t>(); $$->params.push_back($1); }
;

%nterm <std::shared_ptr<func_f_param_t>> func_f_param;
func_f_param: b_type ident array_dims_func_param {
    $$ = std::make_shared<func_f_param_t>();
    $$->b_type = $1;
    $$->ident = $2;
    $$->array_dims = $3;
};

%nterm <ptr_list_of<exp_t>> array_dims_func_param;
array_dims_func_param:
    %empty {}
  | array_dims_func_param_real { $$ = $1; }
;

%nterm <ptr_list_of<exp_t>> array_dims_func_param_real;
array_dims_func_param_real:
    "[" "]" { $$.push_back(nullptr); }
  | array_dims_func_param_real "[" exp "]" { $$ = $1; $$.push_back($3); }
;

%nterm <std::shared_ptr<block_t>> block;
block: "{" block_elements "}" { $$ = std::make_shared<block_t>($2); };

%nterm <ptr_list_of<block_item_t>> block_elements;
block_elements:
    %empty {}
  | block_elements block_item { $$ = $1; $$.push_back($2); }
;

%nterm <std::shared_ptr<block_item_t>> block_item;
block_item:
    decl { $$ = std::make_shared<block_item_decl_t>($1); }
  | stmt { $$ = std::make_shared<block_item_stmt_t>($1); }

%nterm <std::shared_ptr<ident_t>> ident;
ident: IDENT { $$ = std::make_shared<ident_t>($1); };

%nterm <std::shared_ptr<stmt_t>> stmt;
stmt: 
    l_val "=" exp ";"                   { $$ = std::make_shared<stmt_assign_t>($1, $3); }
  | exp ";"                             { $$ = std::make_shared<stmt_exp_t>($1);        }
  | ";"                                 { $$ = std::shared_ptr<stmt_exp_t>(nullptr);    }
  | block                               { $$ = std::make_shared<stmt_block_t>($1);      }
  | "if" "(" cond ")" stmt              { $$ = std::make_shared<stmt_if_t>($3, $5, nullptr); }
                /* TODO：没有做就近匹配 */
  | "if" "(" cond ")" stmt "else" stmt  { $$ = std::make_shared<stmt_if_t>($3, $5, $7); }       
  | "while" "(" cond ")" stmt           { $$ = std::make_shared<stmt_while_t>($3, $5); }
  | "break" ";"                         { $$ = std::make_shared<stmt_break_t>();       }
  | "continue" ";"                      { $$ = std::make_shared<stmt_continue_t>();    }
  | "return" ";"                        { $$ = std::make_shared<stmt_return_t>(nullptr); }
  | "return" exp ";"                    { $$ = std::make_shared<stmt_return_t>($2);    }
;


%nterm <std::shared_ptr<exp_t>> exp;
exp: add_exp { $$ = std::make_shared<exp_add_t>($1); }; 

%nterm <std::shared_ptr<cond_t>> cond;
cond: l_or_exp { $$ = std::make_shared<cond_l_or_t>($1); };

%nterm <std::shared_ptr<l_val_t>> l_val;
l_val: 
    ident array_indices { $$ = std::make_shared<l_val_t>($1, $2); }
  | ident { $$=std::make_shared<l_val_t>($1, ptr_list_of<exp_t>()); }
;
    
%nterm <ptr_list_of<exp_t>> array_indices;
array_indices:
    "[" exp "]"  {{ $$.push_back($2); }}
  | array_indices "[" exp "]"  { $$ = $1; $$.push_back($3); }
;

%nterm <std::shared_ptr<primary_exp_t>> primary_exp;
primary_exp:
    "(" exp ")"     { $$ = std::make_shared<primary_exp_exp_t>($2);     }
  | l_val           { $$ = std::make_shared<primary_exp_l_val_t>($1);   }
  | number          { $$ = std::make_shared<primary_exp_number_t>($1);  }
;

%nterm <std::shared_ptr<number_t>> number;
number: INT_CONST { $$ = std::make_shared<number_t>(std::make_shared<int_const_t>($1)); } ;

%nterm <std::shared_ptr<unary_exp_t>> unary_exp;
unary_exp:
    primary_exp   { $$ = std::make_shared<unary_exp_primary_exp_t>($1); }
  | ident "(" func_r_params ")" { $$ = std::make_shared<unary_exp_func_call_t>($1, $3); }
  | "+" unary_exp   { $$ = std::make_shared<unary_exp_applied_t>(std::make_shared<operator_t>(operator_t::POSITIVE), $2) ;}
  | "-" unary_exp   { $$ = std::make_shared<unary_exp_applied_t>(std::make_shared<operator_t>(operator_t::NEGATIVE), $2) ;}
  | "!" unary_exp   { $$ = std::make_shared<unary_exp_applied_t>(std::make_shared<operator_t>(operator_t::LOGICAL_NOT), $2) ;}
;

/* 不同于文档中的定义，这里的 func_r_params 可以为空 */
%nterm <std::shared_ptr<func_r_params_t>> func_r_params;
func_r_params:
    %empty      { $$ = std::make_shared<func_r_params_t>(); }
  | func_r_params_elements { $$ = std::make_shared<func_r_params_t>($1); }
;

%nterm <ptr_list_of<exp_t>> func_r_params_elements;
func_r_params_elements:
    exp                              { $$.push_back($1);            }
  | func_r_params_elements "," exp   { $$ = $1; $$.push_back($3);   }
;

%nterm <std::shared_ptr<mul_exp_t>> mul_exp;
mul_exp: 
    unary_exp  { $$ = std::make_shared<mul_exp_unary_t>($1); }
  | mul_exp "*" unary_exp  { $$ = std::make_shared<mul_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::MULTIPLY), $3); }
  | mul_exp "/" unary_exp  { $$ = std::make_shared<mul_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::DIVIDE), $3); }
  | mul_exp "%" unary_exp  { $$ = std::make_shared<mul_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::MODULE), $3); }
;

%nterm <std::shared_ptr<add_exp_t>> add_exp;
add_exp: 
    mul_exp  { $$ = std::make_shared<add_exp_mul_t>($1); }
  | add_exp "+" mul_exp  { $$ = std::make_shared<add_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::PLUS), $3); }
  | add_exp "-" mul_exp  { $$ = std::make_shared<add_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::MINUS), $3); }
;

%nterm <std::shared_ptr<rel_exp_t>> rel_exp;
rel_exp: 
    add_exp  { $$ = std::make_shared<rel_exp_add_t>($1); }
  | rel_exp "<"  add_exp  { $$ = std::make_shared<rel_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::LESS), $3); }
  | rel_exp ">"  add_exp  { $$ = std::make_shared<rel_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::GREATER), $3); }
  | rel_exp "<=" add_exp  { $$ = std::make_shared<rel_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::LESS_EQUAL), $3); }
  | rel_exp ">=" add_exp  { $$ = std::make_shared<rel_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::GREATER_EQUAL), $3); }
;

%nterm <std::shared_ptr<eq_exp_t>> eq_exp;
eq_exp: 
    rel_exp  { $$ = std::make_shared<eq_exp_rel_t>($1); }
  | eq_exp "=="  rel_exp  { $$ = std::make_shared<eq_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::EQUAL), $3); }
  | eq_exp "!=" rel_exp  { $$ = std::make_shared<eq_exp_applied_t>($1, std::make_shared<operator_t>(operator_t::NOT_EQUAL), $3); }
;

%nterm <std::shared_ptr<l_and_exp_t>> l_and_exp;
l_and_exp: 
    eq_exp  { $$ = std::make_shared<l_and_exp_eq_t>($1); }
  | l_and_exp "&&"  eq_exp  { $$ = std::make_shared<l_and_exp_applied_t>($1, $3); }
;

%nterm <std::shared_ptr<l_or_exp_t>> l_or_exp;
l_or_exp: 
    l_and_exp  { $$ = std::make_shared<l_or_exp_and_t>($1); }
  | l_or_exp "||"  l_and_exp  { $$ = std::make_shared<l_or_exp_applied_t>($1, $3); }
;

%nterm <std::shared_ptr<const_exp_t>> const_exp;
const_exp: add_exp { $$ = std::make_shared<const_exp_add_t>($1); }; 


%%

