/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:43:55 by mefische          #+#    #+#             */
/*   Updated: 2026/07/21 19:16:49 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* UTILS */
/* Function to check if input is empty 
	- if c == n: check if it is all digits  */
static bool	parseInput(const std::string& input, char c)
{
	if (input.empty())
	{
		std::cout << "Input cannot be empty :(" << std::endl;
		return false;
	}
	if (c == 'n')
	{
		for (int i = 0; input[i]; i++)
		{
			if (!std::isdigit(input[i]))
			{
				std::cout << "Numbers only" << std::endl;
				return false;
			}
		}
	}
	return true;
}
/* Function to guarantee <= 10 characters and to transform >10 into 9 + "." 
	- Const: I use const so I do not change the value of str
	- &: I use & so I do not make a copy of str */
static std::string	formatWord(const std::string& str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

/* Function to transform a string into an int */
static int	strToInt(const std::string& str)
{
	int	num;

	std::stringstream ss(str);
	ss >> num;
	return num;
}

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
	if (parseInput(name, 's'))
		contacts[index].setFirstName(name);
	else
		return ;

	std::cout << " ✿ " << PINK << "Last name: " << RESET;
	std::getline(std::cin, last);
	if (parseInput(last, 's'))
		contacts[index].setLastName(last);
	else
		return ;

	std::cout << " ✿ " << PINK << "Nickname: " << RESET;
	std::getline(std::cin, nickname);
	if (parseInput(last, 's'))
		contacts[index].setNickname(nickname);
	else
		return ;

	std::cout << " ✿ " << PINK << "Darkest secret: " << RESET;
	std::getline(std::cin, secret);
	if (parseInput(last, 's'))
		contacts[index].setDarkSecret(secret);
	else
		return ;

	std::cout << " ✿ " << PINK << "Phone number: " << RESET;
	std::getline(std::cin, phone);
	if (parseInput(last, 'n'))
		contacts[index].setPhoneNumber(phone);
	else
		return ;
	
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

	while (1)
	{
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
		if (input == "BACK")
			return ;
		else if (!parseInput(input, 'n'))
		{
			std::cout << "Invalid index, choose one from the list ✿" << std::endl;
			std::cout << "To go back to MENU, type BACK.." << std::endl;
		}
		else
		{
			choice = strToInt(input);
			if (choice < 0 || choice >= size)
			{
				std::cout << "Invalid index, choose one from the list ✿" << std::endl;
				std::cout << "To go back to MENU, type BACK.." << std::endl;
			}
			else
				break ;
		}
	}
	std::cout << "\n ✿ "<< LILAC << "Name: " << CREAM << contacts[choice].getFirstName() << RESET << std::endl;
	std::cout << " ✿ "<< LILAC << "Last Name: " << CREAM << contacts[choice].getLastName() << RESET << std::endl;
	std::cout << " ✿ "<< LILAC << "Nickname: " << CREAM << contacts[choice].getNickname() << RESET << std::endl;
	std::cout << " ✿ "<< LILAC << "Contact: " << CREAM << contacts[choice].getPhoneNumber() << RESET << std::endl;
	std::cout << " ✿ "<< LILAC << "Darkest Secret: " << CREAM << contacts[choice].getDarkSecret() << RESET << std::endl;
}
