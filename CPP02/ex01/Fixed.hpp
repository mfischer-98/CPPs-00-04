/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:19 by mefische          #+#    #+#             */
/*   Updated: 2026/07/30 15:23:31 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _rawBits;
		static const int _bits = 8;
	public:
		Fixed();
		Fixed(const int other);
		Fixed(const float other);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other); 
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);