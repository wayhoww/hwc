CC=g++
BISON=bison
FLEX=flex

hwc: main.cc parser.o scanner.o
	$(CC) -o $@	$^

parser.o: parser.cc driver.hh
	$(CC) -c $^

scanner.o: scanner.cc driver.hh
	$(CC) -c $^

parser.cc: parser.yy 
	$(BISON) -o $@ $^

scanner.cc: scanner.ll 
	$(FLEX) -o $@ $^

clean: 
	rm -f parser.cc parser.hh scanner.cc scanner.o driver.hh.gch hwc parser.o 