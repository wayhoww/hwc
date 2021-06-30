#include "driver.hh"
#include "parser.hh"

int main(){
    driver drv;
    yy::parser parse(drv);
    return parse();
}
