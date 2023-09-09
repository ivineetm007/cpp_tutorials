Everything starts with main which is a function that returns an **error code** -

- 0 means OK
- It can be any number in [1,255]

`#include` directive- Copies the content of file into the current file

- `#include <file>`- system include files
- `#include "file"`- local include files

## I/O streams

Handle `stdin`, `stdout` and `stderr`

- `std::cin` maps to `stdin`
- `std::cout` maps to `stdout`
- `std::cerr` maps to `stderr`

`#include <iostream>` to use I/O Streams. It is part of C++ standard library

## Compile and Run

- Compilation is translation from text to mahcine code. Compilers `gcc`, `Clang` (Smaller and easier one) and `VisualC++` (Windows)

```
# c++ here refers to any compiler in system. It could be g++
# -o name of the compiled program
c++ -std=c++11 -o hello_world hello_world.cpp
./hello_world
```
