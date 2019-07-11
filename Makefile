# Lark Makefile

TARGET = lark 

SRC_DIR = ./src

INC_PATH = -I$(SRC_DIR)/include\
		   -I$(SRC_DIR)/util\
		   -I$(SRC_DIR)/parser\
		   -I$(SRC_DIR)/analyser\
		   -I$(SRC_DIR)/circuit\
		   -I$(SRC_DIR)/parser\
		   -I$(SRC_DIR)/device\
		   -I$(SRC_DIR)/device/resistor

LIB_PATH = 

LIBS = 

VPATH = $(SRC_DIR):\
        $(SRC_DIR)/analyser:\
		$(SRC_DIR)/circuit:\
		$(SRC_DIR)/parser:\
		$(SRC_DIR)/util:\
		$(SRC_DIR)/device:\
		$(SRC_DIR)/device/resistor:

SRCS = $(foreach dir, $(subst :, , $(VPATH)), $(wildcard $(dir)/*.cpp))

OBJ_DIR = ./build

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(subst .cpp,.o, $(SRCS))))

DEPS = $(OBJS:.o=.o.d)

#CXX = clang++
CXX = g++

#CXXFLAGS = -Wall -g -std=c++11 $(INC_PATH)
CXXFLAGS = -w -g -std=c++11  $(INC_PATH)
LDXXFLAGS = $(LIBS) $(LIB_PATH)

RM = rm -f

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $^ $(LDXXFLAGS)


$(OBJ_DIR)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<


.PHONY : clean

clean:
	$(RM) $(OBJS) $(TARGET)
