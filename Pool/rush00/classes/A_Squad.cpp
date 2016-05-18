// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Squad.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:12 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 05:06:56 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "A_Squad.hpp"

//--------------------------------------------------------------/ STATICS INIT /
int	A_Squad::_count = 0;
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
A_Squad::A_Squad(void) :
	_ships(NULL)
{
}

A_Squad::A_Squad(A_Squad const & src)
{
	*this = src;
}


A_Squad::~A_Squad(void)
{
}

int			A_Squad::getCount() const
{
	return this->_count;
}

SquadLink	*A_Squad::getShips(void) const
{
	return this->_ships;
}

int			A_Squad::addShip(A_Physical *ship)
{
	SquadLink	*newLink = new SquadLink;

	this->_count++;
	newLink->curr = ship;
	if (this->_ships)
		newLink->next = this->_ships;
	else
		newLink->next = NULL;
	this->_ships = newLink;

	return this->_count;
}

SquadLink	*A_Squad::getProjectiles(void) const
{
	return this->_projectiles;
}

void		A_Squad::addProjectile(A_Projectile *projectile)
{
	SquadLink	*newLink = new SquadLink;

	this->_count++;
	newLink->curr = projectile;
	if (this->_projectiles)
		newLink->next = this->_projectiles;
	else
		newLink->next = NULL;
	this->_projectiles = newLink;
}

void		A_Squad::removeShip(int index)
{
	SquadLink	*prev;
	SquadLink	*tmp;
	int			i;

	tmp = this->_ships;
	for (i = 0; i <= this->_count && i != index; i++)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	this->_count--;
	delete tmp->curr;
	delete tmp;
}

void		A_Squad::deleteShipList(void)
{
	A_Physical	*to_delete;

	while (this->_ships)
	{
		to_delete = this->_ships->curr;
		this->_ships = this->_ships->next;
		delete to_delete;
	}
}

void		A_Squad::removeProjectile(int index)
{
	SquadLink	*prev;
	SquadLink	*tmp;
	int			i;

	tmp = this->_projectiles;
	for (i = 0; i <= this->_count && i != index; i++)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	this->_count--;
	delete tmp->curr;
	delete tmp;
}

void		A_Squad::deleteProjectileList(void)
{
	A_Physical	*to_delete;

	while (this->_projectiles)
	{
		to_delete = this->_projectiles->curr;
		this->_projectiles = this->_projectiles->next;
		delete to_delete;
	}
}

//-----------------------------------------------------------------/ FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
A_Squad &	A_Squad::operator=(A_Squad const & rhs)
{
	(void)rhs;
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
