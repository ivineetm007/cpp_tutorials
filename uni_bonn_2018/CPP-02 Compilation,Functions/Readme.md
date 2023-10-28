# Functions

```
ReturnType FuncName(ParamType1 in_1 , ParamType2 in_2) {
    // Some awesome code here.
    return return_value;
}
```

- It is a way to organize your code.
- It should do only thing and do it right.
- Return only value.
- `GOOGLE_STYLE` - Name functions in `CamelCase`
- Never return a reference to a variable defined inside a function.

```
c++ -std=c++11 -Wall -o func1.out func1.cpp
# It will give Segmentation fault
./func1.out
```

## Declaration and Definiton

- Function declaration can be separated from the implementation details
- Function `declaration` sets up an interface
- Function `definition` holds the implementation of the function that can even be hidden from the user. You can use it to hide the logic in a library.

```
c++ -std=c++11 -Wall -o func2.out func2.cpp
./func2.out
```

## Passing by value and Passing by reference

```
void DoSmth(std:: string huge_string); // Slow.
void DoSmth(std:: string& huge_string); // Faster.
```

- By default in C++, objects are copied when passed into functions
- Pass by reference, **no guarantee** that the variable value will remain same

```
c++ -std=c++11 -Wall -o func3.out func3.cpp
./func3.out
OUTPUT
12
```

- Soluton: use const references. For fundamental types, copy is just fine but for others and big varaible use const reference.

```
# It will throw an error
c++ -std=c++11 -Wall -o func4.out func4.cpp
```

## Function overloading

- Compiler infers a function from arguments
- Cannot overload based on return types.
- Avoid non-obvious overloads, like a function with float and integer.

## Default Parameters

- Default parameters should be placed after the mandatory ones in the function declaration.
- Only define it in decalaration.
- **Pros**- Simplify function calss
- **Calls**-
  - Evaluated upon every call
  - Values are hidden in declaration
  - Can lead to un expected behaviour when overused

## Header/Source Separation

- Move all declaration to header files (\*.h)
- Implementation goes to `*.cpp` or `*.cc`
- Every header file should this line `#pragma once`
- How to compile?

```
# We save the temp files (main.ii,main.s, main.o) and disabled optimizations
# This will give linked errors
# Read the main.ii files. This is the actual files that will be compiled. It doesn't have definition of MakeItSunny and MakeItRainy
c++ -std=c++11 -Wall -o main.out -O0 -save-temps main.cpp
```

- Simple Solutions
  - Either include the `tools.cpp` in the `main.cpp`. Or
  - First compile the `tools.cpp`- `c++ -std=c++11 -c tools.cpp -o tools.o`, then compile the main as `c++ -std=c++11 main.cpp tools.o -o main.out`
- Usual steps
  - Compile the modules- `c++ -std=c++11 -c tools.cpp -o tools.o`
  - Organize modules into libraries- `ar rcs libtools.a tools.o <other_modules>`
  - Link libraries when building code. `-L` to input place to search library- `c++ -std=c++11 main.cpp -L . -ltools -o main`
  - Run the code: `./main`

# Compilation

## Compilation Flags

### Warnings

- `Wall` to get all the warnings
- `Wextra` to get the extra warnings as well
- `Werror` to make every warning an error

```
# Command to get all the warnigns
c++ -std=c++11 -Wall -o warn1.out warn1.cpp
```

### Optimizations

- `00` for no optimization, `03` for full optimizations

One example was shown in the lecture, the code contains a variable whose value is assigned as `square(20)`. While using optimization flag, the compiler automatically put value 400 instead of actually calling the function as runtime. The compiler can also remove functions that are not used or does not return something. Be careful, while debugging!!

## Debugging

- `-g` for debugging
- For small programs, just adding print statements are fine
- `gdb` popular tool, for gui use `gdbgui`
  `sudo pip3 install --upgrade gdbgui`

```
c++ -std=c++11 -Wall -g -o warn1.out warn1.cpp
gdbgui warn1.out
```

## Library

- Multiple object files that are logically connected.
- Type of libraries
  - **Static**: These are just archived that are added directly to the end binary. Faster named `lib*.a`
  - **Dynamic**: These exist separately at runtime and can be referenced by a program. It can be shipped and use in the machine with same architecture. Slower named as `lib*.so`
- Create a static library with `ar rcs libname.a module.o...`

## Linking

- Linking maps a function declaration to its compiled implementation.
- To use a library, we need a header and the compiled library object.

## CMake

- Cross-platform
- The library creation and linking can be rewritten as follows:

```
add_library(tools tools.cpp)
add_executable(main main.cpp)
target_link_libraries(main tools)
```

- Typical project structure

```
|-- project_name/
| |-- CMakeLists.txt
| |-- build/ # All generated build files
| |-- bin/
| |   |-- tools_demo
| |-- lib/
| |   |-- libtools.a
| |-- src/
| |   |-- CMakeLists.txt
| |   |-- project_name
| |     |-- CMakeLists.txt
| |     |-- tools.h
| |     |-- tools.cpp
| |     |-- tools_demo.cpp
| |-- tests/ # Tests for your code
| |   |-- test_tools.cpp
| |   |-- CMakeLists.txt
| |-- readme.md # How to use your code
```

- The build is defined in CMake file.
- All the built artifacts goes to `build` folder, binary and libraries are stored in `bin/` and `lib/`

### Build Process

- CMake reads `CmakeLists.txt` sequentially
- Build steps

```
cd <project_folder>
mkdir build
cd build
cmake ..
make -j2 # Libraries are built parallelt in multiple core
```

- CMake is a scripting language which has functions, control structures etc.
- Set variable with `set(VARIABLE)` and get value by `${VAR}`
- Show a message `message(STATUS "message")`
- For clean build, just remove everything from build project

#### Use pre-compiled library

```
add_library(tools SHARED IMPORTED)
set_property(TARGET tools
            PROPERTY IMPORTED_LOCATION
            "${LIBRARY_OUTPUT_PATH}"/libtools.so)
```

### Compilation Options

- `CMAKE_BUILD_TYPE`- `Release` or `Debug`. Not set by default.
- Default Flags like `-Wall` or `-Wextra` in `CMAKE_CXX_FLAGS`
- `CMAKE_CXX_FLAGS_DEBUG`- `-g -OO`, `CMAKE_CXX_FLAGS_RELEASE`- `-O3`

### CMake hands-on

- Bulding a empty project

```
# Sample project
mkdir cmake_proj
cd cmake_proj/
touch CMakeLists.txt
mkdir src
# Edit CmakeLists.txt file,First build,  without any source code
mkdir build
cd build/
# cmake will create a Makefile
cmake ..
# make will not do anything since we don't have any code
make
```

- Add source code
  - Update `CMakeLists` file to add subdirectory
  - Add Cmake file in subdirectory
  - Create a `main.cpp` and add it's existence in Cmake file inside `src`. On cmake build, we can see a `src` folder in build folder and `bin_main` executable inside `src`
  - Add `hello.h` with a defition of a function and include it in main. Try to build again

```
rm -rf build/*
cd src/
touch CMakeLists.txt
cd ../build
cmake ..
make
```

- Build with library
  - Create new file `hello.cpp`, move the function declaration from `hello.h`
  - Update cmake in `src` folder
    - Add the library `add_library(hello hello.cpp)`
    - Link `target_link_libraries(bin_main hello)`. For dynamic library, we can add `SHARED` keyword in between
  - We can add more libraries and repeat the above steps.
