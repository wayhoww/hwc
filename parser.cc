// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 15 "parser.yy"

    #include <iostream>
    #include "driver.hh"
    
    void yy::parser::error (const std::string& m) {
        std::cerr << m << '\n';
    }

#line 55 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 128 "parser.cc"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_INT_CONST: // "integer"
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<block_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
      case symbol_kind::S_real_const_array_elements: // real_const_array_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dims: // array_dims
      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<expr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
      case symbol_kind::S_real_init_array_elements: // real_init_array_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.YY_MOVE_OR_COPY< ptr_list_of<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_b_type: // b_type
        value.YY_MOVE_OR_COPY< std::shared_ptr<b_type_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_item: // block_item
        value.YY_MOVE_OR_COPY< std::shared_ptr<block_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
        value.YY_MOVE_OR_COPY< std::shared_ptr<block_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_comp_unit_item: // comp_unit_item
        value.YY_MOVE_OR_COPY< std::shared_ptr<comp_unit_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_start_symbol: // start_symbol
      case symbol_kind::S_comp_unit: // comp_unit
        value.YY_MOVE_OR_COPY< std::shared_ptr<comp_unit_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.YY_MOVE_OR_COPY< std::shared_ptr<const_decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_def: // const_def
        value.YY_MOVE_OR_COPY< std::shared_ptr<const_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.YY_MOVE_OR_COPY< std::shared_ptr<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl: // decl
        value.YY_MOVE_OR_COPY< std::shared_ptr<decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_primary_exp: // primary_exp
      case symbol_kind::S_unary_exp: // unary_exp
      case symbol_kind::S_mul_exp: // mul_exp
      case symbol_kind::S_add_exp: // add_exp
      case symbol_kind::S_rel_exp: // rel_exp
      case symbol_kind::S_eq_exp: // eq_exp
      case symbol_kind::S_l_and_exp: // l_and_exp
      case symbol_kind::S_l_or_exp: // l_or_exp
      case symbol_kind::S_const_exp: // const_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<expr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_f_param_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_f_params: // func_f_params
      case symbol_kind::S_real_func_f_params: // real_func_f_params
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_f_params_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_r_params_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_val: // init_val
        value.YY_MOVE_OR_COPY< std::shared_ptr<init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_l_val: // l_val
        value.YY_MOVE_OR_COPY< std::shared_ptr<l_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.YY_MOVE_OR_COPY< std::shared_ptr<number_literal_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.YY_MOVE_OR_COPY< std::shared_ptr<stmt_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.YY_MOVE_OR_COPY< std::shared_ptr<var_decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def: // var_def
        value.YY_MOVE_OR_COPY< std::shared_ptr<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // "identifier"
      case symbol_kind::S_ident: // ident
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_INT_CONST: // "integer"
        value.move< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.move< ptr_list_of<block_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
      case symbol_kind::S_real_const_array_elements: // real_const_array_elements
        value.move< ptr_list_of<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dims: // array_dims
      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.move< ptr_list_of<expr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
      case symbol_kind::S_real_init_array_elements: // real_init_array_elements
        value.move< ptr_list_of<init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.move< ptr_list_of<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_b_type: // b_type
        value.move< std::shared_ptr<b_type_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_item: // block_item
        value.move< std::shared_ptr<block_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
        value.move< std::shared_ptr<block_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_comp_unit_item: // comp_unit_item
        value.move< std::shared_ptr<comp_unit_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_start_symbol: // start_symbol
      case symbol_kind::S_comp_unit: // comp_unit
        value.move< std::shared_ptr<comp_unit_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.move< std::shared_ptr<const_decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_def: // const_def
        value.move< std::shared_ptr<const_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.move< std::shared_ptr<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl: // decl
        value.move< std::shared_ptr<decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_primary_exp: // primary_exp
      case symbol_kind::S_unary_exp: // unary_exp
      case symbol_kind::S_mul_exp: // mul_exp
      case symbol_kind::S_add_exp: // add_exp
      case symbol_kind::S_rel_exp: // rel_exp
      case symbol_kind::S_eq_exp: // eq_exp
      case symbol_kind::S_l_and_exp: // l_and_exp
      case symbol_kind::S_l_or_exp: // l_or_exp
      case symbol_kind::S_const_exp: // const_exp
        value.move< std::shared_ptr<expr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.move< std::shared_ptr<func_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.move< std::shared_ptr<func_f_param_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_f_params: // func_f_params
      case symbol_kind::S_real_func_f_params: // real_func_f_params
        value.move< std::shared_ptr<func_f_params_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.move< std::shared_ptr<func_r_params_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_val: // init_val
        value.move< std::shared_ptr<init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_l_val: // l_val
        value.move< std::shared_ptr<l_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.move< std::shared_ptr<number_literal_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< std::shared_ptr<stmt_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< std::shared_ptr<var_decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def: // var_def
        value.move< std::shared_ptr<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // "identifier"
      case symbol_kind::S_ident: // ident
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_INT_CONST: // "integer"
        value.copy< long long > (that.value);
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.copy< ptr_list_of<block_item_t> > (that.value);
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
      case symbol_kind::S_real_const_array_elements: // real_const_array_elements
        value.copy< ptr_list_of<const_init_val_t> > (that.value);
        break;

      case symbol_kind::S_array_dims: // array_dims
      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.copy< ptr_list_of<expr> > (that.value);
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
      case symbol_kind::S_real_init_array_elements: // real_init_array_elements
        value.copy< ptr_list_of<init_val_t> > (that.value);
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.copy< ptr_list_of<var_def_t> > (that.value);
        break;

      case symbol_kind::S_b_type: // b_type
        value.copy< std::shared_ptr<b_type_t> > (that.value);
        break;

      case symbol_kind::S_block_item: // block_item
        value.copy< std::shared_ptr<block_item_t> > (that.value);
        break;

      case symbol_kind::S_block: // block
        value.copy< std::shared_ptr<block_t> > (that.value);
        break;

      case symbol_kind::S_comp_unit_item: // comp_unit_item
        value.copy< std::shared_ptr<comp_unit_item_t> > (that.value);
        break;

      case symbol_kind::S_start_symbol: // start_symbol
      case symbol_kind::S_comp_unit: // comp_unit
        value.copy< std::shared_ptr<comp_unit_t> > (that.value);
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.copy< std::shared_ptr<const_decl_t> > (that.value);
        break;

      case symbol_kind::S_const_def: // const_def
        value.copy< std::shared_ptr<const_def_t> > (that.value);
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.copy< std::shared_ptr<const_init_val_t> > (that.value);
        break;

      case symbol_kind::S_decl: // decl
        value.copy< std::shared_ptr<decl_t> > (that.value);
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_primary_exp: // primary_exp
      case symbol_kind::S_unary_exp: // unary_exp
      case symbol_kind::S_mul_exp: // mul_exp
      case symbol_kind::S_add_exp: // add_exp
      case symbol_kind::S_rel_exp: // rel_exp
      case symbol_kind::S_eq_exp: // eq_exp
      case symbol_kind::S_l_and_exp: // l_and_exp
      case symbol_kind::S_l_or_exp: // l_or_exp
      case symbol_kind::S_const_exp: // const_exp
        value.copy< std::shared_ptr<expr> > (that.value);
        break;

      case symbol_kind::S_func_def: // func_def
        value.copy< std::shared_ptr<func_def_t> > (that.value);
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.copy< std::shared_ptr<func_f_param_t> > (that.value);
        break;

      case symbol_kind::S_func_f_params: // func_f_params
      case symbol_kind::S_real_func_f_params: // real_func_f_params
        value.copy< std::shared_ptr<func_f_params_t> > (that.value);
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.copy< std::shared_ptr<func_r_params_t> > (that.value);
        break;

      case symbol_kind::S_init_val: // init_val
        value.copy< std::shared_ptr<init_val_t> > (that.value);
        break;

      case symbol_kind::S_l_val: // l_val
        value.copy< std::shared_ptr<l_val_t> > (that.value);
        break;

      case symbol_kind::S_number: // number
        value.copy< std::shared_ptr<number_literal_t> > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< std::shared_ptr<stmt_t> > (that.value);
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.copy< std::shared_ptr<var_decl_t> > (that.value);
        break;

      case symbol_kind::S_var_def: // var_def
        value.copy< std::shared_ptr<var_def_t> > (that.value);
        break;

      case symbol_kind::S_IDENT: // "identifier"
      case symbol_kind::S_ident: // ident
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_INT_CONST: // "integer"
        value.move< long long > (that.value);
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.move< ptr_list_of<block_item_t> > (that.value);
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
      case symbol_kind::S_real_const_array_elements: // real_const_array_elements
        value.move< ptr_list_of<const_init_val_t> > (that.value);
        break;

      case symbol_kind::S_array_dims: // array_dims
      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.move< ptr_list_of<expr> > (that.value);
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
      case symbol_kind::S_real_init_array_elements: // real_init_array_elements
        value.move< ptr_list_of<init_val_t> > (that.value);
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.move< ptr_list_of<var_def_t> > (that.value);
        break;

      case symbol_kind::S_b_type: // b_type
        value.move< std::shared_ptr<b_type_t> > (that.value);
        break;

      case symbol_kind::S_block_item: // block_item
        value.move< std::shared_ptr<block_item_t> > (that.value);
        break;

      case symbol_kind::S_block: // block
        value.move< std::shared_ptr<block_t> > (that.value);
        break;

      case symbol_kind::S_comp_unit_item: // comp_unit_item
        value.move< std::shared_ptr<comp_unit_item_t> > (that.value);
        break;

      case symbol_kind::S_start_symbol: // start_symbol
      case symbol_kind::S_comp_unit: // comp_unit
        value.move< std::shared_ptr<comp_unit_t> > (that.value);
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.move< std::shared_ptr<const_decl_t> > (that.value);
        break;

      case symbol_kind::S_const_def: // const_def
        value.move< std::shared_ptr<const_def_t> > (that.value);
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.move< std::shared_ptr<const_init_val_t> > (that.value);
        break;

      case symbol_kind::S_decl: // decl
        value.move< std::shared_ptr<decl_t> > (that.value);
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_primary_exp: // primary_exp
      case symbol_kind::S_unary_exp: // unary_exp
      case symbol_kind::S_mul_exp: // mul_exp
      case symbol_kind::S_add_exp: // add_exp
      case symbol_kind::S_rel_exp: // rel_exp
      case symbol_kind::S_eq_exp: // eq_exp
      case symbol_kind::S_l_and_exp: // l_and_exp
      case symbol_kind::S_l_or_exp: // l_or_exp
      case symbol_kind::S_const_exp: // const_exp
        value.move< std::shared_ptr<expr> > (that.value);
        break;

      case symbol_kind::S_func_def: // func_def
        value.move< std::shared_ptr<func_def_t> > (that.value);
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.move< std::shared_ptr<func_f_param_t> > (that.value);
        break;

      case symbol_kind::S_func_f_params: // func_f_params
      case symbol_kind::S_real_func_f_params: // real_func_f_params
        value.move< std::shared_ptr<func_f_params_t> > (that.value);
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.move< std::shared_ptr<func_r_params_t> > (that.value);
        break;

      case symbol_kind::S_init_val: // init_val
        value.move< std::shared_ptr<init_val_t> > (that.value);
        break;

      case symbol_kind::S_l_val: // l_val
        value.move< std::shared_ptr<l_val_t> > (that.value);
        break;

      case symbol_kind::S_number: // number
        value.move< std::shared_ptr<number_literal_t> > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< std::shared_ptr<stmt_t> > (that.value);
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< std::shared_ptr<var_decl_t> > (that.value);
        break;

      case symbol_kind::S_var_def: // var_def
        value.move< std::shared_ptr<var_def_t> > (that.value);
        break;

      case symbol_kind::S_IDENT: // "identifier"
      case symbol_kind::S_ident: // ident
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_INT_CONST: // "integer"
        yylhs.value.emplace< long long > ();
        break;

      case symbol_kind::S_block_elements: // block_elements
        yylhs.value.emplace< ptr_list_of<block_item_t> > ();
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
      case symbol_kind::S_real_const_array_elements: // real_const_array_elements
        yylhs.value.emplace< ptr_list_of<const_init_val_t> > ();
        break;

      case symbol_kind::S_array_dims: // array_dims
      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        yylhs.value.emplace< ptr_list_of<expr> > ();
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
      case symbol_kind::S_real_init_array_elements: // real_init_array_elements
        yylhs.value.emplace< ptr_list_of<init_val_t> > ();
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        yylhs.value.emplace< ptr_list_of<var_def_t> > ();
        break;

      case symbol_kind::S_b_type: // b_type
        yylhs.value.emplace< std::shared_ptr<b_type_t> > ();
        break;

      case symbol_kind::S_block_item: // block_item
        yylhs.value.emplace< std::shared_ptr<block_item_t> > ();
        break;

      case symbol_kind::S_block: // block
        yylhs.value.emplace< std::shared_ptr<block_t> > ();
        break;

      case symbol_kind::S_comp_unit_item: // comp_unit_item
        yylhs.value.emplace< std::shared_ptr<comp_unit_item_t> > ();
        break;

      case symbol_kind::S_start_symbol: // start_symbol
      case symbol_kind::S_comp_unit: // comp_unit
        yylhs.value.emplace< std::shared_ptr<comp_unit_t> > ();
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        yylhs.value.emplace< std::shared_ptr<const_decl_t> > ();
        break;

      case symbol_kind::S_const_def: // const_def
        yylhs.value.emplace< std::shared_ptr<const_def_t> > ();
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        yylhs.value.emplace< std::shared_ptr<const_init_val_t> > ();
        break;

      case symbol_kind::S_decl: // decl
        yylhs.value.emplace< std::shared_ptr<decl_t> > ();
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_primary_exp: // primary_exp
      case symbol_kind::S_unary_exp: // unary_exp
      case symbol_kind::S_mul_exp: // mul_exp
      case symbol_kind::S_add_exp: // add_exp
      case symbol_kind::S_rel_exp: // rel_exp
      case symbol_kind::S_eq_exp: // eq_exp
      case symbol_kind::S_l_and_exp: // l_and_exp
      case symbol_kind::S_l_or_exp: // l_or_exp
      case symbol_kind::S_const_exp: // const_exp
        yylhs.value.emplace< std::shared_ptr<expr> > ();
        break;

      case symbol_kind::S_func_def: // func_def
        yylhs.value.emplace< std::shared_ptr<func_def_t> > ();
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        yylhs.value.emplace< std::shared_ptr<func_f_param_t> > ();
        break;

      case symbol_kind::S_func_f_params: // func_f_params
      case symbol_kind::S_real_func_f_params: // real_func_f_params
        yylhs.value.emplace< std::shared_ptr<func_f_params_t> > ();
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        yylhs.value.emplace< std::shared_ptr<func_r_params_t> > ();
        break;

      case symbol_kind::S_init_val: // init_val
        yylhs.value.emplace< std::shared_ptr<init_val_t> > ();
        break;

      case symbol_kind::S_l_val: // l_val
        yylhs.value.emplace< std::shared_ptr<l_val_t> > ();
        break;

      case symbol_kind::S_number: // number
        yylhs.value.emplace< std::shared_ptr<number_literal_t> > ();
        break;

      case symbol_kind::S_stmt: // stmt
        yylhs.value.emplace< std::shared_ptr<stmt_t> > ();
        break;

      case symbol_kind::S_var_decl: // var_decl
        yylhs.value.emplace< std::shared_ptr<var_decl_t> > ();
        break;

      case symbol_kind::S_var_def: // var_def
        yylhs.value.emplace< std::shared_ptr<var_def_t> > ();
        break;

      case symbol_kind::S_IDENT: // "identifier"
      case symbol_kind::S_ident: // ident
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // start_symbol: comp_unit
#line 66 "parser.yy"
                        {
    drv.syntax_tree = yystack_[0].value.as < std::shared_ptr<comp_unit_t> > ();
}
#line 1152 "parser.cc"
    break;

  case 3: // comp_unit: comp_unit_item
