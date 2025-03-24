# Stack Library

## Overview
This repository contains a generic stack implementation in C, supporting multiple data types through an enumeration-based approach. The stack provides common operations such as push, pop, top, bottom retrieval, and searching.

## Features
- Supports various data types (integers, floats, strings, structs, etc.)
- Dynamic resizing when capacity is reached
- Stack printing utilities
- Safe memory management
- Unit testing with Unity framework

## Directory Structure
```
.
├── src/          # Source code for stack implementation
├── lib/          # Library source code
├── include/      # Header files
├── tests/        # Unit tests
├── Unity/        # Unity testing framework
├── bin/          # Compiled binaries and object files
├── Makefile      # Build system
└── README.md     # This file
```

## Installation and Usage
### Prerequisites
- GCC compiler
- Make

### Build Instructions
To compile the project, simply run:
```sh
#for Unix
make -f Makefile.unix
```
```sh
#for windows
mingw32-make -f Makefile.windows
```
This will:
- Compile the stack implementation
- Create a static library `libstack.a`
- Build the main executable `bin/DS.exe`


### Running the Program
After building, run the executable:
```sh
#for Unix and Windows
./bin/DS.exe
```

### Running Tests
To run unit tests, execute:
```sh
#for unix
make -f Makefile.unix tests
```
```sh
#for windows
mingw32-make -f Makefile.windows tests
```
This will compile and run test cases using the Unity framework.

### Cleaning the Project
To remove compiled files:
```sh
#for unix
make -f Makefile.unix clean
```
```sh
#for windows
mingw32-make -f Makefile.windows clean
```
## Contributing
1. Fork the repository
2. Create a new branch (`git checkout -b feature-branch`)
3. Make your changes and commit (`git commit -m "Description"`)
4. Push to your branch (`git push origin feature-branch`)
5. Open a Pull Request

## License
This project is licensed under the MIT License - see the `LICENSE` file for details.

