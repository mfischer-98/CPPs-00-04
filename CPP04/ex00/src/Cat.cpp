/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:18:23 by mefische          #+#    #+#             */
/*   Updated: 2026/07/27 17:32:10 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() {
	setType("Cat");
	std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		this->setType(other.getType());
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
}

/* MEMBER FUNCTIONS */

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}