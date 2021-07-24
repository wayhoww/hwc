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

      case symbol_kind::S_array_dims: // array_dims
        value.YY_MOVE_OR_COPY< ptr_list_of<const_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.YY_MOVE_OR_COPY< ptr_list_of<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_add_exp: // add_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<add_exp_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_exp: // exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_f_param_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_f_params: // func_f_params
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_f_params_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_r_params_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.YY_MOVE_OR_COPY< std::shared_ptr<ident_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_mul_exp: // mul_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<mul_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.YY_MOVE_OR_COPY< std::shared_ptr<number_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_exp: // primary_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<primary_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_rel_exp: // rel_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<rel_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.YY_MOVE_OR_COPY< std::shared_ptr<stmt_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unary_exp: // unary_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<unary_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.YY_MOVE_OR_COPY< std::shared_ptr<var_decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def: // var_def
        value.YY_MOVE_OR_COPY< std::shared_ptr<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // "identifier"
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

      case symbol_kind::S_array_dims: // array_dims
        value.move< ptr_list_of<const_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
        value.move< ptr_list_of<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.move< ptr_list_of<exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
        value.move< ptr_list_of<init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.move< ptr_list_of<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_add_exp: // add_exp
        value.move< std::shared_ptr<add_exp_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_exp: // exp
        value.move< std::shared_ptr<exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.move< std::shared_ptr<func_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.move< std::shared_ptr<func_f_param_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_f_params: // func_f_params
        value.move< std::shared_ptr<func_f_params_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.move< std::shared_ptr<func_r_params_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ident: // ident
        value.move< std::shared_ptr<ident_t> > (YY_MOVE (that.value));
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

      case symbol_kind::S_mul_exp: // mul_exp
        value.move< std::shared_ptr<mul_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.move< std::shared_ptr<number_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_primary_exp: // primary_exp
        value.move< std::shared_ptr<primary_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_rel_exp: // rel_exp
        value.move< std::shared_ptr<rel_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< std::shared_ptr<stmt_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_unary_exp: // unary_exp
        value.move< std::shared_ptr<unary_exp_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< std::shared_ptr<var_decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def: // var_def
        value.move< std::shared_ptr<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // "identifier"
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

      case symbol_kind::S_array_dims: // array_dims
        value.copy< ptr_list_of<const_exp_t> > (that.value);
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
        value.copy< ptr_list_of<const_init_val_t> > (that.value);
        break;

      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.copy< ptr_list_of<exp_t> > (that.value);
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
        value.copy< ptr_list_of<init_val_t> > (that.value);
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.copy< ptr_list_of<var_def_t> > (that.value);
        break;

      case symbol_kind::S_add_exp: // add_exp
        value.copy< std::shared_ptr<add_exp_t> > (that.value);
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

      case symbol_kind::S_exp: // exp
        value.copy< std::shared_ptr<exp_t> > (that.value);
        break;

      case symbol_kind::S_func_def: // func_def
        value.copy< std::shared_ptr<func_def_t> > (that.value);
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.copy< std::shared_ptr<func_f_param_t> > (that.value);
        break;

      case symbol_kind::S_func_f_params: // func_f_params
        value.copy< std::shared_ptr<func_f_params_t> > (that.value);
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.copy< std::shared_ptr<func_r_params_t> > (that.value);
        break;

      case symbol_kind::S_ident: // ident
        value.copy< std::shared_ptr<ident_t> > (that.value);
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

      case symbol_kind::S_mul_exp: // mul_exp
        value.copy< std::shared_ptr<mul_exp_t> > (that.value);
        break;

      case symbol_kind::S_number: // number
        value.copy< std::shared_ptr<number_t> > (that.value);
        break;

      case symbol_kind::S_primary_exp: // primary_exp
        value.copy< std::shared_ptr<primary_exp_t> > (that.value);
        break;

      case symbol_kind::S_rel_exp: // rel_exp
        value.copy< std::shared_ptr<rel_exp_t> > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< std::shared_ptr<stmt_t> > (that.value);
        break;

      case symbol_kind::S_unary_exp: // unary_exp
        value.copy< std::shared_ptr<unary_exp_t> > (that.value);
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.copy< std::shared_ptr<var_decl_t> > (that.value);
        break;

      case symbol_kind::S_var_def: // var_def
        value.copy< std::shared_ptr<var_def_t> > (that.value);
        break;

      case symbol_kind::S_IDENT: // "identifier"
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

      case symbol_kind::S_array_dims: // array_dims
        value.move< ptr_list_of<const_exp_t> > (that.value);
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
        value.move< ptr_list_of<const_init_val_t> > (that.value);
        break;

      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.move< ptr_list_of<exp_t> > (that.value);
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
        value.move< ptr_list_of<init_val_t> > (that.value);
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.move< ptr_list_of<var_def_t> > (that.value);
        break;

      case symbol_kind::S_add_exp: // add_exp
        value.move< std::shared_ptr<add_exp_t> > (that.value);
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

      case symbol_kind::S_exp: // exp
        value.move< std::shared_ptr<exp_t> > (that.value);
        break;

      case symbol_kind::S_func_def: // func_def
        value.move< std::shared_ptr<func_def_t> > (that.value);
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.move< std::shared_ptr<func_f_param_t> > (that.value);
        break;

      case symbol_kind::S_func_f_params: // func_f_params
        value.move< std::shared_ptr<func_f_params_t> > (that.value);
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.move< std::shared_ptr<func_r_params_t> > (that.value);
        break;

      case symbol_kind::S_ident: // ident
        value.move< std::shared_ptr<ident_t> > (that.value);
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

      case symbol_kind::S_mul_exp: // mul_exp
        value.move< std::shared_ptr<mul_exp_t> > (that.value);
        break;

      case symbol_kind::S_number: // number
        value.move< std::shared_ptr<number_t> > (that.value);
        break;

      case symbol_kind::S_primary_exp: // primary_exp
        value.move< std::shared_ptr<primary_exp_t> > (that.value);
        break;

      case symbol_kind::S_rel_exp: // rel_exp
        value.move< std::shared_ptr<rel_exp_t> > (that.value);
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< std::shared_ptr<stmt_t> > (that.value);
        break;

      case symbol_kind::S_unary_exp: // unary_exp
        value.move< std::shared_ptr<unary_exp_t> > (that.value);
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< std::shared_ptr<var_decl_t> > (that.value);
        break;

      case symbol_kind::S_var_def: // var_def
        value.move< std::shared_ptr<var_def_t> > (that.value);
        break;

      case symbol_kind::S_IDENT: // "identifier"
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

      case symbol_kind::S_array_dims: // array_dims
        yylhs.value.emplace< ptr_list_of<const_exp_t> > ();
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
        yylhs.value.emplace< ptr_list_of<const_init_val_t> > ();
        break;

      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        yylhs.value.emplace< ptr_list_of<exp_t> > ();
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
        yylhs.value.emplace< ptr_list_of<init_val_t> > ();
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        yylhs.value.emplace< ptr_list_of<var_def_t> > ();
        break;

      case symbol_kind::S_add_exp: // add_exp
        yylhs.value.emplace< std::shared_ptr<add_exp_t> > ();
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

      case symbol_kind::S_exp: // exp
        yylhs.value.emplace< std::shared_ptr<exp_t> > ();
        break;

      case symbol_kind::S_func_def: // func_def
        yylhs.value.emplace< std::shared_ptr<func_def_t> > ();
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        yylhs.value.emplace< std::shared_ptr<func_f_param_t> > ();
        break;

      case symbol_kind::S_func_f_params: // func_f_params
        yylhs.value.emplace< std::shared_ptr<func_f_params_t> > ();
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        yylhs.value.emplace< std::shared_ptr<func_r_params_t> > ();
        break;

      case symbol_kind::S_ident: // ident
        yylhs.value.emplace< std::shared_ptr<ident_t> > ();
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

      case symbol_kind::S_mul_exp: // mul_exp
        yylhs.value.emplace< std::shared_ptr<mul_exp_t> > ();
        break;

      case symbol_kind::S_number: // number
        yylhs.value.emplace< std::shared_ptr<number_t> > ();
        break;

      case symbol_kind::S_primary_exp: // primary_exp
        yylhs.value.emplace< std::shared_ptr<primary_exp_t> > ();
        break;

      case symbol_kind::S_rel_exp: // rel_exp
        yylhs.value.emplace< std::shared_ptr<rel_exp_t> > ();
        break;

      case symbol_kind::S_stmt: // stmt
        yylhs.value.emplace< std::shared_ptr<stmt_t> > ();
        break;

      case symbol_kind::S_unary_exp: // unary_exp
        yylhs.value.emplace< std::shared_ptr<unary_exp_t> > ();
        break;

      case symbol_kind::S_var_decl: // var_decl
        yylhs.value.emplace< std::shared_ptr<var_decl_t> > ();
        break;

      case symbol_kind::S_var_def: // var_def
        yylhs.value.emplace< std::shared_ptr<var_def_t> > ();
        break;

      case symbol_kind::S_IDENT: // "identifier"
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
    yylhs.value.as < std::shared_ptr<comp_unit_t> > () = yystack_[0].value.as < std::shared_ptr<comp_unit_t> > ();
    printf("done\n");
}
#line 1318 "parser.cc"
    break;

  case 3: // comp_unit: comp_unit_item
