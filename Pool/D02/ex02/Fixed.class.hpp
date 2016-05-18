// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 21:27:13 by gmarais           #+#    #+#             //
//   Updated: 2015/01/08 09:04:17 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <cmath>

#ifndef _Fixed_CLASS_
#define _Fixed_CLASS_

class	Fixed
{
public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Fixed();
	Fixed(float fl);
	Fixed(int const integer);
	Fixed(Fixed const & src);
	~Fixed();
//-----------------------------------------------------------------/ OPERATORS /
	Fixed &	operator=(Fixed const & rhs);
	bool	operator>(Fixed const & rhs);
	bool	operator<(Fixed const & rhs);
	bool	operator>=(Fixed const & rhs);
	bool	operator<=(Fixed const & rhs);
	bool	operator==(Fixed const & rhs);
	bool	operator!=(Fixed const & rhs);
	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;
	Fixed &	operator++();
	Fixed &	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);
	static int	_compare(Fixed const & lhs, Fixed const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	int						getRawBits() const;
	void					setRawBits(int const raw);
	float					toFloat() const;
	int						toInt() const;
	int						get_b() const;
	static Fixed const &	min(Fixed const & f1, Fixed const & f2);
	static Fixed &			min(Fixed & f1, Fixed & f2);
	static Fixed const & 	max(Fixed const & f1, Fixed const & f2);
	static Fixed &			max(Fixed & f1, Fixed & f2);
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	int			_raw_bits;
	int const	_b;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif
