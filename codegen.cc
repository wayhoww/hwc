#include "driver.hh"
#include <fstream>
#include <queue>

using std::endl;

std::pair<int, int> get_entrance_exit(int funcid, const ImProgram &imProgram) {
    int entrance = imProgram.functions[funcid].entrance;
    if (imProgram.functions[funcid].declarationOnly) return {entrance, entrance};

    int exit = -1;

    for (auto func: imProgram.functions) {
        if (func.entrance > entrance && (exit == -1 || func.entrance < exit)) {
            exit = func.entrance;
        }
    }
    if (exit < 0) {
        exit = imProgram.imcodes.size();
    }
    return {entrance, exit};
}

int get_max_func_call_parm(int funcid, const ImProgram &imProgram) {
    if (imProgram.functions[funcid].declarationOnly) return {};

    std::set<int> calls;

    auto[entrance, exit] = get_entrance_exit(funcid, imProgram);
    for (int i = entrance; i < exit; i++) {
        if (imProgram.imcodes[i].op == ImCode::CALL) {
            calls.insert(imProgram.imcodes[i].src1.value);
        }
    }

    int max_size = 0;
    for (auto call: calls) {
        max_size =
                imProgram.functions[call].arguments.size() > max_size ? (int) imProgram.functions[call].arguments.size()
                                                                      : (int) max_size;
    }

    return max_size;
}

int get_func_size(int funcid, const ImProgram &imProgram) {
    if (imProgram.functions[funcid].declarationOnly) return {};

    std::map<int, int> sizes;

    auto[entrance, exit] = get_entrance_exit(funcid, imProgram);
    for (int i = entrance; i < exit; i++) {
        auto code = imProgram.imcodes[i];

        ImCode::Oprand oprands[] = {code.src1, code.src2, code.dest};
        for (auto oprand: oprands) {
            if (oprand.type == ImCode::Oprand::VAR) {
                auto varid = oprand.var.varID;
                if (!sizes.count(varid)) sizes[varid] = 0;
                sizes[varid] = std::max(sizes[varid], 4);
            }
        }


        if (code.op == ImCode::ALLOC) {
            sizes[code.dest.var.varID] = std::max(code.src1.value, sizes[code.dest.var.varID]);
        }
    }

    int size = 0;
    for (auto[k, v]: sizes) {
        if (k < imProgram.globalVars.size()) continue;
        size += v;
    }
    return size;
}

std::vector<int> get_label_info(const ImProgram &imProgram) {
    auto &imcodes = imProgram.imcodes;
    std::vector<int> A(imcodes.size(), -1);
    for (auto code: imcodes) {
        if (code.dest.type == ImCode::Oprand::IMCODEID) {
            A[code.dest.value] = 0;
        }
    }
    int value = 0;
    for (auto &val: A) {
        if (val == 0) {
            val = value++;
        }
    }
    return A;
}


// 加上static，不要暴露符号，避免命名冲突
static std::map<int, int> var;
static std::map<int, bool> isParm;
static std::map<int, bool> isArray;
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

bool IsArray(int index) {
    if (isArray.find(index) == isArray.end())
        return false;
    return true;
}

bool IsParm(int index) {
    if (isParm.find(index) == isParm.end())
        return false;
    return true;
}

void PrintImeVar(std::string reg, int item) {
    outfile << "\tmovs\t" << reg << ",#" << item << endl;
}

