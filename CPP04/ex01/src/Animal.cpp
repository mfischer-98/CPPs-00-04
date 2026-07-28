/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:35:14 by mefische          #+#    #+#             */
/*   Updated: 2026/07/27 17:45:28 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor called." << std::endl;
	this->type = "None";
}

Animal::Animal(const std::string& animalType) : type(animalType) {
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

/* SETTERS & GETTERS */

void	Animal::setType(std::string animalType) {
	this->type = animalType;
}

std::string	Animal::getType() const {
	return this->type;
}

/* MEMBER FUNCTIONS */

void Animal::makeSound() const {
	std::cout << "Animal noise not identified." << std::endl;
}