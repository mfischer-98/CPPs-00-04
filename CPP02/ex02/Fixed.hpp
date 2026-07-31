/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:19 by mefische          #+#    #+#             */
/*   Updated: 2026/07/31 11:48:00 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int rawBits;
		static const int bits = 8;
	public:
		// Canonical Form
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		// Other constructors
		Fixed(const int other);
		Fixed(const float other);

		// Setter and getter
		int getRawBits(void) const;
		void setRawBits(int const raw);

		// Conversion methods
		float toFloat(void) const;
		int toInt(void) const;

		// Comparison operators
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;

		// Arithmetic operators
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Prefix increment and decrement
		Fixed& operator++();
		Fixed& operator--();
		// The int inside bracket which indicates postfix increment
		Fixed operator++(int);
		Fixed operator--(int);

		// Overloaded member functions
		// static means these functions belong to the class, not to any instance
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);