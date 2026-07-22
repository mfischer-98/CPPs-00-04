/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:12:02 by mefische          #+#    #+#             */
/*   Updated: 2026/07/22 11:26:43 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>

#define RESET	"\033[0m"
#define PINK	"\033[38;5;205m"
#define MINT	"\033[38;5;121m"
#define LILAC	"\033[38;5;141m"
#define PEACH	"\033[38;5;216m"
#define SKY		"\033[38;5;153m"
#define CREAM	"\033[38;5;230m"
#define ROSE	"\033[38;5;211m"

class PhoneBook {
	private:
		Contact contacts[8]; //instance of the Contact class
		int		index;
		int		size;
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact() const;
};