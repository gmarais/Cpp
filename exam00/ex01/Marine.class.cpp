// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Marine.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 22:27:37 by exam              #+#    #+#             //
//   Updated: 2015/01/09 22:59:52 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "Marine.class.hpp"

//-----------------------------------------------------/ CONSTRUCTS & DESTRUCTS/
Marine::Marine() :
	Unit::Unit()
{
	this->_type = "Marine";
	this->_hp = 40;
	this->_max_hp = 40;
	this->_damage = 6;
	std::cout << "Unit #" << this->getIndex() << ": You want a piece of me, boy ?" << std::endl;
}

Marine::Marine(int x, int y) :
	Unit::Unit(
		"Marine",
		x, y,
		6,
		40, 40
	)
{
	std::cout << "Unit #" << this->getIndex() << ": You want a piece of me, boy ?" << std::endl;
}

Marine::Marine(Marine & src) :
	Unit::Unit(src)
{
	std::cout << "Unit #" << this->getIndex() << ": You want a piece of me, boy ?" << std::endl;
}

Marine::~Marine()
{
}

//------------------------------------------------------------------/ OPERATORS/
Marine&			Marine::operator=(const Marine & src)
{
	Unit::operator=(src);
	return *this;
}

//--------------------------------------------------------------------/ GETTERS/
//------------------------------------------------------------------/ FUNCTIONS/
void				Marine::die()
{
	Unit::die();
	std::cout << "Unit #" << this->getIndex() << ": Aaaargh..." << std::endl;
}

void				Marine::move(int x, int y)
{
	Unit::move(x, y);
	std::cout << "Unit #" << this->getIndex() << ": Rock’n’roll !!!" << std::endl;	
}

void				Marine::stimpack()
{
	if (this->_hp > 10)
	{
		*this -= 10;
		std::cout << "Unit #" << this->getIndex() << ": Ho yeah..." << std::endl;
	}
}
