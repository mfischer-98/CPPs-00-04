/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:35:56 by mefische          #+#    #+#             */
/*   Updated: 2026/07/21 16:34:06 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* CONSTRUCTOR & DESTRUCTOR:
	- constructor guarantees that the object can be created 
	- desctructor is called when object goes out of scope and destroys it */
Contact::Contact() {}
Contact::~Contact() {}

/* GETTERS: methods used to access private variables, returns a copy of it */
std::string	Contact::getFirstName() const {
	return (firstName);
}

std::string	Contact::getLastName() const {
	return (lastName);
}

std::string	Contact::getNickname() const {
	return (nickname);
}

std::string	Contact::getDarkSecret() const {
	return (darkSecret);
}

std::string	Contact::getPhoneNumber() const {
	return (phoneNumber);
}

/* SETTERS: methods used to assign/change a value of a private variable */
void	Contact::setFirstName(std::string name) {
	firstName = name;
}

void	Contact::setLastName(std::string last) {
	lastName = last;
}

void	Contact::setNickname(std::string nick) {
	nickname = nick;
}

void	Contact::setDarkSecret(std::string secret) {
	darkSecret = secret;
}

void	Contact::setPhoneNumber(std::string phone) {
	phoneNumber = phone;
}