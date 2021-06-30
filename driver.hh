#ifndef HWC_DRIVER_H
#define HWC_DRIVER_H

#include "parser.hh"

#define YY_DECL \
    yy::parser::symbol_type yylex (driver& drv)
YY_DECL;

#define yyterminate() return yy::parser::make_YYEOF();

class driver {
protected:

public:

};

#endif