#line 73 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<comp_unit_t> > () = std::make_shared<comp_unit_t>(); yylhs.value.as < std::shared_ptr<comp_unit_t> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<comp_unit_item_t> > ());          }
#line 1158 "parser.cc"
    break;

  case 4: // comp_unit: comp_unit comp_unit_item
#line 74 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<comp_unit_t> > () = yystack_[1].value.as < std::shared_ptr<comp_unit_t> > (); yylhs.value.as < std::shared_ptr<comp_unit_t> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<comp_unit_item_t> > ()); }
#line 1164 "parser.cc"
    break;

  case 5: // comp_unit_item: func_def
#line 79 "parser.yy"
                { yylhs.value.as < std::shared_ptr<comp_unit_item_t> > () = std::make_shared<comp_unit_item_func_def_t>(yystack_[0].value.as < std::shared_ptr<func_def_t> > ()); }
#line 1170 "parser.cc"
    break;

  case 6: // comp_unit_item: decl
#line 80 "parser.yy"
                { yylhs.value.as < std::shared_ptr<comp_unit_item_t> > () = std::make_shared<comp_unit_item_decl_t>(yystack_[0].value.as < std::shared_ptr<decl_t> > ());     }
#line 1176 "parser.cc"
    break;

  case 7: // decl: const_decl_stmt
