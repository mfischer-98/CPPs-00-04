/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplace.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:51:07 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 14:50:32 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplace.hpp"

/* Constructor & Destructor */

StringReplace::StringReplace(std::string path, std::string oldStr, std::string newStr) : filePath(path), oldString(oldStr), newString(newStr) {}

StringReplace::~StringReplace() {}

/* Member Function */

/* Opens filename, creates filename.replace and replace where str1 is for str2 
	- ifstream opens the original file and ofstream creates the .replace file 
	- c_str() converts a std::string into a C-style string (const char*) -C-style API
	- std::getline(stream, line) reads one line at a time from a stream and returns line wo \n
	- std::string::npos is a special constant value used by std::string to mean “no position” / “not found”
	- << sends data to file.replace 
	- find: finds the string in the line
	- erase(pos, len): erases the old string
	- insert(pos, len):inserts new string */ 
void StringReplace::fileReplace() {
	std::string newPath = filePath + ".replace";

	std::ifstream in(filePath.c_str());
	if (!in.is_open())
	{
		std::cerr << "Error\nCould not open input file" << std::endl;
		return ;
	}

	std::ofstream out(newPath.c_str());
		if (!out.is_open())
	{
		std::cerr << "Error\nCould not open output file" << std::endl;
		in.close();
		return ;
	}

	std::string	line;
	if (oldString.empty())
	{
		std::cerr << "Error\nEmpty search string" << std::endl;
		return ;
	}
	size_t	index = 0;
	while(std::getline(in, line))
	{
		index = line.find(oldString);
		while (index != std::string::npos)
		{
			line.erase(index, oldString.length());
			line.insert(index, newString);
			index += newString.length();
			index = line.find(oldString);
		}
		out << line;
		if (!in.eof())
			out << '\n';
	}
	in.close();
	out.close();
}