void codegen(const ImProgram &program) {
    std::vector<int> labelCode = get_label_info(program);
    std::priority_queue<int, std::vector<int>, std::greater<int>> functionEntrance;
    for (auto function:program.functions) {
        functionEntrance.push(function.entrance);
    }
    functionEntrance.push(program.imcodes.size());
    functionEntrance.pop();
    printf("Starting Codegen");
    globalNum = program.globalVars.size();
    outfile.open("code.S");
    outfile << "\t.arch armv7-a\n"
               "\t.arch_extension virt\n"
               "\t.arch_extension idiv\n"
               "\t.arch_extension sec\n"
               "\t.arch_extension mp\n"
               "\t.eabi_attribute 28, 1\n"
               "\t.eabi_attribute 20, 1\n"
               "\t.eabi_attribute 21, 1\n"
               "\t.eabi_attribute 23, 3\n"
               "\t.eabi_attribute 24, 1\n"
               "\t.eabi_attribute 25, 1\n"
               "\t.eabi_attribute 26, 2\n"
               "\t.eabi_attribute 30, 6\n"
               "\t.eabi_attribute 34, 1\n"
               "\t.eabi_attribute 18, 4" << endl
            << "\t.file	\"test.c\"" << endl;
    //输出全局变量
    int varIndex = -1;
    std::string name;
    for (GlobalVarDef i :program.globalVars) {
        varIndex++;
        if (varIndex == 0) {
            outfile << "\t.text" << endl;
        }
        name = "var" + std::to_string(varIndex);
        if (i.initValue.size() == 0) {
            outfile << "\t.comm\t" << name << "," << i.size << ",4" << endl;
        } else {
            outfile << "\t.global\t" << name << endl;
            if (!i.isArray) {
                outfile << "\t.data" << endl;
                isArray[varIndex] = true;
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
    int varSizeNeedByFunction = get_func_size(functionIndex, program);
    int numPrams = get_max_func_call_parm(functionIndex, program);//该函数内调用的时候最多的参数数量
    functionIndex++;
    int floatStack; //最开始的栈偏移量，和numPrams有关
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
            if (labelCode[codeIndex] != -1) {
                outfile << ".label" << labelCode[codeIndex] << ":" << endl;
            }
            ImCode::Operator Operator = program.imcodes[codeIndex].op;
            if (Operator == ImCode::MARK) {
                isParm[program.imcodes[codeIndex].dest.value] = true;
                int parmindex = program.imcodes[codeIndex].src1.value;
                if (parmindex < 4) {
                    outfile << "\tstr\tr" << program.imcodes[codeIndex].src1.value << ", [r7, #"
                            << varFunctionIndex * 4 << "]" << endl;
                    var[program.imcodes[codeIndex].dest.value] = varFunctionIndex * 4;
                    varFunctionIndex++;
                } else {
                    var[program.imcodes[codeIndex].dest.value] =
                            varSizeNeedByFunction - floatStack + (parmindex - 3) * 4;
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
            } else if (Operator == ImCode::ASSIGN) {
                outfile << "\tmovs\tr3, #" << program.imcodes[codeIndex].src1.value<<endl;
                if (var.find(program.imcodes[codeIndex].dest.value) == var.end()) {
                    outfile << "\tstr\tr3, [r7, #"
                            << varFunctionIndex * 4 << "]" << endl;
                    var[program.imcodes[codeIndex].dest.value] = varFunctionIndex * 4;
                    varFunctionIndex++;
                } else {
                    outfile << "\tstr\tr3, [r7, #"
                            << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                }
            } else if (Operator == ImCode::PLUS) {
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tadds\tr3, r3, #"
                            << program.imcodes[codeIndex].src1.value << endl
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tadds\tr3, r3, #"
                            << program.imcodes[codeIndex].src2.value << endl
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;

                } else {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tadd\tr3, r3, r2\n"
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                }
            } else if (Operator == ImCode::MINUS) {
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\trsb\tr3, r3, #"
                            << program.imcodes[codeIndex].src1.value << endl
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tsubs\tr3, r3, #"
                            << program.imcodes[codeIndex].src2.value << endl
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                } else {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tsubs\tr3, r3, r2\n"
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                }
            } else if (Operator == ImCode::MULTIPLY) {
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tmovs\tr2, #"
                            << program.imcodes[codeIndex].src1.value << endl
                            << "\tmul\tr3, r2, r3\n"
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tmovs\tr2, #"
                            << program.imcodes[codeIndex].src2.value << endl
                            << "\tmul\tr3, r2, r3\n"
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                } else {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tmul\tr3, r2, r3\n"
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                }
            } else if (Operator == ImCode::DIVIDE) {
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tmovs\tr2, #"
                            << program.imcodes[codeIndex].src1.value << endl
                            << "\tsdiv\tr3, r2, r3\n"
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tmovs\tr2, #"
                            << program.imcodes[codeIndex].src2.value << endl
                            << "\tsdiv\tr3, r2, r3\n"
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                } else {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tsdiv\tr3, r2, r3\n"
                            << "\tstr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]" << endl;
                }
            } else if (Operator == ImCode::MODULE) {
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    outfile << "求余正在实现" << endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    outfile << "求余正在实现" << endl;
                } else {
                    outfile << "求余正在实现" << endl;
                }
            } else if (Operator == ImCode::JUMP) {//无条件跳转
                outfile << "\tb\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
            } else if (Operator == ImCode::JLT) {//  小于
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    PrintImeVar("r3", program.imcodes[codeIndex].src1.value);
                    outfile << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tblt\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    PrintImeVar("r2", program.imcodes[codeIndex].src2.value);
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tblt\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tblt\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                }
            } else if (Operator == ImCode::JLE) {//  小于等于
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    PrintImeVar("r3", program.imcodes[codeIndex].src1.value);
                    outfile << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tble\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    PrintImeVar("r2", program.imcodes[codeIndex].src2.value);
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tble\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tble\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                }
            } else if (Operator == ImCode::JGT) {//  大于
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    PrintImeVar("r3", program.imcodes[codeIndex].src1.value);
                    outfile << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tbgt\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    PrintImeVar("r2", program.imcodes[codeIndex].src2.value);
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tbgt\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tbgt\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                }
            } else if (Operator == ImCode::JGE) {//   大于等于
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    PrintImeVar("r3", program.imcodes[codeIndex].src1.value);
                    outfile << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tbge\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    PrintImeVar("r2", program.imcodes[codeIndex].src2.value);
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tbge\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tbge\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                }
            } else if (Operator == ImCode::JEQ) {//    如果相等则跳转
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    PrintImeVar("r3", program.imcodes[codeIndex].src1.value);
                    outfile << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tbeq\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    PrintImeVar("r2", program.imcodes[codeIndex].src2.value);
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tbeq\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else {
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].src2.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tbeq\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                }
            } else if (Operator == ImCode::JNE) {//   如果不为0则跳转
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE) {
                    PrintImeVar("r3", program.imcodes[codeIndex].src1.value);
                    PrintImeVar("r2", 0);
                    outfile << "\tcmp\tr3, r2" << endl
                            << "\tbne\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                } else {
                    PrintImeVar("r2", 0);
                    outfile << "\tldr\tr3, [r7, #" << var[program.imcodes[codeIndex].src1.value] << "]" << endl
                            << "\tcmp\tr3, r2" << endl
                            << "\tbne\t.label" << labelCode[program.imcodes[codeIndex].dest.value] << endl;
                }
            } else if (Operator == ImCode::ALLOC) {// 分配数组，dest为数组id，src1为大小
                var[program.imcodes[codeIndex].dest.value] = varFunctionIndex * 4;
                varFunctionIndex += program.imcodes[codeIndex].src1.value;
            } else if (Operator == ImCode::DAGET) {//给数组赋值对应的值，src1表示数组id，src2表示偏移地址，dest表示值
                int index = var[program.imcodes[codeIndex].src1.value];
                outfile << "\tldr\tr3, [r7, #" << index << "]\n"
                        << "\tldr\tr3, [r3, #"
                        << program.imcodes[codeIndex].src2.value * 4 << "]" << endl
                        << "\tsdr\tr3, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]\n";
            } else if (Operator == ImCode::DASET) {//取数组内对应的值，src1表示数组id，src2表示偏移地址，dest表示值
                int index = var[program.imcodes[codeIndex].src1.value];
                outfile << "\tldr\tr3, [r7, #" << index << "]\n"
                        << "\tldr\tr2, [r7, #" << var[program.imcodes[codeIndex].dest.value] << "]\n"
                        << "\tsdr\tr2, [r3, #" << program.imcodes[codeIndex].src2.value * 4 << "]" << endl;
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
            varFunctionIndex = 0;
            varSizeNeedByFunction = get_func_size(functionIndex, program);
            numPrams = get_max_func_call_parm(functionIndex, program);//该函数内调用的时候最多的参数数量
            functionIndex++;
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
