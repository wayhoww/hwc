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

%nterm <std::vector<char>> program;
program: list {
    for(auto item: $1) {
        std::cout << item << ", ";
    }
    std::cout << std::endl;
}
;

%nterm <std::vector<int>> list;
list: 
    %empty {}
  | integer list { 
        $$ = $2; $$.push_back($1);
    }
;

%nterm <int> integer;
integer:
    INT
;

%token <int> INT;


%%