#line 85 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<decl_t> > () = std::make_shared<decl_const_decl_t>(yystack_[0].value.as < std::shared_ptr<const_decl_t> > ()); }
#line 1182 "parser.cc"
    break;

  case 8: // decl: var_decl
#line 86 "parser.yy"
               { yylhs.value.as < std::shared_ptr<decl_t> > () = std::make_shared<decl_var_decl_t>(yystack_[0].value.as < std::shared_ptr<var_decl_t> > ());   }
#line 1188 "parser.cc"
    break;

  case 9: // const_decl: "const" b_type const_def
#line 92 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<const_decl_t> > () = std::make_shared<const_decl_t>(); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->b_type = yystack_[1].value.as < std::shared_ptr<b_type_t> > (); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->const_defs.push_back(yystack_[0].value.as < std::shared_ptr<const_def_t> > ()); }
#line 1194 "parser.cc"
    break;

  case 10: // const_decl: const_decl "," const_def
#line 93 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<const_decl_t> > () = yystack_[2].value.as < std::shared_ptr<const_decl_t> > (); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->const_defs.push_back(yystack_[0].value.as < std::shared_ptr<const_def_t> > ());}
#line 1200 "parser.cc"
    break;

  case 11: // const_decl_stmt: const_decl ";"
#line 96 "parser.yy"
                                { yylhs.value.as < std::shared_ptr<const_decl_t> > () = yystack_[1].value.as < std::shared_ptr<const_decl_t> > (); }
