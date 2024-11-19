/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:56:04 by stopp             #+#    #+#             */
/*   Updated: 2024/11/19 16:57:38 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int int_value)
{
	// std::cout << "Int constructor called" << std::endl;
	_value = int_value << _fractBits;
}

Fixed::Fixed(const float float_value)
{
	// std::cout << "Float constructor called" << std::endl;
	_value = roundf(float_value * (1 << _fractBits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void)const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void)const
{
	return ((float)_value / (float)(1 << _fractBits));
}

int		Fixed::toInt(void)const
{
	return (_value  >> _fractBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fpv)
{
	o << fpv.toFloat();
	return (o);
}

//comparison
bool	Fixed::operator > (const Fixed &other)const
{
	return (this->toFloat() > other.toFloat());
}
bool	Fixed::operator < (const Fixed &other)const
{
	return (this->toFloat() < other.toFloat());
}
bool	Fixed::operator <= (const Fixed &other)const
{
	return (this->toFloat() <= other.toFloat());
}
bool	Fixed::operator >= (const Fixed &other)const
{
	return (this->toFloat() >= other.toFloat());
}
bool	Fixed::operator == (const Fixed &other)const
{
	return (this->toFloat() == other.toFloat());
}
bool	Fixed::operator != (const Fixed &other)const
{
	return (this->toFloat() != other.toFloat());
}
//arithmetic
Fixed	Fixed::operator + (const Fixed &other)const
{
	Fixed	ret;
	ret.setRawBits(this->getRawBits() + other.getRawBits());
	return ret;
}
Fixed	Fixed::operator - (const Fixed &other)const
{
	Fixed	ret;
	ret.setRawBits(this->getRawBits() - other.getRawBits());
	return ret;
}
Fixed	Fixed::operator * (const Fixed &other)const
{
	Fixed ret;
	ret.setRawBits(this->getRawBits() * other.getRawBits() >> _fractBits);
	return (ret);
}
Fixed	Fixed::operator / (const Fixed &other)const
{
	Fixed ret;
	ret.setRawBits(this->getRawBits() / other.getRawBits() << _fractBits);
	return (ret);
}
Fixed	&Fixed::operator ++()
{
	_value++;
	return *this;
}
Fixed	&Fixed::operator --()
{
	_value--;
	return *this;
}
Fixed	Fixed::operator -- (int)
{
	Fixed tmp(*this);
	--(*this);
	return tmp;
}
Fixed	Fixed::operator ++ (int)
{
	Fixed tmp(*this);
	++(*this);
	return tmp;
}
//min-max
Fixed	&Fixed::min (Fixed &one, Fixed &two)
{
	return one < two ? one : two;
	// if (one._value <= two._value)
	// 	return one;
	// else
	// 	return two;
}
Fixed	&Fixed::max (Fixed &one, Fixed &two)
{
	return one > two ? one : two;
	// if (one._value > two.value)
	// 	return one;
	// else
	// 	return two;
}
const Fixed &Fixed::min(const Fixed &one, const Fixed &two)
{
	return one < two ? one : two;
}
const Fixed &Fixed::max (const Fixed &one, const Fixed &two)
{
	return one > two ? one : two;
}
