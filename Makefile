# Makefile for the c_raytracer.

# Compiler and flags:
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -O2 -std=c17

# Executable name
TARGET = raytracer

# Directories
SRC_DIR = src
BUILD_DIR = build

# Source and Object files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# links the .o files into an executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -lm -o $(TARGET)

#Rule to compile the .c files into build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Cleanup
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	rm output.ppm
