/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:22:17 by mefische          #+#    #+#             */
/*   Updated: 2026/07/28 12:35:28 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/* Constructor & Destructor */
Zombie::Zombie() {}

Zombie::~Zombie() {
		std::cout << "Destructor called and Zombie destroyed." << std::endl;
}

/* Member function */
void	Zombie::announce (void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Setter */
void Zombie::setName(std::string zombieName) {
	name = zombieName;
}
