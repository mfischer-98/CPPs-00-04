/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:11:46 by mefische          #+#    #+#             */
/*   Updated: 2026/07/21 11:42:57 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook phonebook;
	std::string command;

	std::cout	<< "Welcome to your crappy awesome phonebook!\n\n"
				<< "  - ADD to save a new contact\n"
				<< "  - SEARCH to display a contact\n"
				<< "  - EXIT to leave your phonebook :(\n" << std::endl;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
	}
	std::cout	<< "Exiting phonebook..." << std::endl;
	return 0;
}