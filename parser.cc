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
#line 1147 "parser.cc"
    break;

  case 3: // comp_unit: comp_unit_item
#line 73 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<comp_unit_t> > () = std::make_shared<comp_unit_t>(); yylhs.value.as < std::shared_ptr<comp_unit_t> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<comp_unit_item_t> > ());          }
#line 1153 "parser.cc"
    break;

  case 4: // comp_unit: comp_unit comp_unit_item
#line 74 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<comp_unit_t> > () = yystack_[1].value.as < std::shared_ptr<comp_unit_t> > (); yylhs.value.as < std::shared_ptr<comp_unit_t> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<comp_unit_item_t> > ()); }
#line 1159 "parser.cc"
    break;

  case 5: // comp_unit_item: func_def
#line 79 "parser.yy"
                { yylhs.value.as < std::shared_ptr<comp_unit_item_t> > () = std::make_shared<comp_unit_item_func_def_t>(yystack_[0].value.as < std::shared_ptr<func_def_t> > ()); }
#line 1165 "parser.cc"
    break;

  case 6: // comp_unit_item: decl
#line 80 "parser.yy"
                { yylhs.value.as < std::shared_ptr<comp_unit_item_t> > () = std::make_shared<comp_unit_item_decl_t>(yystack_[0].value.as < std::shared_ptr<decl_t> > ());     }
#line 1171 "parser.cc"
    break;

  case 7: // decl: const_decl_stmt
#line 85 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<decl_t> > () = std::make_shared<decl_const_decl_t>(yystack_[0].value.as < std::shared_ptr<const_decl_t> > ()); }
#line 1177 "parser.cc"
    break;

  case 8: // decl: var_decl
#line 86 "parser.yy"
               { yylhs.value.as < std::shared_ptr<decl_t> > () = std::make_shared<decl_var_decl_t>(yystack_[0].value.as < std::shared_ptr<var_decl_t> > ());   }
#line 1183 "parser.cc"
    break;

  case 9: // const_decl: "const" b_type const_def
#line 92 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<const_decl_t> > () = std::make_shared<const_decl_t>(); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->b_type = yystack_[1].value.as < std::shared_ptr<b_type_t> > (); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->const_defs.push_back(yystack_[0].value.as < std::shared_ptr<const_def_t> > ()); }
#line 1189 "parser.cc"
    break;

  case 10: // const_decl: const_decl "," const_def
#line 93 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<const_decl_t> > () = yystack_[2].value.as < std::shared_ptr<const_decl_t> > (); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->const_defs.push_back(yystack_[0].value.as < std::shared_ptr<const_def_t> > ());}
#line 1195 "parser.cc"
    break;

  case 11: // const_decl_stmt: const_decl ";"
#line 96 "parser.yy"
                                { yylhs.value.as < std::shared_ptr<const_decl_t> > () = yystack_[1].value.as < std::shared_ptr<const_decl_t> > (); }
#line 1201 "parser.cc"
    break;

  case 12: // b_type: "int"
#line 100 "parser.yy"
          { yylhs.value.as < std::shared_ptr<b_type_t> > () = std::make_shared<b_type_t>(b_type_t::INT); }
#line 1207 "parser.cc"
    break;

  case 13: // b_type: "void"
#line 101 "parser.yy"
           { yylhs.value.as < std::shared_ptr<b_type_t> > () = std::make_shared<b_type_t>(b_type_t::VOID); }
#line 1213 "parser.cc"
    break;

  case 14: // const_def: ident array_dims "=" const_init_val
#line 105 "parser.yy"
                                               {
    yylhs.value.as < std::shared_ptr<const_def_t> > () = std::make_shared<const_def_t>(yystack_[3].value.as < std::string > (), yystack_[2].value.as < ptr_list_of<expr> > (), yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ());
}
#line 1221 "parser.cc"
    break;

  case 15: // array_dims: %empty
#line 111 "parser.yy"
           {}
#line 1227 "parser.cc"
    break;

  case 16: // array_dims: array_dims "[" const_exp "]"
