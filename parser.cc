// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.hh"


// Unqualified %code blocks.
#line 15 "parser.yy"

    #include <iostream>
    #include "driver.hh"
    
    void yy::parser::error (const std::string& m) {
        std::cerr << m << '\n';
    }

#line 54 "parser.cc"


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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
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
#line 126 "parser.cc"


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
  | Symbol types.  |
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

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 3: // "integer"
        value.YY_MOVE_OR_COPY< long long > (YY_MOVE (that.value));
        break;

      case 63: // block_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<block_item_t> > (YY_MOVE (that.value));
        break;

      case 48: // const_array_elements
      case 49: // real_const_array_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case 46: // array_dims
      case 60: // array_dims_func_param
      case 61: // array_dims_func_param_real
      case 70: // array_indices
      case 75: // func_r_params_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<expr> > (YY_MOVE (that.value));
        break;

      case 54: // init_array_elements
      case 55: // real_init_array_elements
        value.YY_MOVE_OR_COPY< ptr_list_of<init_val_t> > (YY_MOVE (that.value));
        break;

      case 51: // var_def_list
        value.YY_MOVE_OR_COPY< ptr_list_of<var_def_t> > (YY_MOVE (that.value));
        break;

      case 44: // b_type
        value.YY_MOVE_OR_COPY< std::shared_ptr<b_type_t> > (YY_MOVE (that.value));
        break;

      case 64: // block_item
        value.YY_MOVE_OR_COPY< std::shared_ptr<block_item_t> > (YY_MOVE (that.value));
        break;

      case 62: // block
        value.YY_MOVE_OR_COPY< std::shared_ptr<block_t> > (YY_MOVE (that.value));
        break;

      case 40: // comp_unit_item
        value.YY_MOVE_OR_COPY< std::shared_ptr<comp_unit_item_t> > (YY_MOVE (that.value));
        break;

      case 38: // start_symbol
      case 39: // comp_unit
        value.YY_MOVE_OR_COPY< std::shared_ptr<comp_unit_t> > (YY_MOVE (that.value));
        break;

      case 42: // const_decl
      case 43: // const_decl_stmt
        value.YY_MOVE_OR_COPY< std::shared_ptr<const_decl_t> > (YY_MOVE (that.value));
        break;

      case 45: // const_def
        value.YY_MOVE_OR_COPY< std::shared_ptr<const_def_t> > (YY_MOVE (that.value));
        break;

      case 47: // const_init_val
        value.YY_MOVE_OR_COPY< std::shared_ptr<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case 41: // decl
        value.YY_MOVE_OR_COPY< std::shared_ptr<decl_t> > (YY_MOVE (that.value));
        break;

      case 67: // exp
      case 68: // cond
      case 71: // primary_exp
      case 73: // unary_exp
      case 76: // mul_exp
      case 77: // add_exp
      case 78: // rel_exp
      case 79: // eq_exp
      case 80: // l_and_exp
      case 81: // l_or_exp
      case 82: // const_exp
        value.YY_MOVE_OR_COPY< std::shared_ptr<expr> > (YY_MOVE (that.value));
        break;

      case 56: // func_def
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_def_t> > (YY_MOVE (that.value));
        break;

      case 59: // func_f_param
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_f_param_t> > (YY_MOVE (that.value));
        break;

      case 57: // func_f_params
      case 58: // real_func_f_params
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_f_params_t> > (YY_MOVE (that.value));
        break;

      case 74: // func_r_params
        value.YY_MOVE_OR_COPY< std::shared_ptr<func_r_params_t> > (YY_MOVE (that.value));
        break;

      case 53: // init_val
        value.YY_MOVE_OR_COPY< std::shared_ptr<init_val_t> > (YY_MOVE (that.value));
        break;

      case 69: // l_val
        value.YY_MOVE_OR_COPY< std::shared_ptr<l_val_t> > (YY_MOVE (that.value));
        break;

      case 72: // number
        value.YY_MOVE_OR_COPY< std::shared_ptr<number_literal_t> > (YY_MOVE (that.value));
        break;

      case 66: // stmt
        value.YY_MOVE_OR_COPY< std::shared_ptr<stmt_t> > (YY_MOVE (that.value));
        break;

      case 50: // var_decl
        value.YY_MOVE_OR_COPY< std::shared_ptr<var_decl_t> > (YY_MOVE (that.value));
        break;

      case 52: // var_def
        value.YY_MOVE_OR_COPY< std::shared_ptr<var_def_t> > (YY_MOVE (that.value));
        break;

      case 4: // "identifier"
      case 65: // ident
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
    switch (that.type_get ())
    {
      case 3: // "integer"
        value.move< long long > (YY_MOVE (that.value));
        break;

      case 63: // block_elements
        value.move< ptr_list_of<block_item_t> > (YY_MOVE (that.value));
        break;

      case 48: // const_array_elements
      case 49: // real_const_array_elements
        value.move< ptr_list_of<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case 46: // array_dims
      case 60: // array_dims_func_param
      case 61: // array_dims_func_param_real
      case 70: // array_indices
      case 75: // func_r_params_elements
        value.move< ptr_list_of<expr> > (YY_MOVE (that.value));
        break;

      case 54: // init_array_elements
      case 55: // real_init_array_elements
        value.move< ptr_list_of<init_val_t> > (YY_MOVE (that.value));
        break;

      case 51: // var_def_list
        value.move< ptr_list_of<var_def_t> > (YY_MOVE (that.value));
        break;

      case 44: // b_type
        value.move< std::shared_ptr<b_type_t> > (YY_MOVE (that.value));
        break;

      case 64: // block_item
        value.move< std::shared_ptr<block_item_t> > (YY_MOVE (that.value));
        break;

      case 62: // block
        value.move< std::shared_ptr<block_t> > (YY_MOVE (that.value));
        break;

      case 40: // comp_unit_item
        value.move< std::shared_ptr<comp_unit_item_t> > (YY_MOVE (that.value));
        break;

      case 38: // start_symbol
      case 39: // comp_unit
        value.move< std::shared_ptr<comp_unit_t> > (YY_MOVE (that.value));
        break;

      case 42: // const_decl
      case 43: // const_decl_stmt
        value.move< std::shared_ptr<const_decl_t> > (YY_MOVE (that.value));
        break;

      case 45: // const_def
        value.move< std::shared_ptr<const_def_t> > (YY_MOVE (that.value));
        break;

      case 47: // const_init_val
        value.move< std::shared_ptr<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case 41: // decl
        value.move< std::shared_ptr<decl_t> > (YY_MOVE (that.value));
        break;

      case 67: // exp
      case 68: // cond
      case 71: // primary_exp
      case 73: // unary_exp
      case 76: // mul_exp
      case 77: // add_exp
      case 78: // rel_exp
      case 79: // eq_exp
      case 80: // l_and_exp
      case 81: // l_or_exp
      case 82: // const_exp
        value.move< std::shared_ptr<expr> > (YY_MOVE (that.value));
        break;

      case 56: // func_def
        value.move< std::shared_ptr<func_def_t> > (YY_MOVE (that.value));
        break;

      case 59: // func_f_param
        value.move< std::shared_ptr<func_f_param_t> > (YY_MOVE (that.value));
        break;

      case 57: // func_f_params
      case 58: // real_func_f_params
        value.move< std::shared_ptr<func_f_params_t> > (YY_MOVE (that.value));
        break;

      case 74: // func_r_params
        value.move< std::shared_ptr<func_r_params_t> > (YY_MOVE (that.value));
        break;

      case 53: // init_val
        value.move< std::shared_ptr<init_val_t> > (YY_MOVE (that.value));
        break;

      case 69: // l_val
        value.move< std::shared_ptr<l_val_t> > (YY_MOVE (that.value));
        break;

      case 72: // number
        value.move< std::shared_ptr<number_literal_t> > (YY_MOVE (that.value));
        break;

      case 66: // stmt
        value.move< std::shared_ptr<stmt_t> > (YY_MOVE (that.value));
        break;

      case 50: // var_decl
        value.move< std::shared_ptr<var_decl_t> > (YY_MOVE (that.value));
        break;

      case 52: // var_def
        value.move< std::shared_ptr<var_def_t> > (YY_MOVE (that.value));
        break;

      case 4: // "identifier"
      case 65: // ident
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 3: // "integer"
        value.copy< long long > (that.value);
        break;

      case 63: // block_elements
        value.copy< ptr_list_of<block_item_t> > (that.value);
        break;

      case 48: // const_array_elements
      case 49: // real_const_array_elements
        value.copy< ptr_list_of<const_init_val_t> > (that.value);
        break;

      case 46: // array_dims
      case 60: // array_dims_func_param
      case 61: // array_dims_func_param_real
      case 70: // array_indices
      case 75: // func_r_params_elements
        value.copy< ptr_list_of<expr> > (that.value);
        break;

      case 54: // init_array_elements
      case 55: // real_init_array_elements
        value.copy< ptr_list_of<init_val_t> > (that.value);
        break;

      case 51: // var_def_list
        value.copy< ptr_list_of<var_def_t> > (that.value);
        break;

      case 44: // b_type
        value.copy< std::shared_ptr<b_type_t> > (that.value);
        break;

      case 64: // block_item
        value.copy< std::shared_ptr<block_item_t> > (that.value);
        break;

      case 62: // block
        value.copy< std::shared_ptr<block_t> > (that.value);
        break;

      case 40: // comp_unit_item
        value.copy< std::shared_ptr<comp_unit_item_t> > (that.value);
        break;

      case 38: // start_symbol
      case 39: // comp_unit
        value.copy< std::shared_ptr<comp_unit_t> > (that.value);
        break;

      case 42: // const_decl
      case 43: // const_decl_stmt
        value.copy< std::shared_ptr<const_decl_t> > (that.value);
        break;

      case 45: // const_def
        value.copy< std::shared_ptr<const_def_t> > (that.value);
        break;

      case 47: // const_init_val
        value.copy< std::shared_ptr<const_init_val_t> > (that.value);
        break;

      case 41: // decl
        value.copy< std::shared_ptr<decl_t> > (that.value);
        break;

      case 67: // exp
      case 68: // cond
      case 71: // primary_exp
      case 73: // unary_exp
      case 76: // mul_exp
      case 77: // add_exp
      case 78: // rel_exp
      case 79: // eq_exp
      case 80: // l_and_exp
      case 81: // l_or_exp
      case 82: // const_exp
        value.copy< std::shared_ptr<expr> > (that.value);
        break;

      case 56: // func_def
        value.copy< std::shared_ptr<func_def_t> > (that.value);
        break;

      case 59: // func_f_param
        value.copy< std::shared_ptr<func_f_param_t> > (that.value);
        break;

      case 57: // func_f_params
      case 58: // real_func_f_params
        value.copy< std::shared_ptr<func_f_params_t> > (that.value);
        break;

      case 74: // func_r_params
        value.copy< std::shared_ptr<func_r_params_t> > (that.value);
        break;

      case 53: // init_val
        value.copy< std::shared_ptr<init_val_t> > (that.value);
        break;

      case 69: // l_val
        value.copy< std::shared_ptr<l_val_t> > (that.value);
        break;

      case 72: // number
        value.copy< std::shared_ptr<number_literal_t> > (that.value);
        break;

      case 66: // stmt
        value.copy< std::shared_ptr<stmt_t> > (that.value);
        break;

      case 50: // var_decl
        value.copy< std::shared_ptr<var_decl_t> > (that.value);
        break;

      case 52: // var_def
        value.copy< std::shared_ptr<var_def_t> > (that.value);
        break;

      case 4: // "identifier"
      case 65: // ident
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
    switch (that.type_get ())
    {
      case 3: // "integer"
        value.move< long long > (that.value);
        break;

      case 63: // block_elements
        value.move< ptr_list_of<block_item_t> > (that.value);
        break;

      case 48: // const_array_elements
      case 49: // real_const_array_elements
        value.move< ptr_list_of<const_init_val_t> > (that.value);
        break;

      case 46: // array_dims
      case 60: // array_dims_func_param
      case 61: // array_dims_func_param_real
      case 70: // array_indices
      case 75: // func_r_params_elements
        value.move< ptr_list_of<expr> > (that.value);
        break;

      case 54: // init_array_elements
      case 55: // real_init_array_elements
        value.move< ptr_list_of<init_val_t> > (that.value);
        break;

      case 51: // var_def_list
        value.move< ptr_list_of<var_def_t> > (that.value);
        break;

      case 44: // b_type
        value.move< std::shared_ptr<b_type_t> > (that.value);
        break;

      case 64: // block_item
        value.move< std::shared_ptr<block_item_t> > (that.value);
        break;

      case 62: // block
        value.move< std::shared_ptr<block_t> > (that.value);
        break;

      case 40: // comp_unit_item
        value.move< std::shared_ptr<comp_unit_item_t> > (that.value);
        break;

      case 38: // start_symbol
      case 39: // comp_unit
        value.move< std::shared_ptr<comp_unit_t> > (that.value);
        break;

      case 42: // const_decl
      case 43: // const_decl_stmt
        value.move< std::shared_ptr<const_decl_t> > (that.value);
        break;

      case 45: // const_def
        value.move< std::shared_ptr<const_def_t> > (that.value);
        break;

      case 47: // const_init_val
        value.move< std::shared_ptr<const_init_val_t> > (that.value);
        break;

      case 41: // decl
        value.move< std::shared_ptr<decl_t> > (that.value);
        break;

      case 67: // exp
      case 68: // cond
      case 71: // primary_exp
      case 73: // unary_exp
      case 76: // mul_exp
      case 77: // add_exp
      case 78: // rel_exp
      case 79: // eq_exp
      case 80: // l_and_exp
      case 81: // l_or_exp
      case 82: // const_exp
        value.move< std::shared_ptr<expr> > (that.value);
        break;

      case 56: // func_def
        value.move< std::shared_ptr<func_def_t> > (that.value);
        break;

      case 59: // func_f_param
        value.move< std::shared_ptr<func_f_param_t> > (that.value);
        break;

      case 57: // func_f_params
      case 58: // real_func_f_params
        value.move< std::shared_ptr<func_f_params_t> > (that.value);
        break;

      case 74: // func_r_params
        value.move< std::shared_ptr<func_r_params_t> > (that.value);
        break;

      case 53: // init_val
        value.move< std::shared_ptr<init_val_t> > (that.value);
        break;

      case 69: // l_val
        value.move< std::shared_ptr<l_val_t> > (that.value);
        break;

      case 72: // number
        value.move< std::shared_ptr<number_literal_t> > (that.value);
        break;

      case 66: // stmt
        value.move< std::shared_ptr<stmt_t> > (that.value);
        break;

      case 50: // var_decl
        value.move< std::shared_ptr<var_decl_t> > (that.value);
        break;

      case 52: // var_def
        value.move< std::shared_ptr<var_def_t> > (that.value);
        break;

      case 4: // "identifier"
      case 65: // ident
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
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
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
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
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
        YYCDEBUG << "Reading a token: ";
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
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
      case 3: // "integer"
        yylhs.value.emplace< long long > ();
        break;

      case 63: // block_elements
        yylhs.value.emplace< ptr_list_of<block_item_t> > ();
        break;

      case 48: // const_array_elements
      case 49: // real_const_array_elements
        yylhs.value.emplace< ptr_list_of<const_init_val_t> > ();
        break;

      case 46: // array_dims
      case 60: // array_dims_func_param
      case 61: // array_dims_func_param_real
      case 70: // array_indices
      case 75: // func_r_params_elements
        yylhs.value.emplace< ptr_list_of<expr> > ();
        break;

      case 54: // init_array_elements
      case 55: // real_init_array_elements
        yylhs.value.emplace< ptr_list_of<init_val_t> > ();
        break;

      case 51: // var_def_list
        yylhs.value.emplace< ptr_list_of<var_def_t> > ();
        break;

      case 44: // b_type
        yylhs.value.emplace< std::shared_ptr<b_type_t> > ();
        break;

      case 64: // block_item
        yylhs.value.emplace< std::shared_ptr<block_item_t> > ();
        break;

      case 62: // block
        yylhs.value.emplace< std::shared_ptr<block_t> > ();
        break;

      case 40: // comp_unit_item
        yylhs.value.emplace< std::shared_ptr<comp_unit_item_t> > ();
        break;

      case 38: // start_symbol
      case 39: // comp_unit
        yylhs.value.emplace< std::shared_ptr<comp_unit_t> > ();
        break;

      case 42: // const_decl
      case 43: // const_decl_stmt
        yylhs.value.emplace< std::shared_ptr<const_decl_t> > ();
        break;

      case 45: // const_def
        yylhs.value.emplace< std::shared_ptr<const_def_t> > ();
        break;

      case 47: // const_init_val
        yylhs.value.emplace< std::shared_ptr<const_init_val_t> > ();
        break;

      case 41: // decl
        yylhs.value.emplace< std::shared_ptr<decl_t> > ();
        break;

      case 67: // exp
      case 68: // cond
      case 71: // primary_exp
      case 73: // unary_exp
      case 76: // mul_exp
      case 77: // add_exp
      case 78: // rel_exp
      case 79: // eq_exp
      case 80: // l_and_exp
      case 81: // l_or_exp
      case 82: // const_exp
        yylhs.value.emplace< std::shared_ptr<expr> > ();
        break;

      case 56: // func_def
        yylhs.value.emplace< std::shared_ptr<func_def_t> > ();
        break;

      case 59: // func_f_param
        yylhs.value.emplace< std::shared_ptr<func_f_param_t> > ();
        break;

      case 57: // func_f_params
      case 58: // real_func_f_params
        yylhs.value.emplace< std::shared_ptr<func_f_params_t> > ();
        break;

      case 74: // func_r_params
        yylhs.value.emplace< std::shared_ptr<func_r_params_t> > ();
        break;

      case 53: // init_val
        yylhs.value.emplace< std::shared_ptr<init_val_t> > ();
        break;

      case 69: // l_val
        yylhs.value.emplace< std::shared_ptr<l_val_t> > ();
        break;

      case 72: // number
        yylhs.value.emplace< std::shared_ptr<number_literal_t> > ();
        break;

      case 66: // stmt
        yylhs.value.emplace< std::shared_ptr<stmt_t> > ();
        break;

      case 50: // var_decl
        yylhs.value.emplace< std::shared_ptr<var_decl_t> > ();
        break;

      case 52: // var_def
        yylhs.value.emplace< std::shared_ptr<var_def_t> > ();
        break;

      case 4: // "identifier"
      case 65: // ident
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
  case 2:
#line 66 "parser.yy"
                        {
    drv.syntax_tree = yystack_[0].value.as < std::shared_ptr<comp_unit_t> > ();
}
#line 1142 "parser.cc"
    break;

  case 3:
#line 73 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<comp_unit_t> > () = std::make_shared<comp_unit_t>(); yylhs.value.as < std::shared_ptr<comp_unit_t> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<comp_unit_item_t> > ());          }
#line 1148 "parser.cc"
    break;

  case 4:
#line 74 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<comp_unit_t> > () = yystack_[1].value.as < std::shared_ptr<comp_unit_t> > (); yylhs.value.as < std::shared_ptr<comp_unit_t> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<comp_unit_item_t> > ()); }
#line 1154 "parser.cc"
    break;

  case 5:
#line 79 "parser.yy"
                { yylhs.value.as < std::shared_ptr<comp_unit_item_t> > () = std::make_shared<comp_unit_item_func_def_t>(yystack_[0].value.as < std::shared_ptr<func_def_t> > ()); }
#line 1160 "parser.cc"
    break;

  case 6:
#line 80 "parser.yy"
                { yylhs.value.as < std::shared_ptr<comp_unit_item_t> > () = std::make_shared<comp_unit_item_decl_t>(yystack_[0].value.as < std::shared_ptr<decl_t> > ());     }
#line 1166 "parser.cc"
    break;

  case 7:
#line 85 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<decl_t> > () = std::make_shared<decl_const_decl_t>(yystack_[0].value.as < std::shared_ptr<const_decl_t> > ()); }
#line 1172 "parser.cc"
    break;

  case 8:
#line 86 "parser.yy"
               { yylhs.value.as < std::shared_ptr<decl_t> > () = std::make_shared<decl_var_decl_t>(yystack_[0].value.as < std::shared_ptr<var_decl_t> > ());   }
#line 1178 "parser.cc"
    break;

  case 9:
#line 92 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<const_decl_t> > () = std::make_shared<const_decl_t>(); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->b_type = yystack_[1].value.as < std::shared_ptr<b_type_t> > (); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->const_defs.push_back(yystack_[0].value.as < std::shared_ptr<const_def_t> > ()); }
#line 1184 "parser.cc"
    break;

  case 10:
#line 93 "parser.yy"
                             { yylhs.value.as < std::shared_ptr<const_decl_t> > () = yystack_[2].value.as < std::shared_ptr<const_decl_t> > (); yylhs.value.as < std::shared_ptr<const_decl_t> > ()->const_defs.push_back(yystack_[0].value.as < std::shared_ptr<const_def_t> > ());}
#line 1190 "parser.cc"
    break;

  case 11:
#line 96 "parser.yy"
                                { yylhs.value.as < std::shared_ptr<const_decl_t> > () = yystack_[1].value.as < std::shared_ptr<const_decl_t> > (); }
#line 1196 "parser.cc"
    break;

  case 12:
#line 100 "parser.yy"
          { yylhs.value.as < std::shared_ptr<b_type_t> > () = std::make_shared<b_type_t>(b_type_t::INT); }
#line 1202 "parser.cc"
    break;

  case 13:
#line 101 "parser.yy"
           { yylhs.value.as < std::shared_ptr<b_type_t> > () = std::make_shared<b_type_t>(b_type_t::VOID); }
#line 1208 "parser.cc"
    break;

  case 14:
#line 105 "parser.yy"
                                               {
    yylhs.value.as < std::shared_ptr<const_def_t> > () = std::make_shared<const_def_t>(yystack_[3].value.as < std::string > (), yystack_[2].value.as < ptr_list_of<expr> > (), yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ());
}
#line 1216 "parser.cc"
    break;

  case 15:
#line 111 "parser.yy"
           {}
#line 1222 "parser.cc"
    break;

  case 16:
#line 112 "parser.yy"
                                 { yylhs.value.as < ptr_list_of<expr> > () = yystack_[3].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1228 "parser.cc"
    break;

  case 17:
#line 117 "parser.yy"
              { yylhs.value.as < std::shared_ptr<const_init_val_t> > () = std::make_shared<const_init_val_scalar_t>(yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1234 "parser.cc"
    break;

  case 18:
#line 118 "parser.yy"
                                 { yylhs.value.as < std::shared_ptr<const_init_val_t> > () = std::make_shared<const_init_val_array_t>(yystack_[1].value.as < ptr_list_of<const_init_val_t> > ()); }
#line 1240 "parser.cc"
    break;

  case 19:
#line 123 "parser.yy"
           {}
#line 1246 "parser.cc"
    break;

  case 20:
#line 124 "parser.yy"
                              { yylhs.value.as < ptr_list_of<const_init_val_t> > () = yystack_[0].value.as < ptr_list_of<const_init_val_t> > (); }
#line 1252 "parser.cc"
    break;

  case 21:
#line 129 "parser.yy"
                                                 { yylhs.value.as < ptr_list_of<const_init_val_t> > () = yystack_[2].value.as < ptr_list_of<const_init_val_t> > (); yylhs.value.as < ptr_list_of<const_init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ()); }
#line 1258 "parser.cc"
    break;

  case 22:
#line 130 "parser.yy"
                   { yylhs.value.as < ptr_list_of<const_init_val_t> > () = ptr_list_of<const_init_val_t>(); yylhs.value.as < ptr_list_of<const_init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<const_init_val_t> > ()); }
#line 1264 "parser.cc"
    break;

  case 23:
#line 135 "parser.yy"
                            {
        yylhs.value.as < std::shared_ptr<var_decl_t> > () = std::make_shared<var_decl_t>(yystack_[2].value.as < std::shared_ptr<b_type_t> > (), yystack_[1].value.as < ptr_list_of<var_def_t> > ());
    }
#line 1272 "parser.cc"
    break;

  case 24:
#line 142 "parser.yy"
            { yylhs.value.as < ptr_list_of<var_def_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<var_def_t> > ()); }
#line 1278 "parser.cc"
    break;

  case 25:
#line 143 "parser.yy"
                             { yylhs.value.as < ptr_list_of<var_def_t> > () = yystack_[2].value.as < ptr_list_of<var_def_t> > (); yylhs.value.as < ptr_list_of<var_def_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<var_def_t> > ()); }
#line 1284 "parser.cc"
    break;

  case 26:
#line 148 "parser.yy"
                                    { yylhs.value.as < std::shared_ptr<var_def_t> > () = std::make_shared<var_def_only_t>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ptr_list_of<expr> > ()); }
