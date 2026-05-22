# libcmor

If you've ever wanted to do more with standard, portable C 17 code, this is the library for you.
It is my personal utility library designed to provide some useful functions and structures.

## Description

Originally inspired by parts of the [.NET API](https://learn.microsoft.com/en-us/dotnet/api/system.bitconverter), this project also contains heavily templated math functions.
The heavily templated code provides [_Generic](https://en.cppreference.com/c/language/generic) selection and has a type list from `metamacros.h` (like C++ type traits).

## Building

This project uses CMake for all of the build configuration. I personally used the [CMake Tools V SCode Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) to make the process a whole lot nicer. This will build both a staic and shared library suitable to your current platform and compiler.

libcmor has been compiled successfully with the following toolchains:

- macOS 15 Apple clang 
- Windows 11 25H2 VS 2022 Enterprise
- Debian 12 GCC

## Usage

Simply drop the headers you need in your project and link against the library you want, and you will be off to the races.

## Roadmap

There are several broad categories of functionality I would like to add in the future. Here's what I've thought of so far.

- [ ] Algorithms
    - [x] QuickSort
    - [x] MergeSort
- [ ] BitConverter
    - [x] To Type
    - [x] From type
    - [x] Reverse Bytes
    - [x] Join
    - [x] Split
- [ ] Build Improvements
    - [ ] Update CMakePresets.json to include well-known kits
    - [ ] Specify pedantic warning errors
    - [ ] Enable Link-Time Optimization
    - [ ] Generate both static and dynamic libraries
- [ ] Data Structures
    - [ ] AVL tree
    - [ ] Binary tree
    - [ ] Dictionary
    - [ ] Doubly-Linked List
    - [ ] Hash table
    - [ ] Ring buffers
    - [ ] Record List
    - [ ] Singularly-Linked List
    - [x] Memory pool
    - [x] Queue
    - [x] Stack
- [ ] Filters
    - [ ] Multiple types:
        - [ ] Butterworth
        - [ ] Chebyshev
        - [ ] Inverse Chebyshev
        - [ ] Elliptic
    - [ ] Order estimation
    - [ ] Normalization
    - [ ] Coefficient calculation
- [ ] Maths
    - [ ] GCD
    - [ ] Euclidean reverse solver
    - [ ] Quadratic solver
    - [x] Quaternions
    - [ ] Statistics
        - [x] Mean (arithmetic)
        - [ ] Mean (geometric)
        - [ ] Median
        - [ ] Mode
        - [ ] Standard Deviation
    - [ ] CORDIC
    - [ ] Taylor Series approximations
    - [ ] FFT
    - [x] Convolution
- [ ] Radar
    - [ ] Albersheim's equation
    - [ ] Range equation
