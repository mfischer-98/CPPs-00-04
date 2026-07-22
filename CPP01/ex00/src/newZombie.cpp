/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:26:48 by mefische          #+#    #+#             */
/*   Updated: 2026/07/22 14:42:25 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

/* This function creates a zombie, names it and returns it 
	- newZombie() uses new, so the zombie is created on the heap. That means it stays alive
	after the function ends, until you manually destroy it with delete. I use this because I
	need the object to survive outside the function scope */
Zombie* newZombie(std::string name) {
	Zombie* newZombie = new Zombie(name);
	return newZombie;
}
