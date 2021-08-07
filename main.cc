#include "driver.hh"
#include "parser.hh"
#include <cstring>
#include <string>
int main(int argc, char** argv){

    bool bison_verbose = false;
    bool imcode_verbose = false;
    const char * filename = nullptr;
    const char * outputfile = nullptr;

    for(int i = 1; i < argc; i++) {
        if(strcmp(argv[i], "--bison-verbose") == 0) {
            bison_verbose = true;
        } else if(strcmp(argv[i], "--imcode-verbose") == 0) {
            imcode_verbose = true;
        } else if(strcmp(argv[i], "-o") == 0) {
            i++;
            outputfile = argv[i];
        } else {
            filename = argv[i];
        }
    }


    if(filename) {
        freopen(filename, "r", stdin);
    }

    driver drv;
    yy::parser parse(drv);
    parse.set_debug_level(bison_verbose);
    if(parse() == 0) {
        drv.compile();
        if(imcode_verbose){
            drv.dump_to(stderr);
        }
        codegen(drv.imProgram, filename, std::string(outputfile));
        return 0;
    }
    fprintf(stderr, "failed to parse\n");
    return 1;
}
