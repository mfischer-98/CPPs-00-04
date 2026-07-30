/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:21:03 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 08:35:15 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string name;

	public:
		Zombie(void);
		~Zombie(void);

		void setName(std::string zombieName);
		void announce(void);
};

Zombie* zombieHorde(int N, std::string name);
