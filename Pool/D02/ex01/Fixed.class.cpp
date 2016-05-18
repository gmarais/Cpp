// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 21:27:06 by gmarais           #+#    #+#             //
//   Updated: 2015/01/08 05:27:58 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "Fixed.class.hpp"

//---------------------------------------------------------------/ STATIC INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Fixed::Fixed() : _raw_bits(0), _b(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const integer) : _raw_bits(integer << 8), _b(8)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float fl) : _b(8)
{
	int		integer;
	int		decimal;
	int		pow_b = 2;

	for (int i = this->_b - 1; i; i--)
	{
		pow_b *= 2;
	}
	std::cout << "Float constructor called" << std::endl;
	integer = (int)fl;
	decimal = (int)roundf((fl - (float)integer) * pow_b);
	this->_raw_bits = (integer << this->_b) + decimal;
}

Fixed::Fixed(Fixed const & src) : _b(8)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//-----------------------------------------------------------------/ FUNCTIONS /
int		Fixed::getRawBits() const
{
	return this->_raw_bits;
}


void	Fixed::setRawBits(int const raw)
{
	this->_raw_bits = raw;
}

float	Fixed::toFloat() const
{
	int		decimal;
	int		integer;
	int		pow_b = 2;

	for (int i = this->_b - 1; i; i--)
	{
		pow_b *= 2;
	}
	integer = this->_raw_bits >> this->_b;
	decimal = this->_raw_bits - (integer << 8);
	return (float)integer + ((float)decimal / pow_b);
}

int		Fixed::toInt() const
{
	return this->_raw_bits >> this->_b;
}

//-----------------------------------------------------------------/ OPERATORS /
Fixed &			Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_raw_bits = rhs.getRawBits();
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
