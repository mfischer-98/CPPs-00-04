/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:00:13 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 15:53:07 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

/* CONSTRUCTORS & DESTRUCTOR */

DiamondTrap::DiamondTrap() : ClapTrap() {}

DiamondTrap::DiamondTrap(const std::string& newName) :
	ClapTrap(newName + "_clap_name"), FragTrap(newName), ScavTrap(newName), _name(newName)
{
	std::cout << "DiamondTrap Constructor called" << std::endl;
	this->setHitPoints(FragTrap::getHitPoints());
	this->setEnergyPoints(ScavTrap::getEnergyPoints());
	this->setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) :
	ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other)
	{
		setName(other.getName());
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

/* MEMBER FUNCTIONS */

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "Presenting robot name " << this->_name << ", ClapTrap name "
			<< ClapTrap::getName() << ". Ready to fight." << std::endl;
}
