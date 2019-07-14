# compile flex and bison
SRC_DIR = ..

INC_PATH = -I$(SRC_DIR)/include\
		   -I$(SRC_DIR)/manager\
           -I$(SRC_DIR)/util

CXX = clang++
#CXX = g++
CXXFLAGS = -w -g -std=c++11 $(INC_PATH)

FLEX = flex
BISON = bison3

BISON_TMP = location.hh position.hh stack.hh Parser.out Parser.output

SRCS = Scanner.cpp Parser.cpp Parser.hpp

all: $(SRCS)

Scanner.cpp : Scanner.l 
	$(FLEX) -o $@ $<

Parser.cpp Parser.hpp: Parser.y
	$(BISON) -d $<

.PHONY : clean

clean :
	$(RM) $(BISON_TMP) $(SRCS)
