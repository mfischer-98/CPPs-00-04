/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:43:24 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 08:40:19 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	private:
		std::string	type;
	public:
		Weapon(std::string weaponType);
		~Weapon();

		const std::string& getType();
		void setType(std::string weaponType);
};

#endif
