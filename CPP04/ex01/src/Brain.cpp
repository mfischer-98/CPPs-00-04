/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:02:48 by mefische          #+#    #+#             */
/*   Updated: 2026/07/29 11:33:51 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() {
	std::cout "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}

Brain::Brain(const Brain& other) {
	std::cout "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
 	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout "Brain destructor called" << std::endl;
}
