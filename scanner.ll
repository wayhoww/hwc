/* 也不清楚什么意思，先放着 */
%option noyywrap nounput noinput batch

%{
    #include "driver.hh"
%}

digit [0-9]

%%

{digit}+ {
    int val = std::stoi(yytext);
    return yy::parser::make_INT(val);
}

<<EOF>> return yy::parser::make_YYEOF();

%%
