/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:03:25 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 14:49:28 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special"
				<< "ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!"
				<< "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years,"
				<< " whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/* Picks which function to call, I use an array of pointers to member functions:
	- (Harl::*) = pointer to a member of class Harl
	- funcs[4] = array of 4 of those pointers 
	- (void) = each pointed-to member function takes no parameters */
void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*funcs[4])(void)  = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
				return ;
		}
	}
	std::cout << "Even for Harl, that level is out of reach" << std::endl;
}

