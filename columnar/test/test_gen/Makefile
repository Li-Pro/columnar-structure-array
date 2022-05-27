SHELL = /bin/bash

LIBCOLUMNAR_INCLUDE = ../../include
LIBCOLUMNAR_PREPROCESS_FLAGS = -DCOLUMNAR_NOINCLUDE -E
LIBCOLUMNAR_CXXFLAGS = $(CXXFLAGS) $(LIBCOLUMNAR_PREPROCESS_FLAGS) -I $(LIBCOLUMNAR_INCLUDE)

all: test

test: usage.cpp.out result.cpp.out
	diff usage.cpp.out result.cpp.out \
		&& echo success: results of usage.cpp and result.cpp are identical \
	|| ( echo error: results of usage.cpp and result.cpp are different; exit 1 )

%.cpp.out: %.cpp
	# preprocess, then trim macro & comment lines, EOL, and whitespaces
	g++ $(LIBCOLUMNAR_CXXFLAGS) $^ > $<.prep.out
	
	# proceed if success
	(sed -E '/^\s*(\#|\/\/)/d' $<.prep.out | tr -d '\n' | sed -E 's/[[:space:]]+/ /g') > $@

clean:
	rm -rf *.out
