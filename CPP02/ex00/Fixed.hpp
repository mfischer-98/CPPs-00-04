/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 15:08:19 by mefische          #+#    #+#             */
/*   Updated: 2026/07/31 11:13:31 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

//Static member: there is only one shared by all Fixed objects.
class Fixed {
	private:
		int _rawBits;
		static const int _bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};
