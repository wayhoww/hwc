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

      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<arithmetic_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<block_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dims: // array_dims
        value.YY_MOVE_OR_COPY< ptr_list_of<const_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.YY_MOVE_OR_COPY< ptr_list_of<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_primary_exp: // primary_exp
      case symbol_kind::S_unary_exp: // unary_exp
      case symbol_kind::S_mul_exp: // mul_exp
      case symbol_kind::S_add_exp: // add_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<arithmetic_exp_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_cond: // cond
        value.YY_MOVE_OR_COPY< std::shared_ptr<cond_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.YY_MOVE_OR_COPY< std::shared_ptr<const_decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_def: // const_def
        value.YY_MOVE_OR_COPY< std::shared_ptr<const_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_exp: // const_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<const_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.YY_MOVE_OR_COPY< std::shared_ptr<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl: // decl
        value.YY_MOVE_OR_COPY< std::shared_ptr<decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_eq_exp: // eq_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<eq_exp_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_l_and_exp: // l_and_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<l_and_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_l_or_exp: // l_or_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<l_or_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_l_val: // l_val
        value.YY_MOVE_OR_COPY< std::shared_ptr<l_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.YY_MOVE_OR_COPY< std::shared_ptr<number_literal_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_rel_exp: // rel_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<rel_exp_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.move< ptr_list_of<arithmetic_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.move< ptr_list_of<block_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dims: // array_dims
        value.move< ptr_list_of<const_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
        value.move< ptr_list_of<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
        value.move< ptr_list_of<init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.move< ptr_list_of<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_primary_exp: // primary_exp
      case symbol_kind::S_unary_exp: // unary_exp
      case symbol_kind::S_mul_exp: // mul_exp
      case symbol_kind::S_add_exp: // add_exp
        value.move< std::shared_ptr<arithmetic_exp_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_cond: // cond
        value.move< std::shared_ptr<cond_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.move< std::shared_ptr<const_decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_def: // const_def
        value.move< std::shared_ptr<const_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_exp: // const_exp
        value.move< std::shared_ptr<const_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.move< std::shared_ptr<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl: // decl
        value.move< std::shared_ptr<decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_eq_exp: // eq_exp
        value.move< std::shared_ptr<eq_exp_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_l_and_exp: // l_and_exp
        value.move< std::shared_ptr<l_and_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_l_or_exp: // l_or_exp
        value.move< std::shared_ptr<l_or_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_l_val: // l_val
        value.move< std::shared_ptr<l_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.move< std::shared_ptr<number_literal_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_rel_exp: // rel_exp
        value.move< std::shared_ptr<rel_exp_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.copy< ptr_list_of<arithmetic_exp_t> > (that.value);
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.copy< ptr_list_of<block_item_t> > (that.value);
        break;

      case symbol_kind::S_array_dims: // array_dims
        value.copy< ptr_list_of<const_exp_t> > (that.value);
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
        value.copy< ptr_list_of<const_init_val_t> > (that.value);
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
        value.copy< ptr_list_of<init_val_t> > (that.value);
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.copy< ptr_list_of<var_def_t> > (that.value);
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_primary_exp: // primary_exp
      case symbol_kind::S_unary_exp: // unary_exp
      case symbol_kind::S_mul_exp: // mul_exp
      case symbol_kind::S_add_exp: // add_exp
        value.copy< std::shared_ptr<arithmetic_exp_t> > (that.value);
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

      case symbol_kind::S_cond: // cond
        value.copy< std::shared_ptr<cond_t> > (that.value);
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.copy< std::shared_ptr<const_decl_t> > (that.value);
        break;

      case symbol_kind::S_const_def: // const_def
        value.copy< std::shared_ptr<const_def_t> > (that.value);
        break;

      case symbol_kind::S_const_exp: // const_exp
        value.copy< std::shared_ptr<const_exp_t> > (that.value);
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.copy< std::shared_ptr<const_init_val_t> > (that.value);
        break;

      case symbol_kind::S_decl: // decl
        value.copy< std::shared_ptr<decl_t> > (that.value);
        break;

      case symbol_kind::S_eq_exp: // eq_exp
        value.copy< std::shared_ptr<eq_exp_t> > (that.value);
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

      case symbol_kind::S_l_and_exp: // l_and_exp
        value.copy< std::shared_ptr<l_and_exp_t> > (that.value);
        break;

      case symbol_kind::S_l_or_exp: // l_or_exp
        value.copy< std::shared_ptr<l_or_exp_t> > (that.value);
        break;

      case symbol_kind::S_l_val: // l_val
        value.copy< std::shared_ptr<l_val_t> > (that.value);
        break;

      case symbol_kind::S_number: // number
        value.copy< std::shared_ptr<number_literal_t> > (that.value);
        break;

      case symbol_kind::S_rel_exp: // rel_exp
        value.copy< std::shared_ptr<rel_exp_t> > (that.value);
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

      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.move< ptr_list_of<arithmetic_exp_t> > (that.value);
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.move< ptr_list_of<block_item_t> > (that.value);
        break;

      case symbol_kind::S_array_dims: // array_dims
        value.move< ptr_list_of<const_exp_t> > (that.value);
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
        value.move< ptr_list_of<const_init_val_t> > (that.value);
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
        value.move< ptr_list_of<init_val_t> > (that.value);
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.move< ptr_list_of<var_def_t> > (that.value);
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_primary_exp: // primary_exp
      case symbol_kind::S_unary_exp: // unary_exp
      case symbol_kind::S_mul_exp: // mul_exp
      case symbol_kind::S_add_exp: // add_exp
        value.move< std::shared_ptr<arithmetic_exp_t> > (that.value);
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

      case symbol_kind::S_cond: // cond
        value.move< std::shared_ptr<cond_t> > (that.value);
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.move< std::shared_ptr<const_decl_t> > (that.value);
        break;

      case symbol_kind::S_const_def: // const_def
        value.move< std::shared_ptr<const_def_t> > (that.value);
        break;

      case symbol_kind::S_const_exp: // const_exp
        value.move< std::shared_ptr<const_exp_t> > (that.value);
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.move< std::shared_ptr<const_init_val_t> > (that.value);
        break;

      case symbol_kind::S_decl: // decl
        value.move< std::shared_ptr<decl_t> > (that.value);
        break;

      case symbol_kind::S_eq_exp: // eq_exp
        value.move< std::shared_ptr<eq_exp_t> > (that.value);
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

      case symbol_kind::S_l_and_exp: // l_and_exp
        value.move< std::shared_ptr<l_and_exp_t> > (that.value);
        break;

      case symbol_kind::S_l_or_exp: // l_or_exp
        value.move< std::shared_ptr<l_or_exp_t> > (that.value);
        break;

      case symbol_kind::S_l_val: // l_val
        value.move< std::shared_ptr<l_val_t> > (that.value);
        break;

      case symbol_kind::S_number: // number
        value.move< std::shared_ptr<number_literal_t> > (that.value);
        break;

      case symbol_kind::S_rel_exp: // rel_exp
        value.move< std::shared_ptr<rel_exp_t> > (that.value);
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

      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        yylhs.value.emplace< ptr_list_of<arithmetic_exp_t> > ();
        break;

      case symbol_kind::S_block_elements: // block_elements
        yylhs.value.emplace< ptr_list_of<block_item_t> > ();
        break;

      case symbol_kind::S_array_dims: // array_dims
        yylhs.value.emplace< ptr_list_of<const_exp_t> > ();
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
        yylhs.value.emplace< ptr_list_of<const_init_val_t> > ();
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
        yylhs.value.emplace< ptr_list_of<init_val_t> > ();
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        yylhs.value.emplace< ptr_list_of<var_def_t> > ();
        break;

      case symbol_kind::S_exp: // exp
      case symbol_kind::S_primary_exp: // primary_exp
      case symbol_kind::S_unary_exp: // unary_exp
      case symbol_kind::S_mul_exp: // mul_exp
      case symbol_kind::S_add_exp: // add_exp
        yylhs.value.emplace< std::shared_ptr<arithmetic_exp_t> > ();
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

      case symbol_kind::S_cond: // cond
        yylhs.value.emplace< std::shared_ptr<cond_t> > ();
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        yylhs.value.emplace< std::shared_ptr<const_decl_t> > ();
        break;

      case symbol_kind::S_const_def: // const_def
        yylhs.value.emplace< std::shared_ptr<const_def_t> > ();
        break;

      case symbol_kind::S_const_exp: // const_exp
        yylhs.value.emplace< std::shared_ptr<const_exp_t> > ();
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        yylhs.value.emplace< std::shared_ptr<const_init_val_t> > ();
        break;

      case symbol_kind::S_decl: // decl
        yylhs.value.emplace< std::shared_ptr<decl_t> > ();
        break;

      case symbol_kind::S_eq_exp: // eq_exp
        yylhs.value.emplace< std::shared_ptr<eq_exp_t> > ();
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

      case symbol_kind::S_l_and_exp: // l_and_exp
        yylhs.value.emplace< std::shared_ptr<l_and_exp_t> > ();
        break;

      case symbol_kind::S_l_or_exp: // l_or_exp
        yylhs.value.emplace< std::shared_ptr<l_or_exp_t> > ();
        break;

      case symbol_kind::S_l_val: // l_val
        yylhs.value.emplace< std::shared_ptr<l_val_t> > ();
        break;

      case symbol_kind::S_number: // number
        yylhs.value.emplace< std::shared_ptr<number_literal_t> > ();
        break;

      case symbol_kind::S_rel_exp: // rel_exp
        yylhs.value.emplace< std::shared_ptr<rel_exp_t> > ();
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
#line 65 "parser.yy"
                        {
    drv.compile(yystack_[0].value.as < std::shared_ptr<comp_unit_t> > ());
}
#line 1247 "parser.cc"
    break;

  case 3: // comp_unit: comp_unit_item
