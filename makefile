# https://www.youtube.com/watch?v=Dyz9O7s7B8w&list=LL&index=1&t=22s TODO ADD DEBUG STUFF
SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
#SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
SRC_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJ_NAME = play
INCLUDE_PATHS = -Iinclude
LIBRARY_FLAGS = -Llib
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g
LINKER_FLAGS = -lsdl2

all:
	$(CC) $(COMPILER_FLAGS)  $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_FLAGS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)