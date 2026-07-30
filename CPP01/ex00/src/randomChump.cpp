/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:27:10 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 08:25:03 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/* This function creates a zombie, names it and makes it announce itself.
	- The object is on the stack, so it is automatically destroyed when the function ends.
	- I use this when the object is only needed briefly inside the function.*/
void randomChump( std::string name ) {
	Zombie zombie(name);
	zombie.announce();
}