#line 72 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<comp_unit_t> > () = std::make_shared<comp_unit_t>(); yylhs.value.as < std::shared_ptr<comp_unit_t> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<comp_unit_item_t> > ());          }
#line 1253 "parser.cc"
    break;

  case 4: // comp_unit: comp_unit comp_unit_item
#line 73 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<comp_unit_t> > () = yystack_[1].value.as < std::shared_ptr<comp_unit_t> > (); yylhs.value.as < std::shared_ptr<comp_unit_t> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<comp_unit_item_t> > ()); }
#line 1259 "parser.cc"
    break;

  case 5: // comp_unit_item: func_def
#line 78 "parser.yy"
                { yylhs.value.as < std::shared_ptr<comp_unit_item_t> > () = std::make_shared<comp_unit_item_func_def_t>(yystack_[0].value.as < std::shared_ptr<func_def_t> > ()); }
#line 1265 "parser.cc"
    break;

  case 6: // comp_unit_item: decl
#line 79 "parser.yy"
                { yylhs.value.as < std::shared_ptr<comp_unit_item_t> > () = std::make_shared<comp_unit_item_decl_t>(yystack_[0].value.as < std::shared_ptr<decl_t> > ());     }
#line 1271 "parser.cc"
    break;

  case 7: // decl: const_decl_stmt
