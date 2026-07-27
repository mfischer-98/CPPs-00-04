/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:50:26 by mefische          #+#    #+#             */
/*   Updated: 2026/07/27 17:50:43 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor called." << std::endl;
	this->type = "None";
}

WrongAnimal::WrongAnimal(const std::string& animalType) : type(animalType) {
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

/* SETTERS & GETTERS */

void	WrongAnimal::setType(std::string animalType) {
	this->type = animalType;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}

/* MEMBER FUNCTIONS */

void WrongAnimal::makeSound() const {
	std::cout << "... Moo? ..." << std::endl;
}