#line 73 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<comp_unit_t> > () = std::make_shared<comp_unit_t>(); yylhs.value.as < std::shared_ptr<comp_unit_t> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<comp_unit_item_t> > ());          }
#line 1324 "parser.cc"
    break;

  case 4: // comp_unit: comp_unit comp_unit_item
#line 74 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<comp_unit_t> > () = yystack_[1].value.as < std::shared_ptr<comp_unit_t> > (); yylhs.value.as < std::shared_ptr<comp_unit_t> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<comp_unit_item_t> > ()); }
#line 1330 "parser.cc"
    break;

  case 5: // comp_unit_item: func_def
#line 79 "parser.yy"
                { yylhs.value.as < std::shared_ptr<comp_unit_item_t> > () = std::make_shared<comp_unit_item_func_def_t>(yystack_[0].value.as < std::shared_ptr<func_def_t> > ()); }
#line 1336 "parser.cc"
    break;

  case 6: // comp_unit_item: decl
#line 80 "parser.yy"
                { yylhs.value.as < std::shared_ptr<comp_unit_item_t> > () = std::make_shared<comp_unit_item_decl_t>(yystack_[0].value.as < std::shared_ptr<decl_t> > ());     }
#line 1342 "parser.cc"
    break;

  case 7: // decl: const_decl_stmt
#line 85 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<decl_t> > () = std::make_shared<decl_const_decl_t>(yystack_[0].value.as < std::shared_ptr<const_decl_t> > ()); }
#line 1348 "parser.cc"
    break;

  case 8: // decl: var_decl
#line 86 "parser.yy"
               { yylhs.value.as < std::shared_ptr<decl_t> > () = std::make_shared<decl_var_decl_t>(yystack_[0].value.as < std::shared_ptr<var_decl_t> > ());   }
#line 1354 "parser.cc"
    break;

  case 9: // const_decl: "const" b_type const_def
#line 92 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<const_decl_t> > () = std::make_shared<const_decl_t>(); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->b_type = yystack_[1].value.as < std::shared_ptr<b_type_t> > (); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->const_defs.push_back(yystack_[0].value.as < std::shared_ptr<const_def_t> > ()); }
#line 1360 "parser.cc"
    break;

  case 10: // const_decl: const_decl "," const_def
