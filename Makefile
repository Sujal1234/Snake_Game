# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wnon-virtual-dtor -Wold-style-cast \
		   -Wcast-align -Wunused -Woverloaded-virtual -Wconversion -Wsign-conversion \
		   -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference \
		   -Wuseless-cast -Wdouble-promotion -Wformat=2 -pedantic -std=c++17
DEPFLAGS = -MMD -MP

# Target executable
TARGET = snake

# Source files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

# Include dependency files
# Automatically recompile .cpp files if included .h files change
-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

.PHONY: clean