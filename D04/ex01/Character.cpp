// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 06:01:25 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Character.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Character::Character(std::string const & name) :
	_name(name),
	_ap(40),
	_weapon(NULL)
{
}

Character::Character() :
	_ap(40),
	_weapon(NULL)
{
}

Character::Character(Character const & src)
{
	*this = src;
}


Character::~Character()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /
std::string const &	Character::getName() const
{
	return this->_name;
}

int					Character::getAP() const
{
	return this->_ap;
}

AWeapon				*Character::getWeapon() const
{
	return this->_weapon;
}

void				Character::recoverAP()
{
	this->_ap += 10;
}

void				Character::equip(AWeapon *w)
{
	this->_weapon = w;
}

void				Character::attack(Enemy *e)
{
	if (e && this->_weapon && this->_ap > this->_weapon->getAPCost())
	{
		std::cout << this->_name << " attacks " << e->getType() << " with a " << this->_weapon->getName() << std::endl;
		this->_ap -= this->_weapon->getAPCost();
		this->_weapon->attack();
		e->takeDamage(this->_weapon->getDamage());
		if (!e->getHP())
		{
			delete e;
		}
	}
}

//-----------------------------------------------------------------/ OPERATORS /
Character &	Character::operator=(Character const & rhs)
{
	this->_name = rhs.getName();
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
std::ostream &	operator<<(std::ostream & os, Character & s)
{
	if (s.getWeapon())
		return os << s.getName() <<" has "
				  << s.getAP() << " AP and wields a "
				  << s.getWeapon()->getName() << std::endl;
	else
		return os << s.getName() << " has "
				  << s.getAP() << " AP and is unarmed" 
				  << std::endl;
}
