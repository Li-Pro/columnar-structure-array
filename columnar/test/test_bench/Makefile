SHELL = /bin/bash

LIBCOLUMNAR_INCLUDE = ../../include
LIBCOLUMNAR_CXXFLAGS = $(CXXFLAGS) -I $(LIBCOLUMNAR_INCLUDE) -c -std=c++14 -Wall -ggdb3

.PRECIOUS: %.asm

.PHONY: all test clean

all: test

test: task_test_usage task_test_aos task_test_soa

task_test_%: %_O0.asm %_O2.asm %_O3.asm
	echo Done task $@

%.asm: %.o
	gdb -batch -ex "disassemble /rs test" $< > $@

%_O0.o: %.cpp
	g++ $(LIBCOLUMNAR_CXXFLAGS) -O0 -o $@ $^

%_O2.o: %.cpp
	g++ $(LIBCOLUMNAR_CXXFLAGS) -O2 -o $@ $^

%_O3.o: %.cpp
	g++ $(LIBCOLUMNAR_CXXFLAGS) -O3 -o $@ $^

clean:
	rm -rf *.o *.asm
