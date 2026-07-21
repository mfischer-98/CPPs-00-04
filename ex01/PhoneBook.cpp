/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:43:55 by mefische          #+#    #+#             */
/*   Updated: 2026/07/21 12:04:34 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* CONSTRUCTOR & DESTRUCTOR */

PhoneBook::PhoneBook() : index(0), oldest(0), size(0) {
	return ;
}

PhoneBook::~PhoneBook() {
	return ;
}

void	PhoneBook::addContact() {
	std::string name;
	std::string last;
	std::string nickname;
	std::string secret;
	std::string phone;

	std::cout << "First name: ";
	std::getline(std::cin, name);
	contacts[index].setFirstName(name);

	std::cout << "Last name: ";
	std::getline(std::cin, last);
	contacts[index].setLastName(last);

	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	contacts[index].setNickname(nickname);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);
	contacts[index].setDarkSecret(secret);

	std::cout << "Phone number: ";
	std::getline(std::cin, phone);
	contacts[index].setPhoneNumber(phone);

	std::cout << "Number was added to Phone Book <3" << std::endl;
	
	index += 1;
	if (size < 8)
		size++;
	else
	{
		index = oldest;
		oldest += 1;
	}
}

void	PhoneBook::searchContact() const {
	std::string	input;
	int choice;

	std::cout << "|";
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << i << "|";
		std::cout << std::setw(10) << contacts[i].getFirstName() << "|";
		std::cout << std::setw(10) << contacts[i].getLastName() << "|";
		std::cout << std::setw(10) << contacts[i].getNickname() << std::endl;
	}
	//each column shows max 10 chars or 9+.
	std::cout << "Pick the index of the contact you want more details: ";
	std::getline(std::cin, input);
	std::istringstream iss(input);
	if (!(iss >> choice) || !iss.eof())
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	if (choice < 0 || choice >= size)
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	std::cout << contacts[choice].getFirstName() << std::endl;
	std::cout << contacts[choice].getLastName() << std::endl;
	std::cout << contacts[choice].getNickname() << std::endl;
	std::cout << contacts[choice].getDarkSecret() << std::endl;
	std::cout << contacts[choice].getPhoneNumber() << std::endl;
}

//maybe int	validIndex() or my_stoi
//check_len if bigger than 10 9.