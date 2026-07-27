/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:20:56 by mefische          #+#    #+#             */
/*   Updated: 2026/07/27 17:44:13 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() {
	setType("Dog");
	std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
		this->setType(other.getType());
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

/* MEMBER FUNCTIONS */

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}