#line 1206 "parser.cc"
    break;

  case 12: // b_type: "int"
#line 100 "parser.yy"
          { yylhs.value.as < std::shared_ptr<b_type_t> > () = std::make_shared<b_type_t>(b_type_t::INT); }
#line 1212 "parser.cc"
    break;

  case 13: // b_type: "void"
#line 101 "parser.yy"
           { yylhs.value.as < std::shared_ptr<b_type_t> > () = std::make_shared<b_type_t>(b_type_t::VOID); }
#line 1218 "parser.cc"
    break;

  case 14: // const_def: ident array_dims "=" const_init_val
#line 105 "parser.yy"
                                               {
    yylhs.value.as < std::shared_ptr<const_def_t> > () = std::make_shared<const_def_t>(yystack_[3].value.as < std::string > (), yystack_[2].value.as < ptr_list_of<expr> > (), yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ());
}
#line 1226 "parser.cc"
    break;

  case 15: // array_dims: %empty
#line 111 "parser.yy"
           {}
#line 1232 "parser.cc"
    break;

  case 16: // array_dims: array_dims "[" const_exp "]"
#line 112 "parser.yy"
                                 { yylhs.value.as < ptr_list_of<expr> > () = yystack_[3].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1238 "parser.cc"
    break;

  case 17: // const_init_val: const_exp
#line 117 "parser.yy"
              { yylhs.value.as < std::shared_ptr<const_init_val_t> > () = std::make_shared<const_init_val_scalar_t>(yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1244 "parser.cc"
    break;

  case 18: // const_init_val: "{" const_array_elements "}"
#line 118 "parser.yy"
                                 { yylhs.value.as < std::shared_ptr<const_init_val_t> > () = std::make_shared<const_init_val_array_t>(yystack_[1].value.as < ptr_list_of<const_init_val_t> > ()); }
#line 1250 "parser.cc"
    break;

  case 19: // const_array_elements: %empty
#line 123 "parser.yy"
           {}
#line 1256 "parser.cc"
    break;

  case 20: // const_array_elements: real_const_array_elements
#line 124 "parser.yy"
                              { yylhs.value.as < ptr_list_of<const_init_val_t> > () = yystack_[0].value.as < ptr_list_of<const_init_val_t> > (); }
#line 1262 "parser.cc"
    break;

  case 21: // real_const_array_elements: real_const_array_elements "," const_init_val
#line 129 "parser.yy"
                                                 { yylhs.value.as < ptr_list_of<const_init_val_t> > () = yystack_[2].value.as < ptr_list_of<const_init_val_t> > (); yylhs.value.as < ptr_list_of<const_init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ()); }
#line 1268 "parser.cc"
    break;

  case 22: // real_const_array_elements: const_init_val
#line 130 "parser.yy"
                   { yylhs.value.as < ptr_list_of<const_init_val_t> > () = ptr_list_of<const_init_val_t>(); yylhs.value.as < ptr_list_of<const_init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ()); }
#line 1274 "parser.cc"
    break;

  case 23: // var_decl: b_type var_def_list ";"
#line 135 "parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<var_decl_t> > () = std::make_shared<var_decl_t>(yystack_[2].value.as < std::shared_ptr<b_type_t> > (), yystack_[1].value.as < ptr_list_of<var_def_t> > ());
    }
#line 1282 "parser.cc"
    break;

  case 24: // var_def_list: var_def
#line 142 "parser.yy"
            { yylhs.value.as < ptr_list_of<var_def_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<var_def_t> > ()); }
#line 1288 "parser.cc"
    break;

  case 25: // var_def_list: var_def_list "," var_def
#line 143 "parser.yy"
                             { yylhs.value.as < ptr_list_of<var_def_t> > () = yystack_[2].value.as < ptr_list_of<var_def_t> > (); yylhs.value.as < ptr_list_of<var_def_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<var_def_t> > ()); }
#line 1294 "parser.cc"
    break;

  case 26: // var_def: ident array_dims
#line 148 "parser.yy"
                                    { yylhs.value.as < std::shared_ptr<var_def_t> > () = std::make_shared<var_def_only_t>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ptr_list_of<expr> > ()); }
#line 1300 "parser.cc"
    break;

  case 27: // var_def: ident array_dims "=" init_val