#line 1290 "parser.cc"
    break;

  case 27:
#line 149 "parser.yy"
                                    { yylhs.value.as < std::shared_ptr<var_def_t> > () = std::make_shared<var_def_init_t>(yystack_[3].value.as < std::string > (), yystack_[2].value.as < ptr_list_of<expr> > (), yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1296 "parser.cc"
    break;

  case 28:
#line 154 "parser.yy"
        { yylhs.value.as < std::shared_ptr<init_val_t> > () = std::make_shared<init_val_scalar_t>(yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1302 "parser.cc"
    break;

  case 29:
#line 155 "parser.yy"
                                {{ yylhs.value.as < std::shared_ptr<init_val_t> > () = std::make_shared<init_val_array_t>(yystack_[1].value.as < ptr_list_of<init_val_t> > ()); }}
#line 1308 "parser.cc"
    break;

  case 30:
#line 159 "parser.yy"
           {}
#line 1314 "parser.cc"
    break;

  case 31:
#line 160 "parser.yy"
                             { yylhs.value.as < ptr_list_of<init_val_t> > () = yystack_[0].value.as < ptr_list_of<init_val_t> > (); }
#line 1320 "parser.cc"
    break;

  case 32:
#line 165 "parser.yy"
             { yylhs.value.as < ptr_list_of<init_val_t> > () = ptr_list_of<init_val_t>(); yylhs.value.as < ptr_list_of<init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1326 "parser.cc"
    break;

  case 33:
#line 166 "parser.yy"
                                          { yylhs.value.as < ptr_list_of<init_val_t> > () = yystack_[2].value.as < ptr_list_of<init_val_t> > (); yylhs.value.as < ptr_list_of<init_val_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<init_val_t> > ()); }
#line 1332 "parser.cc"
    break;

  case 34:
#line 170 "parser.yy"
                                                   {
    yylhs.value.as < std::shared_ptr<func_def_t> > () = std::make_shared<func_def_t>();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->func_type = yystack_[5].value.as < std::shared_ptr<b_type_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->ident = yystack_[4].value.as < std::string > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->params = yystack_[2].value.as < std::shared_ptr<func_f_params_t> > ();
    yylhs.value.as < std::shared_ptr<func_def_t> > ()->block = yystack_[0].value.as < std::shared_ptr<block_t> > ();
}
#line 1344 "parser.cc"
    break;

  case 35:
#line 180 "parser.yy"
           { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = std::make_shared<func_f_params_t>(); }
#line 1350 "parser.cc"
    break;

  case 36:
#line 181 "parser.yy"
                       { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = yystack_[0].value.as < std::shared_ptr<func_f_params_t> > (); }
#line 1356 "parser.cc"
    break;

  case 37:
#line 186 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = yystack_[2].value.as < std::shared_ptr<func_f_params_t> > (); yylhs.value.as < std::shared_ptr<func_f_params_t> > ()->params.push_back(yystack_[0].value.as < std::shared_ptr<func_f_param_t> > ()); }
#line 1362 "parser.cc"
    break;

  case 38:
#line 187 "parser.yy"
                 { yylhs.value.as < std::shared_ptr<func_f_params_t> > () = std::make_shared<func_f_params_t>(); yylhs.value.as < std::shared_ptr<func_f_params_t> > ()->params.push_back(yystack_[0].value.as < std::shared_ptr<func_f_param_t> > ()); }
#line 1368 "parser.cc"
    break;

  case 39:
#line 191 "parser.yy"
                                                 {
    yylhs.value.as < std::shared_ptr<func_f_param_t> > () = std::make_shared<func_f_param_t>();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->b_type = yystack_[2].value.as < std::shared_ptr<b_type_t> > ();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->ident = yystack_[1].value.as < std::string > ();
    yylhs.value.as < std::shared_ptr<func_f_param_t> > ()->array_dims = yystack_[0].value.as < ptr_list_of<expr> > ();
}
#line 1379 "parser.cc"
    break;

  case 40:
#line 200 "parser.yy"
           {}
#line 1385 "parser.cc"
    break;

  case 41:
#line 201 "parser.yy"
                               { yylhs.value.as < ptr_list_of<expr> > () = yystack_[0].value.as < ptr_list_of<expr> > (); }
#line 1391 "parser.cc"
    break;

  case 42:
#line 206 "parser.yy"
            { yylhs.value.as < ptr_list_of<expr> > ().push_back(nullptr); }
#line 1397 "parser.cc"
    break;

  case 43:
#line 207 "parser.yy"
                                           { yylhs.value.as < ptr_list_of<expr> > () = yystack_[3].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1403 "parser.cc"
    break;

  case 44:
#line 211 "parser.yy"
                              { yylhs.value.as < std::shared_ptr<block_t> > () = std::make_shared<block_t>(yystack_[1].value.as < ptr_list_of<block_item_t> > ()); }
#line 1409 "parser.cc"
    break;

  case 45:
#line 215 "parser.yy"
           {}
#line 1415 "parser.cc"
    break;

  case 46:
#line 216 "parser.yy"
                              { yylhs.value.as < ptr_list_of<block_item_t> > () = yystack_[1].value.as < ptr_list_of<block_item_t> > (); yylhs.value.as < ptr_list_of<block_item_t> > ().push_back(yystack_[0].value.as < std::shared_ptr<block_item_t> > ()); }
#line 1421 "parser.cc"
    break;

  case 47:
#line 221 "parser.yy"
         { yylhs.value.as < std::shared_ptr<block_item_t> > () = std::make_shared<block_item_decl_t>(yystack_[0].value.as < std::shared_ptr<decl_t> > ()); }
#line 1427 "parser.cc"
    break;

  case 48:
#line 222 "parser.yy"
         { yylhs.value.as < std::shared_ptr<block_item_t> > () = std::make_shared<block_item_stmt_t>(yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1433 "parser.cc"
    break;

  case 49:
#line 225 "parser.yy"
             { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1439 "parser.cc"
    break;

  case 50:
#line 229 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_assign_t>(yystack_[3].value.as < std::shared_ptr<l_val_t> > (), yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1445 "parser.cc"
    break;

  case 51:
#line 230 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_exp_t>(yystack_[1].value.as < std::shared_ptr<expr> > ());        }
#line 1451 "parser.cc"
    break;

  case 52:
#line 231 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::shared_ptr<stmt_exp_t>(nullptr);    }
#line 1457 "parser.cc"
    break;

  case 53:
#line 232 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_block_t>(yystack_[0].value.as < std::shared_ptr<block_t> > ());      }
#line 1463 "parser.cc"
    break;

  case 54:
#line 233 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_if_t>(yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > (), nullptr); }
#line 1469 "parser.cc"
    break;

  case 55:
#line 234 "parser.yy"
                                        { 
      /* 做就近匹配 */
      yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_if_t>(yystack_[4].value.as < std::shared_ptr<expr> > (), yystack_[2].value.as < std::shared_ptr<stmt_t> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); 
      auto p = yylhs.value.as < std::shared_ptr<stmt_t> > ();
      while(auto pr = dynamic_pointer_cast<stmt_if_t>(p)){
          if(auto r = dynamic_pointer_cast<stmt_if_t>(pr->stmt_if_true); r && r->stmt_if_false == nullptr) {
              std::swap(pr->stmt_if_false, r->stmt_if_false);
              p = r;
          }else{
              break;
          }
      }
  }
#line 1487 "parser.cc"
    break;

  case 56:
#line 247 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_while_t>(yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<stmt_t> > ()); }
#line 1493 "parser.cc"
    break;

  case 57:
#line 248 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_break_t>();       }
#line 1499 "parser.cc"
    break;

  case 58:
#line 249 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_continue_t>();    }
#line 1505 "parser.cc"
    break;

  case 59:
#line 250 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_return_t>(nullptr); }
#line 1511 "parser.cc"
    break;

  case 60:
#line 251 "parser.yy"
                                        { yylhs.value.as < std::shared_ptr<stmt_t> > () = std::make_shared<stmt_return_t>(yystack_[1].value.as < std::shared_ptr<expr> > ());    }
#line 1517 "parser.cc"
    break;

  case 61:
#line 256 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1523 "parser.cc"
    break;

  case 62:
#line 259 "parser.yy"
               { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1529 "parser.cc"
    break;

  case 63:
#line 263 "parser.yy"
                        { yylhs.value.as < std::shared_ptr<l_val_t> > () = std::make_shared<l_val_t>(yystack_[1].value.as < std::string > (), yystack_[0].value.as < ptr_list_of<expr> > ()); }
#line 1535 "parser.cc"
    break;

  case 64:
#line 264 "parser.yy"
          { yylhs.value.as < std::shared_ptr<l_val_t> > ()=std::make_shared<l_val_t>(yystack_[0].value.as < std::string > (), ptr_list_of<expr>()); }
#line 1541 "parser.cc"
    break;

  case 65:
#line 269 "parser.yy"
                 {{ yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }}
#line 1547 "parser.cc"
    break;

  case 66:
#line 270 "parser.yy"
                               { yylhs.value.as < ptr_list_of<expr> > () = yystack_[3].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[1].value.as < std::shared_ptr<expr> > ()); }
#line 1553 "parser.cc"
    break;

  case 67:
#line 275 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[1].value.as < std::shared_ptr<expr> > (); }
#line 1559 "parser.cc"
    break;

  case 68:
#line 276 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<l_val_t> > (); }
#line 1565 "parser.cc"
    break;

  case 69:
#line 277 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<number_literal_t> > (); }
#line 1571 "parser.cc"
    break;

  case 70:
#line 281 "parser.yy"
                  { yylhs.value.as < std::shared_ptr<number_literal_t> > () = std::make_shared<number_literal_t>(yystack_[0].value.as < long long > ()); }
#line 1577 "parser.cc"
    break;

  case 71:
#line 285 "parser.yy"
                  { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1583 "parser.cc"
    break;

  case 72:
#line 286 "parser.yy"
                                { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<func_call_t>(yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::shared_ptr<func_r_params_t> > ()); }
#line 1589 "parser.cc"
    break;

  case 73:
#line 287 "parser.yy"
                    { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1595 "parser.cc"
    break;

  case 74:
#line 288 "parser.yy"
                    { 
      auto e = dynamic_pointer_cast<negative_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ());
      if(e) yylhs.value.as < std::shared_ptr<expr> > () = e->src;
      else  yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<negative_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ()); 
    }
#line 1605 "parser.cc"
    break;

  case 75:
#line 293 "parser.yy"
                    { 
      auto e = dynamic_pointer_cast<logical_not_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ());
      if(e) yylhs.value.as < std::shared_ptr<expr> > () = e->src;
      else  yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<logical_not_expr>(yystack_[0].value.as < std::shared_ptr<expr> > ());
    }
#line 1615 "parser.cc"
    break;

  case 76:
#line 303 "parser.yy"
                { yylhs.value.as < std::shared_ptr<func_r_params_t> > () = std::make_shared<func_r_params_t>(); }
#line 1621 "parser.cc"
    break;

  case 77:
#line 304 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<func_r_params_t> > () = std::make_shared<func_r_params_t>(yystack_[0].value.as < ptr_list_of<expr> > ()); }
#line 1627 "parser.cc"
    break;

  case 78:
#line 309 "parser.yy"
                                     { yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[0].value.as < std::shared_ptr<expr> > ());            }
#line 1633 "parser.cc"
    break;

  case 79:
#line 310 "parser.yy"
                                     { yylhs.value.as < ptr_list_of<expr> > () = yystack_[2].value.as < ptr_list_of<expr> > (); yylhs.value.as < ptr_list_of<expr> > ().push_back(yystack_[0].value.as < std::shared_ptr<expr> > ());   }
#line 1639 "parser.cc"
    break;

  case 80:
#line 315 "parser.yy"
               { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1645 "parser.cc"
    break;

  case 81:
#line 316 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::MULTIPLY, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1651 "parser.cc"
    break;

  case 82:
#line 317 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::DIVIDE  , yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1657 "parser.cc"
    break;

  case 83:
#line 318 "parser.yy"
                           { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::MODULE  , yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1663 "parser.cc"
    break;

  case 84:
#line 323 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1669 "parser.cc"
    break;

  case 85:
#line 324 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::PLUS,  yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1675 "parser.cc"
    break;

  case 86:
#line 325 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::MINUS, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1681 "parser.cc"
    break;

  case 87:
#line 330 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1687 "parser.cc"
    break;

  case 88:
#line 331 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LESS, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1693 "parser.cc"
    break;

  case 89:
#line 332 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::GREATER, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1699 "parser.cc"
    break;

  case 90:
#line 333 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LESS_EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1705 "parser.cc"
    break;

  case 91:
#line 334 "parser.yy"
                          { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::GREATER_EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1711 "parser.cc"
    break;

  case 92:
#line 339 "parser.yy"
             { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1717 "parser.cc"
    break;

  case 93:
#line 340 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1723 "parser.cc"
    break;

  case 94:
#line 341 "parser.yy"
                         { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::NOT_EQUAL, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1729 "parser.cc"
    break;

  case 95:
#line 346 "parser.yy"
            { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1735 "parser.cc"
    break;

  case 96:
#line 347 "parser.yy"
                            { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LOGICAL_AND, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1741 "parser.cc"
    break;

  case 97:
#line 352 "parser.yy"
               { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1747 "parser.cc"
    break;

  case 98:
#line 353 "parser.yy"
                              { yylhs.value.as < std::shared_ptr<expr> > () = std::make_shared<binary_expr>(operator_t::LOGICAL_OR, yystack_[2].value.as < std::shared_ptr<expr> > (), yystack_[0].value.as < std::shared_ptr<expr> > ()); }
#line 1753 "parser.cc"
    break;

  case 99:
#line 357 "parser.yy"
                   { yylhs.value.as < std::shared_ptr<expr> > () = yystack_[0].value.as < std::shared_ptr<expr> > (); }
#line 1759 "parser.cc"
    break;


#line 1763 "parser.cc"

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
      YY_STACK_PRINT ();

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
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
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

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


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

  const short
  parser::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,     9,    10,    22,    28,
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
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"integer\"",
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


  const short
  parser::yyrline_[] =
  {
       0,    66,    66,    73,    74,    79,    80,    85,    86,    92,
      93,    96,   100,   101,   105,   111,   112,   117,   118,   123,
     124,   129,   130,   135,   142,   143,   148,   149,   154,   155,
     159,   160,   165,   166,   170,   180,   181,   186,   187,   191,
     200,   201,   206,   207,   211,   215,   216,   221,   222,   225,
     229,   230,   231,   232,   233,   234,   247,   248,   249,   250,
     251,   256,   259,   263,   264,   269,   270,   275,   276,   277,
     281,   285,   286,   287,   288,   293,   303,   304,   309,   310,
     315,   316,   317,   318,   323,   324,   325,   330,   331,   332,
     333,   334,   339,   340,   341,   346,   347,   352,   353,   357
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
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
#line 2181 "parser.cc"

#line 360 "parser.yy"


