/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:29:43 by mefische          #+#    #+#             */
/*   Updated: 2026/08/03 15:11:45 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	bob("bob");
	ClapTrap	patrick("patrick");
	ClapTrap	plankton(bob);

	patrick = plankton;

	std::cout << bob.getName() << std::endl;
	std::cout << &bob << std::endl;

	std::cout << patrick.getName() << std::endl;
	std::cout << &patrick << std::endl;

	std::cout << plankton.getName() << std::endl;
	std::cout << &plankton << std::endl;

	bob.attack("patrick");
	patrick.takeDamage(5);
	patrick.takeDamage(20);

	patrick.attack("bob");
	patrick.beRepaired(5);
	return 0;
}