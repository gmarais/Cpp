// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Player.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 05:27:06 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "A_Player.hpp"
#include <ncurses.h>
//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
A_Player::A_Player()
{
}

A_Player::A_Player(std::string name, int life, A_Projectile *projectile,
			   A_Squad *squad, v2 weapon, int shcolor, float fire_rate,
			   int height, int width, t_rows *rows, int bucolor, v2 position, float speed) :
	A_Ship(name, life, projectile, squad, weapon, shcolor, fire_rate, height, width,
		   rows, bucolor, position, speed)
{
}

A_Player::A_Player(A_Player const & src) :
	A_Ship(src)
{
	*this = src;
}


A_Player::~A_Player()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /

/*
void	A_Player::smartBomb(void) const
{

}
*/

//-----------------------------------------------------------------/ OPERATORS /
A_Player &	A_Player::operator=(A_Player const & rhs)
{
	(void)rhs;
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
