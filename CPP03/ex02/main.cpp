/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:29:43 by mefische          #+#    #+#             */
/*   Updated: 2026/07/24 16:54:53 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap	bob("bob");
	ClapTrap	gary("gary");
	ScavTrap	squidward("squidward");
	FragTrap	patrick("patrick");
	
	std::cout << std::endl;
	std::cout << std::endl;

	bob.setAttackDamage(5);
	gary.setAttackDamage(2);
	gary.setAttackDamage(-3);
	gary.setHitPoints(30);

	bob.attack("gary");
	gary.takeDamage(bob.getAttackDamage());
	gary.takeDamage(30);
	gary.attack("bob");
	bob.takeDamage(gary.getAttackDamage());
	gary.beRepaired(5);

	squidward.attack("gary");
	squidward.guardGate();

	patrick.attack("squidward");
	patrick.takeDamage(25);
	patrick.beRepaired(10);
	patrick.highFivesGuys();
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}