#include "driver.hh"
#include <fstream>
#include <queue>

using std::endl;

std::pair<int, int> get_entrance_exit(int funcid, const ImProgram& imProgram) {
    int entrance = imProgram.functions[funcid].entrance;
    if(imProgram.functions[funcid].declarationOnly) return {entrance, entrance};

    int exit = -1;

    for(auto func: imProgram.functions) {
        if(func.entrance > entrance && (exit == -1 || func.entrance < exit)) {
            exit = entrance;
        }
    }
    return {entrance, exit};
}

std::set<int> get_all_func_calls(int funcid, const ImProgram& imProgram) {
    if(imProgram.functions[funcid].declarationOnly) return {};

    std::set<int> calls;

    auto [entrance, exit] = get_entrance_exit(funcid, imProgram);
    for(int i = entrance; i < exit; i++) {
        if(imProgram.imcodes[i].op == ImCode::CALL) {
            calls.insert(imProgram.imcodes[i].src1.value);
        }
    }
    return calls;
}

int get_func_size(int funcid, const ImProgram& imProgram) {
    if(imProgram.functions[funcid].declarationOnly) return {};

    std::map<int, int> sizes;

    auto [entrance, exit] = get_entrance_exit(funcid, imProgram);
    for(int i = entrance; i < exit; i++) {
        auto code = imProgram.imcodes[i];

        ImCode::Oprand oprands[] = {code.src1, code.src2, code.dest};
        for(auto oprand: oprands) {
            if(oprand.type == ImCode::Oprand::VAR) {
                auto varid = oprand.var.varID;
                if(!sizes.count(varid)) sizes[varid] = 0;
                sizes[varid] = std::max(sizes[varid], 4);
            }
        }


        if(code.op == ImCode::ALLOC) {
            sizes[code.dest.var.varID] = std::max(code.src1.value, sizes[code.dest.var.varID]);
        }
    }

    int size = 0;
    for(auto [k, v]: sizes) {
        if(k < imProgram.globalVars.size()) continue;
        size += v;
    }
    return v;
}

std::vector<int> get_label_info(const ImProgram& imProgram) {
    auto& imcodes = imProgram.imcodes;
    std::vector<int> A(imcodes.size(), -1);
    for(auto code: imcodes){
        if(code.dest.type == ImCode::Oprand::IMCODEID) {
            A[code.dest.value] = 0;
        }
    }
    int value = 0;
    for(auto& val: A) {
        if(val == 0) {
            val = value++;
        }
    }
    return A;
}


// 加上static，不要暴露符号，避免命名冲突
static std::map<int, int> var;
static std::ofstream outfile;
static int globalNum = 0;

void callFunction(const struct ImCode &code, std::string &name, bool &hasReturn) {
    for (int i = 0; i < code.arguments.size(); i++) {
        if (i < 4) {
            //如果是变量
            if (true) {
                outfile << "\tmovs\tr" << i << ", [r7, #" << var[code.arguments[i]] << "]" << endl;
            } else {
                outfile << "\tmovs\tr" << i << ", #" << code.arguments[i] << endl;
            }
        } else {
            //如果是变量
            if (true) {
                outfile << "\tmovs\tr3, [r7, #" << var[code.arguments[i]] << "]" << endl;
            } else {
                outfile << "\tmovs\tr3, #" << code.arguments[i] << endl;
            }
            if (i == 4) {
                outfile << "\tstr\tr3, [sp]" << endl;
            } else {
                outfile << "\tstr\tr3, [sp,#" << (i - 4) * 4 << "]" << endl;
            }
        }
    }
    outfile << "bl\t" << name << endl;
    if (hasReturn) {
        outfile << "\tstr\tr0, [r7, #" << var[code.dest.value] << "]" << endl;
    }

}

std::string getvar(int index, const ImProgram &program) {
    if (index < globalNum) {
        return program.globalVars[index].identifier;
    } else {
        return "[r7, #" + std::to_string(var[index]) + "]";
    }
}

