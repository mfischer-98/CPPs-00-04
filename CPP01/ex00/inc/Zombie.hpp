/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:21:03 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 08:27:41 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string name;

	public:
		Zombie(std::string name);
		~Zombie(void);

		void announce(void);
};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);
