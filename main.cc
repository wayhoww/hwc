#include "driver.hh"
#include "parser.hh"

int main(){
    freopen("sample.sy", "r", stdin);

    driver drv;
    yy::parser parse(drv);
    parse.set_debug_level(true);
    if(parse() == 0) {
        drv.compile();
        codegen(drv.imProgram);
    }
    return 1;
}
