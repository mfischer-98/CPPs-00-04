/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:46:09 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 08:47:42 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*  HumanA always has a weapon, so it stores a reference to Weapon.
	This works because HumanA must be armed from the moment it is created,
	and a reference must always refer to a valid object. */
class HumanA {
	private:
		std::string	name;
		Weapon		&weapon;
	public:
		HumanA(std::string name, Weapon &weaponType);
		~HumanA();

		void attack();
};
