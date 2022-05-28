SHELL = /bin/bash

PYBIND11_INCLUDES = $(shell python3 -m pybind11 --includes)

LIBCOLUMNAR_INCLUDE = ../../../columnar/include
LIBCOLUMNAR_PREPROCESS_FLAGS = -DCOLUMNAR_NOINCLUDE

PYCOLUMNAR_INCLUDE = ../../include
PYCOLUMNAR_PREPROCESS_FLAGS = $(LIBCOLUMNAR_PREPROCESS_FLAGS) -E
PYCOLUMNAR_CXXFLAGS = $(CXXFLAGS) $(PYCOLUMNAR_PREPROCESS_FLAGS) -I $(LIBCOLUMNAR_INCLUDE) -I $(PYCOLUMNAR_INCLUDE) $(PYBIND11_INCLUDES)

all: test

test: usage.cpp.out result.cpp.out
	diff usage.cpp.out result.cpp.out \
		&& echo success: results of usage.cpp and result.cpp are identical \
	|| ( echo error: results of usage.cpp and result.cpp are different; exit 1 )

%.cpp.out: %.cpp
	# preprocess, then trim macro & comment lines, EOL, and whitespaces
	g++ $(PYCOLUMNAR_CXXFLAGS) $^ > $<.prep.out
	
	# proceed if success
	(sed -E '/^\s*(\#|\/\/)/d' $<.prep.out | tr '\n' ' ' | sed -E 's/[[:space:]]+/ /g') > $@

clean:
	rm -rf *.out *.so
