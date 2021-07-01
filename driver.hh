#ifndef HWC_DRIVER_H
#define HWC_DRIVER_H

#include "parser.hh"
#include <list>
#include <string>

#define YY_DECL \
    yy::parser::symbol_type yylex (driver& drv)
YY_DECL;

#define yyterminate() return yy::parser::make_YYEOF();

/**
 * driver 中的符号表要支持两项功能：
 * 1. 作用域管理
 * 2. 根据名称查找当前作用域中的变量示例
 * 
 * 使用 enter_scoop 进入新的作用域
 * 使用 exit_scoop 退出作用域
 * 
 * 类变量 current_depth 记录当前作用域深度。根作用域的深度是 0
 * 
 * 暂时使用一个 list 来存储符号表。使用 map + list 可以
 * 做到 O(logN) 的时间复杂度
 **/

// TODO 没有检查整数越界

struct symbol_info {
    int scoop_depth;
    std::string identifier;
}

class driver {
protected:
    int current_depth = 0;          //   当前深度（见注释）
    std::list<symbol_info> symbols; //   符号表 
public:
    int enter_scoop(){
        return ++current_depth;
    }

    int exit_scoop(){
        // 先弹出当前作用域的符号。
        // TODO: 或许还要做一些额外的处理
        while(!symbols.empty() 
            && symbols.rbegin()->scoop_depth == current_depth) {
            symbols.pop_back();
        }
        return --current_depth;
    }

};

#endif