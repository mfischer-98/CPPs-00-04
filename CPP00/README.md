*This project has been created as part of the 42 curriculum by mefische.*

# CPP Module 00 – 42 Project

## Description

CPP Module 00 is the first C++ project of the 42 curriculum. Its purpose is to introduce the fundamentals of C++ and object-oriented programming while transitioning from programming in C.

Throughout this module, I learned the basic syntax and concepts that distinguish C++ from C, including namespaces, classes and objects, member functions, constructors and desctructors, standard input/output streams (`std::cin` / `std::cout`) and code organization using header (`.hpp`) and source (`.cpp`) files.

## Instructions

### 🛠️ Compilation

Enter the desired exercise directory and compile the project:

```bash
cd ex00
make
```

Replace `ex00` with the corresponding exercise you want to build, such as `ex01`.

The Makefile compiles the project using:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## Exercises

### 📢 ex00 — Megaphone

A simple introduction to C++.

Concepts covered:

- Command-line arguments
- `std::string`
- `std::cout`
- Basic program structure

Run with:

```bash
./megaphone "Hello World!"
```

### 📞 ex01 — My Awesome PhoneBook

Implement a simple phonebook application using classes.

Concepts covered:

- Classes
- Objects
- Encapsulation
- User input
- Data formatting
- Arrays of objects

Run with:

```bash
./phonebook
```

## 📁 Project Structure

```text
CPP00/
├── ex00/
├── ex01/
└── README.md
```

Each exercise contains its own source files and Makefile.

## 📖 Concepts Learned

### Namespaces
A namespace is a named scope that groups related code and helps avoid name conflicts. In this project, I used the `std` namespace for standard library features such as `std::cout`, `std::string`, and `std::getline`.

```cpp
std::string name = "Melissa";
std::cout << name << std::endl;
```

### Input and output streams
C++ uses streams to handle input and output. `std::cout` sends output to the terminal, `std::cin` reads input from the terminal, and `std::getline()` reads a full line, including spaces.

```cpp
std::string command;
std::cout << "Enter a command: ";
std::getline(std::cin, command);
```

The `<<` operator inserts data into an output stream.

```cpp
std::cout << "Hello" << std::endl;
```

### I/O manipulators (`iomanip`)
The `<iomanip>` header contains tools that format input and output. In this project, I used `std::setw` to align table columns and `std::setfill` to control padding.

```cpp
std::cout << std::setw(10) << std::setfill(' ') << "Hello";
```

- `std::setw(10)` sets the width of the next output field.
- `std::setfill(' ')` sets the character used to fill extra space.

This was especially useful in the phonebook table, where columns need to line up neatly.

### Classes and objects
A `class` is a blueprint for an object. It defines what data and behavior an entity should have. An `object` is a real instance of that class, and it uses memory to store its values.

Classes let you group data and functions together, which makes code easier to organize and understand.

### Encapsulation
Encapsulation means keeping data private and using public functions to interact with it. This protects the class from invalid direct changes and gives more control over how values are updated.

```cpp
class Contact {
private:
    std::string firstName;

public:
    void setFirstName(const std::string& name);
    std::string getFirstName() const;
};
```

### Static members
Static members belong to the class itself instead of to one specific object. That means all objects of the class share the same static value.

### Member functions
Member functions belong to a class and operate on its data. They define what an object can do and how it behaves.

### Getters and setters
A getter returns the value of a private attribute. A setter changes a private attribute in a controlled way.

They are useful because they let us keep data private while still being able to read or update it safely from outside the class.

### Initialization lists
An initialization list is used in a constructor to initialize members before the constructor body runs.

```cpp
PhoneBook::PhoneBook() : index(0), oldest(0), size(0) {}
```

This sets the initial values of `index`, `oldest`, and `size` when the object is created.

Initialization lists are cleaner and more efficient than assigning values inside the constructor body.

### Const and reference
`const` means a value should not be changed. It helps prevent accidental modification and shows that a function will not alter the data it receives or the object it belongs to.

A reference (`&`) is an alias for another object. It avoids copying and lets functions work directly with existing values.

```cpp
const std::string& getFirstName() const;
```

```cpp
void Contact::setFirstName(const std::string& name)
{
    firstName = name;
}
```

In this example, `name` is passed by reference, so the function does not make a full copy of the string just to read it.

### Constructors and destructors
A constructor runs when an object is created and is used to initialize it. A destructor runs when an object is destroyed and is used to clean up.

Object lifetime follows this pattern: create, use, destroy. Constructors and destructors are part of that lifecycle.

```cpp
Contact::Contact() {}

Contact::~Contact() {}
```

### Attributes
Attributes are the data stored inside a class.

```cpp
class Contact {
private:
    std::string firstName;
    std::string lastName;
};
```

### `std::endl` vs `\n`
`std::endl` adds a newline and flushes the output buffer. `\n` only adds a newline. For normal printing, `\n` is usually enough, but `std::endl` is useful when you want to force the output to appear immediately.

### `std::getline`
`std::getline()` reads an entire line, including spaces. It is better than `std::cin >>` when you want to read names, secrets, or other text that may contain spaces.

### `std::isdigit`
For `std::isdigit`, it is safer to cast characters to `unsigned char` before checking them.

```cpp
if (!std::isdigit(static_cast<unsigned char>(input[i])))
    return false;
```

This matters because `std::isdigit` expects a value representable as `unsigned char` or `EOF`.

## 📚 Resources

### C++ Reference

- [cppreference](https://en.cppreference.com/w/cpp)
- [cppreference I/O manipulators](https://en.cppreference.com/w/cpp/header/iomanip)
- [cppreference `std::cout`](https://en.cppreference.com/w/cpp/io/cout)
- [cppreference `operator<<`](https://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2.html)
- [cplusplus.com tutorial](https://cplusplus.com/doc/tutorial/)
- [cplusplus.com classes](https://cplusplus.com/doc/tutorial/classes/)
- [cplusplus.com special members](https://cplusplus.com/doc/tutorial/classes2/)
- [cplusplus.com iomanip reference](https://cplusplus.com/reference/iomanip/)
- [cplusplus.com `setw`](https://cplusplus.com/reference/iomanip/setw/)
- [cplusplus.com `setfill`](https://cplusplus.com/reference/iomanip/setfill/)

### C++98

- [ISO C++](https://isocpp.org/)
- [C++ language reference](https://en.cppreference.com/w/cpp/language)

### Helpful extras

- [cppreference `std::isdigit`](https://en.cppreference.com/w/cpp/string/byte/isdigit)
- [cppreference `std::atoi`](https://cppreference.com/cpp/string/byte/atoi)
- [Getter return discussion](https://stackoverflow.com/questions/134731/returning-a-const-reference-to-an-object-instead-of-a-copy)
- [Getter copy vs reference discussion](https://stackoverflow.com/questions/2182408/return-a-const-reference-or-a-copy-in-a-getter-function)
