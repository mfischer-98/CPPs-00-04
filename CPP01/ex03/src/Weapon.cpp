/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:58:17 by mefische          #+#    #+#             */
/*   Updated: 2026/07/22 16:32:25 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string weaponType) : type(weaponType) {}

Weapon::~Weapon() {}

std::string	Weapon::getType() const {
	return(type);
}

void	Weapon::setType(std::string weaponType) {
	type = weaponType;
}
