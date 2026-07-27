/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:49:49 by mefische          #+#    #+#             */
/*   Updated: 2026/07/27 17:54:08 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat() {
	setType("WrongCat");
	std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
		this->setType(other.getType());
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

/* MEMBER FUNCTIONS */

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}