#Tool definitions
CC ?= gcc
CXX ?= g++

#Settings
SRC_DIR := src
INCLUDE_DIR := inc 
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
NAME := ccwc

#Search path for header files
CFLAGS += -I$(INCLUDE_DIR)

#List of source files
CSOURCES = $(wildcard $(SRC_DIR)/*.c)

#Compiler flagss
CFLAGS += -Wall -g

#Linker flags
LDFLAGS +=

#Generate the corresponding list of object files in the "obj" directory
COBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(CSOURCES))
#Default rule:  Build appllication
.PHONY: all

all: $(NAME) 

#Build target application
.PHONY: $(NAME)
$(NAME): $(COBJECTS) | $(BUILD_DIR)
	$(CC) $(COBJECTS) -o $(BUILD_DIR)/$(NAME) $(LDFLAGS)

# Rule to build object files from source files
$(COBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(BUILD_DIR):
	mkdir $@ 

#Remove compiled object files and the executable
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)






