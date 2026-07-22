/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:22:17 by mefische          #+#    #+#             */
/*   Updated: 2026/07/22 15:12:14 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/* Constructor & Destructor */

/* Constructor already receives the name of zombie as parameter, do I never have to assign it manually later
	- name(zombieName) = assigns zombieName as name in the class */
Zombie::Zombie() {}
Zombie::~Zombie() {}

/* Member function */
void	Zombie::announce (void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Setter */
void Zombie::setName(std::string zombieName) {
	name = zombieName;
}
