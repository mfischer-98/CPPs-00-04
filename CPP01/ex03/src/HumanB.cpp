/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:57:54 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 14:48:37 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string nameB) : name(nameB), weapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::attack() {
	if (!weapon)
		std::cout << name << " has no weapons. RETREAT!" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weaponType) {
	weapon = &weaponType;
}