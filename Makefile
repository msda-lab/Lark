# Lark Makefile

TARGET = lark 

SRC_DIR = ./src

INC_PATH = -I$(SRC_DIR)/include\
		   -I$(SRC_DIR)/util\
		   -I$(SRC_DIR)/main\
		   -I$(SRC_DIR)/parser\
		   -I$(SRC_DIR)/simulator\
		   -I$(SRC_DIR)/circuit\
		   -I$(SRC_DIR)/device\
		   -I$(SRC_DIR)/device/resistor\
		   -I$(SRC_DIR)/device/capacitor\
		   -I$(SRC_DIR)/device/vsource\
		   -I$(SRC_DIR)/device/isource\
		   -I$(SRC_DIR)/numeric\
		   -I$(SRC_DIR)/analysis\
		   -I$(SRC_DIR)/analysis/dc\
		   -I$(SRC_DIR)/analysis/ac\
		   -I$(SRC_DIR)/analysis/tran
		   #-I$(SRC_DIR)/device/mosfet/level1

LIB_PATH = 

LIBS = 

VPATH = $(SRC_DIR)/main:\
        $(SRC_DIR)/simulator:\
		$(SRC_DIR)/circuit:\
		$(SRC_DIR)/parser:\
		$(SRC_DIR)/util:\
		$(SRC_DIR)/device:\
		$(SRC_DIR)/device/resistor:\
		$(SRC_DIR)/device/capacitor:\
		$(SRC_DIR)/device/vsource:\
		$(SRC_DIR)/device/isource:\
		$(SRC_DIR)/numeric:\
		$(SRC_DIR)/analysis:\
		$(SRC_DIR)/analysis/dc:\
		$(SRC_DIR)/analysis/ac:\
		$(SRC_DIR)/analysis/tran:

		#$(SRC_DIR)/device/mosfet/level1:
		
SRCS = $(foreach dir, $(subst :, , $(VPATH)), $(wildcard $(dir)/*.cpp))

OBJ_DIR = ./build

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(subst .cpp,.o, $(SRCS))))

DEPS = $(OBJS:%.o=%.d)

CXX = clang++
#CXX = g++

#CXXFLAGS = -Wall -g -DDEBUG -std=c++11 $(INC_PATH)
CXXFLAGS = -Wall -g -std=c++11 $(INC_PATH)
#CXXFLAGS = -w -g -std=c++11  $(INC_PATH)
LDXXFLAGS = $(LIBS) $(LIB_PATH)

RM = rm -f

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $^ $(LDXXFLAGS)

-include $(DEPS)

$(OBJ_DIR)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c -MMD $<


.PHONY : clean

clean:
	$(RM) $(OBJS) $(TARGET) $(DEPS)
