// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 21:27:13 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 22:38:47 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>

#ifndef _Fixed_CLASS_
#define _Fixed_CLASS_

class	Fixed
{
public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Fixed();
	Fixed(Fixed const & src);
	~Fixed();
//-----------------------------------------------------------------/ OPERATORS /
	Fixed &	operator=(Fixed const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	int		getRawBits() const;
	void	setRawBits(int const raw);

private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	int			_raw_bits;
	int const	_b;

//---------------------------------------------------------/ PRIVATE FUNCTIONS /

};

#endif
