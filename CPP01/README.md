*This project has been created as part of the 42 curriculum by mefische.*

# CPP Module 01 – 42 Project

## Description

CPP Module 01 is the second C++ project of the 42 curriculum. Its purpose is to introduce some of the main features that distinguish C++ from C, such as dynamic memory allocation, references, pointers to members and basic file handling.

Throughout this module, I learned how to manage memory with `new` and `delete`, how references differ from pointers, how to use member function pointers and how to work with file streams in C++98.

## Instructions

### 🛠️ Compilation

Enter the desired exercise directory and compile the project:

```bash
cd ex00
make
```

The Makefile compiles the project using:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

### ex00 — Memory Allocation

A simple introduction to dynamic memory in C++.

### ex01 — Zombie

An exercise about arrays of objects and heap allocation.

### ex02 — Moar brainz!

An exercise about stack-allocated objects and object lifetime.

### ex03 — HumanA and HumanB

An exercise about references and pointers through class design.

### ex04 — Sed is for losers

An exercise about reading and writing files, and replacing text without using `std::string::replace`.

### ex05 — Harl 2.0

An exercise about pointers to member functions.

## Project Structure

```text
CPP01/
├── ex00/
├── ex01/
├── ex02/
├── ex03/
├── ex04/
├── ex05/
└── README.md
```

Each exercise contains its own source files and Makefile.

## Concepts Learned

### Memory allocation

In C, dynamic memory is allocated with `malloc()` and released with `free()`.
In C++, dynamic memory is allocated with `new` and released with `delete`.

`new` allocates memory and calls the constructor of an object.
`delete` releases the memory and calls the destructor.

For arrays, `new[]` and `delete[]` must be used instead of `new` and `delete`. For arrays, use `new[]` and `delete[]`.

```cpp
int *ptr = new int;
*ptr = 45;
delete ptr;
```

```cpp
Zombie* horde = new Zombie[N];
delete[] horde;
```

### References

A reference is an alias for an existing object.

Important rules:
- it must be initialized when declared,
- it cannot be null,
- it cannot be changed to refer to another object later,
- it behaves like a direct name for the same value.

References are useful when a function or class must always work with a valid object.

### Pointers to members

A pointer to member refers to a class member, not a free function.

Example:

```cpp
void (Harl::*funcs)(void);[4]
```

This is an array of pointers to member functions of `Harl`.

To call one:

```cpp
(this->*funcs[i])();
```

### File handling

File streams are used to read from and write to files in C++.

The main file stream classes are:
- `std::ifstream` for reading.
- `std::ofstream` for writing.
- `std::fstream` for both reading and writing.

`std::string::c_str()` converts a `std::string` into a C-style string, which is useful when passing a filename to file stream functions in C++98.

`std::getline()` reads a full line from a stream, stopping at the newline character.
The newline is not stored in the string, so it must be handled manually when writing the output back to another file.

`operator<<` writes data to an output stream.

For text replacement, `std::string::find`, `erase`, and `insert` can be used together to manually replace substrings without using `std::string::replace`.

Example:

```cpp
size_t pos = line.find(oldString);
if (pos != std::string::npos)
{
    line.erase(pos, oldString.length());
    line.insert(pos, newString);
}
```

## Resources

### C++ Reference

- [cppreference](https://en.cppreference.com/w/cpp)
- [cplusplus.com tutorial](https://cplusplus.com/doc/tutorial/)

### C++98

- [ISO C++](https://isocpp.org/)
- [C++ language reference](https://en.cppreference.com/w/cpp/language)

### Helpful extras

- [cppreference `std::string`](https://en.cppreference.com/w/cpp/string/basic_string)
- [cppreference `std::getline`](https://en.cppreference.com/w/cpp/string/basic_string/getline)
- [cppreference `std::ifstream::open`](https://cplusplus.com/reference/fstream/ifstream/open/)
- [cppreference `std::basic_string::erase`](https://en.cppreference.com/w/cpp/string/basic_string/erase)
- [cppreference `std::string::find`](https://en.cppreference.com/w/cpp/string/basic_string/find)
- [Getter return discussion](https://stackoverflow.com/questions/134731/returning-a-const-reference-to-an-object-instead-of-a-copy)
- [Getter copy vs reference discussion](https://stackoverflow.com/questions/2182408/return-a-const-reference-or-a-copy-in-a-getter-function)