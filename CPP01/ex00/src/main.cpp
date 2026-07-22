/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:04:15 by mefische          #+#    #+#             */
/*   Updated: 2026/07/22 14:52:37 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main (void)
{
	Zombie	*zombie;

	randomChump("Kiko");
	zombie = newZombie("Lelo");
	zombie->announce();
	delete zombie;
	return 0;
}
