/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:12:02 by mefische          #+#    #+#             */
/*   Updated: 2026/07/21 11:22:33 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <string>
#include <sstream>
#include <iostream>

class PhoneBook {
	private:
		Contact contacts[8]; //instance of the Contact class
		int		index;
		int		oldest;
		int		size;
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		//Contact name input + contact number input one at a time
		// first name, last name, nickname, phone number, and darkest secret. A saved contact can’t have empty fields
		//if size > 8, replace the oldest by the new one
		void searchContact() const;
		//display list index, 1st name, last name, nickname
		// pipe between parts and text right aligned
		//10 characters, if more 9 plus .
		//iomanip
};