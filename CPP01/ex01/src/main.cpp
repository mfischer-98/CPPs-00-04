/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:04:15 by mefische          #+#    #+#             */
/*   Updated: 2026/07/22 15:13:26 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main (void)
{
	Zombie	*zombies;
	int	n = 5;

	zombies = zombieHorde(n, "Lelo");
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
