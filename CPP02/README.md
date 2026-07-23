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


https://www.ibm.com/docs/en/i/7.6.0?topic=only-copy-assignment-operators-c


