// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Shape.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 02:04:46 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "A_Shape.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
A_Shape::A_Shape(void)
{
}

A_Shape::A_Shape(int height, int width, t_rows *rows, int color, v2 position) :
	A_Printable(position, color),
	_height(height),
	_width(width)
{
	int	i;

//	std::cout << "BONJOUR SHAPE START" << std::endl;
	this->_rows = new t_rows[height];
	i = 0;
	while (i < height)
	{
		this->_rows[i] = new t_row;
		this->_rows[i]->data = rows[i]->data;
		this->_rows[i]->indent = rows[i]->indent;
		i++;
	}
//	std::cout << "BONJOUR SHAPE END" << std::endl;
	rows[i] = NULL;
}

A_Shape::A_Shape(A_Shape const & src) :
	A_Printable()
{
	*this = src;
}


A_Shape::~A_Shape(void)
{
	delete [] this->_rows;
}

//-----------------------------------------------------------------/ FUNCTIONS /

int		A_Shape::getHeight(void) const
{
	return this->_height;
}

int		A_Shape::getWidth(void) const
{
	return this->_width;
}

t_rows	*A_Shape::getRows(void) const
{
	return this->_rows;
}

void		A_Shape::render(void)
{
	v2	*cursor = new v2;

	this->enableAttr();
	for (int i = 0; i < this->_height; i++)
	{
		cursor->x = this->getPosition().x + this->_rows[i]->indent;
		cursor->y = this->getPosition().y + i;
		this->printStrPosition(this->_rows[i]->data, *cursor);
	}
	this->disableAttr();
	delete cursor;
}

//-----------------------------------------------------------------/ OPERATORS /
A_Shape &	A_Shape::operator=(A_Shape const & rhs)
{
	(void)rhs;
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
