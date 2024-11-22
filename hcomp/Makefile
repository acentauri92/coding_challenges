#Tool definitions
CC ?= gcc

#Settings
SRC_DIR := src
INC_DIR := inc
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
TEST_DIR := test

PROJECT_NAME := hcomp

# Search path for header files
CFLAGS += -I$(INC_DIR)

# Source files
CSOURCES += $(wildcard $(SRC_DIR)/*c)

#Compiler flags
CFLAGS += -Wall -g

#Linker flags
LDFLAGS += 

#Generate the corresponding list of object files in the "obj" directory
COBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(CSOURCES))

#Default rule:  Build appllication
.PHONY: all clean test test_clean
	
all: $(PROJECT_NAME)

# Build target app
.PHONY: $(PROJECT_NAME)

$(PROJECT_NAME): $(COBJECTS) | $(BUILD_DIR)
	$(CC) $(COBJECTS) -o $(BUILD_DIR)/$(PROJECT_NAME) $(LDFLAGS)

# Rule to build object files
$(COBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

$(BUILD_DIR):
	mkdir $@

#Remove compiled object files and the executable
.PHONY: clean

#Run tests
test:
	make -C $(TEST_DIR)
test_clean:
	make -C $(TEST_DIR) clean

clean:
	rm -rf $(BUILD_DIR)



