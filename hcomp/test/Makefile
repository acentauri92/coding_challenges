# Get the absolute path of the Makefile and the project and test directories.
# Reference: https://matheusmbar.com/bugfree-robot/2019/04/05/makefile-first-test.html
MAKEFILE_DIR	:= $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
PROJECT_DIR	:= $(realpath $(MAKEFILE_DIR)..)

TEST_DIR	:= $(PROJECT_DIR)/test
TEST_BUILD_DIR	:= build
CPPUTEST_HOME	:= $(TEST_DIR)/cpputest

# Set variables needed by Cpputest helper Makefile.
# See ./cpputest/build/MakefileWorker.mk for info on these variabes.
INCLUDE_DIRS	:=  $(PROJECT_DIR)/inc $(CPPUTEST_HOME)/include
SRC_DIRS	:= $(PROJECT_DIR)/src
TEST_SRC_DIRS	:= $(TEST_DIR)/src
# Silence output of cpputest
TEST_RUNNER_ARGS = -c

#TODO:
#1. Replace hcomp with variable name from top Makefile
COMPONENT_NAME := $(TEST_BUILD_DIR)/hcomp
CPPUTEST_OBJS_DIR := $(TEST_DIR)/$(TEST_BUILD_DIR)
CPPUTEST_LIB_DIR := $(TEST_DIR)/$(TEST_BUILD_DIR)

# Disabling unused parameter warnings for TDD
CPPUTEST_WARNINGFLAGS := -Wno-unused-parameter

#Enable colorization for output and verbose mode
CPPUTEST_EXE_FLAGS := -c -v

# Run MakefileWorker.mk with the variables defined here
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
