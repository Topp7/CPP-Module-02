/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:48:35 by stopp             #+#    #+#             */
/*   Updated: 2024/11/12 16:54:43 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

const int Fixed::_fractBits = 8;

class	Fixed
{
	private:
		int					_value;
		static const int	_fractBits;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator = (const Fixed &src);
		~Fixed();

		int		getRawBits(void)const;
		void	setRawBits(int const raw);
};
