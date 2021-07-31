/* 也不清楚什么意思，先放着 */
%option noyywrap nounput noinput batch

%{
    #include "driver.hh"
%}

/**
 * 该部分是 SysY 语言的词法定义部分
 * 根据 “SysY 语言的终结符特征” 编写
 * 使用文档中的小写字母开头的符号表示非终结符号类型
 * 如，使用 identifier 而非 Ident
 * 
 * 文档中使用了 EBNF 表示词法特征。这里转成正则表达式
 **/

letter              [a-zA-Z]
digit               [0-9]
nonzero_digit       [1-9]
octal_digit         [0-7]
hexadecimal_digit   [0-9a-fA-F] 
identifier          ({letter}|_)({letter}|_|{digit})*

decimal_const       {nonzero_digit}{digit}*
octal_const         0{octal_digit}*
hexadecimal_const   (0x|0X){hexadecimal_digit}+
integer_const       {decimal_const}|{octal_const}|{hexadecimal_const}


%x IN_BLOCK_COMMENT
%x IN_LINE_COMMENT

%%


# http://westes.github.io/flex/manual/How-can-I-match-C_002dstyle-comments_003f.html

<INITIAL>{
    "/*"                BEGIN(IN_BLOCK_COMMENT);
    "//"                BEGIN(IN_LINE_COMMENT);
    "void"              { return yy::parser::make_VOID(); }
    "int"               { return yy::parser::make_INT(); }
    "const"             { return yy::parser::make_CONST(); }
    "if"                { return yy::parser::make_IF(); }
    "else"              { return yy::parser::make_ELSE(); }
    "while"             { return yy::parser::make_WHILE(); }
    "break"             { return yy::parser::make_BREAK(); }
    "continue"          { return yy::parser::make_CONTINUE(); }
    "return"            { return yy::parser::make_RETURN(); }
    ">="                { return yy::parser::make_GE();     }
    "<="                { return yy::parser::make_LE();     }
    "=="                { return yy::parser::make_EQ();     }
    "!="                { return yy::parser::make_NE();     }
    "&&"                { return yy::parser::make_AND();    }
    "||"                { return yy::parser::make_OR();     }
    ">"                 { return yy::parser::make_GT();     }
    "<"                 { return yy::parser::make_LT();     }
    "="                 { return yy::parser::make_ASSIGN(); }
    "!"                 { return yy::parser::make_NOT();    }
    "+"                 { return yy::parser::make_ADD();    }
    "-"                 { return yy::parser::make_SUB();    }
    "*"                 { return yy::parser::make_MUL();    }
    "/"                 { return yy::parser::make_DIV();    }
    "%"                 { return yy::parser::make_MOD();    }
    ","                 { return yy::parser::make_COMMA();    }
    ";"                 { return yy::parser::make_SEMI();    }
    "("                 { return yy::parser::make_LEFT_PAREN();    }
    ")"                 { return yy::parser::make_RIGHT_PAREN();    }
    "["                 { return yy::parser::make_LEFT_BRACKET();    }
    "]"                 { return yy::parser::make_RIGHT_BRACKET();    }
    "{"                 { return yy::parser::make_LEFT_BRACE();    }
    "}"                 { return yy::parser::make_RIGHT_BRACE();    }
    
    {identifier}        { return yy::parser::make_IDENT(yytext); };
    {integer_const}     { return yy::parser::make_INT_CONST(std::stoi(yytext)); };
}

<IN_BLOCK_COMMENT>{
    "*/"      BEGIN(INITIAL);
    [^*\n]+   // eat comment in chunks
    "*"       // eat the lone star
    \n        yylineno++;
}


<IN_LINE_COMMENT>{
    [^\n]+   // eat comment in chunks
    \n        { BEGIN(INITIAL); yylineno++; }
}

<<EOF>> return yy::parser::make_YYEOF();

%%
