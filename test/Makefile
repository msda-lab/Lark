# Test.cpp Makefile

TARGET = test

SRCS = Test.cpp

OBJS = Test.o

CXX = clang++

CXXFLAGS = -Wall -g -std=c++11

INC_PATH = 

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INC_PATH) -o $@ -c $<

.PHONY : clean

RM = rm -f

clean:
	$(RM) $(OBJS) $(TARGET)




