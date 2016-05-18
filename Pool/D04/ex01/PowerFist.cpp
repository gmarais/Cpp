// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PowerFist.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:42:50 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PowerFist.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
PowerFist::PowerFist() :
	AWeapon(
		"Power Fist",
		8,
		50
	)
{
}

PowerFist::PowerFist(PowerFist const & src) :
	AWeapon(src)
{
	*this = src;
}


PowerFist::~PowerFist()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /
void		PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

//-----------------------------------------------------------------/ OPERATORS /
PowerFist &	PowerFist::operator=(PowerFist const & rhs)
{
	AWeapon::operator=(rhs);
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
