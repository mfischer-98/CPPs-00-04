*This project has been created as part of the 42 curriculum by mefische.*

# CPP Module 02 – 42 Project

## Description

CPP Module 02 introduces some of the most important ideas in C++: ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form.

Throughout this module, I learned how to make custom classes behave like built-in types, how to overload operators such as `+`, `-`, `<<`, `++`, and how to design a class so that copying, assignment, and destruction behave correctly and predictably.

This module also introduces fixed-point numbers, which are a useful way to represent decimal values without relying on floating-point arithmetic all the time.

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

## Project Structure

```text
CPP02/
├── ex00/
├── ex01/
├── ex02/
└── README.md
```

Each exercise contains its own source files and Makefile.

## Exercises

### ex00 — My First Phonebook

An exercise focused on basic class creation, constructors, and object-oriented design.

### ex01 — String Manipulation and Class Design

An exercise about creating a useful class with proper canonical form and stream output.

### ex02 — Fixed-Point Numbers

An exercise about fixed-point representation, conversions, operator overloading, and class behavior.

## Concepts Learned

### Orthodox Canonical Form

The Orthodox Canonical Form is a standard way of designing C++ classes. It means your class should include four special member functions:
- Default constructor.
- Copy constructor.
- Copy assignment operator.
- Destructor.


```cpp
class Example {
private:
    int value;

public:
    Example() : value(0) {}
    Example(const Example& other) { *this = other; }
    Example& operator=(const Example& other) {
        if (this != &other)
            value = other.value;
        return *this;
    }
    ~Example() {}
};
```

These functions are important because they define how an object is created, copied, assigned, and destroyed.

Even when a class is simple, following this form helps keep the code clean, predictable, and ready for future changes.

#### Default constructor

The default constructor is called when an object is created without any arguments. It is used to give the object a valid starting state. For example, a `Fixed` object might start with a raw value of `0`.

#### Copy constructor

The copy constructor is called when a new object is created from an existing object of the same class. It creates a new object with the same content as the source object.

Example:

```cpp
Fixed a;
Fixed b(a);
```


#### Copy assignment operator

The copy assignment operator is used when one already existing object receives the value of another one.

Example:

```cpp
Fixed a;
Fixed b;
a = b;
```

Here, `a` already exists, and its value is replaced with the value of `b`.

This is different from the copy constructor because assignment does not create a new object, it updates an existing one.


### Why the Orthodox Canonical Form matters

The Orthodox Canonical Form helps prevent problems when objects are copied, assigned, or destroyed. It is especially important when a class manages resources such as dynamic memory, file handles, or pointers.

Even if your class does not manage resources yet, using the canonical form is a good habit because it makes the class safer and easier to extend later.

### Ad-hoc polymorphism

Ad-hoc polymorphism means that the same function name or operator can behave differently depending on the types involved.

For example, `+` can add integers, concatenate strings, or combine custom objects if the correct overload exists.


```cpp
int a = 2;
int b = 3;
std::cout << a + b << std::endl;
```

Here, `+` adds two integers.


```cpp
std::string first = "Hello ";
std::string second = "world";
std::cout << first + second << std::endl;
```

Here, `+` concatenates strings.


The operator is the same, but the behavior changes depending on the types.

This is a form of compile-time polymorphism because the compiler chooses the correct version based on the types used in the expression. A simple idea to remember is: the same symbol can have different meanings depending on the object type.

### Operator overloading

Operator overloading means giving a new meaning to operators like `+`, `-`, `*`, `/`, `<<`, `++`, `--`, `==`, and `!=` when they are used with user-defined types.

This allows custom classes to behave more naturally, like numbers or containers.

For example, a `Fixed` class can be printed with `std::cout << fixed`, compared with `>`, and incremented with `++`.

Operator overloading is useful because it makes code shorter, clearer, and easier to read.

### Stream insertion operator `<<`

The `<<` operator is called the stream insertion operator.

With built-in types, `std::cout << 42` works because `std::ostream` already knows how to display integers, floats, and strings.

