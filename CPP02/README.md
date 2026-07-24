Ad-hoc polymorphism, operator overloading and the Orthodox Canonical class form


From now on, all your classes must be designed in the Orthodox Canonical Form,
unless explicitly stated otherwise. They will then implement the four required member
functions below:
• Default constructor
• Copy constructor
• Copy assignment operator (assign one value to another)
• Destructor
Split your class code into two files. The header file (.hpp/.h) contains the class
definition, whereas the source file (.cpp) contains the implementation

Using Floating Point Numbers: Floating point numbers provide a kind of illusion; they look like "real" numbers, with decimals and possibly very large or small magnitudes. In reality, a 4-byte floating point number, for example, can actually hold fewer distinct values than a 4-byte integer. The reason for this is, of course, that the internal representation of floating point numbers is not straightforward. Bits representing an integer are interpreted literally as a binary number, while bits in a floating point number have a more complicated interpretation. I will talk about this interpretation at length, but first I'd like to discuss some conceptual differences between integers and floats.
"Accuracy" refers to how close a measurement is to the true value, whereas "precision" has to do with how much information you have about a quantity, how uniquely you have it pinned down.

https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

 the IEEE-754 standard. This standard is prevalent enough that it's worthwhile to look at it in depth; chances are good you'd be able to use this information on your platform (look for ieee754.h). An IEEE-754 float (4 bytes) or double (8 bytes) has three components (there is also an analogous 96-bit extended-precision format under IEEE-854): a sign bit telling whether the number is positive or negative, an exponent giving its order of magnitude, and a mantissa specifying the actual digits of the number. Using single-precision floats (32 bits) as an example, here is the bit layout:

 seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm    meaning
31                              0    bit #
s = sign bit, e = exponent, m = mantissa

Floating-point numbers in IEEE 754 are stored using a sign bit, exponent, and mantissa. The exponent controls the range, while the mantissa controls precision, so numbers are stored approximately and may need rounding.
https://www.youtube.com/watch?v=bbkcEiUjehk

Fixed Point Number
Understanding fixed point number representation requires knowledge of the shifting process described above. Simply by implicitly establishing the binary point to be at a specific place of a numeral, we can define a fixed point number type to represent a real number in computers (or any hardware, in general). Then we will just use this implicit standard to express numbers.

Two arguments are all that are required to theoretically create a fixed point type:

Width of the number representation.
Binary point position within the number.
the notation fixed<w, b>, where "w" stands for the overall amount of bits used (the width of a number) and "b" stands for the location of the binary point counting from the least significant bit (counting from 0).
https://www.geeksforgeeks.org/computer-organization-architecture/fixed-point-representation/

https://www.ibm.com/docs/en/i/7.6.0?topic=only-copy-assignment-operators-c

INT AND FLOAT CONVERSION
https://ncot.uk/devnotes/computing_maths/fixed_point_arithmetic/int_to_fixed/index.html


Polymorphism in C++
Last Updated : 27 May, 2026
The word polymorphism means having many forms. In C++, polymorphism concept can be applied to functions and operators. A single function name can work differently in different situations. Similarly, an operator works different when used in different context.

Same function or operator can behave differently depending on the context or object it is used with.
Achieved through function overloading and function overriding, improving code reusability and flexibility.
Types of Polymorphism
In C++, polymorphism is mainly divided into two types

Compile-Time Polymorphism: The function or operator is decided at the time of compilation based on how it is called.
Run-Time Polymorphism: The function is decided while the program is running based on the object being used.
https://www.geeksforgeeks.org/cpp/cpp-polymorphism/


1. Function Overloading
Function Overloading allows multiple functions to have the same name but different parameters. The difference can be in:

Number of parameters
Type of parameters
Explanation: An add() function is used to perform addition of two numbers, and it works differently for integers and floating-point values. The compiler selects the correct function based on the arguments passed during the function call.


#include <bits/stdc++.h>
using namespace std;
​
class Geeks {
public:
    
    // Function to add two integers
    void add(int a, int b) {
        cout << "Integer Sum = " << a + b
        << endl;
    }
    
    // Function to add two floating point values
    void add(double a, double b) {
        cout << "Float Sum = " << a + b
        << endl ;
    }

https://www.geeksforgeeks.org/cpp/operator-overloading-cpp/
Operator overloading means giving a new meaning to an operator (like +, -, *, []) when it is used with objects.
With operator overloading, we can make operators work for user defined classes structures.
It is an example of compile-time polymorphism.

Why use Operator Overloading?
Allows objects to behave like basic data types.
Useful for mathematical objects like Complex numbers and Vectors.
Reduces the need for extra function calls.

Important Points About Operator Overloading
At least one operand must be a user-defined type
Operators can be overloaded as member or non-member functions
Some operators (like conversion operators) must be member functions


Ad-hoc Polymorphism (Overloading)
Ad-hoc polymorphism allows functions with the same name act differently for each type. For example, given two ints and the + operator, it adds them together. Given two std::strings it concatenates them together. This is called overloading.
https://catonmat.net/cpp-polymorphism#:~:text=Ad%2Dhoc%20Polymorphism%20(Overloading),This%20is%20called%20overloading.

The Four Polymorphisms in C++
Last updated 2 weeks ago
When people talk about polymorphism in C++ they usually mean the thing of using a derived class through the base class pointer or reference, which is called subtype polymorphism. But they often forget that there are all kinds of other polymorphisms in C++, such as parametric polymorphism, ad-hoc polymorphism and coercion polymorphism.

These polymorphisms also go by different names in C++,

Subtype polymorphism is also known as runtime polymorphism.
Parametric polymorphism is also known as compile-time polymorphism.
Ad-hoc polymorphism is also known as overloading.
Coercion is also known as (implicit or explicit) casting.
In this article I'll illustrate all the polymorphisms through examples in C++ language and also give insight on why they have various other names.


<< is the stream insertion operator. With built-in types, std::cout << 42 works because ostream already knows how to print integers, floats, strings, and so on.

For your own class, C++ does not guess how to print it, so you define an overload that takes an ostream and your object, then writes a readable representation into the stream.

std::ostream& means “a reference to an output stream object,” and ostream is the C++ type behind things like std::cout.

So std::ostream& operator<<(std::ostream& os, const Fixed& fixed) means: take an output stream, write your object into it, and return the same stream so output can be chained.

What ostream is
ostream stands for output stream. It is the standard class C++ uses for writing text to outputs like the terminal, files, or string buffers.

std::cout is one specific ostream object: the standard console output stream.

Why the & is there
The & means reference, which avoids copying the stream object and keeps writing into the original stream.

That is important because you want to modify the same std::cout, not a temporary copy of it.

Operator overload (why, how, examples)
https://coddy.tech/learn/cpp/object_oriented_programming/comparison_operator_overload
https://coddy.tech/learn/cpp/object_oriented_programming/arithmetic_operator_overload
https://www.programiz.com/cpp-programming/increment-decrement-operator-overloading

what is a static member function?
Static Member Function in C++ is a special kind of function that belongs to the class itself rather than any specific object. A static keyword is used to define those functions. They can be directly called by using just the class name, without creating an instance of the class, which is an object.
These are only accessible within the body of the class they are defined in, thus, implementing class-wide operations and certain security measures.