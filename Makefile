# Makefile for the c_raytracer.

# Compiler and flags:
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2 -std=c17

# Executable name
TARGET = raytracer

# Source and Object files
SRC = src/main.c src/vec3.c
OBJ = $(SRC:.c=.o)

# linkes the .o files into an executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -lm -o $(TARGET)

# Compiles .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup
clean:
	rm -f $(OBJ) $(TARGET)
