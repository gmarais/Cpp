// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 21:27:06 by gmarais           #+#    #+#             //
//   Updated: 2015/01/08 09:03:05 by gmarais          ###   ########.fr       //
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

Fixed const &	Fixed::min(Fixed const & f1, Fixed const & f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return f2;
	return f1;
}

Fixed &	Fixed::min(Fixed & f1, Fixed & f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return f2;
	return f1;
}

Fixed const &	Fixed::max(Fixed const & f1, Fixed const & f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return f2;
	return f1;
}

Fixed &	Fixed::max(Fixed & f1, Fixed & f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return f2;
	return f1;
}

//-----------------------------------------------------------------/ OPERATORS /
Fixed &			Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_raw_bits = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const & rhs)
{
	return (this->_raw_bits > rhs.getRawBits()) ? true : false;
}

bool	Fixed::operator<(Fixed const & rhs)
{
	return (this->_raw_bits < rhs.getRawBits()) ? true : false;
}

bool	Fixed::operator>=(Fixed const & rhs)
{
	return (this->_raw_bits >= rhs.getRawBits()) ? true : false;
}

bool	Fixed::operator<=(Fixed const & rhs)
{
	return (this->_raw_bits <= rhs.getRawBits()) ? true : false;
}

bool	Fixed::operator==(Fixed const & rhs)
{
	return (this->_raw_bits == rhs.getRawBits()) ? true : false;
}

bool	Fixed::operator!=(Fixed const & rhs)
{
	return (this->_raw_bits != rhs.getRawBits()) ? true : false;
}

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	Fixed result;
	result.setRawBits(this->_raw_bits + rhs.getRawBits());
	return Fixed(result);
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	Fixed result;
	result.setRawBits(this->_raw_bits - rhs.getRawBits());
	return Fixed(result);
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &	Fixed::operator++()
{
	this->_raw_bits++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_raw_bits++;
	return tmp;
}

Fixed &	Fixed::operator--()
{
	this->_raw_bits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_raw_bits--;
	return tmp;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
