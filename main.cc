#include "driver.hh"
#include "parser.hh"

int main(){
    driver drv;
    yy::parser parse(drv);
    parse.set_debug_level(true);
    return parse();
}
