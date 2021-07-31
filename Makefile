CC=g++
CC_FLAGS=-std=c++17 -g
BISON=bison --debug
FLEX=flex

hwc: main.cc parser.o scanner.o driver_compile.o driver_control.o driver_static_eval.o driver_tools.o codegen.o
	$(CC) $(CC_FLAGS) -o $@ $^

parser.o: parser.cc driver.hh
	$(CC) $(CC_FLAGS) -c $^

scanner.o: scanner.cc driver.hh
	$(CC) $(CC_FLAGS) -c $^

driver_tools.o: driver_tools.cc driver.hh
	$(CC) $(CC_FLAGS) -c $^

driver_control.o: driver_control.cc driver.hh
	$(CC) $(CC_FLAGS) -c $^

driver_compile.o: driver_compile.cc driver.hh
	$(CC) $(CC_FLAGS) -c $^

driver_static_eval.o: driver_static_eval.cc driver.hh
	$(CC) $(CC_FLAGS) -c $^

codegen.o: codegen.cc driver.hh
	$(CC) $(CC_FLAGS) -c $^

imfile: parser.cc scanner.cc

parser.cc: parser.yy
	$(BISON) -o $@ $^

parser.yy: constructs.hh

scanner.cc: scanner.ll 
	$(FLEX) -o $@ $^

clean: 
	rm -f parser.cc parser.hh scanner.cc scanner.o driver.hh.gch hwc parser.o driver_compile.o driver_control.o driver_static_eval.o driver_tools.o codegen.o hwc_noenv




