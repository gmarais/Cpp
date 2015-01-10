// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:24:06 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Enemy::Enemy(int hp, std::string const & type) :
	_hp(hp),
	_type(type)
{
}

Enemy::Enemy()
{
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}


Enemy::~Enemy()
{
}

//-------------------------------------------------------------------/ GETTERS /
std::string const &	Enemy::getType() const
{
	return this->_type;
}

int					Enemy::getHP() const
{
	return this->_hp;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void				Enemy::takeDamage(int amount)
{
	if (this->_hp - amount <= 0)
	{
		this->_hp = 0;
	}
	else
		this->_hp -= amount;
}

//-----------------------------------------------------------------/ OPERATORS /
Enemy &				Enemy::operator=(Enemy const & rhs)
{
	this->_type = rhs.getType();
	this->_hp = rhs.getHP();
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
