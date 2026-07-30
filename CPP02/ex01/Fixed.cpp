/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:59:19 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 15:25:58 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* CONSTRUCTORS & DESTRUCTOR */

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

/* Copy Constructor: Creates a new Fixed object as a copy of another Fixed object. */
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/* Copy assignment operator: Copies the internal fixed-point value from another Fixed object 
	into this object, unless both objects are the same.
	- In a more complex function I can decide which members are copied */
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawBits = other._rawBits;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/* Converts an integer to fixed-point representation by shifting left
	by the number of fractional bits (after point)
	- This multiplies the value by 2^bits (2^8 = 256), size of the fractional part */
Fixed::Fixed(const int other) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = other << _bits; //other number / 2^bits
}

/* Converts a floating-point number to fixed-point representation by
	multiplying by 2^bits and rounding to the nearest integer. */
Fixed::Fixed(const float other) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = (int)roundf(other * (1 << _bits)); //convert and round
}

/* MEMBER FUNCTIONS */

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

/* Converts the internal fixed-point value back to a float (cast) by dividing
	the raw integer by 2^bits. */
float Fixed::toFloat(void) const {
	return (float)this->_rawBits / (1 << _bits);
}

/* Converts the internal fixed-point value back to an int by removing
	the fractional part (after point) with a right shift. */
int Fixed::toInt(void) const {
	return this->_rawBits >> _bits;
}

/* OPERATOR OVERLOAD FUNCTION */

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

