#include "driver.hh"

std::pair<bool, int32_t> driver::static_eval_offset(
        const ptr_list_of<expr> indices,                                     
        const std::vector<int32_t>& dims) {

    // 这个是统一的逻辑
    int offset = 0;
    int index = 1;
    for(auto exp: indices) {
        auto [ok, val] = static_eval(exp);
        if(!ok) return {false, 0};
        offset += val;
        if(index < indices.size()) offset *= dims[index++];
    }
    return {true, offset};
}

std::pair<bool, int32_t> driver::static_eval(shared_ptr<expr> root, bool for_init) {
    if(!for_init && static_eval_cache.count(root)){
        return static_eval_cache[root];
    }

    std::pair<bool, int32_t> rst1;       
    std::pair<bool, int32_t> rst2;
    auto& ok1 = rst1.first;
    auto& ok2 = rst2.first;
    auto& val1 = rst1.second;
    auto& val2 = rst2.second;
    int var_id = 0;

    auto final_result = std::make_pair(true, 0);
    auto& rst = final_result.second;

    if(auto r = dynamic_pointer_cast<logical_not_expr>(root);  r && (rst1 = static_eval(r->src), ok1)) {
        rst = !val1;
    }else if(auto r = dynamic_pointer_cast<negative_expr>(root); r && (rst1 = static_eval(r->src), ok1)) {
        rst = -val1;
    }else if(auto r = dynamic_pointer_cast<binary_expr>(root); 
                r && (rst1 = static_eval(r->src1), 
                      rst2 = static_eval(r->src2), ok1 && ok2)) {
        switch (r->op.type) {
        case operator_t::PLUS:          rst = val1 +  val2; break;
        case operator_t::MINUS:         rst = val1 -  val2; break;
        case operator_t::MULTIPLY:      rst = val1 *  val2; break;
        case operator_t::DIVIDE:        rst = val1 /  val2; break;
        case operator_t::MODULE:        rst = val1 %  val2; break;
        case operator_t::EQUAL:         rst = val1 == val2; break;
        case operator_t::NOT_EQUAL:     rst = val1 != val2; break;
        case operator_t::GREATER:       rst = val1 >  val2; break;
        case operator_t::GREATER_EQUAL: rst = val1 >= val2; break;
        case operator_t::LESS:          rst = val1 <  val2; break;
        case operator_t::LESS_EQUAL:    rst = val1 <= val2; break;
        case operator_t::LOGICAL_AND:   rst = val1 && val2; break;
        case operator_t::LOGICAL_OR:    rst = val1 || val2; break;
        default: exit(108); assert(false); break;
        }
    }else if(auto r = dynamic_pointer_cast<l_val_t>(root); 
                r && (
                var_id = query_var(r->ident),
                rst1 = static_eval_offset(r->exps, symbols[var_id].dims), 
                ok1 && (symbols[var_id].is_const || (for_init && symbols[var_id].is_static) ) )) {
        rst = symbols[var_id].init_value[val1];
    }else if(auto r = dynamic_pointer_cast<number_literal_t>(root)) {
        rst = r->value;
    }else{
        final_result.first = false;
    }
    if(!for_init) static_eval_cache[root] = final_result;
    return final_result;
}