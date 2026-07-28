/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:22:17 by mefische          #+#    #+#             */
/*   Updated: 2026/07/28 14:43:32 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/* Constructor & Destructor */

/* Constructor already receives the name of zombie as parameter, do I never have to assign it manually later
	- name(zombieName) = assigns zombieName as name in the class */
Zombie::Zombie(std::string zombieName) : name(zombieName) {}

Zombie::~Zombie() {
	std::cout << "Destructor called and Zombie " << name << " was destroyed." << std::endl;
}

/* Member function */
void	Zombie::announce (void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
