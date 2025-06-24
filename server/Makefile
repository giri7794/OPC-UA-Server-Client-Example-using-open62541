# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -O2

# Include path for header files
INCLUDES = -Iincludes

# Source and object files
SRC = main.cpp includes/opcua_server_wrapper.cpp
TARGET = opcua_server

# Libraries to link against
LIBS = -lpthread -lopen62541

# Default target to build the executable
all: $(TARGET)

# Link and compile the target binary
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET) $(LIBS)

# Clean rule to remove build artifacts
clean:
	rm -f $(TARGET) *.o includes/*.o
