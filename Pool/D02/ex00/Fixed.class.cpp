// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 21:27:06 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 22:38:41 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "Fixed.class.hpp"

//---------------------------------------------------------------/ STATIC INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Fixed::Fixed() : _raw_bits(0), _b(8)
{
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw_bits;
}


void	Fixed::setRawBits(int const raw)
{
	this->_raw_bits = raw;
}

//-----------------------------------------------------------------/ OPERATORS /
Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_raw_bits = rhs.getRawBits();
	return *this;
}