#line 84 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<decl_t> > () = std::make_shared<decl_const_decl_t>(yystack_[0].value.as < std::shared_ptr<const_decl_t> > ()); }
#line 1277 "parser.cc"
    break;

  case 8: // decl: var_decl
#line 85 "parser.yy"
               { yylhs.value.as < std::shared_ptr<decl_t> > () = std::make_shared<decl_var_decl_t>(yystack_[0].value.as < std::shared_ptr<var_decl_t> > ());   }
#line 1283 "parser.cc"
    break;

  case 9: // const_decl: "const" b_type const_def
#line 91 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<const_decl_t> > () = std::make_shared<const_decl_t>(); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->b_type = yystack_[1].value.as < std::shared_ptr<b_type_t> > (); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->const_defs.push_back(yystack_[0].value.as < std::shared_ptr<const_def_t> > ()); }
#line 1289 "parser.cc"
    break;

  case 10: // const_decl: const_decl "," const_def
#line 92 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<const_decl_t> > () = yystack_[2].value.as < std::shared_ptr<const_decl_t> > (); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->const_defs.push_back(yystack_[0].value.as < std::shared_ptr<const_def_t> > ());}
#line 1295 "parser.cc"
    break;

  case 11: // const_decl_stmt: const_decl ";"
#line 95 "parser.yy"
                                { yylhs.value.as < std::shared_ptr<const_decl_t> > () = yystack_[1].value.as < std::shared_ptr<const_decl_t> > (); }
#line 1301 "parser.cc"
    break;

  case 12: // b_type: "int"
#line 99 "parser.yy"
          { yylhs.value.as < std::shared_ptr<b_type_t> > () = std::make_shared<b_type_t>(b_type_t::INT); }
#line 1307 "parser.cc"
    break;

  case 13: // b_type: "void"
#line 100 "parser.yy"
           { yylhs.value.as < std::shared_ptr<b_type_t> > () = std::make_shared<b_type_t>(b_type_t::VOID); }
#line 1313 "parser.cc"
    break;

  case 14: // const_def: ident array_dims "=" const_init_val
#line 104 "parser.yy"
                                               {
    yylhs.value.as < std::shared_ptr<const_def_t> > () = std::make_shared<const_def_t>(yystack_[3].value.as < std::string > (), yystack_[2].value.as < ptr_list_of<const_exp_t> > (), yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ());
}
#line 1321 "parser.cc"
    break;

  case 15: // array_dims: %empty
#line 110 "parser.yy"
           {}
#line 1327 "parser.cc"
    break;

  case 16: // array_dims: array_dims "[" const_exp "]"
#line 111 "parser.yy"
                                 { yylhs.value.as < ptr_list_of<const_exp_t> > () = yystack_[3].value.as < ptr_list_of<const_exp_t> > (); yylhs.value.as < ptr_list_of<const_exp_t> > ().push_back(yystack_[1].value.as < std::shared_ptr<const_exp_t> > ()); }
#line 1333 "parser.cc"
    break;

  case 17: // const_init_val: const_exp
#line 116 "parser.yy"
              { yylhs.value.as < std::shared_ptr<const_init_val_t> > () = std::make_shared<const_init_val_scalar_t>(yystack_[0].value.as < std::shared_ptr<const_exp_t> > ()); }
#line 1339 "parser.cc"
    break;

  case 18: // const_init_val: "{" const_array_elements "}"
#line 117 "parser.yy"
                                 { yylhs.value.as < std::shared_ptr<const_init_val_t> > () = std::make_shared<const_init_val_array_t>(yystack_[1].value.as < ptr_list_of<const_init_val_t> > ()); }
#line 1345 "parser.cc"
    break;

  case 19: // const_array_elements: %empty
#line 122 "parser.yy"
           {}
#line 1351 "parser.cc"
    break;

  case 20: // const_array_elements: const_array_elements "," const_init_val
#line 123 "parser.yy"
                                            { yylhs.value.as < ptr_list_of<const_init_val_t> > () = yystack_[2].value.as < ptr_list_of<const_init_val_t> > (); yylhs.value.as < ptr_list_of<const_init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ()); }
#line 1357 "parser.cc"
    break;

  case 21: // var_decl: b_type var_def_list ";"
#line 128 "parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<var_decl_t> > () = std::make_shared<var_decl_t>(yystack_[2].value.as < std::shared_ptr<b_type_t> > (), yystack_[1].value.as < ptr_list_of<var_def_t> > ());
    }
#line 1365 "parser.cc"
    break;

  case 22: // var_def_list: var_def
#line 135 "parser.yy"
            { yylhs.value.as < ptr_list_of<var_def_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<var_def_t> > ()); }
#line 1371 "parser.cc"
    break;

  case 23: // var_def_list: var_def_list "," var_def
#line 136 "parser.yy"
                             { yylhs.value.as < ptr_list_of<var_def_t> > () = yystack_[2].value.as < ptr_list_of<var_def_t> > (); yylhs.value.as < ptr_list_of<var_def_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<var_def_t> > ()); }
#line 1377 "parser.cc"
    break;

  case 24: // var_def: ident array_dims
#line 141 "parser.yy"
                                    { yylhs.value.as < std::shared_ptr<var_def_t> > () = std::make_shared<var_def_only_t>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ptr_list_of<const_exp_t> > ()); }
#line 1383 "parser.cc"
    break;

  case 25: // var_def: ident array_dims "=" init_val
