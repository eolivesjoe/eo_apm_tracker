# Compiler and flags
CC = g++
CFLAGS = -Ieo_apm_tracker/include -I../../libs/wxWidgets/include -Wall -Wextra -std=c++20
LDFLAGS = -L../../libs/wxWidgets/lib/gcc_lib -lwxbase33u -lwxmsw33u_core

# Directories
SRC_DIR = eo_apm_tracker/src
OBJ_DIR = eo_apm_tracker/obj
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/apm_tracker

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# Make sure directories exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Default target
all: $(TARGET)

# Linking target
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.d $(TARGET)

.PHONY: all clean
