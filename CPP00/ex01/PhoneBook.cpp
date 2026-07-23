/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:43:55 by mefische          #+#    #+#             */
/*   Updated: 2026/07/23 10:59:05 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* UTILS */

/* Function to check if input is empty */
static bool	checkEmpty(const std::string& input)
{
	if (input.empty())
	{
		std::cout << "Input cannot be empty :(" << std::endl;
		return false;
	}
	return true;
}

/* Prompt field for Add feature 
	- check EOF if person presses ctrl + D not in infinite loop */
static bool	promptLine(const std::string& prompt, std::string& input)
{
	std::cout << " ✿ "<< PINK << prompt << RESET;
	std::getline(std::cin, input);
	if (std::cin.eof())
		return false;
	return checkEmpty(input);
}

/* Function to check if input is only numbers 
	- needs to be unsigned char so function has normal behaviour across systems */
static bool	checkDigits(const std::string& input)
{
	for (int i = 0; input.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
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

/* Prints error for index: empty, letters or number out of the value list */
static void invalidIndex(void)
{
	std::cout << PEACH << "Invalid index, choose one from the list ✿" << std::endl;
	std::cout << "To go back to MENU, type BACK..\n" << RESET << std::endl;
}

/* CONSTRUCTOR & DESTRUCTOR */

PhoneBook::PhoneBook() : index(0), size(0) {}
PhoneBook::~PhoneBook() {}

/* MEMBER FUNCTIONS */

/* Adds a new contact to the phonebook.
	- Prompts the user for first name, last name, nickname, dark secret and phone number
	- Uses std::getline for every field so spaces are allowed
	- Rejects empty input and invalid phone numbers
	- Allows the user to type "BACK" when mistaking phone to cancel and return to the menu
	- Stops cleanly if EOF is reached with Ctrl+D.
	- Stores contacts in a circular way, overwriting the oldest entry when the phonebook is full */
void	PhoneBook::addContact() {
	std::string name;
	std::string last;
	std::string nickname;
	std::string secret;
	std::string phone;

	std::cout << std::endl;
	if (!promptLine("First name: ", name))
		return ;
	contacts[index].setFirstName(name);
	
	if (!promptLine("Last name: ", last))
		return ;
	contacts[index].setLastName(last);

	if (!promptLine("Nickname: ", nickname))
		return ;
	contacts[index].setNickname(nickname);

	if (!promptLine("Darkest secret: ", secret))
		return ;
	contacts[index].setDarkSecret(secret);

	
	while (1)
	{
		std::cout << " ✿ " << PINK << "Phone number: " << RESET;
		std::getline(std::cin, phone); 
		if (std::cin.eof())
			return ;
		if (phone == "BACK")
		{
			std::cout << std::endl;
			return ;
		}
		if (checkDigits(phone) && checkEmpty(phone))
			break ;
		std::cout << "Invalid phone number, try again or type BACK to return to MENU ✿" << std::endl;
	}
	std::cout << PEACH << "\nContact added successfully ♡\n" << RESET << std::endl;
	contacts[index].setPhoneNumber(phone);
	if (size < 8)
		size++;
	index = (index + 1) % 8;
}

/* Displays the list of stored contacts and shows the details of one selected contact.
	- Prints a table with index, first name, last name, and nickname.
	- Truncates fields longer than 10 characters for table formatting.
	- Asks the user to enter an index to view the full contact information.
	- Rejects empty input, non-numeric input and out-of-range indexes.
	- Allows the user to type "BACK" to return to the menu.
	- Stops cleanly if EOF is reached with Ctrl+D. */
void	PhoneBook::searchContact() const {
	std::string	input;
	int choice;

	std::cout << ROSE << "\n     ╭──────────────────────────────╮" << RESET << std::endl;
	std::cout << ROSE << "     │" << CREAM << "       your contacts ✿        " << ROSE << "│" << RESET << std::endl;
	std::cout << ROSE << "     ╰──────────────────────────────╯" << RESET << std::endl;
	std::cout << std::endl;

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
	std::cout << std::endl;

	while (1)
	{
		std::cout << CREAM << "⌕ Enter an index to view details: " << RESET;
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input == "BACK")
			return ;
		if (!checkEmpty(input) || !checkDigits(input))
			invalidIndex();
		else
		{
			choice = strToInt(input);
			if (choice < 0 || choice >= size)
				invalidIndex();
			else
				break ;
		}
	}
	std::cout << "\n ✿ "<< LILAC << "Name: " << CREAM << contacts[choice].getFirstName() << RESET << std::endl;
	std::cout << " ✿ "<< LILAC << "Last Name: " << CREAM << contacts[choice].getLastName() << RESET << std::endl;
	std::cout << " ✿ "<< LILAC << "Nickname: " << CREAM << contacts[choice].getNickname() << RESET << std::endl;
	std::cout << " ✿ "<< LILAC << "Contact: " << CREAM << contacts[choice].getPhoneNumber() << RESET << std::endl;
	std::cout << " ✿ "<< LILAC << "Darkest Secret: " << CREAM << contacts[choice].getDarkSecret() << RESET << std::endl;
	std::cout << std::endl;
}
