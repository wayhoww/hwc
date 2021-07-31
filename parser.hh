// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
// "%code requires" blocks.
#line 10 "parser.yy"

    class driver;
    #include "constructs.hh"

#line 54 "parser.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 183 "parser.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // "integer"
      char dummy1[sizeof (long long)];

      // block_elements
      char dummy2[sizeof (ptr_list_of<block_item_t>)];

      // const_array_elements
      // real_const_array_elements
      char dummy3[sizeof (ptr_list_of<const_init_val_t>)];

      // array_dims
      // array_dims_func_param
      // array_dims_func_param_real
      // array_indices
      // func_r_params_elements
      char dummy4[sizeof (ptr_list_of<expr>)];

      // init_array_elements
      // real_init_array_elements
      char dummy5[sizeof (ptr_list_of<init_val_t>)];

      // var_def_list
      char dummy6[sizeof (ptr_list_of<var_def_t>)];

      // b_type
      char dummy7[sizeof (std::shared_ptr<b_type_t>)];

      // block_item
      char dummy8[sizeof (std::shared_ptr<block_item_t>)];

      // block
      char dummy9[sizeof (std::shared_ptr<block_t>)];

      // comp_unit_item
      char dummy10[sizeof (std::shared_ptr<comp_unit_item_t>)];

      // start_symbol
      // comp_unit
      char dummy11[sizeof (std::shared_ptr<comp_unit_t>)];

      // const_decl
      // const_decl_stmt
      char dummy12[sizeof (std::shared_ptr<const_decl_t>)];

      // const_def
      char dummy13[sizeof (std::shared_ptr<const_def_t>)];

      // const_init_val
      char dummy14[sizeof (std::shared_ptr<const_init_val_t>)];

      // decl
      char dummy15[sizeof (std::shared_ptr<decl_t>)];

      // exp
      // cond
      // primary_exp
      // unary_exp
      // mul_exp
      // add_exp
      // rel_exp
      // eq_exp
      // l_and_exp
      // l_or_exp
      // const_exp
      char dummy16[sizeof (std::shared_ptr<expr>)];

      // func_def
      char dummy17[sizeof (std::shared_ptr<func_def_t>)];

      // func_f_param
      char dummy18[sizeof (std::shared_ptr<func_f_param_t>)];

      // func_f_params
      // real_func_f_params
      char dummy19[sizeof (std::shared_ptr<func_f_params_t>)];

      // func_r_params
      char dummy20[sizeof (std::shared_ptr<func_r_params_t>)];

      // init_val
      char dummy21[sizeof (std::shared_ptr<init_val_t>)];

      // l_val
      char dummy22[sizeof (std::shared_ptr<l_val_t>)];

      // number
      char dummy23[sizeof (std::shared_ptr<number_literal_t>)];

      // stmt
      char dummy24[sizeof (std::shared_ptr<stmt_t>)];

      // var_decl
      char dummy25[sizeof (std::shared_ptr<var_decl_t>)];

      // var_def
      char dummy26[sizeof (std::shared_ptr<var_def_t>)];

      // "identifier"
      // ident
      char dummy27[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    INT_CONST = 258,               // "integer"
    IDENT = 259,                   // "identifier"
    VOID = 260,                    // "void"
    INT = 261,                     // "int"
    CONST = 262,                   // "const"
    IF = 263,                      // "if"
    ELSE = 264,                    // "else"
    WHILE = 265,                   // "while"
    BREAK = 266,                   // "break"
    CONTINUE = 267,                // "continue"
    RETURN = 268,                  // "return"
    GE = 269,                      // ">="
    LE = 270,                      // "<="
    EQ = 271,                      // "=="
    NE = 272,                      // "!="
    AND = 273,                     // "&&"
    OR = 274,                      // "||"
    GT = 275,                      // ">"
    LT = 276,                      // "<"
    ASSIGN = 277,                  // "="
    NOT = 278,                     // "!"
    ADD = 279,                     // "+"
    SUB = 280,                     // "-"
    MUL = 281,                     // "*"
    DIV = 282,                     // "/"
    MOD = 283,                     // "%"
    COMMA = 284,                   // ","
    SEMI = 285,                    // ";"
    LEFT_PAREN = 286,              // "("
    RIGHT_PAREN = 287,             // ")"
    LEFT_BRACKET = 288,            // "["
    RIGHT_BRACKET = 289,           // "]"
    LEFT_BRACE = 290,              // "{"
    RIGHT_BRACE = 291              // "}"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 37, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_INT_CONST = 3,                         // "integer"
        S_IDENT = 4,                             // "identifier"
        S_VOID = 5,                              // "void"
        S_INT = 6,                               // "int"
        S_CONST = 7,                             // "const"
        S_IF = 8,                                // "if"
        S_ELSE = 9,                              // "else"
        S_WHILE = 10,                            // "while"
        S_BREAK = 11,                            // "break"
        S_CONTINUE = 12,                         // "continue"
        S_RETURN = 13,                           // "return"
        S_GE = 14,                               // ">="
        S_LE = 15,                               // "<="
        S_EQ = 16,                               // "=="
        S_NE = 17,                               // "!="
        S_AND = 18,                              // "&&"
        S_OR = 19,                               // "||"
        S_GT = 20,                               // ">"
        S_LT = 21,                               // "<"
        S_ASSIGN = 22,                           // "="
        S_NOT = 23,                              // "!"
        S_ADD = 24,                              // "+"
        S_SUB = 25,                              // "-"
        S_MUL = 26,                              // "*"
        S_DIV = 27,                              // "/"
        S_MOD = 28,                              // "%"
        S_COMMA = 29,                            // ","
        S_SEMI = 30,                             // ";"
        S_LEFT_PAREN = 31,                       // "("
        S_RIGHT_PAREN = 32,                      // ")"
        S_LEFT_BRACKET = 33,                     // "["
        S_RIGHT_BRACKET = 34,                    // "]"
        S_LEFT_BRACE = 35,                       // "{"
        S_RIGHT_BRACE = 36,                      // "}"
        S_YYACCEPT = 37,                         // $accept
        S_start_symbol = 38,                     // start_symbol
        S_comp_unit = 39,                        // comp_unit
        S_comp_unit_item = 40,                   // comp_unit_item
        S_decl = 41,                             // decl
        S_const_decl = 42,                       // const_decl
        S_const_decl_stmt = 43,                  // const_decl_stmt
        S_b_type = 44,                           // b_type
        S_const_def = 45,                        // const_def
        S_array_dims = 46,                       // array_dims
        S_const_init_val = 47,                   // const_init_val
        S_const_array_elements = 48,             // const_array_elements
        S_real_const_array_elements = 49,        // real_const_array_elements
        S_var_decl = 50,                         // var_decl
        S_var_def_list = 51,                     // var_def_list
        S_var_def = 52,                          // var_def
        S_init_val = 53,                         // init_val
        S_init_array_elements = 54,              // init_array_elements
        S_real_init_array_elements = 55,         // real_init_array_elements
        S_func_def = 56,                         // func_def
        S_func_f_params = 57,                    // func_f_params
        S_real_func_f_params = 58,               // real_func_f_params
        S_func_f_param = 59,                     // func_f_param
        S_array_dims_func_param = 60,            // array_dims_func_param
        S_array_dims_func_param_real = 61,       // array_dims_func_param_real
        S_block = 62,                            // block
        S_block_elements = 63,                   // block_elements
        S_block_item = 64,                       // block_item
        S_ident = 65,                            // ident
        S_stmt = 66,                             // stmt
        S_exp = 67,                              // exp
        S_cond = 68,                             // cond
        S_l_val = 69,                            // l_val
        S_array_indices = 70,                    // array_indices
        S_primary_exp = 71,                      // primary_exp
        S_number = 72,                           // number
        S_unary_exp = 73,                        // unary_exp
        S_func_r_params = 74,                    // func_r_params
        S_func_r_params_elements = 75,           // func_r_params_elements
        S_mul_exp = 76,                          // mul_exp
        S_add_exp = 77,                          // add_exp
        S_rel_exp = 78,                          // rel_exp
        S_eq_exp = 79,                           // eq_exp
        S_l_and_exp = 80,                        // l_and_exp
        S_l_or_exp = 81,                         // l_or_exp
        S_const_exp = 82                         // const_exp
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_INT_CONST: // "integer"
        value.move< long long > (std::move (that.value));
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.move< ptr_list_of<block_item_t> > (std::move (that.value));
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
      case symbol_kind::S_real_const_array_elements: // real_const_array_elements
        value.move< ptr_list_of<const_init_val_t> > (std::move (that.value));
        break;

      case symbol_kind::S_array_dims: // array_dims
      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.move< ptr_list_of<expr> > (std::move (that.value));
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
      case symbol_kind::S_real_init_array_elements: // real_init_array_elements
        value.move< ptr_list_of<init_val_t> > (std::move (that.value));
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.move< ptr_list_of<var_def_t> > (std::move (that.value));
        break;

      case symbol_kind::S_b_type: // b_type
        value.move< std::shared_ptr<b_type_t> > (std::move (that.value));
        break;

      case symbol_kind::S_block_item: // block_item
        value.move< std::shared_ptr<block_item_t> > (std::move (that.value));
        break;

      case symbol_kind::S_block: // block
        value.move< std::shared_ptr<block_t> > (std::move (that.value));
        break;

      case symbol_kind::S_comp_unit_item: // comp_unit_item
        value.move< std::shared_ptr<comp_unit_item_t> > (std::move (that.value));
        break;

      case symbol_kind::S_start_symbol: // start_symbol
      case symbol_kind::S_comp_unit: // comp_unit
        value.move< std::shared_ptr<comp_unit_t> > (std::move (that.value));
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.move< std::shared_ptr<const_decl_t> > (std::move (that.value));
        break;

      case symbol_kind::S_const_def: // const_def
        value.move< std::shared_ptr<const_def_t> > (std::move (that.value));
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.move< std::shared_ptr<const_init_val_t> > (std::move (that.value));
        break;

      case symbol_kind::S_decl: // decl
        value.move< std::shared_ptr<decl_t> > (std::move (that.value));
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
        value.move< std::shared_ptr<expr> > (std::move (that.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.move< std::shared_ptr<func_def_t> > (std::move (that.value));
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.move< std::shared_ptr<func_f_param_t> > (std::move (that.value));
        break;

      case symbol_kind::S_func_f_params: // func_f_params
      case symbol_kind::S_real_func_f_params: // real_func_f_params
        value.move< std::shared_ptr<func_f_params_t> > (std::move (that.value));
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.move< std::shared_ptr<func_r_params_t> > (std::move (that.value));
        break;

      case symbol_kind::S_init_val: // init_val
        value.move< std::shared_ptr<init_val_t> > (std::move (that.value));
        break;

      case symbol_kind::S_l_val: // l_val
        value.move< std::shared_ptr<l_val_t> > (std::move (that.value));
        break;

      case symbol_kind::S_number: // number
        value.move< std::shared_ptr<number_literal_t> > (std::move (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< std::shared_ptr<stmt_t> > (std::move (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< std::shared_ptr<var_decl_t> > (std::move (that.value));
        break;

      case symbol_kind::S_var_def: // var_def
        value.move< std::shared_ptr<var_def_t> > (std::move (that.value));
        break;

      case symbol_kind::S_IDENT: // "identifier"
      case symbol_kind::S_ident: // ident
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, long long&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const long long& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ptr_list_of<block_item_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ptr_list_of<block_item_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ptr_list_of<const_init_val_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ptr_list_of<const_init_val_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ptr_list_of<expr>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ptr_list_of<expr>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ptr_list_of<init_val_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ptr_list_of<init_val_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, ptr_list_of<var_def_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const ptr_list_of<var_def_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<b_type_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<b_type_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<block_item_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<block_item_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<block_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<block_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<comp_unit_item_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<comp_unit_item_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<comp_unit_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<comp_unit_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<const_decl_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<const_decl_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<const_def_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<const_def_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<const_init_val_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<const_init_val_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<decl_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<decl_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<expr>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<expr>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<func_def_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<func_def_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<func_f_param_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<func_f_param_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<func_f_params_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<func_f_params_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<func_r_params_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<func_r_params_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<init_val_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<init_val_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<l_val_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<l_val_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<number_literal_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<number_literal_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<stmt_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<stmt_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<var_decl_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<var_decl_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<var_def_t>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<var_def_t>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_INT_CONST: // "integer"
        value.template destroy< long long > ();
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.template destroy< ptr_list_of<block_item_t> > ();
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
      case symbol_kind::S_real_const_array_elements: // real_const_array_elements
        value.template destroy< ptr_list_of<const_init_val_t> > ();
        break;

      case symbol_kind::S_array_dims: // array_dims
      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.template destroy< ptr_list_of<expr> > ();
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
      case symbol_kind::S_real_init_array_elements: // real_init_array_elements
        value.template destroy< ptr_list_of<init_val_t> > ();
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.template destroy< ptr_list_of<var_def_t> > ();
        break;

      case symbol_kind::S_b_type: // b_type
        value.template destroy< std::shared_ptr<b_type_t> > ();
        break;

      case symbol_kind::S_block_item: // block_item
        value.template destroy< std::shared_ptr<block_item_t> > ();
        break;

      case symbol_kind::S_block: // block
        value.template destroy< std::shared_ptr<block_t> > ();
        break;

      case symbol_kind::S_comp_unit_item: // comp_unit_item
        value.template destroy< std::shared_ptr<comp_unit_item_t> > ();
        break;

      case symbol_kind::S_start_symbol: // start_symbol
      case symbol_kind::S_comp_unit: // comp_unit
        value.template destroy< std::shared_ptr<comp_unit_t> > ();
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.template destroy< std::shared_ptr<const_decl_t> > ();
        break;

      case symbol_kind::S_const_def: // const_def
        value.template destroy< std::shared_ptr<const_def_t> > ();
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.template destroy< std::shared_ptr<const_init_val_t> > ();
        break;

      case symbol_kind::S_decl: // decl
        value.template destroy< std::shared_ptr<decl_t> > ();
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
        value.template destroy< std::shared_ptr<expr> > ();
        break;

      case symbol_kind::S_func_def: // func_def
        value.template destroy< std::shared_ptr<func_def_t> > ();
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.template destroy< std::shared_ptr<func_f_param_t> > ();
        break;

      case symbol_kind::S_func_f_params: // func_f_params
      case symbol_kind::S_real_func_f_params: // real_func_f_params
        value.template destroy< std::shared_ptr<func_f_params_t> > ();
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.template destroy< std::shared_ptr<func_r_params_t> > ();
        break;

      case symbol_kind::S_init_val: // init_val
        value.template destroy< std::shared_ptr<init_val_t> > ();
        break;

      case symbol_kind::S_l_val: // l_val
        value.template destroy< std::shared_ptr<l_val_t> > ();
        break;

      case symbol_kind::S_number: // number
        value.template destroy< std::shared_ptr<number_literal_t> > ();
        break;

      case symbol_kind::S_stmt: // stmt
        value.template destroy< std::shared_ptr<stmt_t> > ();
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.template destroy< std::shared_ptr<var_decl_t> > ();
        break;

      case symbol_kind::S_var_def: // var_def
        value.template destroy< std::shared_ptr<var_def_t> > ();
        break;

      case symbol_kind::S_IDENT: // "identifier"
      case symbol_kind::S_ident: // ident
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type(token_type (tok))
#else
      symbol_type (int tok)
        : super_type(token_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, long long v)
        : super_type(token_type (tok), std::move (v))
#else
      symbol_type (int tok, const long long& v)
        : super_type(token_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type(token_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type(token_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
    parser (driver& drv_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT_CONST (long long v)
      {
        return symbol_type (token::INT_CONST, std::move (v));
      }
#else
      static
      symbol_type
      make_INT_CONST (const long long& v)
      {
        return symbol_type (token::INT_CONST, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENT (std::string v)
      {
        return symbol_type (token::IDENT, std::move (v));
      }
#else
      static
      symbol_type
      make_IDENT (const std::string& v)
      {
        return symbol_type (token::IDENT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID ()
      {
        return symbol_type (token::VOID);
      }
#else
      static
      symbol_type
      make_VOID ()
      {
        return symbol_type (token::VOID);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT ()
      {
        return symbol_type (token::INT);
      }
#else
      static
      symbol_type
      make_INT ()
      {
        return symbol_type (token::INT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONST ()
      {
        return symbol_type (token::CONST);
      }
#else
      static
      symbol_type
      make_CONST ()
      {
        return symbol_type (token::CONST);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::IF);
      }
#else
      static
      symbol_type
      make_IF ()
      {
        return symbol_type (token::IF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::ELSE);
      }
#else
      static
      symbol_type
      make_ELSE ()
      {
        return symbol_type (token::ELSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::WHILE);
      }
#else
      static
      symbol_type
      make_WHILE ()
      {
        return symbol_type (token::WHILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK ()
      {
        return symbol_type (token::BREAK);
      }
#else
      static
      symbol_type
      make_BREAK ()
      {
        return symbol_type (token::BREAK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE ()
      {
        return symbol_type (token::CONTINUE);
      }
#else
      static
      symbol_type
      make_CONTINUE ()
      {
        return symbol_type (token::CONTINUE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN ()
      {
        return symbol_type (token::RETURN);
      }
#else
      static
      symbol_type
      make_RETURN ()
      {
        return symbol_type (token::RETURN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GE ()
      {
        return symbol_type (token::GE);
      }
#else
      static
      symbol_type
      make_GE ()
      {
        return symbol_type (token::GE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LE ()
      {
        return symbol_type (token::LE);
      }
#else
      static
      symbol_type
      make_LE ()
      {
        return symbol_type (token::LE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQ ()
      {
        return symbol_type (token::EQ);
      }
#else
      static
      symbol_type
      make_EQ ()
      {
        return symbol_type (token::EQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NE ()
      {
        return symbol_type (token::NE);
      }
#else
      static
      symbol_type
      make_NE ()
      {
        return symbol_type (token::NE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND ()
      {
        return symbol_type (token::AND);
      }
#else
      static
      symbol_type
      make_AND ()
      {
        return symbol_type (token::AND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR ()
      {
        return symbol_type (token::OR);
      }
#else
      static
      symbol_type
      make_OR ()
      {
        return symbol_type (token::OR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT ()
      {
        return symbol_type (token::GT);
      }
#else
      static
      symbol_type
      make_GT ()
      {
        return symbol_type (token::GT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT ()
      {
        return symbol_type (token::LT);
      }
#else
      static
      symbol_type
      make_LT ()
      {
        return symbol_type (token::LT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN ()
      {
        return symbol_type (token::ASSIGN);
      }
#else
      static
      symbol_type
      make_ASSIGN ()
      {
        return symbol_type (token::ASSIGN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#else
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD ()
      {
        return symbol_type (token::ADD);
      }
#else
      static
      symbol_type
      make_ADD ()
      {
        return symbol_type (token::ADD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB ()
      {
        return symbol_type (token::SUB);
      }
#else
      static
      symbol_type
      make_SUB ()
      {
        return symbol_type (token::SUB);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL ()
      {
        return symbol_type (token::MUL);
      }
#else
      static
      symbol_type
      make_MUL ()
      {
        return symbol_type (token::MUL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV ()
      {
        return symbol_type (token::DIV);
      }
#else
      static
      symbol_type
      make_DIV ()
      {
        return symbol_type (token::DIV);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD ()
      {
        return symbol_type (token::MOD);
      }
#else
      static
      symbol_type
      make_MOD ()
      {
        return symbol_type (token::MOD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::COMMA);
      }
#else
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::COMMA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMI ()
      {
        return symbol_type (token::SEMI);
      }
#else
      static
      symbol_type
      make_SEMI ()
      {
        return symbol_type (token::SEMI);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_PAREN ()
      {
        return symbol_type (token::LEFT_PAREN);
      }
#else
      static
      symbol_type
      make_LEFT_PAREN ()
      {
        return symbol_type (token::LEFT_PAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_PAREN ()
      {
        return symbol_type (token::RIGHT_PAREN);
      }
#else
      static
      symbol_type
      make_RIGHT_PAREN ()
      {
        return symbol_type (token::RIGHT_PAREN);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_BRACKET ()
      {
        return symbol_type (token::LEFT_BRACKET);
      }
#else
      static
      symbol_type
      make_LEFT_BRACKET ()
      {
        return symbol_type (token::LEFT_BRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_BRACKET ()
      {
        return symbol_type (token::RIGHT_BRACKET);
      }
#else
      static
      symbol_type
      make_RIGHT_BRACKET ()
      {
        return symbol_type (token::RIGHT_BRACKET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_BRACE ()
      {
        return symbol_type (token::LEFT_BRACE);
      }
#else
      static
      symbol_type
      make_LEFT_BRACE ()
      {
        return symbol_type (token::LEFT_BRACE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_BRACE ()
      {
        return symbol_type (token::RIGHT_BRACE);
      }
#else
      static
      symbol_type
      make_RIGHT_BRACE ()
      {
        return symbol_type (token::RIGHT_BRACE);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 186,     ///< Last index in yytable_.
      yynnts_ = 46,  ///< Number of nonterminal symbols.
      yyfinal_ = 14 ///< Termination state number.
    };


    // User arguments.
    driver& drv;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
    };
    // Last valid token kind.
    const int code_max = 291;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_INT_CONST: // "integer"
        value.copy< long long > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.copy< ptr_list_of<block_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
      case symbol_kind::S_real_const_array_elements: // real_const_array_elements
        value.copy< ptr_list_of<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_array_dims: // array_dims
      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.copy< ptr_list_of<expr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
      case symbol_kind::S_real_init_array_elements: // real_init_array_elements
        value.copy< ptr_list_of<init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.copy< ptr_list_of<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_b_type: // b_type
        value.copy< std::shared_ptr<b_type_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block_item: // block_item
        value.copy< std::shared_ptr<block_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_block: // block
        value.copy< std::shared_ptr<block_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_comp_unit_item: // comp_unit_item
        value.copy< std::shared_ptr<comp_unit_item_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_start_symbol: // start_symbol
      case symbol_kind::S_comp_unit: // comp_unit
        value.copy< std::shared_ptr<comp_unit_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.copy< std::shared_ptr<const_decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_def: // const_def
        value.copy< std::shared_ptr<const_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.copy< std::shared_ptr<const_init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_decl: // decl
        value.copy< std::shared_ptr<decl_t> > (YY_MOVE (that.value));
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
        value.copy< std::shared_ptr<expr> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.copy< std::shared_ptr<func_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.copy< std::shared_ptr<func_f_param_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_f_params: // func_f_params
      case symbol_kind::S_real_func_f_params: // real_func_f_params
        value.copy< std::shared_ptr<func_f_params_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.copy< std::shared_ptr<func_r_params_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_init_val: // init_val
        value.copy< std::shared_ptr<init_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_l_val: // l_val
        value.copy< std::shared_ptr<l_val_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_number: // number
        value.copy< std::shared_ptr<number_literal_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.copy< std::shared_ptr<stmt_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.copy< std::shared_ptr<var_decl_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_def: // var_def
        value.copy< std::shared_ptr<var_def_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENT: // "identifier"
      case symbol_kind::S_ident: // ident
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_INT_CONST: // "integer"
        value.move< long long > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_block_elements: // block_elements
        value.move< ptr_list_of<block_item_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_const_array_elements: // const_array_elements
      case symbol_kind::S_real_const_array_elements: // real_const_array_elements
        value.move< ptr_list_of<const_init_val_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_array_dims: // array_dims
      case symbol_kind::S_array_dims_func_param: // array_dims_func_param
      case symbol_kind::S_array_dims_func_param_real: // array_dims_func_param_real
      case symbol_kind::S_array_indices: // array_indices
      case symbol_kind::S_func_r_params_elements: // func_r_params_elements
        value.move< ptr_list_of<expr> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_init_array_elements: // init_array_elements
      case symbol_kind::S_real_init_array_elements: // real_init_array_elements
        value.move< ptr_list_of<init_val_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_var_def_list: // var_def_list
        value.move< ptr_list_of<var_def_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_b_type: // b_type
        value.move< std::shared_ptr<b_type_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_block_item: // block_item
        value.move< std::shared_ptr<block_item_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_block: // block
        value.move< std::shared_ptr<block_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_comp_unit_item: // comp_unit_item
        value.move< std::shared_ptr<comp_unit_item_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_start_symbol: // start_symbol
      case symbol_kind::S_comp_unit: // comp_unit
        value.move< std::shared_ptr<comp_unit_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_const_decl: // const_decl
      case symbol_kind::S_const_decl_stmt: // const_decl_stmt
        value.move< std::shared_ptr<const_decl_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_const_def: // const_def
        value.move< std::shared_ptr<const_def_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_const_init_val: // const_init_val
        value.move< std::shared_ptr<const_init_val_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_decl: // decl
        value.move< std::shared_ptr<decl_t> > (YY_MOVE (s.value));
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
        value.move< std::shared_ptr<expr> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_func_def: // func_def
        value.move< std::shared_ptr<func_def_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_func_f_param: // func_f_param
        value.move< std::shared_ptr<func_f_param_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_func_f_params: // func_f_params
      case symbol_kind::S_real_func_f_params: // real_func_f_params
        value.move< std::shared_ptr<func_f_params_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_func_r_params: // func_r_params
        value.move< std::shared_ptr<func_r_params_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_init_val: // init_val
        value.move< std::shared_ptr<init_val_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_l_val: // l_val
        value.move< std::shared_ptr<l_val_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_number: // number
        value.move< std::shared_ptr<number_literal_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_stmt: // stmt
        value.move< std::shared_ptr<stmt_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< std::shared_ptr<var_decl_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_var_def: // var_def
        value.move< std::shared_ptr<var_def_t> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENT: // "identifier"
      case symbol_kind::S_ident: // ident
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  inline
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

} // yy
#line 2744 "parser.hh"




#endif // !YY_YY_PARSER_HH_INCLUDED
