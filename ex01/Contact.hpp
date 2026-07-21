/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:36:18 by mefische          #+#    #+#             */
/*   Updated: 2026/07/21 12:00:31 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/* Set to private the data that will be used only inside the class
	- after setting contact, the user will not change anything on the contact so it is private
	Set to public functions that will be used in this class and we will acceess outside in main */
class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string darkSecret;
		std::string	phoneNumber;

	public:
		Contact();
		~Contact();
		void setFirstName(std::string name);
		void setLastName(std::string last);
		void setNickname(std::string nick);
		void setDarkSecret(std::string secret);
		void setPhoneNumber(std::string phone);

		std::string getFirstName() const; //to access private variables
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getDarkSecret() const;
		std::string getPhoneNumber() const;
		// I use const to tell the reader that the object will not be modified when calling this function
		//void displayShort(); //prints short version for SEARCH
		//void displyFull(); //prints full version for SEARCH
};