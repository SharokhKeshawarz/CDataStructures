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
├── src/             # Can code here if you want
├── lib/             # Source code for stack implementation
    .
    ├── include/     # Header files for the data structures
    ├── stack/       # Stack implementation
    └── utils/       # Utility functions
├── include/         # Header files
├── tests/           # Unit tests
├── bin/             # Compiled binaries and object files
├── Makefile.unix    # Build system for Linux/MacOs
├── Makefile.windows # Build system for Windows
├── .gitignore       # Ignores some files to github
└── README.md        # This file
```

## Installation and Usage
### Prerequisites
- GCC compiler
- Make
- Mingw (windows users only)

### Build Instructions
To compile for UNIX the project, simply run:
```sh
make -f Makefile.unix
```
This will:
- Compile the stack implementation
- Create a static library `libstack.a`
- Build the main executable `bin/DS`

To compile for Windows the project, simply run:
```sh
mingw32-make -f Makefile.windows
```
This will:
- Compile the stack implementation
- Create a static library `libstack.lib`
- Build the main executable `bin/DS.exe`

### Running the Program
After building, run the executable:
```sh
# unix
./bin/DS
# windows
./bin/DS.exe
```

### Running Tests
To run unit tests, execute:
```sh
# unix
make -f Makefile.unix tests
```
```sh
# windows
mingw32-make -f Makefile.windows tests
```
This will compile and run test cases using the Unity framework.

### Cleaning the Project
To remove compiled files:
```sh
# unix
make -f Makefile.unix clean
```
```sh
# windows
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
