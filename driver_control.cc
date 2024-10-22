#include "driver.hh"

int32_t driver::entry(const std::string& ident, const std::vector<int32_t>& dims, bool is_const_var, const std::vector<int32_t>& init_value) {
    for(int i = symbols.size() - 1; i >= 0; i--) {
        if(symbols[i].scoop_depth < current_depth) {
            break;
        }
        if(symbols[i].identifier == ident){
            exit(101); assert(false);
        }
    }
    symbol_info sym;
    sym.identifier = ident;
    sym.scoop_depth = current_depth;
    sym.is_const = is_const_var;
    sym.dims = dims;
    sym.size = 4;
    sym.init_value = init_value;
    for(auto dim: dims) sym.size *= dim;
    symbols.push_back(sym);
    return symbols.size() - 1;
}

int32_t driver::query_var(const std::string& ident) {
    for(int i = symbols.size() - 1; i >= 0; i--) {
        if(symbols[i].identifier == ident){
            return i;
        }
    }
    exit(102); assert(false);
    return 0;
}

int32_t driver::add_function(const std::string& ident, int32_t entrance, bool returnVoid, const std::vector<Argument>& arguments) {
    for(int i = 0; i < functions().size(); i++) {
        if(functions()[i].identifier == ident){
            exit(103); assert(false);
        }
    }
    for(int i = 0; i < global_vars().size(); i++) {
        if(global_vars()[i].identifier == ident) {
            exit(104); assert(false);
        }
    }
    FunctionDef func;
    func.entrance = entrance;
    func.identifier = ident;
    func.returnVoid = returnVoid;
    func.arguments = arguments;
    functions().push_back(func);
    return functions().size() - 1;
}

int32_t driver::query_function(const std::string& ident) {
    for(int i = 0; i < functions().size(); i++) {
        auto func = functions()[i];
        if(func.identifier == ident) {
            return i;
        }
    }
    exit(105); assert(false);
    return 0;
}


int32_t driver::add_var(const std::string& ident, const std::vector<int32_t>& dims, bool is_const, const std::vector<int32_t>& init_value) {
    if(current_depth == 0) {
        for(int i = 0; i < functions().size(); i++) {
            if(functions()[i].identifier == ident){
                exit(106); assert(false);
            }
        }
        for(int i = 0; i < global_vars().size(); i++) {
            if(global_vars()[i].identifier == ident) {
                exit(107); assert(false);
            }
        }
    }
    int32_t size = 4;
    for(auto dim: dims)
        size *= dim;
    
    if(current_depth == 0) {
        GlobalVarDef var;
        var.identifier = ident;
        var.size = size;
        // TODO 这边还是转 byte 比较好
        var.initValue = init_value;
        if(dims.size())var.isArray = true;
        global_vars().push_back(var);
    }
    
    auto varID = entry(ident, dims, is_const, init_value);
    return varID;
}

int32_t driver::add_temp() {
    symbol_info sym;
    sym.size = 4;
    sym.is_const = false;
    sym.scoop_depth = current_depth;
    sym.is_temp = true;
    symbols.push_back(sym);
    return symbols.size() - 1;
}