#line 112 "parser.yy"
                                 { yylhs.value.as < ptr_list_of<expr> > () = yystack_[3].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1233 "parser.cc"
    break;

  case 17: // const_init_val: const_exp
#line 117 "parser.yy"
              { yylhs.value.as < std::shared_ptr<const_init_val_t> > () = std::make_shared<const_init_val_scalar_t>(yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1239 "parser.cc"
    break;

  case 18: // const_init_val: "{" const_array_elements "}"
#line 118 "parser.yy"
                                 { yylhs.value.as < std::shared_ptr<const_init_val_t> > () = std::make_shared<const_init_val_array_t>(yystack_[1].value.as < ptr_list_of<const_init_val_t> > ()); }
#line 1245 "parser.cc"
    break;

  case 19: // const_array_elements: %empty
#line 123 "parser.yy"
           {}
#line 1251 "parser.cc"
    break;

  case 20: // const_array_elements: real_const_array_elements
#line 124 "parser.yy"
                              { yylhs.value.as < ptr_list_of<const_init_val_t> > () = yystack_[0].value.as < ptr_list_of<const_init_val_t> > (); }
#line 1257 "parser.cc"
    break;

  case 21: // real_const_array_elements: real_const_array_elements "," const_init_val
#line 129 "parser.yy"
                                                 { yylhs.value.as < ptr_list_of<const_init_val_t> > () = yystack_[2].value.as < ptr_list_of<const_init_val_t> > (); yylhs.value.as < ptr_list_of<const_init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ()); }
#line 1263 "parser.cc"
    break;

  case 22: // real_const_array_elements: const_init_val
#line 130 "parser.yy"
                   { yylhs.value.as < ptr_list_of<const_init_val_t> > () = ptr_list_of<const_init_val_t>(); yylhs.value.as < ptr_list_of<const_init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ()); }
#line 1269 "parser.cc"
    break;

  case 23: // var_decl: b_type var_def_list ";"
#line 135 "parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<var_decl_t> > () = std::make_shared<var_decl_t>(yystack_[2].value.as < std::shared_ptr<b_type_t> > (), yystack_[1].value.as < ptr_list_of<var_def_t> > ());
    }
#line 1277 "parser.cc"
    break;

  case 24: // var_def_list: var_def
#line 142 "parser.yy"
            { yylhs.value.as < ptr_list_of<var_def_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<var_def_t> > ()); }
#line 1283 "parser.cc"
    break;

  case 25: // var_def_list: var_def_list "," var_def
#line 143 "parser.yy"
                             { yylhs.value.as < ptr_list_of<var_def_t> > () = yystack_[2].value.as < ptr_list_of<var_def_t> > (); yylhs.value.as < ptr_list_of<var_def_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<var_def_t> > ()); }
#line 1289 "parser.cc"
    break;

  case 26: // var_def: ident array_dims
#line 148 "parser.yy"
                                    { yylhs.value.as < std::shared_ptr<var_def_t> > () = std::make_shared<var_def_only_t>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ptr_list_of<expr> > ()); }
#line 1295 "parser.cc"
    break;

  case 27: // var_def: ident array_dims "=" init_val
