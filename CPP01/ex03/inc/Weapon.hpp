/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:43:24 by mefische          #+#    #+#             */
/*   Updated: 2026/07/22 16:32:30 by mefische         ###   ########.fr       */
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

		std::string	getType() const;
		void		setType(std::string weaponType);
};

#endif
