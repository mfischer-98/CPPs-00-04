/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:56:18 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 08:48:07 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*	HumanB may not have a weapon right away, so it stores a pointer to Weapon.
	A pointer can be empty at first, then set later when a weapon is given.
	So HumanB can exist before receiving a weapon. */
class HumanB {
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		
		void attack();
		void setWeapon(Weapon &weaponType);
};