#line 149 "parser.yy"
                                    { yylhs.value.as < std::shared_ptr<var_def_t> > () = std::make_shared<var_def_init_t>(yystack_[3].value.as < std::string > (), yystack_[2].value.as < ptr_list_of<expr> > (), yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1301 "parser.cc"
    break;

  case 28: // init_val: exp
#line 154 "parser.yy"
        { yylhs.value.as < std::shared_ptr<init_val_t> > () = std::make_shared<init_val_scalar_t>(yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1307 "parser.cc"
    break;

  case 29: // init_val: "{" init_array_elements "}"
#line 155 "parser.yy"
                                {{ yylhs.value.as < std::shared_ptr<init_val_t> > () = std::make_shared<init_val_array_t>(yystack_[1].value.as < ptr_list_of<init_val_t> > ()); }}
#line 1313 "parser.cc"
    break;

  case 30: // init_array_elements: %empty
#line 159 "parser.yy"
           {}
#line 1319 "parser.cc"
    break;

  case 31: // init_array_elements: init_array_elements init_val
#line 160 "parser.yy"
                                 { yylhs.value.as < ptr_list_of<init_val_t> > () = yystack_[1].value.as < ptr_list_of<init_val_t> > (); yylhs.value.as < ptr_list_of<init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1325 "parser.cc"
    break;

  case 32: // func_def: b_type ident "(" func_f_params ")" block
#line 164 "parser.yy"
                                                   {
    yylhs.value.as < std::shared_ptr<func_def_t> > () = std::make_shared<func_def_t>();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->func_type = yystack_[5].value.as < std::shared_ptr<b_type_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->ident = yystack_[4].value.as < std::string > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->params = yystack_[2].value.as < std::shared_ptr<func_f_params_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->block = yystack_[0].value.as < std::shared_ptr<block_t> > ();
}
#line 1337 "parser.cc"
    break;

  case 33: // func_f_params: %empty
#line 174 "parser.yy"
           { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = std::make_shared<func_f_params_t>(); }
#line 1343 "parser.cc"
    break;

  case 34: // func_f_params: real_func_f_params
#line 175 "parser.yy"
                       { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = yystack_[0].value.as < std::shared_ptr<func_f_params_t> > (); }
#line 1349 "parser.cc"
    break;

  case 35: // real_func_f_params: real_func_f_params "," func_f_param
#line 180 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = yystack_[2].value.as < std::shared_ptr<func_f_params_t> > (); yylhs.value.as < std::shared_ptr<func_f_params_t> > ()->params.push_back(yystack_[0].value.as < std::shared_ptr<func_f_param_t> > ()); }
#line 1355 "parser.cc"
    break;

  case 36: // real_func_f_params: func_f_param
#line 181 "parser.yy"
                 { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = std::make_shared<func_f_params_t>(); yylhs.value.as < std::shared_ptr<func_f_params_t> > ()->params.push_back(yystack_[0].value.as < std::shared_ptr<func_f_param_t> > ()); }
#line 1361 "parser.cc"
    break;

  case 37: // func_f_param: b_type ident array_dims_func_param
#line 185 "parser.yy"
                                                 {
    yylhs.value.as < std::shared_ptr<func_f_param_t> > () = std::make_shared<func_f_param_t>();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->b_type = yystack_[2].value.as < std::shared_ptr<b_type_t> > ();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->ident = yystack_[1].value.as < std::string > ();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->array_dims = yystack_[0].value.as < ptr_list_of<expr> > ();
}
#line 1372 "parser.cc"
    break;

  case 38: // array_dims_func_param: %empty
#line 194 "parser.yy"
           {}
#line 1378 "parser.cc"
    break;

  case 39: // array_dims_func_param: array_dims_func_param_real
#line 195 "parser.yy"
                               { yylhs.value.as < ptr_list_of<expr> > () = yystack_[0].value.as < ptr_list_of<expr> > (); }
#line 1384 "parser.cc"
    break;

  case 40: // array_dims_func_param_real: "[" "]"
#line 200 "parser.yy"
            { yylhs.value.as < ptr_list_of<expr> > ().push_back(nullptr); }
#line 1390 "parser.cc"
    break;

  case 41: // array_dims_func_param_real: array_dims_func_param_real "[" exp "]"
#line 201 "parser.yy"
                                           { yylhs.value.as < ptr_list_of<expr> > () = yystack_[3].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1396 "parser.cc"
    break;

  case 42: // block: "{" block_elements "}"
#line 205 "parser.yy"
                              { yylhs.value.as < std::shared_ptr<block_t> > () = std::make_shared<block_t>(yystack_[1].value.as < ptr_list_of<block_item_t> > ()); }
#line 1402 "parser.cc"
    break;

  case 43: // block_elements: %empty
#line 209 "parser.yy"
           {}
#line 1408 "parser.cc"
    break;

  case 44: // block_elements: block_elements block_item
#line 210 "parser.yy"
                              { yylhs.value.as < ptr_list_of<block_item_t> > () = yystack_[1].value.as < ptr_list_of<block_item_t> > (); yylhs.value.as < ptr_list_of<block_item_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<block_item_t> > ()); }
#line 1414 "parser.cc"
    break;

  case 45: // block_item: decl
#line 215 "parser.yy"
         { yylhs.value.as < std::shared_ptr<block_item_t> > () = std::make_shared<block_item_decl_t>(yystack_[0].value.as < std::shared_ptr<decl_t> > ()); }
#line 1420 "parser.cc"
    break;

  case 46: // block_item: stmt
#line 216 "parser.yy"
         { yylhs.value.as < std::shared_ptr<block_item_t> > () = std::make_shared<block_item_stmt_t>(yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1426 "parser.cc"
    break;

  case 47: // ident: "identifier"
#line 219 "parser.yy"
             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1432 "parser.cc"
    break;

  case 48: // stmt: l_val "=" exp ";"
#line 223 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_assign_t>(yystack_[3].value.as < std::shared_ptr<l_val_t> > (), yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1438 "parser.cc"
    break;

  case 49: // stmt: exp ";"
#line 224 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_exp_t>(yystack_[1].value.as < std::shared_ptr<expr> > ());        }
#line 1444 "parser.cc"
    break;

  case 50: // stmt: ";"
#line 225 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::shared_ptr<stmt_exp_t>(nullptr);    }
#line 1450 "parser.cc"
    break;

  case 51: // stmt: block
#line 226 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_block_t>(yystack_[0].value.as < std::shared_ptr<block_t> > ());      }
#line 1456 "parser.cc"
    break;

  case 52: // stmt: "if" "(" cond ")" stmt
#line 227 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_if_t>(yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > (), nullptr); }
#line 1462 "parser.cc"
    break;

  case 53: // stmt: "if" "(" cond ")" stmt "else" stmt
#line 229 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_if_t>(yystack_[4].value.as < std::shared_ptr<expr> > (), yystack_[2].value.as < std::shared_ptr<stmt_t> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1468 "parser.cc"
    break;

  case 54: // stmt: "while" "(" cond ")" stmt
#line 230 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_while_t>(yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1474 "parser.cc"
    break;

  case 55: // stmt: "break" ";"
#line 231 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_break_t>();       }
#line 1480 "parser.cc"
    break;

  case 56: // stmt: "continue" ";"
#line 232 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_continue_t>();    }
#line 1486 "parser.cc"
    break;

  case 57: // stmt: "return" ";"
#line 233 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_return_t>(nullptr); }
#line 1492 "parser.cc"
    break;

  case 58: // stmt: "return" exp ";"
#line 234 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_return_t>(yystack_[1].value.as < std::shared_ptr<expr> > ());    }
#line 1498 "parser.cc"
    break;

  case 59: // exp: add_exp
#line 239 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1504 "parser.cc"
    break;

  case 60: // cond: l_or_exp
#line 242 "parser.yy"
               { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1510 "parser.cc"
    break;

  case 61: // l_val: ident array_indices
#line 246 "parser.yy"
                        { yylhs.value.as < std::shared_ptr<l_val_t> > () = std::make_shared<l_val_t>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ptr_list_of<expr> > ()); }
#line 1516 "parser.cc"
    break;

  case 62: // l_val: ident
#line 247 "parser.yy"
          { yylhs.value.as < std::shared_ptr<l_val_t> > ()=std::make_shared<l_val_t>(yystack_[0].value.as < std::string > (), ptr_list_of<expr>()); }
#line 1522 "parser.cc"
    break;

  case 63: // array_indices: "[" exp "]"
#line 252 "parser.yy"
                 {{ yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }}
#line 1528 "parser.cc"
    break;

  case 64: // array_indices: array_indices "[" exp "]"
#line 253 "parser.yy"
                               { yylhs.value.as < ptr_list_of<expr> > () = yystack_[3].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1534 "parser.cc"
    break;

  case 65: // primary_exp: "(" exp ")"
#line 258 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[1].value.as < std::shared_ptr<expr> > (); }
#line 1540 "parser.cc"
    break;

  case 66: // primary_exp: l_val
#line 259 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<l_val_t> > (); }
#line 1546 "parser.cc"
    break;

  case 67: // primary_exp: number
#line 260 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<number_literal_t> > (); }
#line 1552 "parser.cc"
    break;

  case 68: // number: "integer"
#line 264 "parser.yy"
                  { yylhs.value.as < std::shared_ptr<number_literal_t> > () = std::make_shared<number_literal_t>(yystack_[0].value.as < long long > ()); }
#line 1558 "parser.cc"
    break;

  case 69: // unary_exp: primary_exp
#line 268 "parser.yy"
                  { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1564 "parser.cc"
    break;

  case 70: // unary_exp: ident "(" func_r_params ")"
#line 269 "parser.yy"
                                { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<func_call_t>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<func_r_params_t> > ()); }
#line 1570 "parser.cc"
    break;

  case 71: // unary_exp: "+" unary_exp
#line 270 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1576 "parser.cc"
    break;

  case 72: // unary_exp: "-" unary_exp
#line 271 "parser.yy"
                    { 
      auto e = dynamic_pointer_cast<negative_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ());
      if(e) yylhs.value.as < std::shared_ptr<expr> > () = e->src;
      else  yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<negative_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ()); 
    }
#line 1586 "parser.cc"
    break;

  case 73: // unary_exp: "!" unary_exp
#line 276 "parser.yy"
                    { 
      auto e = dynamic_pointer_cast<logical_not_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ());
      if(e) yylhs.value.as < std::shared_ptr<expr> > () = e->src;
      else  yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<logical_not_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ());
    }
#line 1596 "parser.cc"
    break;

  case 74: // func_r_params: %empty
#line 286 "parser.yy"
                { yylhs.value.as < std::shared_ptr<func_r_params_t> > () = std::make_shared<func_r_params_t>(); }
#line 1602 "parser.cc"
    break;

  case 75: // func_r_params: func_r_params_elements
#line 287 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<func_r_params_t> > () = std::make_shared<func_r_params_t>(yystack_[0].value.as < ptr_list_of<expr> > ()); }
#line 1608 "parser.cc"
    break;

  case 76: // func_r_params_elements: exp
#line 292 "parser.yy"
                                     { yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[0].value.as < std::shared_ptr<expr> > ());            }
#line 1614 "parser.cc"
    break;

  case 77: // func_r_params_elements: func_r_params_elements "," exp
#line 293 "parser.yy"
                                     { yylhs.value.as < ptr_list_of<expr> > () = yystack_[2].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[0].value.as < std::shared_ptr<expr> > ());   }
#line 1620 "parser.cc"
    break;

  case 78: // mul_exp: unary_exp
#line 298 "parser.yy"
               { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1626 "parser.cc"
    break;

  case 79: // mul_exp: mul_exp "*" unary_exp
#line 299 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::MULTIPLY, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1632 "parser.cc"
    break;

  case 80: // mul_exp: mul_exp "/" unary_exp
#line 300 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::DIVIDE  , yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1638 "parser.cc"
    break;

  case 81: // mul_exp: mul_exp "%" unary_exp
#line 301 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::MODULE  , yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1644 "parser.cc"
    break;

  case 82: // add_exp: mul_exp
#line 306 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1650 "parser.cc"
    break;

  case 83: // add_exp: add_exp "+" mul_exp
#line 307 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::PLUS,  yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1656 "parser.cc"
    break;

  case 84: // add_exp: add_exp "-" mul_exp
#line 308 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::MINUS, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1662 "parser.cc"
    break;

  case 85: // rel_exp: add_exp
#line 313 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1668 "parser.cc"
    break;

  case 86: // rel_exp: add_exp "<" add_exp
#line 314 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LESS, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1674 "parser.cc"
    break;

  case 87: // rel_exp: add_exp ">" add_exp
#line 315 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::GREATER, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1680 "parser.cc"
    break;

  case 88: // rel_exp: add_exp "<=" add_exp
#line 316 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LESS_EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1686 "parser.cc"
    break;

  case 89: // rel_exp: add_exp ">=" add_exp
#line 317 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::GREATER_EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1692 "parser.cc"
    break;

  case 90: // eq_exp: rel_exp
#line 322 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1698 "parser.cc"
    break;

  case 91: // eq_exp: eq_exp "==" rel_exp
#line 323 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1704 "parser.cc"
    break;

  case 92: // eq_exp: eq_exp "!=" rel_exp
#line 324 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::NOT_EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1710 "parser.cc"
    break;

  case 93: // l_and_exp: eq_exp
#line 329 "parser.yy"
            { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1716 "parser.cc"
    break;

  case 94: // l_and_exp: l_and_exp "&&" eq_exp
#line 330 "parser.yy"
                            { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LOGICAL_AND, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1722 "parser.cc"
    break;

  case 95: // l_or_exp: l_and_exp
#line 335 "parser.yy"
               { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1728 "parser.cc"
    break;

  case 96: // l_or_exp: l_or_exp "||" l_and_exp
#line 336 "parser.yy"
                              { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LOGICAL_OR, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1734 "parser.cc"
    break;

  case 97: // const_exp: add_exp
#line 340 "parser.yy"
                   { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1740 "parser.cc"
    break;


#line 1744 "parser.cc"

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





  const short parser::yypact_ninf_ = -134;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      71,  -134,  -134,    20,    11,    71,  -134,  -134,    29,  -134,
      14,  -134,  -134,    14,  -134,  -134,    14,  -134,  -134,    55,
    -134,    -2,  -134,  -134,  -134,    14,  -134,    20,   -13,   -10,
    -134,  -134,    14,   -11,    17,  -134,    48,   170,   154,    -1,
       7,    20,  -134,   170,   170,   170,   170,  -134,  -134,    12,
    -134,  -134,  -134,  -134,  -134,    65,    70,    70,    27,   154,
    -134,  -134,    30,  -134,    33,  -134,  -134,  -134,  -134,  -134,
    -134,    22,    32,   170,   170,    37,   170,   170,   170,   170,
     170,  -134,  -134,    38,    51,  -134,   170,   112,  -134,  -134,
    -134,  -134,    50,    60,    72,   170,  -134,  -134,  -134,    65,
      65,  -134,   154,    87,    68,    74,    96,    97,   137,  -134,
    -134,  -134,    14,  -134,  -134,  -134,    98,   107,  -134,   170,
    -134,    99,  -134,  -134,   170,   170,  -134,  -134,  -134,   100,
    -134,   170,  -134,  -134,   102,    13,  -134,    80,   113,   119,
     114,  -134,   109,   141,   170,   170,   170,   170,   170,   170,
     170,   170,   141,  -134,   123,    70,    70,    70,    70,  -134,
    -134,    80,   113,  -134,   141,  -134
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    13,    12,     0,     0,     2,     3,     6,     0,     7,
       0,     8,     5,     0,     1,     4,     0,    11,    47,     0,
      24,    15,     9,    15,    10,     0,    23,    33,    26,     0,
      25,    15,     0,     0,    34,    36,     0,     0,     0,    38,
       0,     0,    68,     0,     0,     0,     0,    30,    27,    62,
      28,    66,    69,    67,    78,    82,    59,    97,     0,    19,
      14,    17,     0,    37,    39,    43,    32,    35,    73,    71,
      72,     0,     0,    74,     0,    61,     0,     0,     0,     0,
       0,    16,    22,     0,    20,    40,     0,     0,    65,    29,
      31,    76,     0,    75,     0,     0,    79,    80,    81,    83,
      84,    18,     0,     0,     0,     0,     0,     0,     0,    50,
      42,    45,     0,    51,    44,    46,     0,    66,    70,     0,
      63,     0,    21,    41,     0,     0,    55,    56,    57,     0,
      49,     0,    77,    64,     0,    85,    90,    93,    95,    60,
       0,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,    52,    89,    88,    87,    86,    91,
      92,    94,    96,    54,     0,    53
  };

  const short
  parser::yypgoto_[] =
  {
    -134,  -134,  -134,   145,    69,  -134,  -134,     3,   139,   136,
     -52,  -134,  -134,  -134,  -134,   138,   103,  -134,  -134,  -134,
    -134,   128,  -134,  -134,   130,  -134,  -134,    -8,  -133,   -33,
      56,   -83,  -134,  -134,  -134,   -29,  -134,  -134,    21,   -37,
     -46,    34,    31,  -134,   143
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     4,     5,     6,     7,     8,     9,    10,    22,    28,
      60,    83,    84,    11,    19,    20,    48,    72,    12,    33,
      34,    35,    63,    64,   113,    87,   114,    49,   115,   116,
     134,    51,    75,    52,    53,    54,    92,    93,    55,    56,
     136,   137,   138,   139,    61
  };

  const unsigned char
  parser::yytable_[] =
  {
      57,    57,    21,    50,   117,    23,    13,    82,    23,    36,
     154,    14,    38,    71,    68,    69,    70,    31,    18,   163,
      37,    40,    57,    37,    39,     1,     2,   144,   145,    27,
      32,   165,    62,   146,   147,    42,    18,    79,    80,    50,
      91,    94,    65,    73,    32,    74,    41,    96,    97,    98,
     122,    42,    18,   103,    88,    43,    44,    45,    16,    17,
     117,    81,   121,    46,    85,    57,    86,    47,    89,   117,
      95,    43,    44,    45,   101,   129,     1,     2,     3,    46,
     102,   117,   118,    47,    25,    26,   132,   135,   135,   119,
     112,    76,    77,    78,    79,    80,   148,   149,   142,   124,
      99,   100,   159,   160,    31,   125,   120,   155,   156,   157,
     158,   135,   135,   135,   135,    42,    18,     1,     2,     3,
     104,   123,   105,   106,   107,   108,   126,   127,   130,   131,
     141,   150,   164,   133,   143,    43,    44,    45,   151,   153,
      42,    18,   109,    46,    42,    18,   152,    65,   110,   104,
      15,   105,   106,   107,   108,    24,   111,    42,    18,    29,
      43,    44,    45,    30,    43,    44,    45,   128,    46,    67,
      66,   109,    46,    42,    18,    90,    65,    43,    44,    45,
      58,   140,   162,     0,   161,    46,     0,     0,     0,    59,
       0,     0,     0,    43,    44,    45,     0,     0,     0,     0,
       0,    46
  };

  const short
  parser::yycheck_[] =
  {
      37,    38,    10,    36,    87,    13,     3,    59,    16,    22,
     143,     0,    22,    46,    43,    44,    45,    25,     4,   152,
      33,    32,    59,    33,    32,     5,     6,    14,    15,    31,
      27,   164,    33,    20,    21,     3,     4,    24,    25,    72,
      73,    74,    35,    31,    41,    33,    29,    76,    77,    78,
     102,     3,     4,    86,    32,    23,    24,    25,    29,    30,
     143,    34,    95,    31,    34,   102,    33,    35,    36,   152,
      33,    23,    24,    25,    36,   108,     5,     6,     7,    31,
      29,   164,    32,    35,    29,    30,   119,   124,   125,    29,
      87,    26,    27,    28,    24,    25,    16,    17,   131,    31,
      79,    80,   148,   149,   112,    31,    34,   144,   145,   146,
     147,   148,   149,   150,   151,     3,     4,     5,     6,     7,
       8,    34,    10,    11,    12,    13,    30,    30,    30,    22,
      30,    18,     9,    34,    32,    23,    24,    25,    19,    30,
       3,     4,    30,    31,     3,     4,    32,    35,    36,     8,
       5,    10,    11,    12,    13,    16,    87,     3,     4,    23,
      23,    24,    25,    25,    23,    24,    25,    30,    31,    41,
      40,    30,    31,     3,     4,    72,    35,    23,    24,    25,
      37,   125,   151,    -1,   150,    31,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    31
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,     6,     7,    38,    39,    40,    41,    42,    43,
      44,    50,    55,    44,     0,    40,    29,    30,     4,    51,
      52,    64,    45,    64,    45,    29,    30,    31,    46,    46,
      52,    64,    44,    56,    57,    58,    22,    33,    22,    64,
      32,    29,     3,    23,    24,    25,    31,    35,    53,    64,
      66,    68,    70,    71,    72,    75,    76,    76,    81,    35,
      47,    81,    33,    59,    60,    35,    61,    58,    72,    72,
      72,    66,    54,    31,    33,    69,    26,    27,    28,    24,
      25,    34,    47,    48,    49,    34,    33,    62,    32,    36,
      53,    66,    73,    74,    66,    33,    72,    72,    72,    75,
      75,    36,    29,    66,     8,    10,    11,    12,    13,    30,
      36,    41,    44,    61,    63,    65,    66,    68,    32,    29,
      34,    66,    47,    34,    31,    31,    30,    30,    30,    66,
      30,    22,    66,    34,    67,    76,    77,    78,    79,    80,
      67,    30,    66,    32,    14,    15,    20,    21,    16,    17,
      18,    19,    32,    30,    65,    76,    76,    76,    76,    77,
      77,    78,    79,    65,     9,    65
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    44,    44,    45,    46,    46,    47,    47,    48,
      48,    49,    49,    50,    51,    51,    52,    52,    53,    53,
      54,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    60,    61,    62,    62,    63,    63,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      67,    68,    68,    69,    69,    70,    70,    70,    71,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    75,    75,
      75,    75,    76,    76,    76,    77,    77,    77,    77,    77,
      78,    78,    78,    79,    79,    80,    80,    81
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     1,     3,
       3,     2,     1,     1,     4,     0,     4,     1,     3,     0,
       1,     3,     1,     3,     1,     3,     2,     4,     1,     3,
       0,     2,     6,     0,     1,     3,     1,     3,     0,     1,
       2,     4,     3,     0,     2,     1,     1,     1,     4,     2,
       1,     1,     5,     7,     5,     2,     2,     2,     3,     1,
       1,     2,     1,     3,     4,     3,     1,     1,     1,     1,
       4,     2,     2,     2,     0,     1,     1,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1
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
  "func_def", "func_f_params", "real_func_f_params", "func_f_param",
  "array_dims_func_param", "array_dims_func_param_real", "block",
  "block_elements", "block_item", "ident", "stmt", "exp", "cond", "l_val",
  "array_indices", "primary_exp", "number", "unary_exp", "func_r_params",
  "func_r_params_elements", "mul_exp", "add_exp", "rel_exp", "eq_exp",
  "l_and_exp", "l_or_exp", "const_exp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    66,    66,    73,    74,    79,    80,    85,    86,    92,
      93,    96,   100,   101,   105,   111,   112,   117,   118,   123,
     124,   129,   130,   135,   142,   143,   148,   149,   154,   155,
     159,   160,   164,   174,   175,   180,   181,   185,   194,   195,
     200,   201,   205,   209,   210,   215,   216,   219,   223,   224,
     225,   226,   227,   229,   230,   231,   232,   233,   234,   239,
     242,   246,   247,   252,   253,   258,   259,   260,   264,   268,
     269,   270,   271,   276,   286,   287,   292,   293,   298,   299,
     300,   301,   306,   307,   308,   313,   314,   315,   316,   317,
     322,   323,   324,   329,   330,   335,   336,   340
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
#line 2173 "parser.cc"

#line 343 "parser.yy"


