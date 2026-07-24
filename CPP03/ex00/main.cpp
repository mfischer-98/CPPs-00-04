/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:29:43 by mefische          #+#    #+#             */
/*   Updated: 2026/07/24 15:43:38 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	madMan("madMan");
	ClapTrap	oldMan("oldMan");

	madMan.setAttackDamage(5);
	oldMan.setAttackDamage(2);
	oldMan.setAttackDamage(-3);

	madMan.attack("oldMan");
	oldMan.takeDamage(madMan.getAttackDamage());
	oldMan.takeDamage(30);
	oldMan.attack("madMan");
	madMan.takeDamage(oldMan.getAttackDamage());
	oldMan.beRepaired(5);
	return 0;
}