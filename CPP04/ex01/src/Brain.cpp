/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:02:48 by mefische          #+#    #+#             */
/*   Updated: 2026/07/28 15:05:59 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain() {
}

Brain::Brain(const Brain& other) {
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
/* 	if (this != &other)
		this->setType(other.getType()); */
	return *this;
}

Brain::~Brain() {
}
