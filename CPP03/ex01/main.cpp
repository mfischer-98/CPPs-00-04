/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:29:43 by mefische          #+#    #+#             */
/*   Updated: 2026/07/24 16:39:26 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	bob("bob");
	ClapTrap	jerry("jerry");
	ScavTrap	squid("squid");

	bob.setAttackDamage(5);
	jerry.setAttackDamage(2);
	jerry.setAttackDamage(-3);
	jerry.setHitPoints(30);

	bob.attack("jerry");
	jerry.takeDamage(bob.getAttackDamage());
	jerry.takeDamage(30);
	jerry.attack("bob");
	bob.takeDamage(jerry.getAttackDamage());
	jerry.beRepaired(5);

	squid.attack("jerry");
	squid.guardGate();
	return 0;
}