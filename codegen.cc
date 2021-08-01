#include "driver.hh"
#include <fstream>
#include <queue>

using std::endl;

std::map<int, int> var;
std::ofstream outfile;
int globalNum = 0;

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
            } else if (Operator == ImCode::ASSIGN) {
                outfile << "\tmovs\tr3, #" << program.imcodes[codeIndex].src1.value;
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
            }  else if (Operator == ImCode::DIVIDE) {
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    outfile<<"除法正在实现"<<endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    outfile<<"除法正在实现"<<endl;
                } else {
                    outfile<<"除法正在实现"<<endl;
                }
            }   else if (Operator == ImCode::MODULE) {
                if (program.imcodes[codeIndex].src1.type == ImCode::Oprand::IMMEDIATE &&
                    program.imcodes[codeIndex].src2.type == ImCode::Oprand::VAR) {
                    outfile<<"求余正在实现"<<endl;
                } else if (program.imcodes[codeIndex].src2.type == ImCode::Oprand::IMMEDIATE &&
                           program.imcodes[codeIndex].src1.type == ImCode::Oprand::VAR) {
                    outfile<<"除法正在实现"<<endl;
                } else {
                    outfile<<"除法正在实现"<<endl;
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
            varFunctionIndex = 0;
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
