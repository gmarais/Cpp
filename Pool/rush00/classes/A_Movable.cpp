// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Movable.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:12 by gmarais           #+#    #+#             //
//   Updated: 2015/01/18 21:04:19 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "A_Movable.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
A_Movable::A_Movable()
{
	this->_moved = 1;
}

A_Movable::A_Movable(float speed, A_Physical *physical) :
	_speed(speed),
	_physical(physical)
{
	this->_moved = 1;
}

A_Movable::A_Movable(A_Movable const & src)
{
	*this = src;
	this->_moved = 1;
}


A_Movable::~A_Movable()
{
}

//---------------------------------------------------------/ GETTERS / SETTERS /
void	A_Movable::setDir(int x, int y)
{
	this->_dir.x = x;
	this->_dir.y = y;
}

void	A_Movable::setSpeed(float speed)
{
	this->_speed = speed;
}

const v2	&A_Movable::getDir(void) const
{
	return this->_dir;
}

float		A_Movable::getSpeed(void) const
{
	return this->_speed;
}

//-----------------------------------------------------------------/ FUNCTIONS /

void	A_Movable::move(void)
{
	v2	pos;
	v2	screen;

	this->_last_move++;
	if (this->_last_move > (int)(this->getSpeed() * g_frame_rate))
	{
		getmaxyx(stdscr, screen.y, screen.x);
		pos = this->_physical->getPosition();
		if ((pos.x += this->_dir.x) < 1)
			pos.x = 1;
		else if (pos.x > screen.x - 5)
			pos.x = screen.x - 5;
		if ((pos.y += this->_dir.y) < 1)
			pos.y = 1;
		else if (pos.y > screen.y - 7 - this->_physical->getHeight() / 2)
			pos.y = screen.y - 7 - this->_physical->getHeight() / 2;
		this->_physical->setPosition(pos.x, pos.y);
		this->_last_move = 0;
		this->_moved = 1;
	}

}

//-----------------------------------------------------------------/ OPERATORS /
A_Movable &	A_Movable::operator=(A_Movable const & rhs)
{
	(void)rhs;
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
