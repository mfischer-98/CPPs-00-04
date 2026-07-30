/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:41:13 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 15:50:49 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* Constructors & Destructor*/

FragTrap::FragTrap() : ClapTrap() {}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap Constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap Copy constructor called" << std::endl;
	if (this != &other)
	{
		setName(other.getName());
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

/* Member Functions */

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << getName() << " requests high-fives from everybody! " << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (getEnergyPoints() < 0 && getHitPoints() < 0)
	{
		std::cout << "FragTrap " << getName() << " cannot attack." << std::endl;
		return ;
	}
	setEnergyPoints(getEnergyPoints() - 1);
	std::cout << "FragTrap " << getName() << " attacks " << target << ", causing "
					<< getAttackDamage() << " points of damage!" << std::endl;
}
