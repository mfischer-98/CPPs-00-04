# 42 C++ Modules: CPP00 to CPP04

This repository gathers the first C++ modules from the 42 curriculum, written in C++98 and centered on learning object-oriented programming step by step. These exercises gradually move from basic class design to inheritance, canonical form, and polymorphism.

## About

The goal of these modules is to build a strong foundation in C++ through small exercises that introduce core language features and object-oriented design progressively. CPP00 starts with the basics of classes, streams, and encapsulation, while later modules expand into memory management, operator overloading, inheritance, and abstract interfaces. CPP00 to CPP04 are the first real step into object-oriented programming with C++. 

## Modules overview

### CPP00

CPP00 introduces the core syntax and habits needed to move from C to C++. It focuses on namespaces, classes, member functions, standard I/O streams, initialization, `static`, `const`, constructors, and destructors.

### CPP01

CPP01 is about memory and object lifetime. It introduces dynamic allocation, references, pointers to members, file streams, and the difference between stack and heap usage.

### CPP02

CPP02 explores ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form. It is usually the module where copy constructor, copy assignment operator, and destructor start to feel like practical tools instead of theory.

### CPP03

CPP03 focuses on inheritance and class hierarchies. It builds on canonical form and introduces parent-child relationships between classes, constructor chaining, and reuse through derivation.

### CPP04

CPP04 dives into subtype polymorphism, abstract classes, interfaces, virtual functions, and deeper class hierarchy design. It also highlights deep copying and resource handling in polymorphic structures.

## Repository structure

```text
CPP00/
├── ex00/
├── ex01/
├── ex02/
...
CPP01/
├── ex00/
├── ex01/
...
CPP02/
CPP03/
CPP04/
```

Each exercise is self-contained and usually includes its own source files, headers, and `Makefile`.

## Build

All exercises can be compiled from inside their own folder:

```bash
cd CPP00/ex01
make
./phonebook
```

The binary name depends on the exercise, but the general workflow stays the same: enter the exercise directory, build with `make` and run the generated executable.
