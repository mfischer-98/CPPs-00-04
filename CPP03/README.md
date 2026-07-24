*This project has been created as part of the 42 curriculum by mefische.*


# CPP Module 03 – 42 Project


## Description


CPP Module 03 introduces one of the most important concepts in object-oriented programming: **inheritance**.


Inheritance allows a class to reuse and extend the behavior of another class instead of rewriting the same code again. It helps build a hierarchy of related classes and makes code easier to organize, reuse, and maintain.

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
CPP03/
├── ex00/
├── ex01/
├── ex02/
└── README.md
```


Each exercise contains its own source files and Makefile.


## Exercises


### ex00 — ClapTrap


An exercise about building a base class with attributes, member functions, and simple combat behavior.


### ex01 — ScavTrap


An exercise about inheritance, constructor chaining, destructor chaining, and overriding behavior in a derived class.


### ex02 — FragTrap


An exercise about another derived class with different stats and its own special ability.


## Concepts Learned


### Inheritance


Inheritance is an object-oriented concept that lets one class acquire the properties and behaviors of another class. The class being inherited from is called the **base class**, and the class that inherits is called the **derived class**.


Inheritance is useful because it allows code reuse. Instead of rewriting the same attributes and methods in every class, the base class can store the common parts and the derived class can add or change only what is different.


A simple way to think about inheritance is: **a ScavTrap is a ClapTrap**, **a FragTrap is a ClapTrap**.


### Inheritance example


```cpp
class ClapTrap
{
public:
    void attack(const std::string& target);
};

class ScavTrap : public ClapTrap
{
public:
    void guardGate();
};
```

Here, `ScavTrap` inherits the `attack()` function from `ClapTrap` and adds its own `guardGate()` function. [web:213][web:217]


### Base class and derived class


The **base class** contains the shared part of the design.  
The **derived class** extends the base class with its own features.


In CPP03, `ClapTrap` is the base class for the first exercises. `ScavTrap` and `FragTrap` are derived classes that reuse most of the base behavior but change the stats and the printed messages.


### Constructor chaining


When a derived object is created, the base class constructor runs first. Then the derived class constructor runs.  
This is called **constructor chaining**.


For example, when you create a `ScavTrap`, the program first builds the `ClapTrap` part, then the `ScavTrap` part.  
This is why your test output shows both constructor messages.


Example:


```cpp
ScavTrap a("bob");
```

This creates a `ClapTrap` subobject first, then finishes constructing `ScavTrap`.


### Destructor chaining


Destruction happens in reverse order.  
The derived class destructor runs first, then the base class destructor runs.


This is important because the child class may need to clean up its own work before the base class is destroyed.  
In your tests, this should be visible in the output when objects go out of scope.


### Protected members


In inheritance exercises, the access level of class members matters a lot.  
If a member is `private`, the derived class cannot access it directly. If it is `protected`, the derived class can access it while code outside the class still cannot.


In CPP03, the base class often uses `protected` so derived classes like `ScavTrap` and `FragTrap` can reuse and adjust the inherited stats directly.


### Virtual functions and overriding


A virtual function allows a derived class to replace the base class version with its own behavior.  
This is called **overriding**.


In CPP03, `attack()` is overridden so `ScavTrap` and `FragTrap` can print their own messages instead of always using the `ClapTrap` version.


Example:


```cpp
class ClapTrap
{
public:
    virtual void attack(const std::string& target);
};

class ScavTrap : public ClapTrap
{
public:
    void attack(const std::string& target);
};
```

If `attack()` is virtual in the base class, the derived version can behave differently.

`FragTrap` is a class derived from `ClapTrap`.  
It also inherits the shared behavior but uses different stats:
- 100 hit points,
- 100 energy points,
- 30 attack damage.


Its special function is:

```cpp
void highFivesGuys(void);
```

This prints a positive high-fives request on the standard output.


Example:


```cpp
FragTrap frank("frank");
frank.attack("enemy");
frank.highFivesGuys();
```

This shows that a derived class can reuse the base functionality while also adding its own personality.

### Main ideas to remember


- Inheritance lets a derived class reuse and extend a base class.
- Constructors run from base to derived.
- Destructors run from derived to base.
- `protected` members can be used by child classes.
- `virtual` functions allow derived classes to override behavior.
- `ScavTrap` and `FragTrap` are specialized versions of `ClapTrap`.
- `DiamondTrap` shows the problems and power of multiple inheritance.


## Resources


- [Inheritance in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/inheritance-in-c/)
- [Inheritance (C++) - Microsoft](https://learn.microsoft.com/en-us/cpp/cpp/inheritance-cpp?view=msvc-170)
- [Inheritance notes - IBM](https://www.ibm.com/docs/en/i/7.4.0?topic=reference-inheritance-c-only)
- [C++ Inheritance - W3Schools](https://www.w3schools.com/cpp/cpp_inheritance.asp)
- [CPP Module 03 subject discussion](https://www.scribd.com/document/558619654/en-subject-04-CPP-Mod03-7)
- [42 CPP03 project notes](https://github.com/dhuss42/cpp03)