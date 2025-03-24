# Compiler and Flags
CC = gcc
CFLAGS = -g -Wall -Wextra -Wpedantic -Ilib -Ilib/include -IUnity  # Include project and Unity headers
LDFLAGS = -L. -lstack  # Link with libstack.a

# Source and Object Files
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, bin/%.o, $(SRC))  # Store compiled objects in bin/
EXEC = bin/DS.exe

# Library Source Files
LIB_SRC = $(wildcard lib/**/*.c)  # Look for .c files in lib/** (all subdirectories)
LIB_OBJ = $(patsubst lib/%.c, bin/%.o, $(LIB_SRC))  # Convert to object files in bin/
LIBRARY = libstack.a  # Static library output

# Unity Test Files
TEST_SRC = $(wildcard tests/*.c)
$(info Test Files Found: $(TEST_SRC))
TEST_OBJ = $(patsubst tests/%.c, bin/tests/%.o, $(TEST_SRC))  # Store test objects in bin/tests/
UNITY_SRC = Unity/unity.c  # Unity framework source file
TEST_EXEC = bin/tests/test_runner.exe  # Test executable

# Ensure bin directories exist
$(shell mkdir -p bin bin/stack bin/utils bin/tests)

# Default Target: Build and Run
all: $(EXEC)
	@echo "Executing Program..."
	./$(EXEC)

# Compile Library Object Files
bin/%.o: lib/%.c
	@mkdir -p $(dir $@)  # Ensure subdirectories exist
	$(CC) $(CFLAGS) -c $< -o $@

# Create Static Library
$(LIBRARY): $(LIB_OBJ)
	@echo "Creating Static Library $(LIBRARY)..."
	ar rcs $@ $^
	ranlib $@

# Compile Main Executable Object Files
bin/%.o: src/%.c
	@mkdir -p $(dir $@)  # Ensure subdirectories exist
	$(CC) $(CFLAGS) -c $< -o $@

# Link Executable
$(EXEC): $(OBJ) $(LIBRARY)
	@echo "Linking Executable $(EXEC)..."
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

# Compile and Run Unity Tests
test: $(TEST_EXEC)
	@echo "Running Tests..."
	./$(TEST_EXEC)

# Compile Test Object Files (store in bin/tests/)
bin/tests/%.o: tests/%.c
	@mkdir -p $(dir $@)  # Ensure subdirectories exist
	$(CC) $(CFLAGS) -c $< -o $@

# Compile Test Executable
$(TEST_EXEC): $(TEST_OBJ) $(LIBRARY) $(UNITY_SRC)
	@echo "Compiling Tests..."
	$(CC) $(CFLAGS) $(TEST_OBJ) $(UNITY_SRC) $(LDFLAGS) -o $(TEST_EXEC)

# Recompile Everything
re: clean all

# Clean Compiled Files
clean:
	@echo "Cleaning up..."
	rm -f bin/*.o bin/*/*.o bin/tests/*.o $(EXEC) $(LIBRARY) $(TEST_EXEC)
	rm -R -f bin/*

# PHONY to avoid conflicts with files named "clean", "all", or "test"
.PHONY: all clean re test
