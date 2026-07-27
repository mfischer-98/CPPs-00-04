/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:29:43 by mefische          #+#    #+#             */
/*   Updated: 2026/07/27 16:07:12 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"
#include <iostream>

int	main()
{
	FragTrap	patrick("patrick");
	DiamondTrap sandy("sandy");

	std::cout << std::endl;

	sandy.attack("patrick");
	patrick.takeDamage(sandy.getAttackDamage());
	sandy.whoAmI();
	sandy.beRepaired(10);

	std::cout << std::endl;
	return 0;
}
