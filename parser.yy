%require "3.2"
%language "c++"

%defines
%define api.token.constructor
%define api.value.type variant

%param { driver& drv }

%code requires {
  class driver;
}

%code {
    #include <iostream>
    #include "driver.hh"
    
    void yy::parser::error (const std::string& m) {
        std::cerr << m << '\n';
    }
}

%%

%token YYEOF  0  "end of file";
%token <string> INT;

/** 
 * 将生成一个语法树。之所以使用语法树，而非课上所用方式，
 * 是为了减少解析时候的思维量，
 * 也便于后期优化的时候做手脚。
 * 如果想要使用课上的方式，只要后序遍历即可。
 **/

%%

