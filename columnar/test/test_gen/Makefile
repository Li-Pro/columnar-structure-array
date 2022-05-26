SHELL = /bin/bash

LIBCOLUMNAR_INC = ../../include

all: test

test: usage.cpp.out result.cpp.out
	(g++ -DCOLUMNAR_NOINCLUDE -I $(LIBCOLUMNAR_INC) -E usage.cpp  | sed -E '/^\s*(\#|\/\/)/d' | tr -d '\n' | sed -E 's/[[:space:]]+/ /g') > usage.cpp.out
	(g++ -DCOLUMNAR_NOINCLUDE -I $(LIBCOLUMNAR_INC) -E result.cpp | sed -E '/^\s*(\#|\/\/)/d' | tr -d '\n' | sed -E 's/[[:space:]]+/ /g') > result.cpp.out
	
	diff usage.cpp.out result.cpp.out || (echo Result of usage.cpp and result.cpp are different; exit 1)

clean:
	rm -rf *.out
