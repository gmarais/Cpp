// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Physical.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 02:32:17 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "A_Physical.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
A_Physical::A_Physical()
{
}

A_Physical::A_Physical(int height, int width, t_rows *rows, int color, v2 position) :
	A_Shape(height, width, rows, color, position)
{
//	std::cout << "BONJOUR PHYSICAL" << std::endl;
}

A_Physical::A_Physical(A_Physical const & src) :
	A_Shape(src)
{
	*this = src;
}


A_Physical::~A_Physical()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
A_Physical &	A_Physical::operator=(A_Physical const & rhs)
{
	(void)rhs;
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /


bool	A_Physical::collide(v2 *pos) const // 0 for collision, else 1.
{
	v2	curr;
	int rel_x;
	int	rel_y;

	curr = this->getPosition();
	if (pos->x < curr.x || curr.x + this->getWidth() < pos->x
		|| pos->y < curr.y || curr.y + this->getHeight() < pos->y)
		return 1;
	else
	{
		rel_x = pos->x - curr.x;
		rel_y = pos->y - curr.y;
	}
	if ((rel_x = pos->x - this->getRows()[rel_y]->indent - curr.x) < 0)
		return 1;
	return 0;
}

bool	A_Physical::collide(A_Shape &shape) const
{
	v2	curr;
	v2	pos;
	int rel_x;
	int	rel_y;
	int	rel_y2;
	int	s_width;
	int	s_height;

	pos = shape.getPosition();
	curr = this->getPosition();
	s_width = shape.getWidth();
	s_height = shape.getHeight();
	if (pos.x + s_width < curr.x || curr.x + this->getWidth() < pos.x
		|| pos.y + s_height < curr.y || curr.y + this->getHeight() < pos.y)
		return 1;
	else
		rel_y = pos.y - curr.y;
	rel_y2 = 0;
	if (rel_y < 0)
	{
		rel_y2 = rel_y * -1;
		rel_y = 0;
	}
	while (rel_y < this->getHeight() && rel_y2 < s_height)
	{
		rel_x = pos.x + shape.getRows()[rel_y2]->indent - this->getRows()[rel_y]->indent - curr.x;
		if (rel_x < 0 && (unsigned int)(-rel_x) < shape.getRows()[rel_y2]->data.length())
			return 1;
		else if ((unsigned int)rel_x < this->getRows()[rel_y]->data.length())
			return 1;
		rel_y++;
		rel_y2++;
	}
	return 1;
}
