/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:22:17 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 08:32:29 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/* Constructor & Destructor */
Zombie::Zombie() {}

Zombie::~Zombie() {
	std::cout << "Zombie " << name << " destroyed." << std::endl;
}

/* Member function */
void	Zombie::announce (void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Setter */
void Zombie::setName(std::string zombieName) {
	name = zombieName;
}
