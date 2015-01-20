// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Enemy.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 20:57:13 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "A_Enemy.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
A_Enemy::A_Enemy()
{/*
	v2	pos;
	pos.x = this->getScreenWH().x / 2 + std::rand() % this->getScreenWH().x / 2 - 4;
	pos.y = std::rand() % (this->getScreenWH().y - 8);
	this->setDir(1, ((std::rand() % 2) ? 1 : 0));
	this->setPosition(pos.x, pos.y);*/
}

/*
A_Enemy::A_Enemy() :
{
}
*/

A_Enemy::A_Enemy(A_Enemy const & src) :
	A_Ship()
{
	*this = src;
}


A_Enemy::~A_Enemy()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /
/*void	A_Enemy::basicIA()
{
	v2 dir;

	if (std::abs(g_curr_time - this->_past_time_ia) >= 8)
	{
		dir = this->getDir();
		if (std::rand() % 2)
			this->setDir(dir.x , -dir.y);
		else
			this->setDir(-dir.x , -dir.y);
		this->_past_time_ia = g_curr_time;
	}
}*/

void	A_Enemy::play(void)
{
//	this->basicIA();
	this->move();
	this->fire();
	this->render();
}

//-----------------------------------------------------------------/ OPERATORS /
A_Enemy &	A_Enemy::operator=(A_Enemy const & rhs)
{
	// @TODO : COPY ATTRIBUTES HERE.
	(void)rhs;
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