#line 142 "parser.yy"
                                    { yylhs.value.as < std::shared_ptr<var_def_t> > () = std::make_shared<var_def_init_t>(yystack_[3].value.as < std::string > (), yystack_[2].value.as < ptr_list_of<const_exp_t> > (), yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1389 "parser.cc"
    break;

  case 26: // init_val: exp
#line 147 "parser.yy"
        { yylhs.value.as < std::shared_ptr<init_val_t> > () = std::make_shared<init_val_scalar_t>(yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1395 "parser.cc"
    break;

  case 27: // init_val: "{" init_array_elements "}"
#line 148 "parser.yy"
                                {{ yylhs.value.as < std::shared_ptr<init_val_t> > () = std::make_shared<init_val_array_t>(yystack_[1].value.as < ptr_list_of<init_val_t> > ()); }}
#line 1401 "parser.cc"
    break;

  case 28: // init_array_elements: %empty
#line 152 "parser.yy"
           {}
#line 1407 "parser.cc"
    break;

  case 29: // init_array_elements: init_array_elements init_val
#line 153 "parser.yy"
                                 { yylhs.value.as < ptr_list_of<init_val_t> > () = yystack_[1].value.as < ptr_list_of<init_val_t> > (); yylhs.value.as < ptr_list_of<init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1413 "parser.cc"
    break;

  case 30: // func_def: b_type ident "(" func_f_params ")" block
#line 157 "parser.yy"
                                                   {
    yylhs.value.as < std::shared_ptr<func_def_t> > () = std::make_shared<func_def_t>();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->func_type = yystack_[5].value.as < std::shared_ptr<b_type_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->ident = yystack_[4].value.as < std::string > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->params = yystack_[2].value.as < std::shared_ptr<func_f_params_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->block = yystack_[0].value.as < std::shared_ptr<block_t> > ();
}
#line 1425 "parser.cc"
    break;

  case 31: // func_f_params: %empty
#line 167 "parser.yy"
           { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = std::make_shared<func_f_params_t>(); }
#line 1431 "parser.cc"
    break;

  case 32: // func_f_params: real_func_f_params
#line 168 "parser.yy"
                       { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = yystack_[0].value.as < std::shared_ptr<func_f_params_t> > (); }
#line 1437 "parser.cc"
    break;

  case 33: // real_func_f_params: real_func_f_params "," func_f_param
#line 173 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = yystack_[2].value.as < std::shared_ptr<func_f_params_t> > (); yylhs.value.as < std::shared_ptr<func_f_params_t> > ()->params.push_back(yystack_[0].value.as < std::shared_ptr<func_f_param_t> > ()); }
#line 1443 "parser.cc"
    break;

  case 34: // real_func_f_params: func_f_param
#line 174 "parser.yy"
                 { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = std::make_shared<func_f_params_t>(); yylhs.value.as < std::shared_ptr<func_f_params_t> > ()->params.push_back(yystack_[0].value.as < std::shared_ptr<func_f_param_t> > ()); }
#line 1449 "parser.cc"
    break;

  case 35: // func_f_param: b_type ident array_dims_func_param
#line 178 "parser.yy"
                                                 {
    yylhs.value.as < std::shared_ptr<func_f_param_t> > () = std::make_shared<func_f_param_t>();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->b_type = yystack_[2].value.as < std::shared_ptr<b_type_t> > ();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->ident = yystack_[1].value.as < std::string > ();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->array_dims = yystack_[0].value.as < ptr_list_of<arithmetic_exp_t> > ();
}
#line 1460 "parser.cc"
    break;

  case 36: // array_dims_func_param: %empty
#line 187 "parser.yy"
           {}
#line 1466 "parser.cc"
    break;

  case 37: // array_dims_func_param: array_dims_func_param_real
#line 188 "parser.yy"
                               { yylhs.value.as < ptr_list_of<arithmetic_exp_t> > () = yystack_[0].value.as < ptr_list_of<arithmetic_exp_t> > (); }
#line 1472 "parser.cc"
    break;

  case 38: // array_dims_func_param_real: "[" "]"
#line 193 "parser.yy"
            { yylhs.value.as < ptr_list_of<arithmetic_exp_t> > ().push_back(nullptr); }
#line 1478 "parser.cc"
    break;

  case 39: // array_dims_func_param_real: array_dims_func_param_real "[" exp "]"
#line 194 "parser.yy"
                                           { yylhs.value.as < ptr_list_of<arithmetic_exp_t> > () = yystack_[3].value.as < ptr_list_of<arithmetic_exp_t> > (); yylhs.value.as < ptr_list_of<arithmetic_exp_t> > ().push_back(yystack_[1].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1484 "parser.cc"
    break;

  case 40: // block: "{" block_elements "}"
#line 198 "parser.yy"
                              { yylhs.value.as < std::shared_ptr<block_t> > () = std::make_shared<block_t>(yystack_[1].value.as < ptr_list_of<block_item_t> > ()); }
#line 1490 "parser.cc"
    break;

  case 41: // block_elements: %empty
#line 202 "parser.yy"
           {}
#line 1496 "parser.cc"
    break;

  case 42: // block_elements: block_elements block_item
#line 203 "parser.yy"
                              { yylhs.value.as < ptr_list_of<block_item_t> > () = yystack_[1].value.as < ptr_list_of<block_item_t> > (); yylhs.value.as < ptr_list_of<block_item_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<block_item_t> > ()); }
#line 1502 "parser.cc"
    break;

  case 43: // block_item: decl
#line 208 "parser.yy"
         { yylhs.value.as < std::shared_ptr<block_item_t> > () = std::make_shared<block_item_decl_t>(yystack_[0].value.as < std::shared_ptr<decl_t> > ()); }
#line 1508 "parser.cc"
    break;

  case 44: // block_item: stmt
#line 209 "parser.yy"
         { yylhs.value.as < std::shared_ptr<block_item_t> > () = std::make_shared<block_item_stmt_t>(yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1514 "parser.cc"
    break;

  case 45: // ident: "identifier"
#line 212 "parser.yy"
             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1520 "parser.cc"
    break;

  case 46: // stmt: l_val "=" exp ";"
#line 216 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_assign_t>(yystack_[3].value.as < std::shared_ptr<l_val_t> > (), yystack_[1].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1526 "parser.cc"
    break;

  case 47: // stmt: exp ";"
#line 217 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_exp_t>(yystack_[1].value.as < std::shared_ptr<arithmetic_exp_t> > ());        }
#line 1532 "parser.cc"
    break;

  case 48: // stmt: ";"
#line 218 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::shared_ptr<stmt_exp_t>(nullptr);    }
#line 1538 "parser.cc"
    break;

  case 49: // stmt: block
#line 219 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_block_t>(yystack_[0].value.as < std::shared_ptr<block_t> > ());      }
#line 1544 "parser.cc"
    break;

  case 50: // stmt: "if" "(" cond ")" stmt
#line 220 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_if_t>(yystack_[2].value.as < std::shared_ptr<cond_t> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > (), nullptr); }
#line 1550 "parser.cc"
    break;

  case 51: // stmt: "if" "(" cond ")" stmt "else" stmt
#line 222 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_if_t>(yystack_[4].value.as < std::shared_ptr<cond_t> > (), yystack_[2].value.as < std::shared_ptr<stmt_t> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1556 "parser.cc"
    break;

  case 52: // stmt: "while" "(" cond ")" stmt
#line 223 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_while_t>(yystack_[2].value.as < std::shared_ptr<cond_t> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1562 "parser.cc"
    break;

  case 53: // stmt: "break" ";"
#line 224 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_break_t>();       }
#line 1568 "parser.cc"
    break;

  case 54: // stmt: "continue" ";"
#line 225 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_continue_t>();    }
#line 1574 "parser.cc"
    break;

  case 55: // stmt: "return" ";"
#line 226 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_return_t>(nullptr); }
#line 1580 "parser.cc"
    break;

  case 56: // stmt: "return" exp ";"
#line 227 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_return_t>(yystack_[1].value.as < std::shared_ptr<arithmetic_exp_t> > ());    }
#line 1586 "parser.cc"
    break;

  case 57: // exp: add_exp
#line 232 "parser.yy"
             { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > (); }
#line 1592 "parser.cc"
    break;

  case 58: // cond: l_or_exp
#line 235 "parser.yy"
               { yylhs.value.as < std::shared_ptr<cond_t> > () = std::make_shared<cond_l_or_t>(yystack_[0].value.as < std::shared_ptr<l_or_exp_t> > ()); }
#line 1598 "parser.cc"
    break;

  case 59: // l_val: ident array_indices
#line 239 "parser.yy"
                        { yylhs.value.as < std::shared_ptr<l_val_t> > () = std::make_shared<l_val_t>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ptr_list_of<arithmetic_exp_t> > ()); }
#line 1604 "parser.cc"
    break;

  case 60: // l_val: ident
#line 240 "parser.yy"
          { yylhs.value.as < std::shared_ptr<l_val_t> > ()=std::make_shared<l_val_t>(yystack_[0].value.as < std::string > (), ptr_list_of<arithmetic_exp_t>()); }
#line 1610 "parser.cc"
    break;

  case 61: // array_indices: "[" exp "]"
#line 245 "parser.yy"
                 {{ yylhs.value.as < ptr_list_of<arithmetic_exp_t> > ().push_back(yystack_[1].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }}
#line 1616 "parser.cc"
    break;

  case 62: // array_indices: array_indices "[" exp "]"
#line 246 "parser.yy"
                               { yylhs.value.as < ptr_list_of<arithmetic_exp_t> > () = yystack_[3].value.as < ptr_list_of<arithmetic_exp_t> > (); yylhs.value.as < ptr_list_of<arithmetic_exp_t> > ().push_back(yystack_[1].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1622 "parser.cc"
    break;

  case 63: // primary_exp: "(" exp ")"
#line 251 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = yystack_[1].value.as < std::shared_ptr<arithmetic_exp_t> > ();     }
#line 1628 "parser.cc"
    break;

  case 64: // primary_exp: l_val
#line 252 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = yystack_[0].value.as < std::shared_ptr<l_val_t> > ();   }
#line 1634 "parser.cc"
    break;

  case 65: // primary_exp: number
#line 253 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = yystack_[0].value.as < std::shared_ptr<number_literal_t> > ();  }
#line 1640 "parser.cc"
    break;

  case 66: // number: "integer"
#line 257 "parser.yy"
                  { yylhs.value.as < std::shared_ptr<number_literal_t> > () = std::make_shared<number_literal_t>(yystack_[0].value.as < long long > ()); }
#line 1646 "parser.cc"
    break;

  case 67: // unary_exp: primary_exp
#line 261 "parser.yy"
                  { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > (); }
#line 1652 "parser.cc"
    break;

  case 68: // unary_exp: ident "(" func_r_params ")"
#line 262 "parser.yy"
                                { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = std::make_shared<func_call_t>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<func_r_params_t> > ()); }
#line 1658 "parser.cc"
    break;

  case 69: // unary_exp: "+" unary_exp
#line 263 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > (); }
#line 1664 "parser.cc"
    break;

  case 70: // unary_exp: "-" unary_exp
#line 264 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > (); yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > ()->toggle_sign(); }
#line 1670 "parser.cc"
    break;

  case 71: // func_r_params: %empty
#line 271 "parser.yy"
                { yylhs.value.as < std::shared_ptr<func_r_params_t> > () = std::make_shared<func_r_params_t>(); }
#line 1676 "parser.cc"
    break;

  case 72: // func_r_params: func_r_params_elements
#line 272 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<func_r_params_t> > () = std::make_shared<func_r_params_t>(yystack_[0].value.as < ptr_list_of<arithmetic_exp_t> > ()); }
#line 1682 "parser.cc"
    break;

  case 73: // func_r_params_elements: exp
#line 277 "parser.yy"
                                     { yylhs.value.as < ptr_list_of<arithmetic_exp_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ());            }
#line 1688 "parser.cc"
    break;

  case 74: // func_r_params_elements: func_r_params_elements "," exp
#line 278 "parser.yy"
                                     { yylhs.value.as < ptr_list_of<arithmetic_exp_t> > () = yystack_[2].value.as < ptr_list_of<arithmetic_exp_t> > (); yylhs.value.as < ptr_list_of<arithmetic_exp_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ());   }
#line 1694 "parser.cc"
    break;

  case 75: // mul_exp: unary_exp
#line 283 "parser.yy"
               { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > (); }
#line 1700 "parser.cc"
    break;

  case 76: // mul_exp: mul_exp "*" unary_exp
#line 284 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = std::make_shared<binary_arithmetic_exp_t>(operator_t::MULTIPLY, yystack_[2].value.as < std::shared_ptr<arithmetic_exp_t> > (), yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1706 "parser.cc"
    break;

  case 77: // mul_exp: mul_exp "/" unary_exp
#line 285 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = std::make_shared<binary_arithmetic_exp_t>(operator_t::DIVIDE  , yystack_[2].value.as < std::shared_ptr<arithmetic_exp_t> > (), yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1712 "parser.cc"
    break;

  case 78: // mul_exp: mul_exp "%" unary_exp
#line 286 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = std::make_shared<binary_arithmetic_exp_t>(operator_t::MODULE  , yystack_[2].value.as < std::shared_ptr<arithmetic_exp_t> > (), yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1718 "parser.cc"
    break;

  case 79: // add_exp: mul_exp
#line 291 "parser.yy"
             { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > (); }
#line 1724 "parser.cc"
    break;

  case 80: // add_exp: add_exp "+" mul_exp
#line 292 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = std::make_shared<binary_arithmetic_exp_t>(operator_t::PLUS,  yystack_[2].value.as < std::shared_ptr<arithmetic_exp_t> > (), yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1730 "parser.cc"
    break;

  case 81: // add_exp: add_exp "-" mul_exp
#line 293 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<arithmetic_exp_t> > () = std::make_shared<binary_arithmetic_exp_t>(operator_t::MINUS, yystack_[2].value.as < std::shared_ptr<arithmetic_exp_t> > (), yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1736 "parser.cc"
    break;

  case 82: // rel_exp: add_exp
#line 298 "parser.yy"
             { yylhs.value.as < std::shared_ptr<rel_exp_t> > () = std::make_shared<rel_exp_add_t>(yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1742 "parser.cc"
    break;

  case 83: // rel_exp: rel_exp "<" add_exp
#line 299 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<rel_exp_t> > () = std::make_shared<rel_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<rel_exp_t> > (), std::make_shared<operator_t>(operator_t::LESS), yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1748 "parser.cc"
    break;

  case 84: // rel_exp: rel_exp ">" add_exp
#line 300 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<rel_exp_t> > () = std::make_shared<rel_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<rel_exp_t> > (), std::make_shared<operator_t>(operator_t::GREATER), yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1754 "parser.cc"
    break;

  case 85: // rel_exp: rel_exp "<=" add_exp
#line 301 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<rel_exp_t> > () = std::make_shared<rel_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<rel_exp_t> > (), std::make_shared<operator_t>(operator_t::LESS_EQUAL), yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1760 "parser.cc"
    break;

  case 86: // rel_exp: rel_exp ">=" add_exp
#line 302 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<rel_exp_t> > () = std::make_shared<rel_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<rel_exp_t> > (), std::make_shared<operator_t>(operator_t::GREATER_EQUAL), yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1766 "parser.cc"
    break;

  case 87: // eq_exp: rel_exp
#line 307 "parser.yy"
             { yylhs.value.as < std::shared_ptr<eq_exp_t> > () = std::make_shared<eq_exp_rel_t>(yystack_[0].value.as < std::shared_ptr<rel_exp_t> > ()); }
#line 1772 "parser.cc"
    break;

  case 88: // eq_exp: eq_exp "==" rel_exp
#line 308 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<eq_exp_t> > () = std::make_shared<eq_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<eq_exp_t> > (), std::make_shared<operator_t>(operator_t::EQUAL), yystack_[0].value.as < std::shared_ptr<rel_exp_t> > ()); }
#line 1778 "parser.cc"
    break;

  case 89: // eq_exp: eq_exp "!=" rel_exp
#line 309 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<eq_exp_t> > () = std::make_shared<eq_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<eq_exp_t> > (), std::make_shared<operator_t>(operator_t::NOT_EQUAL), yystack_[0].value.as < std::shared_ptr<rel_exp_t> > ()); }
#line 1784 "parser.cc"
    break;

  case 90: // l_and_exp: eq_exp
#line 314 "parser.yy"
            { yylhs.value.as < std::shared_ptr<l_and_exp_t> > () = std::make_shared<l_and_exp_eq_t>(yystack_[0].value.as < std::shared_ptr<eq_exp_t> > ()); }
#line 1790 "parser.cc"
    break;

  case 91: // l_and_exp: l_and_exp "&&" eq_exp
#line 315 "parser.yy"
                            { yylhs.value.as < std::shared_ptr<l_and_exp_t> > () = std::make_shared<l_and_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<l_and_exp_t> > (), yystack_[0].value.as < std::shared_ptr<eq_exp_t> > ()); }
#line 1796 "parser.cc"
    break;

  case 92: // l_or_exp: l_and_exp
#line 320 "parser.yy"
               { yylhs.value.as < std::shared_ptr<l_or_exp_t> > () = std::make_shared<l_or_exp_and_t>(yystack_[0].value.as < std::shared_ptr<l_and_exp_t> > ()); }
#line 1802 "parser.cc"
    break;

  case 93: // l_or_exp: l_or_exp "||" l_and_exp
#line 321 "parser.yy"
                              { yylhs.value.as < std::shared_ptr<l_or_exp_t> > () = std::make_shared<l_or_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<l_or_exp_t> > (), yystack_[0].value.as < std::shared_ptr<l_and_exp_t> > ()); }
#line 1808 "parser.cc"
    break;

  case 94: // const_exp: add_exp
#line 325 "parser.yy"
                   { yylhs.value.as < std::shared_ptr<const_exp_t> > () = std::make_shared<const_exp_add_t>(yystack_[0].value.as < std::shared_ptr<arithmetic_exp_t> > ()); }
#line 1814 "parser.cc"
    break;


#line 1818 "parser.cc"

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





  const short parser::yypact_ninf_ = -136;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      57,  -136,  -136,    45,    11,    57,  -136,  -136,    48,  -136,
      12,  -136,  -136,    12,  -136,  -136,    12,  -136,  -136,    50,
    -136,   -11,  -136,  -136,  -136,    12,  -136,    45,   -14,   -12,
    -136,  -136,    12,    -3,    -5,  -136,    31,   126,    65,    -1,
       6,    45,  -136,   126,   126,   126,  -136,  -136,    27,  -136,
    -136,  -136,  -136,  -136,    47,    67,    67,    10,  -136,  -136,
    -136,    23,  -136,    35,  -136,  -136,  -136,  -136,  -136,    39,
      18,   126,   126,    53,   126,   126,   126,   126,   126,  -136,
       1,  -136,   126,   108,  -136,  -136,  -136,  -136,    92,    70,
      91,   126,  -136,  -136,  -136,    47,    47,    65,  -136,    93,
      95,   103,   105,   106,    98,  -136,  -136,  -136,    12,  -136,
    -136,  -136,   107,   120,  -136,   126,  -136,   118,  -136,  -136,
     126,   126,  -136,  -136,  -136,   123,  -136,   126,  -136,  -136,
     122,    67,    13,    77,   137,   139,   124,  -136,   129,   136,
     126,   126,   126,   126,   126,   126,   126,   126,   136,  -136,
     125,    67,    67,    67,    67,    13,    13,    77,   137,  -136,
     136,  -136
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    13,    12,     0,     0,     2,     3,     6,     0,     7,
       0,     8,     5,     0,     1,     4,     0,    11,    45,     0,
      22,    15,     9,    15,    10,     0,    21,    31,    24,     0,
      23,    15,     0,     0,    32,    34,     0,     0,     0,    36,
       0,     0,    66,     0,     0,     0,    28,    25,    60,    26,
      64,    67,    65,    75,    79,    57,    94,     0,    19,    14,
      17,     0,    35,    37,    41,    30,    33,    69,    70,     0,
       0,    71,     0,    59,     0,     0,     0,     0,     0,    16,
       0,    38,     0,     0,    63,    27,    29,    73,     0,    72,
       0,     0,    76,    77,    78,    80,    81,     0,    18,     0,
       0,     0,     0,     0,     0,    48,    40,    43,     0,    49,
      42,    44,     0,    64,    68,     0,    61,     0,    20,    39,
       0,     0,    53,    54,    55,     0,    47,     0,    74,    62,
       0,    82,    87,    90,    92,    58,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    46,
      50,    86,    85,    84,    83,    88,    89,    91,    93,    52,
       0,    51
  };

  const short
  parser::yypgoto_[] =
  {
    -136,  -136,  -136,   157,    80,  -136,  -136,     3,   148,   144,
      71,  -136,  -136,  -136,   146,    99,  -136,  -136,  -136,  -136,
     131,  -136,  -136,   133,  -136,  -136,    -8,  -135,   -33,    54,
     -73,  -136,  -136,  -136,   -29,  -136,  -136,    19,   -37,   -64,
      28,    29,  -136,   140
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     4,     5,     6,     7,     8,     9,    10,    22,    28,
      59,    80,    11,    19,    20,    47,    70,    12,    33,    34,
      35,    62,    63,   109,    83,   110,    48,   111,   112,   130,
      50,    73,    51,    52,    53,    88,    89,    54,    55,   132,
     133,   134,   135,    60
  };

  const unsigned char
  parser::yytable_[] =
  {
      56,    56,    21,    49,   150,    23,    13,    36,    23,    38,
     113,    14,    69,   159,    67,    68,    18,    31,    37,    27,
      37,    42,    18,    41,    39,   161,   140,   141,    40,    97,
      32,    61,   142,   143,    42,    18,    98,    49,    87,    90,
      64,    43,    44,    79,    32,    92,    93,    94,    45,    99,
       1,     2,    46,    85,    43,    44,    81,    71,   117,    72,
      56,    45,     1,     2,     3,    46,   113,    82,    42,    18,
      84,   125,    74,    75,    76,   113,    16,    17,    25,    26,
     155,   156,   128,   131,   131,    91,   108,   113,    43,    44,
      77,    78,   144,   145,   138,    45,    95,    96,   115,    58,
      31,    42,    18,   151,   152,   153,   154,   131,   131,   131,
     131,    42,    18,     1,     2,     3,   100,   101,   102,   103,
     104,    43,    44,   114,   116,   120,   119,   124,    45,    42,
      18,    43,    44,   121,   122,   123,   126,   105,    45,    42,
      18,   127,    64,   106,   100,   101,   102,   103,   104,    43,
      44,   129,   137,   139,   146,   148,    45,   147,   149,    43,
      44,   160,    15,   107,    24,   105,    45,    29,   118,    86,
      64,    30,    66,    65,   157,   136,   158,    57
  };

  const unsigned char
  parser::yycheck_[] =
  {
      37,    38,    10,    36,   139,    13,     3,    21,    16,    21,
      83,     0,    45,   148,    43,    44,     4,    25,    32,    30,
      32,     3,     4,    28,    32,   160,    13,    14,    31,    28,
      27,    32,    19,    20,     3,     4,    35,    70,    71,    72,
      34,    23,    24,    33,    41,    74,    75,    76,    30,    82,
       5,     6,    34,    35,    23,    24,    33,    30,    91,    32,
      97,    30,     5,     6,     7,    34,   139,    32,     3,     4,
      31,   104,    25,    26,    27,   148,    28,    29,    28,    29,
     144,   145,   115,   120,   121,    32,    83,   160,    23,    24,
      23,    24,    15,    16,   127,    30,    77,    78,    28,    34,
     108,     3,     4,   140,   141,   142,   143,   144,   145,   146,
     147,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    23,    24,    31,    33,    30,    33,    29,    30,     3,
       4,    23,    24,    30,    29,    29,    29,    29,    30,     3,
       4,    21,    34,    35,     8,     9,    10,    11,    12,    23,
      24,    33,    29,    31,    17,    31,    30,    18,    29,    23,
      24,    36,     5,    83,    16,    29,    30,    23,    97,    70,
      34,    25,    41,    40,   146,   121,   147,    37
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,     6,     7,    38,    39,    40,    41,    42,    43,
      44,    49,    54,    44,     0,    40,    28,    29,     4,    50,
      51,    63,    45,    63,    45,    28,    29,    30,    46,    46,
      51,    63,    44,    55,    56,    57,    21,    32,    21,    63,
      31,    28,     3,    23,    24,    30,    34,    52,    63,    65,
      67,    69,    70,    71,    74,    75,    75,    80,    34,    47,
      80,    32,    58,    59,    34,    60,    57,    71,    71,    65,
      53,    30,    32,    68,    25,    26,    27,    23,    24,    33,
      48,    33,    32,    61,    31,    35,    52,    65,    72,    73,
      65,    32,    71,    71,    71,    74,    74,    28,    35,    65,
       8,     9,    10,    11,    12,    29,    35,    41,    44,    60,
      62,    64,    65,    67,    31,    28,    33,    65,    47,    33,
      30,    30,    29,    29,    29,    65,    29,    21,    65,    33,
      66,    75,    76,    77,    78,    79,    66,    29,    65,    31,
      13,    14,    19,    20,    15,    16,    17,    18,    31,    29,
      64,    75,    75,    75,    75,    76,    76,    77,    78,    64,
      36,    64
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    44,    44,    45,    46,    46,    47,    47,    48,
      48,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      54,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      60,    61,    61,    62,    62,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    66,    67,
      67,    68,    68,    69,    69,    69,    70,    71,    71,    71,
      71,    72,    72,    73,    73,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    76,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    80
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     1,     3,
       3,     2,     1,     1,     4,     0,     4,     1,     3,     0,
       3,     3,     1,     3,     2,     4,     1,     3,     0,     2,
       6,     0,     1,     3,     1,     3,     0,     1,     2,     4,
       3,     0,     2,     1,     1,     1,     4,     2,     1,     1,
       5,     7,     5,     2,     2,     2,     3,     1,     1,     2,
       1,     3,     4,     3,     1,     1,     1,     1,     4,     2,
       2,     0,     1,     1,     3,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"integer\"",
  "\"identifier\"", "\"void\"", "\"int\"", "\"const\"", "\"if\"",
  "\"while\"", "\"break\"", "\"continue\"", "\"return\"", "\">=\"",
  "\"<=\"", "\"==\"", "\"!=\"", "\"&&\"", "\"||\"", "\">\"", "\"<\"",
  "\"=\"", "\"!\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"%\"", "\",\"",
  "\";\"", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\"{\"", "\"}\"",
  "\"else\"", "$accept", "start_symbol", "comp_unit", "comp_unit_item",
  "decl", "const_decl", "const_decl_stmt", "b_type", "const_def",
  "array_dims", "const_init_val", "const_array_elements", "var_decl",
  "var_def_list", "var_def", "init_val", "init_array_elements", "func_def",
  "func_f_params", "real_func_f_params", "func_f_param",
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
       0,    65,    65,    72,    73,    78,    79,    84,    85,    91,
      92,    95,    99,   100,   104,   110,   111,   116,   117,   122,
     123,   128,   135,   136,   141,   142,   147,   148,   152,   153,
     157,   167,   168,   173,   174,   178,   187,   188,   193,   194,
     198,   202,   203,   208,   209,   212,   216,   217,   218,   219,
     220,   222,   223,   224,   225,   226,   227,   232,   235,   239,
     240,   245,   246,   251,   252,   253,   257,   261,   262,   263,
     264,   271,   272,   277,   278,   283,   284,   285,   286,   291,
     292,   293,   298,   299,   300,   301,   302,   307,   308,   309,
     314,   315,   320,   321,   325
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
#line 2241 "parser.cc"

#line 328 "parser.yy"


