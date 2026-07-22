/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:11:46 by mefische          #+#    #+#             */
/*   Updated: 2026/07/22 11:48:34 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook phonebook;
	std::string command;

	std::cout << ROSE << "╭──────────────────────────────╮" << RESET << std::endl;
	std::cout << ROSE << "│" << CREAM << "      your phonebook ✿        " << ROSE << "│" << RESET << std::endl;
	std::cout << ROSE << "╰──────────────────────────────╯" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << LILAC << "  ADD    " << CREAM << "- save a new contact" << RESET << std::endl;
	std::cout << LILAC << "  SEARCH " << CREAM << "- browse saved contacts" << RESET << std::endl;
	std::cout << LILAC << "  EXIT   " << CREAM << "- close the phonebook" << RESET << std::endl;
	std::cout << std::endl;

	while (true)
	{
		std::cout << "Enter a command " << CREAM << "(ADD ♡, SEARCH ⌕ or EXIT ✿ ): ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			return 0;
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
	}
	std::cout << LILAC <<  "Phonebook closed ♡ " << std::endl;
	return 0;
}