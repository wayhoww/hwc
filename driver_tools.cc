#include "driver.hh"

// 为了避免 multiple def 暂时放这儿
std::string format(ImCode::Operator op) {
    switch (op) {
    case ImCode::Operator::ALLOC :      return "alloc";
    case ImCode::Operator::ASSIGN :     return "=";
    case ImCode::Operator::CALL :       return "call";
    case ImCode::Operator::DAGET :      return "*get";
    case ImCode::Operator::DASET :      return "*set";
    case ImCode::Operator::DIVIDE :     return "/";
    case ImCode::Operator::JEQ :        return "j==";
    case ImCode::Operator::JGE :        return "j>=";
    case ImCode::Operator::JGT :        return "j>";
    case ImCode::Operator::JLE :        return "j<=";
    case ImCode::Operator::JLT :        return "j<";
    case ImCode::Operator::JNE :        return "j!=";
    case ImCode::Operator::JUMP :       return "jmp";
    case ImCode::Operator::MARK :       return "mark";
    case ImCode::Operator::MINUS :      return "-";
    case ImCode::Operator::MODULE :     return "%";
    case ImCode::Operator::MULTIPLY :   return "*";
    case ImCode::Operator::PLUS :       return "+";
    case ImCode::Operator::RET :        return "ret";
    default:
        assert(false);
        return "error";
    }
}


std::string format(const ImCode::Oprand& oprand) {
    char buffer[1025];
    switch (oprand.type) {
    case ImCode::Oprand::FUNCID:
        sprintf(buffer, "func %d", oprand.value);
        break;
    case ImCode::Oprand::IMCODEID:
        sprintf(buffer, "imcode %d", oprand.value);
        break;
    case ImCode::Oprand::IMMEDIATE:
        sprintf(buffer, "#%d", oprand.value);
        break;
    case ImCode::Oprand::PARAMID:
        sprintf(buffer, "param %d", oprand.value);
        break;
    case ImCode::Oprand::VAR:
        if(oprand.var.isTemp) {
            sprintf(buffer, "$%d (tmp)", oprand.var.varID);
        }else{
            sprintf(buffer, "$%d", oprand.var.varID);
        }
        break;
    case ImCode::Oprand::INVALID:
        sprintf(buffer, "");
        break;
    default:
        sprintf(buffer, "");
        assert(false);
        break;
    }
    return std::string(buffer);
}

template<typename int_t>
std::string format(const std::vector<int_t>& vec) {
    std::string str = "[";
    for(auto item: vec) {
        str.append(std::to_string(item));
        str.append(", ");
    }
    str.append("]");
    return str;
}

template<>
std::string format(const std::vector<Argument>& vec) {
    std::string str = "[";
    for(auto item: vec) {
        str.append("_");
        for(auto dim : item.dims) {
            str.append("[");
            if(dim >= 0){
                str.append(std::to_string(dim));
            }
            str.append("]");
        }
        str.append(", ");
    }
    str.append("]");
    return str;
}

void driver::dump_to(FILE* file) {
    fprintf(file, "Global Variables\n\n");
    fprintf(file, "%-20s%-20s%-20s%-20s%-20s\n", "VarID", "Identifier", "Size (in bytes)", "Array", "Init Value (in int32)");
    fprintf(file, "----------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < global_vars().size(); i++) {
        auto var = global_vars()[i];
        fprintf(file, "%-20d%-20s%-20d%-20s%-20s\n", i, var.identifier.c_str(), var.size,  (var.isArray ? "YES" : "NO"), format<int32_t>(var.initValue).c_str());
    }        
    fprintf(file, "\n\n");

    fprintf(file, "Functions\n\n");
    fprintf(file, "%-20s%-20s%-20s%-20s%-20s\n", "Function ID", "Function Name", "Entrance", "Start Function", "Arguments");
    fprintf(file, "----------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < functions().size(); i++) {
        auto func = functions()[i];
        fprintf(file, "%-20d%-20s%-20d%-20s%-20s\n", i, func.identifier.c_str(), func.entrance, imProgram.startFunction == i ? "YES" : "", format(func.arguments).c_str());
    }
    fprintf(file, "\n\n");

    fprintf(file, "Immediate Code\n\n");
    fprintf(file, "%-20s%-20s%-20s%-20s%-20s%-20s\n", "ImCode ID", "Operator", "Src1", "Src2", "Dest", "Arguments");
    fprintf(file, "------------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < imcodes().size(); i++) {
        auto code = imcodes()[i];
        fprintf(file, "%-20d%-20s%-20s%-20s%-20s%-20s\n", i, format(code.op).c_str(), format(code.src1).c_str(), format(code.src2).c_str(), format(code.dest).c_str(), format<int32_t>(code.arguments).c_str());
    }
}