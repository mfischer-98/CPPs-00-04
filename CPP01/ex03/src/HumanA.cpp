/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:57:51 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 08:45:23 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string nameA, Weapon& weaponType) : name(nameA), weapon(weaponType) {}

HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
