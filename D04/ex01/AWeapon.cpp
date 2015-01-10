// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:05:40 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AWeapon.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
	_name(name),
	_apcost(apcost),
	_damage(damage)
{
}

AWeapon::AWeapon()
{
}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}


AWeapon::~AWeapon()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /
std::string const &	AWeapon::getName() const
{
	return this->_name;
}

int			AWeapon::getAPCost() const
{
	return this->_apcost;
}

int			AWeapon::getDamage() const
{
	return this->_damage;
}


//-----------------------------------------------------------------/ OPERATORS /
AWeapon &	AWeapon::operator=(AWeapon const & rhs)
{
	this->_name = rhs.getName();
	this->_apcost = rhs.getAPCost();
	this->_damage = rhs.getDamage();
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
