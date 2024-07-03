# ID: 3224653689
# MAIL: adam.sinale@gmail.com

CC=g++
FLAGS=-std=c++14 -Werror -Wsign-conversion -Wall -Wextra -std=c++11

# Source files and object files
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

# Target executable
TARGET := catan

# Default target
all: $(TARGET)

test: $(TARGET)
	./$(TARGET) test
	
# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)