void codegen(const ImProgram &program) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> functionEntrance;
    for (auto function:program.functions) {
        functionEntrance.push(function.entrance);
    }
    functionEntrance.push(program.imcodes.size());
    functionEntrance.pop();
    printf("Starting Codegen");
    globalNum = program.globalVars.size();
    outfile.open("code.S");
    outfile << "\t.arch armv7" << endl
            << "\t.eabi_attribute 28, 1" << endl
            << "\t.eabi_attribute 20, 1" << endl
            << "\t.eabi_attribute 21, 1" << endl
            << "\t.eabi_attribute 23, 3" << endl
            << "\t.eabi_attribute 24, 1" << endl
            << "\t.eabi_attribute 25, 1" << endl
            << "\t.eabi_attribute 26, 2" << endl
            << "\t.eabi_attribute 30, 6" << endl
            << "\t.eabi_attribute 34, 1" << endl
            << "\t.eabi_attribute 18, 4" << endl
            << "\t.file	\"test.c\"" << endl;
    //输出全局变量
    int varIndex = 0;
    std::string name;
    for (GlobalVarDef i :program.globalVars) {
        if (varIndex == 0) {
            outfile << "\t.text" << endl;
        }
        name = "var" + std::to_string(varIndex++);
        if (i.initValue.size() == 0) {
            outfile << "\t.comm\t" << name << "," << i.size << ",4" << endl;
        } else {
            outfile << "\t.global\t" << name << endl;
            if (i.size == 4) {
                outfile << "\t.data" << endl;
            }
            outfile << "\t.align\t2" << endl;
            outfile << "\t.type\t" << name << ", %object" << endl;
            outfile << "\t.size\t" << name << ", " << i.size << endl
                    << name << ":\n";
            for (auto initValue:i.initValue) {
                outfile << "\t.word\t" << initValue << endl;
            }
        }
    }
    //输出每一个函数
    int functionIndex = 0;
    int numFunction = program.functions.size();
    int nextFunction = functionEntrance.top();
    functionEntrance.pop();
    int varSizeNeedByFunction = 100;
    int numPrams = 1;//该函数内调用的时候最多的参数数量
    int floatStack; //最开始的栈偏移量，和numPrams有关
    if (numFunction > 1) {
        nextFunction = program.functions[1].entrance;
    }
    int codeIndex = 0;
    for (int i = 0; i < numFunction; i++) {
        auto function = program.functions[i];
        name = function.identifier;
        outfile << "\t.text\n"
                << "\t.align\t1\n"
                << "\t.global\t" << name << "\n"
                << "\t.syntax unified\n"
                << "\t.thumb\n"
                << "\t.thumb_func\n"
                << "\t.fpu vfp\n"
                << "\t.type\t" << name << ", %function" << endl;
        outfile << name << ":" << endl;
        outfile << "\tpush\t{r4, r5, r7, lr}" << endl;
//        if (name == "main") {
//            outfile << "\tpush\t{r4, r5, r7, lr}" << endl;
//        } else {
//            outfile << "\tpush\t{r4, r5, r7, lr}" << endl;
//        }
        outfile << "\tsub\tsp, sp, #" << varSizeNeedByFunction << endl;
        if (numPrams <= 4) {
            floatStack = 0;
        } else {
            floatStack = (numPrams - 4) * 4;
        }
        outfile << "\tadd\tr7, sp, #" << floatStack << endl;
        int varFunctionIndex = 0;
        for (; codeIndex < program.imcodes.size() && codeIndex < nextFunction; codeIndex++) {
            ImCode::Operator Operator = program.imcodes[codeIndex].op;
            if (Operator == ImCode::MARK) {
                int parmindex = program.imcodes[codeIndex].src1.value;
                if (parmindex < 4) {
                    outfile << "\tstr\tr" << program.imcodes[codeIndex].src1.value << ", [r7, #"
                            << varFunctionIndex * 4 << "]" << endl;
                    var[program.imcodes[codeIndex].dest.value] = varFunctionIndex * 4;
                    varFunctionIndex++;
                } else {
                    var[program.imcodes[codeIndex].dest.value] = varSizeNeedByFunction + (parmindex - 3) * 4;
                }
            } else if (Operator == ImCode::CALL) {
                for (int i = 0; i < program.imcodes[codeIndex].arguments.size(); i++) {
                    if (i < 4) {
                        //如果是变量
                        if (true) {
                            outfile << "\tmovs\tr" << i << ", "
                                    << getvar(program.imcodes[codeIndex].arguments[i], program) << endl;
                        } else {
                            outfile << "\tmovs\tr" << i << ", #" << program.imcodes[codeIndex].arguments[i] << endl;
                        }
                    } else {
                        //如果是变量
                        if (true) {
                            outfile << "\tmovs\tr3, "
                                    << getvar(program.imcodes[codeIndex].arguments[i], program) << endl;
                        } else {
                            outfile << "\tmovs\tr3, #" << program.imcodes[codeIndex].arguments[i] << endl;
                        }
                        if (i == 4) {
                            outfile << "\tstr\tr3, [sp]" << endl;
                        } else {
                            outfile << "\tstr\tr3, [sp,#" << (i - 4) * 4 << "]" << endl;
                        }
                    }
                }
                outfile << "\tbl\t" << program.functions[program.imcodes[codeIndex].src1.value].identifier << endl;
                if (program.functions[program.imcodes[codeIndex].src1.value].returnVoid) {
                    outfile << "\tstr\tr0, " << getvar(program.imcodes[codeIndex].dest.value, program) << endl;
                }
//                callFunction(program.imcodes[codeIndex],
//                             program.functions[program.imcodes[codeIndex].src1.value].identifier,
//                             program.functions[program.imcodes[codeIndex].src1.value].returnVoid);
            } else if (Operator == ImCode::RET) {
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    outfile << "\tmovs\tr3, " << getvar(program.imcodes[codeIndex].src1.value, program) << endl;
                    outfile << "\tmov\tr0, r3" << endl;
                } else {
                    outfile << "\tmovs\tr3, #" << program.imcodes[codeIndex].src1.value << endl;
                    outfile << "\tmov\tr0, r3" << endl;
                }
            } else {
                outfile << "\t这儿缺少了下标为" << codeIndex << "的代码:\t\t" << format(program.imcodes[codeIndex].op).c_str()
                        << "\t"
                        << "\t" << format(program.imcodes[codeIndex].src1).c_str()
                        << "\t" << format(program.imcodes[codeIndex].src2).c_str()
                        << "\t" << format(program.imcodes[codeIndex].dest).c_str() << endl;

            }
        }
        if (!functionEntrance.empty()) {
            nextFunction = functionEntrance.top();
            functionEntrance.pop();
        }
        outfile << "\tadds\tr7, r7, #" << varSizeNeedByFunction - floatStack << "\n"
                << "\tmov\tsp, r7" << endl;
        outfile << "\tpop\t{r4, r5, r7, pc}" << endl;
//        if (name == "main") {
//            outfile << "\tpop\t{r4, r5, r7, pc}" << endl;
//        } else {
//            outfile << "\tpop\t{r4, r5, r7}" << endl;
//            outfile << "\tbx\tlr\n";
//        }
        outfile << "\t.size\t" << name << ", .-" << name << endl;

    }
}
