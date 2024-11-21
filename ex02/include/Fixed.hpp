/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:48:35 by stopp             #+#    #+#             */
/*   Updated: 2024/11/21 16:13:03 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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

		Fixed(const int int_value);
		Fixed(const float float_value);

		int		getRawBits(void)const;
		void	setRawBits(int const raw);

		float	toFloat(void)const;
		int		toInt(void)const;

	//Overloaded operators
		//comparison
		bool	operator > (const Fixed &other)const;
		bool	operator < (const Fixed &other)const;
		bool	operator >= (const Fixed &other)const;
		bool	operator <= (const Fixed &other)const;
		bool	operator == (const Fixed &other)const;
		bool	operator != (const Fixed &other)const;
		//arithmetic
		Fixed	operator + (const Fixed &other)const;
		Fixed	operator - (const Fixed &other)const;
		Fixed	operator * (const Fixed &other)const;
		Fixed	operator / (const Fixed &other)const;
		//in-/decrement
		Fixed	&operator ++ ();
		Fixed	&operator -- ();
		Fixed	operator -- (int);
		Fixed	operator ++ (int);
		//min-max
		static Fixed		&min (Fixed &one, Fixed &two);
		static const Fixed	&min (const Fixed &one, const Fixed &two);
		static Fixed		&max (Fixed &one, Fixed &two);
		static const Fixed	&max (const Fixed &one, const Fixed &two);
};

std::ostream &operator << (std::ostream &o, Fixed const &fpv);
