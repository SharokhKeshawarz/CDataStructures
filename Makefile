CC = gcc -std=c23 -g -Wall -Wextra -Wpedantic
CFLAGS = -Iinclude -Ilib/stack -Ilib  # Add -Ilib to include lib/main.h

LDFLAGS = -L. -lmystack  # Assuming the library will be located in lib/ and named libmystack.a

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, bin/%.o, $(SRC))  # Place object files in bin/
EXEC = bin/DS.exe

LIB_SRC = $(wildcard lib/stack/*.c)
LIB_OBJ = $(patsubst lib/stack/%.c, bin/stack/%.o, $(LIB_SRC))  # Place object files for the library in bin/stack/
LIBRARY = libmystack.a  # Output static library in the root folder (libmystack.a)

# Ensure bin and bin/stack directories exist
$(shell mkdir -p bin/stack)

all: $(EXEC)

# Compile the library object files (store in bin/stack)
bin/stack/%.o: lib/stack/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create the static library (store in root folder)
$(LIBRARY): $(LIB_OBJ)
	ar rcs $@ $^

# Compile the source files for the main executable (store in bin/)
bin/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link the object files and the library to create the executable
$(EXEC): $(OBJ) $(LIBRARY)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

# Clean the compiled files
clean:
	rm -f bin/*.o bin/stack/*.o $(EXEC) $(LIBRARY)
