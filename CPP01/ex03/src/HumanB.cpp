/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:57:54 by mefische          #+#    #+#             */
/*   Updated: 2026/07/22 16:39:50 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string nameB) : name(nameB) {}

HumanB::~HumanB() {}

void	HumanB::attack() {
	std::cout << name << " attacks with their " << type->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weaponType) {
	type = &weaponType;
}