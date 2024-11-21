#Tool definitions
CC ?= gcc

#Settings
SRC_DIR := src
INC_DIR := inc
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
NAME := hcomp

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
.PHONY: all
	
all: $(NAME)

# Build target app
.PHONY: $(NAME)

$(NAME): $(COBJECTS) | $(BUILD_DIR)
	$(CC) $(COBJECTS) -o $(BUILD_DIR)/$(NAME) $(LDFLAGS)

# Rule to build object files
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



