// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:26:54 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "PlasmaRifle.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
PlasmaRifle::PlasmaRifle() :
	AWeapon(
		"Plasma Rifle",
		5,
		21
	)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) :
	AWeapon(src)
{
	*this = src;
}


PlasmaRifle::~PlasmaRifle()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /
void			PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

//-----------------------------------------------------------------/ OPERATORS /
PlasmaRifle &	PlasmaRifle::operator=(PlasmaRifle const & rhs)
{
	AWeapon::operator=(rhs);
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
