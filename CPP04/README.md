*This project has been created as part of the 42 curriculum by mefische.*

# CPP Module 04 – 42 Project

## Description

CPP Module 04 introduces one of the most important object-oriented programming concepts: **polymorphism**.

Polymorphism means that the same function call can behave differently depending on the actual object behind it. In this module, the base class `Animal` is used through pointers or references, and the derived classes `Dog` and `Cat` can provide their own behavior.

This exercise also explains why `virtual` is needed in a base class function and why a polymorphic base class should have a **virtual destructor**.

## Exercise

### ex00 — Animal

This exercise introduces:

- a base class `Animal`,
- derived classes `Dog` and `Cat`,
- polymorphic function calls,
- virtual functions,
- and safe destruction through base pointers.

The goal is to understand how C++ chooses which function to call when a base pointer points to a derived object.

## Concepts Learned

### Polymorphism

Polymorphism allows one interface to represent different types of objects.

For example:

```cpp
Animal* a = new Dog();
Animal* b = new Cat();
```

Even though `a` and `b` are both `Animal*`, they can point to different derived objects. If `makeSound()` is virtual, calling it through the base pointer will use the correct derived version.

### Virtual functions

A function should be declared `virtual` in the base class when you want derived classes to provide their own version of it.

Example:

```cpp
class Animal
{
public:
    virtual void makeSound() const;
};
```

Then `Dog` and `Cat` can override it with their own sounds.

Without `virtual`, C++ decides which function to call based on the pointer type, not the real object type. With `virtual`, C++ chooses at runtime based on the actual object.

### Virtual destructors

If a class is meant to be used polymorphically, its destructor should be `virtual`.

Example:

```cpp
class Animal
{
public:
    virtual ~Animal();
};
```

This is important because if you delete a derived object through a base pointer, C++ must call the derived destructor first and then the base destructor.

Without a virtual destructor, deleting through a base pointer can cause undefined behavior, and the derived destructor may not run correctly.

### Why `virtual` is needed in `Animal`

In this exercise, `Animal` is the base type, but the program stores `Dog` and `Cat` objects through `Animal*`.

That means:

- `makeSound()` must be virtual so the correct animal sound is chosen.
- `~Animal()` must be virtual so deletion through `Animal*` is safe.

## Main ideas to remember

- Polymorphism lets one base type behave like different derived types.
- `virtual` functions enable runtime dispatch.
- `makeSound()` should be `virtual` in `Animal`.
- A polymorphic base class should have a `virtual` destructor.
- Deleting a derived object through a base pointer is only safe when the base destructor is virtual.

## Example

```cpp
Animal* meta = new Animal();
Animal* j = new Dog();
Animal* i = new Cat();

meta->makeSound();
j->makeSound();
i->makeSound();

delete meta;
delete j;
delete i;
```

This tests both polymorphism and proper destruction through base pointers.

## Resources

- [Virtual Destructor - GeeksforGeeks](https://www.geeksforgeeks.org/cpp/virtual-destructor/)
- [Virtual Destructor in C++ - Tutorialspoint](https://www.tutorialspoint.com/cplusplus/cpp_virtual_destructor.htm)
- [Polymorphism and virtual destructors](https://www.geeksforgeeks.org/cpp/when-to-use-virtual-destructors-in-cpp/)