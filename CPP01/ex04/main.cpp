/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:40:24 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 09:12:50 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplace.hpp"

/* Function to check if file exists and if I can open/read it */
static bool	checkFile(std::string path)
{
	std::ifstream file(path.c_str());
	if (!file.is_open())
		return false;
	file.close();
	return true;
}

int main (int argc, char **argv)
{
	if (argc != 4 || argv[2][0] == '\0' || !checkFile(argv[1]))
	{
		std::cerr << "Error\nInvalid file or args" << std::endl;
		return 1;
	}
	StringReplace sReplace(argv[1], argv[2], argv[3]);
	sReplace.fileReplace();
	return 0;
}
