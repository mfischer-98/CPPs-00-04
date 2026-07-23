/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:00:46 by mefische          #+#    #+#             */
/*   Updated: 2026/07/23 14:37:02 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};
