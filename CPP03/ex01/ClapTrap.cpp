/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:29:48 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 15:34:13 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructors & Destructor*/
ClapTrap::ClapTrap() : name("Default") {}


ClapTrap::ClapTrap(const std::string& str) : name(str), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

/* Getters & Setters */
void	ClapTrap::setName(std::string str) {
	this->name = str;
}

void	ClapTrap::setHitPoints(int hit) {
	if (hit > 0)
		this->hitPoints = hit;
	else
		std::cout << "HitPoints have to be more than 0." << std::endl;
}

void	ClapTrap::setEnergyPoints(int energy) {
	if (energy > 0)
		this->energyPoints = energy;
	else
		std::cout << "EnergyPoints have to be more than 0." << std::endl;
}

void	ClapTrap::setAttackDamage(int attack) {
	if (attack > 0)
		this->attackDamage = attack;
	else
		std::cout << "AttackDamage has to be more than 0." << std::endl;
}

std::string	ClapTrap::getName() const {
	return this->name;
}

int	ClapTrap::getHitPoints() const {
	return this->hitPoints;
}

int	ClapTrap::getEnergyPoints() const {
	return this->energyPoints;
}

int	ClapTrap::getAttackDamage() const {
	return this->attackDamage;
}

/* Member Functions */

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
					<< attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " cannot attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage! ";
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << name << " only has " << hitPoints << " remaining." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->hitPoints += amount;
		std::cout << "ClapTrap " << name << " heals itself, recovering " << amount
					<< " hitPoints!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " be repaired." << std::endl;
}
