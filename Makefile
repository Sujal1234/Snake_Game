# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wnon-virtual-dtor -Wold-style-cast \
		   -Wcast-align -Wunused -Woverloaded-virtual -Wconversion -Wsign-conversion \
		   -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference \
		   -Wuseless-cast -Wdouble-promotion -Wformat=2 -pedantic -std=c++17

# Target executable
TARGET = snake

# Source files
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean