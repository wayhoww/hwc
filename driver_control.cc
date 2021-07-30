#include "driver.hh"

uint64_t driver::entry(const std::string& ident, const std::vector<uint64_t>& dims, bool is_const_var, const std::vector<int64_t>& init_value) {
    for(int i = symbols.size() - 1; i >= 0; i--) {
        if(symbols[i].scoop_depth < current_depth) {
            break;
        }
        if(symbols[i].identifier == ident){
            assert(false);
        }
    }
    symbol_info sym;
    sym.identifier = ident;
    sym.scoop_depth = current_depth;
    sym.is_const = is_const_var;
    sym.dims = dims;
    sym.size = 8;
    sym.init_value = init_value;
    for(auto dim: dims) sym.size *= dim;
    symbols.push_back(sym);
    return symbols.size() - 1;
}

uint64_t driver::query_var(const std::string& ident) {
    for(int i = symbols.size() - 1; i >= 0; i--) {
        if(symbols[i].identifier == ident){
            return i;
        }
    }
    assert(false);
    return 0;
}

uint64_t driver::add_function(const std::string& ident, uint64_t entrance) {
    for(int i = 0; i < functions().size(); i++) {
        if(functions()[i].identifier == ident){
            assert(false);
        }
    }
    for(int i = 0; i < global_vars().size(); i++) {
        if(global_vars()[i].identifier == ident) {
            assert(false);
        }
    }
    FunctionDef func;
    func.entrance = entrance;
    func.identifier = ident;
    functions().push_back(func);
    return functions().size() - 1;
}

uint64_t driver::query_function(const std::string& ident) {
    for(int i = 0; i < functions().size(); i++) {
        auto func = functions()[i];
        if(func.identifier == ident) {
            return i;
        }
    }
    assert(false);
    return 0;
}


uint64_t driver::add_var(const std::string& ident, const std::vector<uint64_t>& dims, bool is_const, const std::vector<int64_t>& init_value) {
    if(current_depth == 0) {
        for(int i = 0; i < functions().size(); i++) {
            if(functions()[i].identifier == ident){
                assert(false);
            }
        }
        for(int i = 0; i < global_vars().size(); i++) {
            if(global_vars()[i].identifier == ident) {
                assert(false);
            }
        }
    }
    uint64_t size = 8;
    for(auto dim: dims)
        size *= dim;
    
    if(current_depth == 0) {
        GlobalVarDef var;
        var.identifier = ident;
        var.size = size;
        // TODO 这边还是转 byte 比较好
       // var.initValue = init_value;
        global_vars().push_back(var);
    }
    
    auto varID = entry(ident, dims, is_const, init_value);
    return varID;
}

uint64_t driver::add_temp() {
    symbol_info sym;
    sym.size = 8;
    sym.is_const = false;
    sym.scoop_depth = current_depth;
    sym.is_temp = true;
    symbols.push_back(sym);
    return symbols.size() - 1;
}