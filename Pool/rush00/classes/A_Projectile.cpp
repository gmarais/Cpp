// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Projectile.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:12 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 04:46:38 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "A_Projectile.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
A_Projectile::A_Projectile()
{
}

A_Projectile::A_Projectile(std::string name, int damage, int height, int width
						   , t_rows *rows, int color, v2 position, int speed) :
	A_Physical(height, width, rows, color, position),
	A_Movable(speed, this),
	_name(name),
	_damage(damage)
{
	
//	std::cout << "BONJOUR PROJECTILE !" << std::endl;
}

A_Projectile::A_Projectile(A_Projectile const & src) :
	A_Physical(src.getHeight(), src.getWidth(), src.getRows(), src.getColor(), src.getPosition()),
	A_Movable(src.getSpeed(), this),
	_name(src._name),
	_damage(src._damage)
{
	
}


A_Projectile::~A_Projectile()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /
const std::string		&A_Projectile::getName(void) const
{
	return this->_name;
}

int			A_Projectile::getDamage(void) const
{
	return this->_damage;
}

//-----------------------------------------------------------------/ OPERATORS /
A_Projectile	&A_Projectile::operator=(A_Projectile const & rhs)
{
	(void)rhs;
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
