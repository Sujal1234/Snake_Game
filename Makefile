# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Wshadow -Wnon-virtual-dtor \
		   -Wcast-align -Wunused -Woverloaded-virtual -Wconversion -Wsign-conversion \
		   -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference \
		   -Wuseless-cast -Wdouble-promotion -Wformat=2 -pedantic -g -std=c++17
DEPFLAGS = -MMD -MP

# Target executable
TARGET = snake

# Source files
SRCS = $(wildcard src/*.cpp)
OBJS = $(patsubst src/%.cpp, bin/%.o, $(SRCS))
INCLUDES = -Iheaders
DEPS = $(patsubst bin/%.o, bin/%.d, $(OBJS))

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
bin/%.o: src/%.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

# Include dependency files
# Automatically recompile .cpp files if included .h files change
-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)

.PHONY: clean