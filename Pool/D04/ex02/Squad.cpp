// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 07:10:24 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 08:41:29 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Squad.hpp"

//--------------------------------------------------------------/ STATICS INIT /
int	Squad::_count = 0;

//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Squad::Squad()
{
}

Squad::Squad(Squad const & src)
{
	this->deleteSquadList();
	*this = src;
}


Squad::~Squad()
{
	this->deleteSquadList();
}

//-----------------------------------------------------------------/ FUNCTIONS /
void		Squad::deleteSquadList()
{
	SquadLink	*to_delete;

	while (this->_squad_list)
	{
		to_delete = this->_squad_list;
		this->_squad_list = this->_squad_list->next;
		delete to_delete;
	}
}

int			Squad::getCount() const
{
	return this->_count;
}

void		Squad::remove(int N)
{
	SquadLink	*prev;
	SquadLink	*tmp;
	int			i;

	tmp = this->_squad_list;
	for (i = 0; i <= this->_count && i != N; i++)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	this->_count--;
	delete tmp->curr;
	delete tmp;
}

int			Squad::push(ISpaceMarine *sm)
{
	SquadLink	*newLink = new SquadLink;

	this->_count++;
	newLink->curr = sm;
	if (this->_squad_list)
		newLink->next = this->_squad_list;
	else
		newLink->next = NULL;
	this->_squad_list = newLink;
}

ISpaceMarine*	Squad::getUnit(int N) const
{
	SquadLink	*tmp;
	int			i;

	tmp = this->_squad_list;
	for (i = 0; i <= this->_count && i != N; i++)
	{
		tmp = tmp->next;
	}
	return tmp->curr;
}

SquadLink	Squad::*getSquadList()
{
	return this->_squad_list;
}

//-----------------------------------------------------------------/ OPERATORS /
Squad &		Squad::operator=(Squad const & rhs)
{
	this->deleteSquadList();
	this->_count = rhs.getCount();
	this->_squad_list = rhs.getSquadList();
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
