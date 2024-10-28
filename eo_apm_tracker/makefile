# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++20 `wx-config --cxxflags`

# Linker flags
LDFLAGS = `wx-config --libs`

# Source files
SRC = src/main.cpp

# Output executable
OUT = main

# Build the application
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Clean up
clean:
	rm -f $(OUT)
