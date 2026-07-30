/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:11:37 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 14:50:01 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
	{
		std::cerr << "Error\nEnter a level: DEBUG, INFO, WARNING or ERROR" << std::endl;
		return 1;
	}
	harl.complain(av[1]);
	return 0;
}