For custom classes, C++ does not automatically know how the object should be printed, so we define:

```cpp
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
```

This function tells C++ how to send the object’s value into an output stream.

It returns the same stream so that output can be chained:

```cpp
std::cout << a << b << std::endl;
```

### Increment and decrement operators

The increment and decrement operators `++` and `--` can be overloaded in two forms: prefix and postfix.

Prefix means the object is modified first, then returned.

Postfix means the current value is returned first, and the object is modified after that.

This difference is important because `++a` and `a++` do not behave exactly the same way.


### Floating point numbers

Floating-point numbers give the illusion of storing exact real numbers, but they actually store values approximately. A float uses a sign bit, an exponent and a mantissa.

The exponent controls the range, while the mantissa controls precision. Because of this representation, some decimal values cannot be stored exactly, and small rounding differences may appear.

This is why a value like `42.42f` may not print exactly as `42.42` when converted and displayed.

### Fixed-point numbers

Fixed-point numbers are a way to represent real numbers using integers.

Instead of storing a number directly as a float, the class stores a raw integer and treats part of the bits as fractional bits.

This means the value is stored with a fixed scale.

For example, if the number of fractional bits is `8`, then the scale factor is `2^8 = 256`.

That means:
- `1.0` is stored as `256`.
- `2.5` is stored as `640`.
- `0.5` is stored as `128`.

### Fixed-point integer conversion


An integer is converted to fixed-point by shifting it left by the number of fractional bits.
This multiplies the value by the scale factor.


Example:


```cpp
int n = 42;
int raw = n << 8;
std::cout << raw << std::endl;
```

This gives `42 * 256 = 10752`.


In the class, this is usually done in the constructor:


```cpp
Fixed::Fixed(const int number) {
    rawBits = number << bits;
}
```


### Fixed-point float conversion


A float is converted by multiplying it by the scale factor and rounding to the nearest integer.


This keeps the closest representable fixed-point value.


Example:


```cpp
float f = 42.42f;
int raw = roundf(f * (1 << 8));
std::cout << raw << std::endl;
```

This stores the closest raw value that represents `42.42`.


In the class, this is usually done in the constructor:


```cpp
Fixed::Fixed(const float number) {
    rawBits = roundf(number * (1 << bits));
}
```

### Static member functions

A static member function belongs to the class itself, not to one specific object.

It can be called without creating an instance of the class.

Static member functions are useful for operations that work on two objects but do not depend on a single `this` object.

In this module, `min` and `max` are good examples of static member functions.

### Main ideas to remember

- Ad-hoc polymorphism means the same operator can behave differently for different types.
- Operator overloading lets user-defined classes behave like built-in types.
- Orthodox Canonical Form gives a class the four core special member functions.
- Fixed-point numbers store scaled integers instead of true floating-point values.
- Floating-point numbers are approximate, not exact.
- Static member functions belong to the class, not to an object.

## Resources

- [cppreference](https://en.cppreference.com/w/cpp)
- [cplusplus.com tutorial](https://cplusplus.com/doc/tutorial/)
- [cppreference operator overloading](https://en.cppreference.com/w/cpp/language/operators)
- [cppreference increment/decrement operators](https://en.cppreference.com/w/cpp/language/operator_incdec)
- [cppreference static members](https://en.cppreference.com/w/cpp/language/static)
- [Orthodox Canonical Form explanation](https://hackmd.io/@ChloeIsCoding/S1D-y80bll)
- [Orthodox Canonical Form example](https://hackmd.io/@QBrv51OvRPqs9dJjL2YIig/ry9Uc8TTyl)
- [Fixed-point representation](https://www.geeksforgeeks.org/computer-organization-architecture/fixed-point-representation/)
- [Fixed-point arithmetic basics](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)
- [Copy assignment operators](https://www.ibm.com/docs/en/i/7.6.0?topic=only-copy-assignment-operators-c)
- [Ad-hoc polymorphism explanation](https://catonmat.net/cpp-polymorphism)