#line 93 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<const_decl_t> > () = yystack_[2].value.as < std::shared_ptr<const_decl_t> > (); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->const_defs.push_back(yystack_[0].value.as < std::shared_ptr<const_def_t> > ());}
#line 1366 "parser.cc"
    break;

  case 11: // const_decl_stmt: const_decl ";"
#line 96 "parser.yy"
                                { yylhs.value.as < std::shared_ptr<const_decl_t> > () = yystack_[1].value.as < std::shared_ptr<const_decl_t> > (); }
#line 1372 "parser.cc"
    break;

  case 12: // b_type: "int"
#line 100 "parser.yy"
          { yylhs.value.as < std::shared_ptr<b_type_t> > () = std::make_shared<b_type_t>(b_type_t::INT); }
#line 1378 "parser.cc"
    break;

  case 13: // b_type: "void"
#line 101 "parser.yy"
           { yylhs.value.as < std::shared_ptr<b_type_t> > () = std::make_shared<b_type_t>(b_type_t::VOID); }
#line 1384 "parser.cc"
    break;

  case 14: // const_def: ident array_dims "=" const_init_val
#line 105 "parser.yy"
                                               {
    yylhs.value.as < std::shared_ptr<const_def_t> > () = std::make_shared<const_def_t>(yystack_[3].value.as < std::shared_ptr<ident_t> > (), yystack_[2].value.as < ptr_list_of<const_exp_t> > (), yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ());
}
#line 1392 "parser.cc"
    break;

  case 15: // array_dims: %empty
#line 111 "parser.yy"
           {}
#line 1398 "parser.cc"
    break;

  case 16: // array_dims: array_dims "[" const_exp "]"
#line 112 "parser.yy"
                                 { yylhs.value.as < ptr_list_of<const_exp_t> > () = yystack_[3].value.as < ptr_list_of<const_exp_t> > (); yylhs.value.as < ptr_list_of<const_exp_t> > ().push_back(yystack_[1].value.as < std::shared_ptr<const_exp_t> > ()); }
#line 1404 "parser.cc"
    break;

  case 17: // const_init_val: const_exp
#line 117 "parser.yy"
              { yylhs.value.as < std::shared_ptr<const_init_val_t> > () = std::make_shared<const_init_val_scalar_t>(yystack_[0].value.as < std::shared_ptr<const_exp_t> > ()); }
#line 1410 "parser.cc"
    break;

  case 18: // const_init_val: "{" const_array_elements "}"
#line 118 "parser.yy"
                                 { yylhs.value.as < std::shared_ptr<const_init_val_t> > () = std::make_shared<const_init_val_array_t>(yystack_[1].value.as < ptr_list_of<const_init_val_t> > ()); }
#line 1416 "parser.cc"
    break;

  case 19: // const_array_elements: %empty
#line 123 "parser.yy"
           {}
#line 1422 "parser.cc"
    break;

  case 20: // const_array_elements: const_array_elements "," const_init_val
#line 124 "parser.yy"
                                            { yylhs.value.as < ptr_list_of<const_init_val_t> > () = yystack_[2].value.as < ptr_list_of<const_init_val_t> > (); yylhs.value.as < ptr_list_of<const_init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ()); }
#line 1428 "parser.cc"
    break;

  case 21: // var_decl: b_type var_def_list ";"
#line 129 "parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<var_decl_t> > () = std::make_shared<var_decl_t>(yystack_[2].value.as < std::shared_ptr<b_type_t> > (), yystack_[1].value.as < ptr_list_of<var_def_t> > ());
    }
#line 1436 "parser.cc"
    break;

  case 22: // var_def_list: var_def
#line 136 "parser.yy"
            { yylhs.value.as < ptr_list_of<var_def_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<var_def_t> > ()); }
#line 1442 "parser.cc"
    break;

  case 23: // var_def_list: var_def_list "," var_def
#line 137 "parser.yy"
                             { yylhs.value.as < ptr_list_of<var_def_t> > () = yystack_[2].value.as < ptr_list_of<var_def_t> > (); yylhs.value.as < ptr_list_of<var_def_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<var_def_t> > ()); }
#line 1448 "parser.cc"
    break;

  case 24: // var_def: ident array_dims
#line 142 "parser.yy"
                                    { yylhs.value.as < std::shared_ptr<var_def_t> > () = std::make_shared<var_def_only_t>(yystack_[1].value.as < std::shared_ptr<ident_t> > (), yystack_[0].value.as < ptr_list_of<const_exp_t> > ()); }
#line 1454 "parser.cc"
    break;

  case 25: // var_def: ident array_dims "=" init_val