#line 149 "parser.yy"
                                    { yylhs.value.as < std::shared_ptr<var_def_t> > () = std::make_shared<var_def_init_t>(yystack_[3].value.as < std::string > (), yystack_[2].value.as < ptr_list_of<expr> > (), yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1306 "parser.cc"
    break;

  case 28: // init_val: exp
#line 154 "parser.yy"
        { yylhs.value.as < std::shared_ptr<init_val_t> > () = std::make_shared<init_val_scalar_t>(yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1312 "parser.cc"
    break;

  case 29: // init_val: "{" init_array_elements "}"
#line 155 "parser.yy"
                                {{ yylhs.value.as < std::shared_ptr<init_val_t> > () = std::make_shared<init_val_array_t>(yystack_[1].value.as < ptr_list_of<init_val_t> > ()); }}
#line 1318 "parser.cc"
    break;

  case 30: // init_array_elements: %empty
#line 159 "parser.yy"
           {}
#line 1324 "parser.cc"
    break;

  case 31: // init_array_elements: real_init_array_elements
#line 160 "parser.yy"
                             { yylhs.value.as < ptr_list_of<init_val_t> > () = yystack_[0].value.as < ptr_list_of<init_val_t> > (); }
#line 1330 "parser.cc"
    break;

  case 32: // real_init_array_elements: init_val
#line 165 "parser.yy"
             { yylhs.value.as < ptr_list_of<init_val_t> > () = ptr_list_of<init_val_t>(); yylhs.value.as < ptr_list_of<init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1336 "parser.cc"
    break;

  case 33: // real_init_array_elements: real_init_array_elements "," init_val
#line 166 "parser.yy"
                                          { yylhs.value.as < ptr_list_of<init_val_t> > () = yystack_[2].value.as < ptr_list_of<init_val_t> > (); yylhs.value.as < ptr_list_of<init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1342 "parser.cc"
    break;

  case 34: // func_def: b_type ident "(" func_f_params ")" block
#line 170 "parser.yy"
                                                   {
    yylhs.value.as < std::shared_ptr<func_def_t> > () = std::make_shared<func_def_t>();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->func_type = yystack_[5].value.as < std::shared_ptr<b_type_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->ident = yystack_[4].value.as < std::string > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->params = yystack_[2].value.as < std::shared_ptr<func_f_params_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->block = yystack_[0].value.as < std::shared_ptr<block_t> > ();
}
#line 1354 "parser.cc"
    break;

  case 35: // func_f_params: %empty
#line 180 "parser.yy"
           { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = std::make_shared<func_f_params_t>(); }
#line 1360 "parser.cc"
    break;

  case 36: // func_f_params: real_func_f_params
#line 181 "parser.yy"
                       { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = yystack_[0].value.as < std::shared_ptr<func_f_params_t> > (); }
#line 1366 "parser.cc"
    break;

  case 37: // real_func_f_params: real_func_f_params "," func_f_param
#line 186 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = yystack_[2].value.as < std::shared_ptr<func_f_params_t> > (); yylhs.value.as < std::shared_ptr<func_f_params_t> > ()->params.push_back(yystack_[0].value.as < std::shared_ptr<func_f_param_t> > ()); }
#line 1372 "parser.cc"
    break;

  case 38: // real_func_f_params: func_f_param
#line 187 "parser.yy"
                 { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = std::make_shared<func_f_params_t>(); yylhs.value.as < std::shared_ptr<func_f_params_t> > ()->params.push_back(yystack_[0].value.as < std::shared_ptr<func_f_param_t> > ()); }
#line 1378 "parser.cc"
    break;

  case 39: // func_f_param: b_type ident array_dims_func_param
#line 191 "parser.yy"
                                                 {
    yylhs.value.as < std::shared_ptr<func_f_param_t> > () = std::make_shared<func_f_param_t>();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->b_type = yystack_[2].value.as < std::shared_ptr<b_type_t> > ();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->ident = yystack_[1].value.as < std::string > ();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->array_dims = yystack_[0].value.as < ptr_list_of<expr> > ();
}
#line 1389 "parser.cc"
    break;

  case 40: // array_dims_func_param: %empty
#line 200 "parser.yy"
           {}
#line 1395 "parser.cc"
    break;

  case 41: // array_dims_func_param: array_dims_func_param_real
#line 201 "parser.yy"
                               { yylhs.value.as < ptr_list_of<expr> > () = yystack_[0].value.as < ptr_list_of<expr> > (); }
#line 1401 "parser.cc"
    break;

  case 42: // array_dims_func_param_real: "[" "]"
#line 206 "parser.yy"
            { yylhs.value.as < ptr_list_of<expr> > ().push_back(nullptr); }
#line 1407 "parser.cc"
    break;

  case 43: // array_dims_func_param_real: array_dims_func_param_real "[" exp "]"
#line 207 "parser.yy"
                                           { yylhs.value.as < ptr_list_of<expr> > () = yystack_[3].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1413 "parser.cc"
    break;

  case 44: // block: "{" block_elements "}"
#line 211 "parser.yy"
                              { yylhs.value.as < std::shared_ptr<block_t> > () = std::make_shared<block_t>(yystack_[1].value.as < ptr_list_of<block_item_t> > ()); }
#line 1419 "parser.cc"
    break;

  case 45: // block_elements: %empty
#line 215 "parser.yy"
           {}
#line 1425 "parser.cc"
    break;

  case 46: // block_elements: block_elements block_item
#line 216 "parser.yy"
                              { yylhs.value.as < ptr_list_of<block_item_t> > () = yystack_[1].value.as < ptr_list_of<block_item_t> > (); yylhs.value.as < ptr_list_of<block_item_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<block_item_t> > ()); }
#line 1431 "parser.cc"
    break;

  case 47: // block_item: decl
#line 221 "parser.yy"
         { yylhs.value.as < std::shared_ptr<block_item_t> > () = std::make_shared<block_item_decl_t>(yystack_[0].value.as < std::shared_ptr<decl_t> > ()); }
#line 1437 "parser.cc"
    break;

  case 48: // block_item: stmt
#line 222 "parser.yy"
         { yylhs.value.as < std::shared_ptr<block_item_t> > () = std::make_shared<block_item_stmt_t>(yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1443 "parser.cc"
    break;

  case 49: // ident: "identifier"
#line 225 "parser.yy"
             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1449 "parser.cc"
    break;

  case 50: // stmt: l_val "=" exp ";"
#line 229 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_assign_t>(yystack_[3].value.as < std::shared_ptr<l_val_t> > (), yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1455 "parser.cc"
    break;

  case 51: // stmt: exp ";"
#line 230 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_exp_t>(yystack_[1].value.as < std::shared_ptr<expr> > ());        }
#line 1461 "parser.cc"
    break;

  case 52: // stmt: ";"
#line 231 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::shared_ptr<stmt_exp_t>(nullptr);    }
#line 1467 "parser.cc"
    break;

  case 53: // stmt: block
#line 232 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_block_t>(yystack_[0].value.as < std::shared_ptr<block_t> > ());      }
#line 1473 "parser.cc"
    break;

  case 54: // stmt: "if" "(" cond ")" stmt
#line 233 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_if_t>(yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > (), nullptr); }
#line 1479 "parser.cc"
    break;

  case 55: // stmt: "if" "(" cond ")" stmt "else" stmt
#line 235 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_if_t>(yystack_[4].value.as < std::shared_ptr<expr> > (), yystack_[2].value.as < std::shared_ptr<stmt_t> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1485 "parser.cc"
    break;

  case 56: // stmt: "while" "(" cond ")" stmt
#line 236 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_while_t>(yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1491 "parser.cc"
    break;

  case 57: // stmt: "break" ";"
#line 237 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_break_t>();       }
#line 1497 "parser.cc"
    break;

  case 58: // stmt: "continue" ";"
#line 238 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_continue_t>();    }
#line 1503 "parser.cc"
    break;

  case 59: // stmt: "return" ";"
#line 239 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_return_t>(nullptr); }
#line 1509 "parser.cc"
    break;

  case 60: // stmt: "return" exp ";"
#line 240 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_return_t>(yystack_[1].value.as < std::shared_ptr<expr> > ());    }
#line 1515 "parser.cc"
    break;

  case 61: // exp: add_exp
#line 245 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1521 "parser.cc"
    break;

  case 62: // cond: l_or_exp
#line 248 "parser.yy"
               { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1527 "parser.cc"
    break;

  case 63: // l_val: ident array_indices
#line 252 "parser.yy"
                        { yylhs.value.as < std::shared_ptr<l_val_t> > () = std::make_shared<l_val_t>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ptr_list_of<expr> > ()); }
#line 1533 "parser.cc"
    break;

  case 64: // l_val: ident
#line 253 "parser.yy"
          { yylhs.value.as < std::shared_ptr<l_val_t> > ()=std::make_shared<l_val_t>(yystack_[0].value.as < std::string > (), ptr_list_of<expr>()); }
#line 1539 "parser.cc"
    break;

  case 65: // array_indices: "[" exp "]"
#line 258 "parser.yy"
                 {{ yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }}
#line 1545 "parser.cc"
    break;

  case 66: // array_indices: array_indices "[" exp "]"
#line 259 "parser.yy"
                               { yylhs.value.as < ptr_list_of<expr> > () = yystack_[3].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1551 "parser.cc"
    break;

  case 67: // primary_exp: "(" exp ")"
#line 264 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[1].value.as < std::shared_ptr<expr> > (); }
#line 1557 "parser.cc"
    break;

  case 68: // primary_exp: l_val
#line 265 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<l_val_t> > (); }
#line 1563 "parser.cc"
    break;

  case 69: // primary_exp: number
#line 266 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<number_literal_t> > (); }
#line 1569 "parser.cc"
    break;

  case 70: // number: "integer"
#line 270 "parser.yy"
                  { yylhs.value.as < std::shared_ptr<number_literal_t> > () = std::make_shared<number_literal_t>(yystack_[0].value.as < long long > ()); }
#line 1575 "parser.cc"
    break;

  case 71: // unary_exp: primary_exp
#line 274 "parser.yy"
                  { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1581 "parser.cc"
    break;

  case 72: // unary_exp: ident "(" func_r_params ")"
#line 275 "parser.yy"
                                { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<func_call_t>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<func_r_params_t> > ()); }
#line 1587 "parser.cc"
    break;

  case 73: // unary_exp: "+" unary_exp
#line 276 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1593 "parser.cc"
    break;

  case 74: // unary_exp: "-" unary_exp
#line 277 "parser.yy"
                    { 
      auto e = dynamic_pointer_cast<negative_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ());
      if(e) yylhs.value.as < std::shared_ptr<expr> > () = e->src;
      else  yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<negative_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ()); 
    }
#line 1603 "parser.cc"
    break;

  case 75: // unary_exp: "!" unary_exp
#line 282 "parser.yy"
                    { 
      auto e = dynamic_pointer_cast<logical_not_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ());
      if(e) yylhs.value.as < std::shared_ptr<expr> > () = e->src;
      else  yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<logical_not_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ());
    }
#line 1613 "parser.cc"
    break;

  case 76: // func_r_params: %empty
#line 292 "parser.yy"
                { yylhs.value.as < std::shared_ptr<func_r_params_t> > () = std::make_shared<func_r_params_t>(); }
#line 1619 "parser.cc"
    break;

  case 77: // func_r_params: func_r_params_elements
#line 293 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<func_r_params_t> > () = std::make_shared<func_r_params_t>(yystack_[0].value.as < ptr_list_of<expr> > ()); }
#line 1625 "parser.cc"
    break;

  case 78: // func_r_params_elements: exp
#line 298 "parser.yy"
                                     { yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[0].value.as < std::shared_ptr<expr> > ());            }
#line 1631 "parser.cc"
    break;

  case 79: // func_r_params_elements: func_r_params_elements "," exp
#line 299 "parser.yy"
                                     { yylhs.value.as < ptr_list_of<expr> > () = yystack_[2].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[0].value.as < std::shared_ptr<expr> > ());   }
#line 1637 "parser.cc"
    break;

  case 80: // mul_exp: unary_exp
#line 304 "parser.yy"
               { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1643 "parser.cc"
    break;

  case 81: // mul_exp: mul_exp "*" unary_exp
#line 305 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::MULTIPLY, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1649 "parser.cc"
    break;

  case 82: // mul_exp: mul_exp "/" unary_exp
#line 306 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::DIVIDE  , yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1655 "parser.cc"
    break;

  case 83: // mul_exp: mul_exp "%" unary_exp
#line 307 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::MODULE  , yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1661 "parser.cc"
    break;

  case 84: // add_exp: mul_exp
#line 312 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1667 "parser.cc"
    break;

  case 85: // add_exp: add_exp "+" mul_exp
#line 313 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::PLUS,  yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1673 "parser.cc"
    break;

  case 86: // add_exp: add_exp "-" mul_exp
#line 314 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::MINUS, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1679 "parser.cc"
    break;

  case 87: // rel_exp: add_exp
#line 319 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1685 "parser.cc"
    break;

  case 88: // rel_exp: add_exp "<" add_exp
#line 320 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LESS, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1691 "parser.cc"
    break;

  case 89: // rel_exp: add_exp ">" add_exp
#line 321 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::GREATER, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1697 "parser.cc"
    break;

  case 90: // rel_exp: add_exp "<=" add_exp
#line 322 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LESS_EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1703 "parser.cc"
    break;

  case 91: // rel_exp: add_exp ">=" add_exp
#line 323 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::GREATER_EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1709 "parser.cc"
    break;

  case 92: // eq_exp: rel_exp
#line 328 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1715 "parser.cc"
    break;

  case 93: // eq_exp: eq_exp "==" rel_exp
#line 329 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1721 "parser.cc"
    break;

  case 94: // eq_exp: eq_exp "!=" rel_exp
#line 330 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::NOT_EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1727 "parser.cc"
    break;

  case 95: // l_and_exp: eq_exp
#line 335 "parser.yy"
            { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1733 "parser.cc"
    break;

  case 96: // l_and_exp: l_and_exp "&&" eq_exp
#line 336 "parser.yy"
                            { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LOGICAL_AND, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1739 "parser.cc"
    break;

  case 97: // l_or_exp: l_and_exp
#line 341 "parser.yy"
               { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1745 "parser.cc"
    break;

  case 98: // l_or_exp: l_or_exp "||" l_and_exp
#line 342 "parser.yy"
                              { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LOGICAL_OR, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1751 "parser.cc"
    break;

  case 99: // const_exp: add_exp
#line 346 "parser.yy"
                   { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1757 "parser.cc"
    break;


#line 1761 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const short parser::yypact_ninf_ = -135;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      73,  -135,  -135,     5,    15,    73,  -135,  -135,    -4,  -135,
      14,  -135,  -135,    14,  -135,  -135,    14,  -135,  -135,     2,
    -135,     4,  -135,  -135,  -135,    14,  -135,     5,    -6,     1,
    -135,  -135,    14,    42,    24,  -135,    16,    62,    25,    51,
      53,     5,  -135,    62,    62,    62,    62,    16,  -135,    50,
    -135,  -135,  -135,  -135,  -135,   103,    21,    21,    60,    25,
    -135,  -135,    66,  -135,    74,  -135,  -135,  -135,  -135,  -135,
    -135,    92,  -135,    96,   104,    62,    62,   101,    62,    62,
      62,    62,    62,  -135,  -135,    99,   107,  -135,    62,   115,
    -135,  -135,    16,  -135,   105,   112,   108,    62,  -135,  -135,
    -135,   103,   103,  -135,    25,   109,   113,   118,   123,   128,
      72,  -135,  -135,  -135,    14,  -135,  -135,  -135,   129,   138,
    -135,  -135,    62,  -135,   127,  -135,  -135,    62,    62,  -135,
    -135,  -135,   132,  -135,    62,  -135,  -135,   131,    84,  -135,
      41,   146,   147,   133,  -135,   140,   144,    62,    62,    62,
      62,    62,    62,    62,    62,   144,  -135,   162,    21,    21,
      21,    21,  -135,  -135,    41,   146,  -135,   144,  -135
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    13,    12,     0,     0,     2,     3,     6,     0,     7,
       0,     8,     5,     0,     1,     4,     0,    11,    49,     0,
      24,    15,     9,    15,    10,     0,    23,    35,    26,     0,
      25,    15,     0,     0,    36,    38,     0,     0,     0,    40,
       0,     0,    70,     0,     0,     0,     0,    30,    27,    64,
      28,    68,    71,    69,    80,    84,    61,    99,     0,    19,
      14,    17,     0,    39,    41,    45,    34,    37,    75,    73,
      74,     0,    32,     0,    31,    76,     0,    63,     0,     0,
       0,     0,     0,    16,    22,     0,    20,    42,     0,     0,
      67,    29,     0,    78,     0,    77,     0,     0,    81,    82,
      83,    85,    86,    18,     0,     0,     0,     0,     0,     0,
       0,    52,    44,    47,     0,    53,    46,    48,     0,    68,
      33,    72,     0,    65,     0,    21,    43,     0,     0,    57,
      58,    59,     0,    51,     0,    79,    66,     0,    87,    92,
      95,    97,    62,     0,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    54,    91,    90,
      89,    88,    93,    94,    96,    98,    56,     0,    55
  };

  const short
  parser::yypgoto_[] =
  {
    -135,  -135,  -135,   167,    87,  -135,  -135,     3,   157,   154,
     -52,  -135,  -135,  -135,  -135,   153,   -38,  -135,  -135,  -135,
    -135,  -135,   139,  -135,  -135,   141,  -135,  -135,    -8,  -134,
     -33,    54,   -85,  -135,  -135,  -135,    -7,  -135,  -135,   -19,
     -37,   -83,    30,    31,  -135,   149
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     4,     5,     6,     7,     8,     9,    10,    22,    28,
      60,    85,    86,    11,    19,    20,    48,    73,    74,    12,
      33,    34,    35,    63,    64,   115,    89,   116,    49,   117,
     118,   137,    51,    77,    52,    53,    54,    94,    95,    55,
      56,   139,   140,   141,   142,    61
  };

  const unsigned char
  parser::yytable_[] =
  {
      57,    57,    21,    50,   119,    23,    13,    84,    23,    72,
       1,     2,   157,    71,    50,    14,    36,    31,    18,    42,
      18,   166,    57,    38,    39,    16,    17,    37,    42,    18,
      32,    25,    26,   168,    37,    27,    68,    69,    70,    43,
      44,    45,    93,    96,    32,    81,    82,    46,    43,    44,
      45,    47,   125,    41,   120,   105,    46,   151,   152,    50,
      59,   119,   101,   102,   124,    42,    18,    57,   162,   163,
     119,    98,    99,   100,    40,    42,    18,   132,     1,     2,
       3,    75,   119,    76,    62,    43,    44,    45,    65,   135,
     138,   138,   114,    46,    83,    43,    44,    45,   147,   148,
      87,   145,   131,    46,   149,   150,    31,    88,    81,    82,
     158,   159,   160,   161,   138,   138,   138,   138,    42,    18,
       1,     2,     3,   106,    90,   107,   108,   109,   110,    78,
      79,    80,    91,    92,    97,   103,   104,   121,    43,    44,
      45,   122,   123,   126,   127,   111,    46,    42,    18,   128,
      65,   112,   106,   129,   107,   108,   109,   110,   130,   133,
     134,   136,   144,   146,   153,   155,   154,    43,    44,    45,
     156,   167,    15,    24,   111,    46,   113,    29,    30,    65,
      67,    66,   143,   164,     0,   165,    58
  };

  const short
  parser::yycheck_[] =
  {
      37,    38,    10,    36,    89,    13,     3,    59,    16,    47,
       5,     6,   146,    46,    47,     0,    22,    25,     4,     3,
       4,   155,    59,    22,    32,    29,    30,    33,     3,     4,
      27,    29,    30,   167,    33,    31,    43,    44,    45,    23,
      24,    25,    75,    76,    41,    24,    25,    31,    23,    24,
      25,    35,   104,    29,    92,    88,    31,    16,    17,    92,
      35,   146,    81,    82,    97,     3,     4,   104,   151,   152,
     155,    78,    79,    80,    32,     3,     4,   110,     5,     6,
       7,    31,   167,    33,    33,    23,    24,    25,    35,   122,
     127,   128,    89,    31,    34,    23,    24,    25,    14,    15,
      34,   134,    30,    31,    20,    21,   114,    33,    24,    25,
     147,   148,   149,   150,   151,   152,   153,   154,     3,     4,
       5,     6,     7,     8,    32,    10,    11,    12,    13,    26,
      27,    28,    36,    29,    33,    36,    29,    32,    23,    24,
      25,    29,    34,    34,    31,    30,    31,     3,     4,    31,
      35,    36,     8,    30,    10,    11,    12,    13,    30,    30,
      22,    34,    30,    32,    18,    32,    19,    23,    24,    25,
      30,     9,     5,    16,    30,    31,    89,    23,    25,    35,
      41,    40,   128,   153,    -1,   154,    37
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,     6,     7,    38,    39,    40,    41,    42,    43,
      44,    50,    56,    44,     0,    40,    29,    30,     4,    51,
      52,    65,    45,    65,    45,    29,    30,    31,    46,    46,
      52,    65,    44,    57,    58,    59,    22,    33,    22,    65,
      32,    29,     3,    23,    24,    25,    31,    35,    53,    65,
      67,    69,    71,    72,    73,    76,    77,    77,    82,    35,
      47,    82,    33,    60,    61,    35,    62,    59,    73,    73,
      73,    67,    53,    54,    55,    31,    33,    70,    26,    27,
      28,    24,    25,    34,    47,    48,    49,    34,    33,    63,
      32,    36,    29,    67,    74,    75,    67,    33,    73,    73,
      73,    76,    76,    36,    29,    67,     8,    10,    11,    12,
      13,    30,    36,    41,    44,    62,    64,    66,    67,    69,
      53,    32,    29,    34,    67,    47,    34,    31,    31,    30,
      30,    30,    67,    30,    22,    67,    34,    68,    77,    78,
      79,    80,    81,    68,    30,    67,    32,    14,    15,    20,
      21,    16,    17,    18,    19,    32,    30,    66,    77,    77,
      77,    77,    78,    78,    79,    80,    66,     9,    66
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    44,    44,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    50,    51,    51,    52,    52,    53,    53,
      54,    54,    55,    55,    56,    57,    57,    58,    58,    59,
      60,    60,    61,    61,    62,    63,    63,    64,    64,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    68,    69,    69,    70,    70,    71,    71,    71,
      72,    73,    73,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    76,    77,    77,    77,    78,    78,    78,
      78,    78,    79,    79,    79,    80,    80,    81,    81,    82
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     1,     3,
       3,     2,     1,     1,     4,     0,     4,     1,     3,     0,
       1,     3,     1,     3,     1,     3,     2,     4,     1,     3,
       0,     1,     1,     3,     6,     0,     1,     3,     1,     3,
       0,     1,     2,     4,     3,     0,     2,     1,     1,     1,
       4,     2,     1,     1,     5,     7,     5,     2,     2,     2,
       3,     1,     1,     2,     1,     3,     4,     3,     1,     1,
       1,     1,     4,     2,     2,     2,     0,     1,     1,     3,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"integer\"",
  "\"identifier\"", "\"void\"", "\"int\"", "\"const\"", "\"if\"",
  "\"else\"", "\"while\"", "\"break\"", "\"continue\"", "\"return\"",
  "\">=\"", "\"<=\"", "\"==\"", "\"!=\"", "\"&&\"", "\"||\"", "\">\"",
  "\"<\"", "\"=\"", "\"!\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"",
  "\",\"", "\";\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"",
  "$accept", "start_symbol", "comp_unit", "comp_unit_item", "decl",
  "const_decl", "const_decl_stmt", "b_type", "const_def", "array_dims",
  "const_init_val", "const_array_elements", "real_const_array_elements",
  "var_decl", "var_def_list", "var_def", "init_val", "init_array_elements",
  "real_init_array_elements", "func_def", "func_f_params",
  "real_func_f_params", "func_f_param", "array_dims_func_param",
  "array_dims_func_param_real", "block", "block_elements", "block_item",
  "ident", "stmt", "exp", "cond", "l_val", "array_indices", "primary_exp",
  "number", "unary_exp", "func_r_params", "func_r_params_elements",
  "mul_exp", "add_exp", "rel_exp", "eq_exp", "l_and_exp", "l_or_exp",
  "const_exp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    66,    66,    73,    74,    79,    80,    85,    86,    92,
      93,    96,   100,   101,   105,   111,   112,   117,   118,   123,
     124,   129,   130,   135,   142,   143,   148,   149,   154,   155,
     159,   160,   165,   166,   170,   180,   181,   186,   187,   191,
     200,   201,   206,   207,   211,   215,   216,   221,   222,   225,
     229,   230,   231,   232,   233,   235,   236,   237,   238,   239,
     240,   245,   248,   252,   253,   258,   259,   264,   265,   266,
     270,   274,   275,   276,   277,   282,   292,   293,   298,   299,
     304,   305,   306,   307,   312,   313,   314,   319,   320,   321,
     322,   323,   328,   329,   330,   335,   336,   341,   342,   346
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2187 "parser.cc"

#line 349 "parser.yy"


