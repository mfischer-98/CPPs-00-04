/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:59:19 by mefische          #+#    #+#             */
/*   Updated: 2026/07/31 11:28:57 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* CONSTRUCTORS & DESTRUCTOR */

Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

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
	- This multiplies the value by 2^bits (2^8 = 256), size of the fractional part
	- x 256 is the same as shifting left by 8 bits */
Fixed::Fixed(const int other) {
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = other << _bits;
}

/* Converts a floating-point number to fixed-point representation by
	multiplying by 2^bits and rounding to the nearest integer. 
	- bitwise operators only works on ints, so I do 1 << bits first */
Fixed::Fixed(const float other) {
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = (int)roundf(other * (1 << _bits));
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

