// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RadScorpion.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:30:21 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "RadScorpion.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
RadScorpion::RadScorpion() :
	Enemy(
		80,
		"RadScorpion"
	)
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & src) :
	Enemy(src)
{
	*this = src;
}


RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void			RadScorpion::takeDamage(int amount)
{
	if (this->_hp - amount <= 0)
	{
		this->_hp = 0;
	}
	else
		this->_hp -= amount;
}

//-----------------------------------------------------------------/ OPERATORS /
RadScorpion &	RadScorpion::operator=(RadScorpion const & rhs)
{
	Enemy::operator=(rhs);
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