#line 143 "parser.yy"
                                    { yylhs.value.as < std::shared_ptr<var_def_t> > () = std::make_shared<var_def_init_t>(yystack_[3].value.as < std::shared_ptr<ident_t> > (), yystack_[2].value.as < ptr_list_of<const_exp_t> > (), yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1460 "parser.cc"
    break;

  case 26: // init_val: exp
#line 148 "parser.yy"
        { yylhs.value.as < std::shared_ptr<init_val_t> > () = std::make_shared<init_val_scalar_t>(yystack_[0].value.as < std::shared_ptr<exp_t> > ()); }
#line 1466 "parser.cc"
    break;

  case 27: // init_val: "{" init_array_elements "}"
#line 149 "parser.yy"
                                {{ yylhs.value.as < std::shared_ptr<init_val_t> > () = std::make_shared<init_val_array_t>(yystack_[1].value.as < ptr_list_of<init_val_t> > ()); }}
#line 1472 "parser.cc"
    break;

  case 28: // init_array_elements: %empty
#line 153 "parser.yy"
           {}
#line 1478 "parser.cc"
    break;

  case 29: // init_array_elements: init_array_elements init_val
#line 154 "parser.yy"
                                 { yylhs.value.as < ptr_list_of<init_val_t> > () = yystack_[1].value.as < ptr_list_of<init_val_t> > (); yylhs.value.as < ptr_list_of<init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1484 "parser.cc"
    break;

  case 30: // func_def: b_type ident "(" func_f_params ")" block
#line 158 "parser.yy"
                                                   {
    yylhs.value.as < std::shared_ptr<func_def_t> > () = std::make_shared<func_def_t>();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->func_type = yystack_[5].value.as < std::shared_ptr<b_type_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->ident = yystack_[4].value.as < std::shared_ptr<ident_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->params = yystack_[2].value.as < std::shared_ptr<func_f_params_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->block = yystack_[0].value.as < std::shared_ptr<block_t> > ();
}
#line 1496 "parser.cc"
    break;

  case 31: // func_f_params: %empty
#line 168 "parser.yy"
           { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = std::make_shared<func_f_params_t>(); }
#line 1502 "parser.cc"
    break;

  case 32: // func_f_params: func_f_params "," func_f_param
#line 169 "parser.yy"
                                   { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = yystack_[2].value.as < std::shared_ptr<func_f_params_t> > (); yylhs.value.as < std::shared_ptr<func_f_params_t> > ()->params.push_back(yystack_[0].value.as < std::shared_ptr<func_f_param_t> > ()); }
#line 1508 "parser.cc"
    break;

  case 33: // func_f_param: b_type ident array_dims_func_param
#line 173 "parser.yy"
                                                 {
    yylhs.value.as < std::shared_ptr<func_f_param_t> > () = std::make_shared<func_f_param_t>();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->b_type = yystack_[2].value.as < std::shared_ptr<b_type_t> > ();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->ident = yystack_[1].value.as < std::shared_ptr<ident_t> > ();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->array_dims = yystack_[0].value.as < ptr_list_of<exp_t> > ();
}
#line 1519 "parser.cc"
    break;

  case 34: // array_dims_func_param: %empty
#line 182 "parser.yy"
           {}
#line 1525 "parser.cc"
    break;

  case 35: // array_dims_func_param: array_dims_func_param_real
#line 183 "parser.yy"
                               { yylhs.value.as < ptr_list_of<exp_t> > () = yystack_[0].value.as < ptr_list_of<exp_t> > (); }
#line 1531 "parser.cc"
    break;

  case 36: // array_dims_func_param_real: "[" "]"
#line 188 "parser.yy"
            { yylhs.value.as < ptr_list_of<exp_t> > ().push_back(nullptr); }
#line 1537 "parser.cc"
    break;

  case 37: // array_dims_func_param_real: array_dims_func_param_real "[" exp "]"
#line 189 "parser.yy"
                                           { yylhs.value.as < ptr_list_of<exp_t> > () = yystack_[3].value.as < ptr_list_of<exp_t> > (); yylhs.value.as < ptr_list_of<exp_t> > ().push_back(yystack_[1].value.as < std::shared_ptr<exp_t> > ()); }
#line 1543 "parser.cc"
    break;

  case 38: // block: "{" block_elements "}"
#line 193 "parser.yy"
                              { yylhs.value.as < std::shared_ptr<block_t> > () = std::make_shared<block_t>(yystack_[1].value.as < ptr_list_of<block_item_t> > ()); }
#line 1549 "parser.cc"
    break;

  case 39: // block_elements: %empty
#line 197 "parser.yy"
           {}
#line 1555 "parser.cc"
    break;

  case 40: // block_elements: block_elements block_item
#line 198 "parser.yy"
                              { yylhs.value.as < ptr_list_of<block_item_t> > () = yystack_[1].value.as < ptr_list_of<block_item_t> > (); yylhs.value.as < ptr_list_of<block_item_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<block_item_t> > ()); }
#line 1561 "parser.cc"
    break;

  case 41: // block_item: decl
#line 203 "parser.yy"
         { yylhs.value.as < std::shared_ptr<block_item_t> > () = std::make_shared<block_item_decl_t>(yystack_[0].value.as < std::shared_ptr<decl_t> > ()); }
#line 1567 "parser.cc"
    break;

  case 42: // block_item: stmt
#line 204 "parser.yy"
         { yylhs.value.as < std::shared_ptr<block_item_t> > () = std::make_shared<block_item_stmt_t>(yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1573 "parser.cc"
    break;

  case 43: // ident: "identifier"
#line 207 "parser.yy"
             { yylhs.value.as < std::shared_ptr<ident_t> > () = std::make_shared<ident_t>(yystack_[0].value.as < std::string > ()); }
#line 1579 "parser.cc"
    break;

  case 44: // stmt: l_val "=" exp ";"
#line 211 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_assign_t>(yystack_[3].value.as < std::shared_ptr<l_val_t> > (), yystack_[1].value.as < std::shared_ptr<exp_t> > ()); }
#line 1585 "parser.cc"
    break;

  case 45: // stmt: exp ";"
#line 212 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_exp_t>(yystack_[1].value.as < std::shared_ptr<exp_t> > ());        }
#line 1591 "parser.cc"
    break;

  case 46: // stmt: ";"
#line 213 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::shared_ptr<stmt_exp_t>(nullptr);    }
#line 1597 "parser.cc"
    break;

  case 47: // stmt: block
#line 214 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_block_t>(yystack_[0].value.as < std::shared_ptr<block_t> > ());      }
#line 1603 "parser.cc"
    break;

  case 48: // stmt: "if" "(" cond ")" stmt
#line 215 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_if_t>(yystack_[2].value.as < std::shared_ptr<cond_t> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > (), nullptr); }
#line 1609 "parser.cc"
    break;

  case 49: // stmt: "if" "(" cond ")" stmt "else" stmt
#line 217 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_if_t>(yystack_[4].value.as < std::shared_ptr<cond_t> > (), yystack_[2].value.as < std::shared_ptr<stmt_t> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1615 "parser.cc"
    break;

  case 50: // stmt: "while" "(" cond ")" stmt
#line 218 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_while_t>(yystack_[2].value.as < std::shared_ptr<cond_t> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1621 "parser.cc"
    break;

  case 51: // stmt: "break" ";"
#line 219 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_break_t>();       }
#line 1627 "parser.cc"
    break;

  case 52: // stmt: "continue" ";"
#line 220 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_continue_t>();    }
#line 1633 "parser.cc"
    break;

  case 53: // stmt: "return" ";"
#line 221 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_return_t>(nullptr); }
#line 1639 "parser.cc"
    break;

  case 54: // stmt: "return" exp ";"
#line 222 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_return_t>(yystack_[1].value.as < std::shared_ptr<exp_t> > ());    }
#line 1645 "parser.cc"
    break;

  case 55: // exp: add_exp
#line 227 "parser.yy"
             { yylhs.value.as < std::shared_ptr<exp_t> > () = std::make_shared<exp_add_t>(yystack_[0].value.as < std::shared_ptr<add_exp_t> > ()); }
#line 1651 "parser.cc"
    break;

  case 56: // cond: l_or_exp
#line 230 "parser.yy"
               { yylhs.value.as < std::shared_ptr<cond_t> > () = std::make_shared<cond_l_or_t>(yystack_[0].value.as < std::shared_ptr<l_or_exp_t> > ()); }
#line 1657 "parser.cc"
    break;

  case 57: // l_val: ident array_indices
#line 234 "parser.yy"
                        { yylhs.value.as < std::shared_ptr<l_val_t> > () = std::make_shared<l_val_t>(yystack_[1].value.as < std::shared_ptr<ident_t> > (), yystack_[0].value.as < ptr_list_of<exp_t> > ()); }
#line 1663 "parser.cc"
    break;

  case 58: // l_val: ident
#line 235 "parser.yy"
          { yylhs.value.as < std::shared_ptr<l_val_t> > ()=std::make_shared<l_val_t>(yystack_[0].value.as < std::shared_ptr<ident_t> > (), ptr_list_of<exp_t>()); }
#line 1669 "parser.cc"
    break;

  case 59: // array_indices: "[" exp "]"
#line 240 "parser.yy"
                 {{ yylhs.value.as < ptr_list_of<exp_t> > ().push_back(yystack_[1].value.as < std::shared_ptr<exp_t> > ()); }}
#line 1675 "parser.cc"
    break;

  case 60: // array_indices: array_indices "[" exp "]"
#line 241 "parser.yy"
                               { yylhs.value.as < ptr_list_of<exp_t> > () = yystack_[3].value.as < ptr_list_of<exp_t> > (); yylhs.value.as < ptr_list_of<exp_t> > ().push_back(yystack_[1].value.as < std::shared_ptr<exp_t> > ()); }
#line 1681 "parser.cc"
    break;

  case 61: // primary_exp: "(" exp ")"
#line 246 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<primary_exp_t> > () = std::make_shared<primary_exp_exp_t>(yystack_[1].value.as < std::shared_ptr<exp_t> > ());     }
#line 1687 "parser.cc"
    break;

  case 62: // primary_exp: l_val
#line 247 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<primary_exp_t> > () = std::make_shared<primary_exp_l_val_t>(yystack_[0].value.as < std::shared_ptr<l_val_t> > ());   }
#line 1693 "parser.cc"
    break;

  case 63: // primary_exp: number
#line 248 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<primary_exp_t> > () = std::make_shared<primary_exp_number_t>(yystack_[0].value.as < std::shared_ptr<number_t> > ());  }
#line 1699 "parser.cc"
    break;

  case 64: // number: "integer"
#line 252 "parser.yy"
                  { yylhs.value.as < std::shared_ptr<number_t> > () = std::make_shared<number_t>(std::make_shared<int_const_t>(yystack_[0].value.as < long long > ())); }
#line 1705 "parser.cc"
    break;

  case 65: // unary_exp: primary_exp
#line 256 "parser.yy"
                  { yylhs.value.as < std::shared_ptr<unary_exp_t> > () = std::make_shared<unary_exp_primary_exp_t>(yystack_[0].value.as < std::shared_ptr<primary_exp_t> > ()); }
#line 1711 "parser.cc"
    break;

  case 66: // unary_exp: ident "(" func_r_params ")"
#line 257 "parser.yy"
                                { yylhs.value.as < std::shared_ptr<unary_exp_t> > () = std::make_shared<unary_exp_func_call_t>(yystack_[3].value.as < std::shared_ptr<ident_t> > (), yystack_[1].value.as < std::shared_ptr<func_r_params_t> > ()); }
#line 1717 "parser.cc"
    break;

  case 67: // unary_exp: "+" unary_exp
#line 258 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<unary_exp_t> > () = std::make_shared<unary_exp_applied_t>(std::make_shared<operator_t>(operator_t::POSITIVE), yystack_[0].value.as < std::shared_ptr<unary_exp_t> > ()) ;}
#line 1723 "parser.cc"
    break;

  case 68: // unary_exp: "-" unary_exp
#line 259 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<unary_exp_t> > () = std::make_shared<unary_exp_applied_t>(std::make_shared<operator_t>(operator_t::NEGATIVE), yystack_[0].value.as < std::shared_ptr<unary_exp_t> > ()) ;}
#line 1729 "parser.cc"
    break;

  case 69: // unary_exp: "!" unary_exp
#line 260 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<unary_exp_t> > () = std::make_shared<unary_exp_applied_t>(std::make_shared<operator_t>(operator_t::LOGICAL_NOT), yystack_[0].value.as < std::shared_ptr<unary_exp_t> > ()) ;}
#line 1735 "parser.cc"
    break;

  case 70: // func_r_params: %empty
#line 266 "parser.yy"
                { yylhs.value.as < std::shared_ptr<func_r_params_t> > () = std::make_shared<func_r_params_t>(); }
#line 1741 "parser.cc"
    break;

  case 71: // func_r_params: func_r_params_elements
#line 267 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<func_r_params_t> > () = std::make_shared<func_r_params_t>(yystack_[0].value.as < ptr_list_of<exp_t> > ()); }
#line 1747 "parser.cc"
    break;

  case 72: // func_r_params_elements: exp
#line 272 "parser.yy"
                                     { yylhs.value.as < ptr_list_of<exp_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<exp_t> > ());            }
#line 1753 "parser.cc"
    break;

  case 73: // func_r_params_elements: func_r_params_elements "," exp
#line 273 "parser.yy"
                                     { yylhs.value.as < ptr_list_of<exp_t> > () = yystack_[2].value.as < ptr_list_of<exp_t> > (); yylhs.value.as < ptr_list_of<exp_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<exp_t> > ());   }
#line 1759 "parser.cc"
    break;

  case 74: // mul_exp: unary_exp
#line 278 "parser.yy"
               { yylhs.value.as < std::shared_ptr<mul_exp_t> > () = std::make_shared<mul_exp_unary_t>(yystack_[0].value.as < std::shared_ptr<unary_exp_t> > ()); }
#line 1765 "parser.cc"
    break;

  case 75: // mul_exp: mul_exp "*" unary_exp
#line 279 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<mul_exp_t> > () = std::make_shared<mul_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<mul_exp_t> > (), std::make_shared<operator_t>(operator_t::MULTIPLY), yystack_[0].value.as < std::shared_ptr<unary_exp_t> > ()); }
#line 1771 "parser.cc"
    break;

  case 76: // mul_exp: mul_exp "/" unary_exp
#line 280 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<mul_exp_t> > () = std::make_shared<mul_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<mul_exp_t> > (), std::make_shared<operator_t>(operator_t::DIVIDE), yystack_[0].value.as < std::shared_ptr<unary_exp_t> > ()); }
#line 1777 "parser.cc"
    break;

  case 77: // mul_exp: mul_exp "%" unary_exp
#line 281 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<mul_exp_t> > () = std::make_shared<mul_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<mul_exp_t> > (), std::make_shared<operator_t>(operator_t::MODULE), yystack_[0].value.as < std::shared_ptr<unary_exp_t> > ()); }
#line 1783 "parser.cc"
    break;

  case 78: // add_exp: mul_exp
#line 286 "parser.yy"
             { yylhs.value.as < std::shared_ptr<add_exp_t> > () = std::make_shared<add_exp_mul_t>(yystack_[0].value.as < std::shared_ptr<mul_exp_t> > ()); }
#line 1789 "parser.cc"
    break;

  case 79: // add_exp: add_exp "+" mul_exp
#line 287 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<add_exp_t> > () = std::make_shared<add_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<add_exp_t> > (), std::make_shared<operator_t>(operator_t::PLUS), yystack_[0].value.as < std::shared_ptr<mul_exp_t> > ()); }
#line 1795 "parser.cc"
    break;

  case 80: // add_exp: add_exp "-" mul_exp
#line 288 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<add_exp_t> > () = std::make_shared<add_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<add_exp_t> > (), std::make_shared<operator_t>(operator_t::MINUS), yystack_[0].value.as < std::shared_ptr<mul_exp_t> > ()); }
#line 1801 "parser.cc"
    break;

  case 81: // rel_exp: add_exp
#line 293 "parser.yy"
             { yylhs.value.as < std::shared_ptr<rel_exp_t> > () = std::make_shared<rel_exp_add_t>(yystack_[0].value.as < std::shared_ptr<add_exp_t> > ()); }
#line 1807 "parser.cc"
    break;

  case 82: // rel_exp: rel_exp "<" add_exp
#line 294 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<rel_exp_t> > () = std::make_shared<rel_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<rel_exp_t> > (), std::make_shared<operator_t>(operator_t::LESS), yystack_[0].value.as < std::shared_ptr<add_exp_t> > ()); }
#line 1813 "parser.cc"
    break;

  case 83: // rel_exp: rel_exp ">" add_exp
#line 295 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<rel_exp_t> > () = std::make_shared<rel_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<rel_exp_t> > (), std::make_shared<operator_t>(operator_t::GREATER), yystack_[0].value.as < std::shared_ptr<add_exp_t> > ()); }
#line 1819 "parser.cc"
    break;

  case 84: // rel_exp: rel_exp "<=" add_exp
#line 296 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<rel_exp_t> > () = std::make_shared<rel_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<rel_exp_t> > (), std::make_shared<operator_t>(operator_t::LESS_EQUAL), yystack_[0].value.as < std::shared_ptr<add_exp_t> > ()); }
#line 1825 "parser.cc"
    break;

  case 85: // rel_exp: rel_exp ">=" add_exp
#line 297 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<rel_exp_t> > () = std::make_shared<rel_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<rel_exp_t> > (), std::make_shared<operator_t>(operator_t::GREATER_EQUAL), yystack_[0].value.as < std::shared_ptr<add_exp_t> > ()); }
#line 1831 "parser.cc"
    break;

  case 86: // eq_exp: rel_exp
#line 302 "parser.yy"
             { yylhs.value.as < std::shared_ptr<eq_exp_t> > () = std::make_shared<eq_exp_rel_t>(yystack_[0].value.as < std::shared_ptr<rel_exp_t> > ()); }
#line 1837 "parser.cc"
    break;

  case 87: // eq_exp: eq_exp "==" rel_exp
#line 303 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<eq_exp_t> > () = std::make_shared<eq_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<eq_exp_t> > (), std::make_shared<operator_t>(operator_t::EQUAL), yystack_[0].value.as < std::shared_ptr<rel_exp_t> > ()); }
#line 1843 "parser.cc"
    break;

  case 88: // eq_exp: eq_exp "!=" rel_exp
#line 304 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<eq_exp_t> > () = std::make_shared<eq_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<eq_exp_t> > (), std::make_shared<operator_t>(operator_t::NOT_EQUAL), yystack_[0].value.as < std::shared_ptr<rel_exp_t> > ()); }
#line 1849 "parser.cc"
    break;

  case 89: // l_and_exp: eq_exp
#line 309 "parser.yy"
            { yylhs.value.as < std::shared_ptr<l_and_exp_t> > () = std::make_shared<l_and_exp_eq_t>(yystack_[0].value.as < std::shared_ptr<eq_exp_t> > ()); }
#line 1855 "parser.cc"
    break;

  case 90: // l_and_exp: l_and_exp "&&" eq_exp
#line 310 "parser.yy"
                            { yylhs.value.as < std::shared_ptr<l_and_exp_t> > () = std::make_shared<l_and_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<l_and_exp_t> > (), yystack_[0].value.as < std::shared_ptr<eq_exp_t> > ()); }
#line 1861 "parser.cc"
    break;

  case 91: // l_or_exp: l_and_exp
#line 315 "parser.yy"
               { yylhs.value.as < std::shared_ptr<l_or_exp_t> > () = std::make_shared<l_or_exp_and_t>(yystack_[0].value.as < std::shared_ptr<l_and_exp_t> > ()); }
#line 1867 "parser.cc"
    break;

  case 92: // l_or_exp: l_or_exp "||" l_and_exp
#line 316 "parser.yy"
                              { yylhs.value.as < std::shared_ptr<l_or_exp_t> > () = std::make_shared<l_or_exp_applied_t>(yystack_[2].value.as < std::shared_ptr<l_or_exp_t> > (), yystack_[0].value.as < std::shared_ptr<l_and_exp_t> > ()); }
#line 1873 "parser.cc"
    break;

  case 93: // const_exp: add_exp
#line 320 "parser.yy"
                   { yylhs.value.as < std::shared_ptr<const_exp_t> > () = std::make_shared<const_exp_add_t>(yystack_[0].value.as < std::shared_ptr<add_exp_t> > ()); }
#line 1879 "parser.cc"
    break;


#line 1883 "parser.cc"

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





  const short parser::yypact_ninf_ = -130;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      61,  -130,  -130,    28,    11,    61,  -130,  -130,    34,  -130,
      12,  -130,  -130,    12,  -130,  -130,    12,  -130,  -130,    51,
    -130,    13,  -130,  -130,  -130,    12,  -130,  -130,   -14,   -12,
    -130,  -130,     4,    69,   139,   114,    28,    25,  -130,   139,
     139,   139,   139,  -130,  -130,    19,  -130,  -130,  -130,  -130,
    -130,    50,    81,    81,    45,  -130,  -130,  -130,    12,  -130,
    -130,  -130,  -130,  -130,  -130,    52,    66,   139,   139,    62,
     139,   139,   139,   139,   139,  -130,    29,    70,    18,  -130,
    -130,  -130,  -130,    67,    88,    99,   139,  -130,  -130,  -130,
      50,    50,   114,  -130,   106,  -130,   115,   116,   122,   124,
     125,   127,  -130,  -130,  -130,    12,  -130,  -130,  -130,   126,
     137,  -130,   139,  -130,   131,  -130,  -130,   139,   139,   139,
    -130,  -130,  -130,   130,  -130,   139,  -130,  -130,   132,   129,
      81,    41,   109,   149,   150,   136,  -130,   141,  -130,   111,
     139,   139,   139,   139,   139,   139,   139,   139,   111,  -130,
     135,    81,    81,    81,    81,    41,    41,   109,   149,  -130,
     111,  -130
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    13,    12,     0,     0,     2,     3,     6,     0,     7,
       0,     8,     5,     0,     1,     4,     0,    11,    43,     0,
      22,    15,     9,    15,    10,     0,    21,    31,    24,     0,
      23,    15,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,    28,    25,    58,    26,    62,    65,    63,
      74,    78,    55,    93,     0,    19,    14,    17,     0,    32,
      39,    30,    69,    67,    68,     0,     0,    70,     0,    57,
       0,     0,     0,     0,     0,    16,     0,    34,     0,    61,
      27,    29,    72,     0,    71,     0,     0,    75,    76,    77,
      79,    80,     0,    18,     0,    33,    35,     0,     0,     0,
       0,     0,    46,    38,    41,     0,    47,    40,    42,     0,
      62,    66,     0,    59,     0,    20,    36,     0,     0,     0,
      51,    52,    53,     0,    45,     0,    73,    60,     0,     0,
      81,    86,    89,    91,    56,     0,    54,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      48,    85,    84,    83,    82,    87,    88,    90,    92,    50,
       0,    49
  };

  const short
  parser::yypgoto_[] =
  {
    -130,  -130,  -130,   167,    95,  -130,  -130,     3,   158,   152,
      84,  -130,  -130,  -130,   153,   113,  -130,  -130,  -130,  -130,
    -130,  -130,   140,  -130,  -130,    -8,  -129,   -30,    63,   -74,
    -130,  -130,  -130,   -26,  -130,  -130,    53,   -34,   -16,    35,
      33,  -130,   151
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     4,     5,     6,     7,     8,     9,    10,    22,    28,
      56,    76,    11,    19,    20,    44,    66,    12,    32,    59,
      95,    96,   106,    78,   107,    45,   108,   109,   129,    47,
      69,    48,    49,    50,    83,    84,    51,    52,   131,   132,
     133,   134,    57
  };

  const unsigned char
  parser::yytable_[] =
  {
      53,    53,    21,    46,   110,    23,    13,    33,    23,    35,
     150,    14,    65,    62,    63,    64,    18,    31,    34,   159,
      34,    38,    18,     1,     2,     3,    97,    98,    99,   100,
     101,   161,    36,     1,     2,    37,    46,    82,    85,    58,
      39,    40,    41,    27,    87,    88,    89,   102,    42,    67,
      77,    68,    60,   103,   140,   141,   114,    92,    53,    60,
     142,   143,    16,    17,    93,   110,     1,     2,     3,    38,
      18,   123,    38,    18,   110,    70,    71,    72,    75,    25,
      26,   105,   126,    79,   130,   130,   110,   128,    39,    40,
      41,    39,    40,    41,    86,   137,    42,    31,   111,    42,
      43,    80,    94,    43,    73,    74,   151,   152,   153,   154,
     130,   130,   130,   130,    38,    18,   112,    38,    18,    97,
      98,    99,   100,   101,   144,   145,    90,    91,   155,   156,
      38,    18,   113,    39,    40,    41,    39,    40,    41,   116,
     102,    42,    38,    18,    42,    60,   118,   117,    55,    39,
      40,    41,   119,   120,   121,   124,   122,    42,   125,   136,
     139,    39,    40,    41,   127,   138,   146,   148,   147,    42,
     149,   160,    15,   104,    24,    29,   115,    61,    30,    81,
     158,   157,   135,     0,     0,    54
  };

  const short
  parser::yycheck_[] =
  {
      34,    35,    10,    33,    78,    13,     3,    21,    16,    21,
     139,     0,    42,    39,    40,    41,     4,    25,    32,   148,
      32,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,   160,    28,     5,     6,    31,    66,    67,    68,    36,
      22,    23,    24,    30,    70,    71,    72,    29,    30,    30,
      58,    32,    34,    35,    13,    14,    86,    28,    92,    34,
      19,    20,    28,    29,    35,   139,     5,     6,     7,     3,
       4,   101,     3,     4,   148,    25,    26,    27,    33,    28,
      29,    78,   112,    31,   118,   119,   160,   117,    22,    23,
      24,    22,    23,    24,    32,   125,    30,   105,    31,    30,
      34,    35,    32,    34,    23,    24,   140,   141,   142,   143,
     144,   145,   146,   147,     3,     4,    28,     3,     4,     8,
       9,    10,    11,    12,    15,    16,    73,    74,   144,   145,
       3,     4,    33,    22,    23,    24,    22,    23,    24,    33,
      29,    30,     3,     4,    30,    34,    30,    32,    34,    22,
      23,    24,    30,    29,    29,    29,    29,    30,    21,    29,
      31,    22,    23,    24,    33,    33,    17,    31,    18,    30,
      29,    36,     5,    78,    16,    23,    92,    37,    25,    66,
     147,   146,   119,    -1,    -1,    34
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,     6,     7,    38,    39,    40,    41,    42,    43,
      44,    49,    54,    44,     0,    40,    28,    29,     4,    50,
      51,    62,    45,    62,    45,    28,    29,    30,    46,    46,
      51,    62,    55,    21,    32,    21,    28,    31,     3,    22,
      23,    24,    30,    34,    52,    62,    64,    66,    68,    69,
      70,    73,    74,    74,    79,    34,    47,    79,    44,    56,
      34,    59,    70,    70,    70,    64,    53,    30,    32,    67,
      25,    26,    27,    23,    24,    33,    48,    62,    60,    31,
      35,    52,    64,    71,    72,    64,    32,    70,    70,    70,
      73,    73,    28,    35,    32,    57,    58,     8,     9,    10,
      11,    12,    29,    35,    41,    44,    59,    61,    63,    64,
      66,    31,    28,    33,    64,    47,    33,    32,    30,    30,
      29,    29,    29,    64,    29,    21,    64,    33,    64,    65,
      74,    75,    76,    77,    78,    65,    29,    64,    33,    31,
      13,    14,    19,    20,    15,    16,    17,    18,    31,    29,
      63,    74,    74,    74,    74,    75,    75,    76,    77,    63,
      36,    63
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    43,    44,    44,    45,    46,    46,    47,    47,    48,
      48,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      54,    55,    55,    56,    57,    57,    58,    58,    59,    60,
      60,    61,    61,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    65,    66,    66,    67,
      67,    68,    68,    68,    69,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    74,    74,
      74,    75,    75,    75,    75,    75,    76,    76,    76,    77,
      77,    78,    78,    79
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     1,     1,     1,     1,     3,
       3,     2,     1,     1,     4,     0,     4,     1,     3,     0,
       3,     3,     1,     3,     2,     4,     1,     3,     0,     2,
       6,     0,     3,     3,     0,     1,     2,     4,     3,     0,
       2,     1,     1,     1,     4,     2,     1,     1,     5,     7,
       5,     2,     2,     2,     3,     1,     1,     2,     1,     3,
       4,     3,     1,     1,     1,     1,     4,     2,     2,     2,
       0,     1,     1,     3,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     1
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
  "func_f_params", "func_f_param", "array_dims_func_param",
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
       0,    65,    65,    73,    74,    79,    80,    85,    86,    92,
      93,    96,   100,   101,   105,   111,   112,   117,   118,   123,
     124,   129,   136,   137,   142,   143,   148,   149,   153,   154,
     158,   168,   169,   173,   182,   183,   188,   189,   193,   197,
     198,   203,   204,   207,   211,   212,   213,   214,   215,   217,
     218,   219,   220,   221,   222,   227,   230,   234,   235,   240,
     241,   246,   247,   248,   252,   256,   257,   258,   259,   260,
     266,   267,   272,   273,   278,   279,   280,   281,   286,   287,
     288,   293,   294,   295,   296,   297,   302,   303,   304,   309,
     310,   315,   316,   320
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
#line 2308 "parser.cc"

#line 323 "parser.yy"


