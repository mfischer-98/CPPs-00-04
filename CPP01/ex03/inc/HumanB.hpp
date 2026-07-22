/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:56:18 by mefische          #+#    #+#             */
/*   Updated: 2026/07/22 16:44:10 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*	HumanB may not have a weapon right away, so it stores a pointer to Weapon.
	A pointer can be empty at first, then set later when a weapon is given.
	This matches the exercise because HumanB can exist before receiving a weapon.
	It also lets HumanB use the same weapon object without making a copy. */
class HumanB {
	private:
		std::string	name;
		Weapon*		type;
	public:
		HumanB(std::string name);
		~HumanB();
		
		void attack();
		void setWeapon(Weapon& weaponType);
};
