// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperMutant.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:54:01 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperMutant.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
SuperMutant::SuperMutant() :
	Enemy(
		170,
		"Super Mutant"
	)
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src) :
	Enemy(src)
{
	*this = src;
}


SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void			SuperMutant::takeDamage(int amount)
{
	if (this->_hp - (amount - 3) <= 0)
	{
		this->_hp = 0;
	}
	else
		this->_hp -= (amount - 3);
}

//-----------------------------------------------------------------/ OPERATORS /
SuperMutant &	SuperMutant::operator=(SuperMutant const & rhs)
{
	Enemy::operator=(rhs);
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
