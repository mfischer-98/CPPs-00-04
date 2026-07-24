/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:59:19 by mefische          #+#    #+#             */
/*   Updated: 2026/07/24 12:14:17 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* CONSTRUCTORS & DESTRUCTOR */

Fixed::Fixed() : rawBits(0) {}

/* Copy Constructor: Creates a new Fixed object as a copy of another Fixed object. */
Fixed::Fixed(const Fixed& other) {
	*this = other;
}

/* Copy assignment operator: Copies the internal fixed-point value from another Fixed object 
	into this object, unless both objects are the same.
	- In a more complex function I can decide which members are copied */
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		rawBits = other.rawBits;
	return *this;
}

Fixed::~Fixed() {}

/* Converts an integer to fixed-point representation by shifting left
	by the number of fractional bits (after point)
	- This multiplies the value by 2^bits (2^8 = 256), size of the fractional part */
Fixed::Fixed(const int other) {
	this->rawBits = other << bits; //other number / 2^bits
}

/* Converts a floating-point number to fixed-point representation by
	multiplying by 2^bits and rounding to the nearest integer. */
Fixed::Fixed(const float other) {
	this->rawBits = (int)roundf(other * (1 << bits)); //convert and round
}

/* MEMBER FUNCTIONS */

int Fixed::getRawBits(void) const {
	return rawBits;
}

void Fixed::setRawBits(int const raw) {
	rawBits = raw;
}

/* Converts the internal fixed-point value back to a float (cast) by dividing
	the raw integer by 2^bits. */
float Fixed::toFloat(void) const {
	return (float)this->rawBits / (1 << bits);
}

/* Converts the internal fixed-point value back to an int by removing
	the fractional part (after point) with a right shift. */
int Fixed::toInt(void) const {
	return this->rawBits >> bits;
}

/* OPERATOR OVERLOAD METHODS: COMPARISON */

bool Fixed::operator>(const Fixed& other) const {
	return this->rawBits > other.rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->rawBits <= other.rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->rawBits != other.rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->rawBits == other.rawBits;
}

/* OPERATOR OVERLOAD METHODS: ARITHMETIC */

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->rawBits + other.rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->rawBits - other.rawBits);
	return result;
}

/* Multiply the two raw fixed-point values, then divide by the scale factor
	to correct the extra multiplication by 2^bits (256) */
Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->rawBits * other.rawBits) / (1 << bits));
	return result;
}

/* Scale the numerator first so division keeps the fracional part, then divide by the other raw value
	This keeps the fixed-point precision during division */
Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->rawBits * (1 << bits)) / other.rawBits);
	return result;
}

/* OPERATOR OVERLOAD METHODS: INCREMENT/DECREMENT */

Fixed& Fixed::operator++() {
	++rawBits;
	return *this;
}

Fixed& Fixed::operator--() {
	--rawBits;
	return *this;
}

/* Copy the current object into a temporary variable
	This stores the old value so postfix ++/-- can return it after changing rawBits */
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	rawBits++;
	return temp;

}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	rawBits--;
	return temp;
}

/* OVERLOADED MEMBER FUNCTIONS: MIN MAX */

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a.rawBits < b.rawBits)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a.rawBits < b.rawBits)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a.rawBits > b.rawBits)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a.rawBits > b.rawBits)
		return a;
	return b;
}

/* OPERATOR OVERLOAD FUNCTION */

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

