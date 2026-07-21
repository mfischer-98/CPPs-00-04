/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:43:55 by mefische          #+#    #+#             */
/*   Updated: 2026/07/21 17:32:37 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* UTILS */

/* Function to guarantee <= 10 characters and to transform >10 into 9 + "." 
	- Const: I use const so I do not change the value of str
	- &: I use & so I do not make a copy of str */
static std::string	formatWord(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

// static int	parse_input(const std::string& input)
// {
// 	//Function to parse the user input not empty all numbers or all letters
// 	//Function to guarantee all letters
// 	//Function to guarantee all numbers
// }


//Function to transform string into number
//Function to check if index is in the list

/* CONSTRUCTOR & DESTRUCTOR */

PhoneBook::PhoneBook() : index(0), oldest(0), size(0) {}
PhoneBook::~PhoneBook() {}

/* METHODS */

void	PhoneBook::addContact() {
	std::string name;
	std::string last;
	std::string nickname;
	std::string secret;
	std::string phone;

	std::cout << "\n ✿ "<< PINK << "First name: " << RESET;
	std::getline(std::cin, name);
	contacts[index].setFirstName(name);

	std::cout << " ✿ " << PINK << "Last name: " << RESET;
	std::getline(std::cin, last);
	contacts[index].setLastName(last);

	std::cout << " ✿ " << PINK << "Nickname: " << RESET;
	std::getline(std::cin, nickname);
	contacts[index].setNickname(nickname);

	std::cout << " ✿ " << PINK << "Darkest secret: " << RESET;
	std::getline(std::cin, secret);
	contacts[index].setDarkSecret(secret);

	std::cout << " ✿ " << PINK << "Phone number: " << RESET;
	std::getline(std::cin, phone);
	contacts[index].setPhoneNumber(phone);

	std::cout << PEACH << "\nContact added successfully ♡\n" << RESET << std::endl;
	
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

	std::cout << ROSE << "\n     ╭──────────────────────────────╮" << RESET << std::endl;
	std::cout << ROSE << "     │" << CREAM << "       your contacts ✿        " << ROSE << "│" << RESET << std::endl;
	std::cout << ROSE << "     ╰──────────────────────────────╯" << RESET << std::endl;
	std::cout << std::endl;

	//need a loop for when they want to leave this area
	std::cout << ROSE << "|"
				<< std::setw(10) << "index" << "|"
				<< std::setw(10) << "first name" << "|"
				<< std::setw(10) << "last name" << "|"
				<< std::setw(10) << "nickname" << "|"
				<< RESET << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << PEACH << "|" << RESET
					<< std::setw(10) << i << PEACH << "|" << RESET
					<< std::setw(10) << formatWord(contacts[i].getFirstName()) << PEACH << "|" << RESET
					<< std::setw(10) << formatWord(contacts[i].getLastName()) << PEACH << "|" << RESET
					<< std::setw(10) << formatWord(contacts[i].getNickname()) << PEACH << "|" << RESET
					<< std::endl;
	}

	std::cout << CREAM << "⌕ Enter an index to view details: ";
	std::getline(std::cin, input);
	// choice = ft_stoi(input);
	// if (choice < 0 || choice >= size)
	// {
	// 	std::cout << "Invalid index, choose one from the list ✿" << std::endl;
	// 	return ;
	// }
	// std::cout << LILAC << "Name: " << CREAM << contacts[choice].getFirstName() << RESET << std::endl;
	// std::cout << LILAC << "Last Name: " << CREAM << contacts[choice].getLastName() << RESET << std::endl;
	// std::cout << LILAC << "Nickname: " << CREAM << contacts[choice].getNickname() << RESET << std::endl;
	// std::cout << LILAC << "Contact: " << CREAM << contacts[choice].getPhoneNumber() << RESET << std::endl;
	// std::cout << LILAC << "Darkest Secret: " << CREAM << contacts[choice].getDarkSecret() << RESET << std::endl;
}
