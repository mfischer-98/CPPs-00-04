/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:04:15 by mefische          #+#    #+#             */
/*   Updated: 2026/07/28 12:33:51 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main (void)
{
	Zombie	*zombie;

	randomChump("Kiko");
	std::cout << std::endl;

	zombie = newZombie("Lelo");
	zombie->announce();
	delete zombie;
	return 0;
}
