// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Ship.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 05:39:09 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "A_Ship.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
A_Ship::A_Ship()
{

}

A_Ship::A_Ship(std::string name, int life, A_Projectile *projectile,
			   A_Squad *squad, v2 weapon, int shcolor, float fire_rate,
			   int height, int width, t_rows *rows,int bucolor,v2 position, float speed) :
	A_Movable(speed, this),
	A_Physical(height, width, rows, shcolor, position),
	_name(name),
	_life(life),
	_projectile(projectile),
	_squad(squad),
	_weapon(weapon),
	_bullet_color(bucolor),
	_fire_rate(fire_rate),
	_firing(0),
	_last_shot(0)
{
	squad->addShip(this);
}

A_Ship::A_Ship(A_Ship const & src) :
	A_Movable(),
	A_Physical()
{
	*this = src;
}


A_Ship::~A_Ship()
{

}

std::string const	&A_Ship::getName(void) const
{
	return this->_name;
}

int			A_Ship::getLife(void) const
{
	return this->_life;
}

bool			A_Ship::getFiring(void) const
{
	return this->_firing;
}

float		A_Ship::getFireRate(void) const
{
	return this->_fire_rate;
}

A_Projectile const	&A_Ship::getProjectile(void)
{
	return *(this->_projectile);
}

v2 const			&A_Ship::getWeapon(void) const
{
	return this->_weapon;
}

A_Squad	*A_Ship::getSquad(void)
{
	return (A_Squad *)(this->_squad);
}

void		A_Ship::setProjectile(A_Projectile *proj)
{
	this->_projectile = proj;
}

void		A_Ship::setFiring(void)
{
	this->_firing = 1;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void	A_Ship::fire(void)
{
	v2				pos;
	A_Projectile	*proj;
	std::string		str2 = "Benoit";

	this->_last_shot++;
	if (this->_last_shot > (this->getFireRate() * g_frame_rate))
	{
		proj = new A_Projectile(this->getProjectile());
		pos = this->getPosition();
		proj->setDir(1, 0);
		proj->setPosition(pos.x + this->_weapon.x, pos.y + this->_weapon.y);
		proj->setColor(this->_bullet_color);
		if (this->getSquad())
			this->getSquad()->addProjectile(proj);
		this->_last_shot = 0;
	}
}

void	A_Ship::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	else if ((this->_life -= damage) <= 0)
		this->_life = 0;
}


//-----------------------------------------------------------------/ OPERATORS /
A_Ship &	A_Ship::operator=(A_Ship const & rhs)
{
	(void)rhs;
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /

