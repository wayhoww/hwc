CC=g++
CC_FLAGS=-std=c++11
BISON=bison
FLEX=flex

hwc: main.cc parser.o scanner.o
	$(CC) $(CC_FLAGS) -o $@ $^

parser.o: parser.cc driver.hh
	$(CC) $(CC_FLAGS) -c $^

scanner.o: scanner.cc driver.hh
	$(CC) $(CC_FLAGS) -c $^

parser.cc: parser.yy 
	$(BISON) -o $@ $^

scanner.cc: scanner.ll 
	$(FLEX) -o $@ $^

clean: 
	rm -f parser.cc parser.hh scanner.cc scanner.o driver.hh.gch hwc parser.o 