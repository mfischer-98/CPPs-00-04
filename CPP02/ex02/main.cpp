/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:06:50 by mefische          #+#    #+#             */
/*   Updated: 2026/07/31 11:50:58 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
	// Fixed		a;
	// Fixed const	b( Fixed(5.05f) * Fixed(2));

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;
	
	// std::cout << Fixed::max( a, b ) << std::endl;
	// std::cout << std::endl;

	Fixed		a(1.5f);
	Fixed const b(2.0f);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	
	Fixed c = a + b;
	Fixed d = b - a;
	Fixed e = a * b;
	Fixed f = b / a;

	std::cout << "a + b = " << c << std::endl;
	std::cout << "b - a = " << d << std::endl;
	std::cout << "a * b = " << e << std::endl;
	std::cout << "b / a = " << f << std::endl;

	std::cout << "a before ++: " << a << std::endl;
	std::cout << "++a : " << ++a << std::endl; //increases 1/256 = 0.00391
	std::cout << "a++ : " << a++ << std::endl; //increases 1/256 = 0.00391
	std::cout << "a after ++ : " << a << std::endl; //prints updated result after line

	std::cout << "min(a, b) : " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) : " << Fixed::max(a, b) << std::endl;

	return 0;
}