/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplace.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:49:50 by mefische          #+#    #+#             */
/*   Updated: 2026/07/23 11:54:53 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

class StringReplace {
	private:
		std::string	filePath;
		std::string	oldString;
		std::string	newString;

	public:
		StringReplace(std::string path, std::string oldStr, std::string newStr);
		~StringReplace();
		
		void fileReplace();
};
