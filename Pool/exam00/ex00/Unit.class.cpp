// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Unit.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 19:16:41 by exam              #+#    #+#             //
//   Updated: 2015/01/09 22:49:41 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "Unit.class.hpp"


int	Unit::_instances_count = 0;

//-----------------------------------------------------/ CONSTRUCTS & DESTRUCTS/
Unit::Unit() :
	_index(Unit::_instances_count),
	_type("Unit"),
	_x(0),
	_y(0),
	_damage(0),
	_hp(0),
	_max_hp(0)
{
	Unit::_instances_count++;
	std::cout << "[CREATED] Unit #"
			  << this->_index << ": "
			  << this->_type << " in "
			  << this->_x << "/" << this->_y << " with "
			  << this->_hp << "/" << this->_max_hp << "HP damaging at "
			  << this->_damage << "." << std::endl;
}

Unit::Unit(std::string type, int x, int y, int damage, int hp, int max_hp) :
	_index(Unit::_instances_count),
	_type(type),
	_x(x),
	_y(y),
	_damage(damage),
	_hp(hp),
	_max_hp(max_hp)
{
	Unit::_instances_count++;
	std::cout << "[CREATED] Unit #"
			  << this->_index << ": "
			  << this->_type << " in "
			  << this->_x << "/" << this->_y << " with "
			  << this->_hp << "/" << this->_max_hp << "HP damaging at "
			  << this->_damage << "." << std::endl;
}

Unit::Unit(Unit & src) :
	_index(Unit::_instances_count),
	_type(src.getType()),
	_x(src.getX()),
	_y(src.getY()),
	_damage(src.getDam()),
	_hp(src.getCHP()),
	_max_hp(src.getMHP())
{
	Unit::_instances_count++;
	std::cout << "[CREATED] Unit #"
			  << this->_index << ": "
			  << this->_type << " in "
			  << this->_x << "/" << this->_y << " with "
			  << this->_hp << "/" << this->_max_hp << "HP damaging at "
			  << this->_damage << "." << std::endl;
}

Unit::~Unit()
{
	std::cout << "[DESTRUCTED] Unit #"
			  << this->_index << ": "
			  << this->_type << " in "
			  << this->_x << "/" << this->_y << " with "
			  << this->_hp << "/" << this->_max_hp << "HP damaging at "
			  << this->_damage << "." << std::endl;
}

//------------------------------------------------------------------/ OPERATORS/
Unit&			Unit::operator=(const Unit & src)
{
	this->_type = src.getType();
	this->_x = src.getX();
	this->_y = src.getY();
	this->_damage = src.getDam();
	this->_hp = src.getCHP();
	this->_max_hp = src.getMHP();
	return *this;
}

std::ostream &		operator<<(std::ostream & os, Unit & u)
{
	return os << "Unit #" << u.getIndex()
			   << ": in " << u.getX() << "/" << u.getY() << " with "
			   << u.getCHP() << "/" << u.getMHP() << "HP damaging at "
			   << u.getDam() << ".";
}

void				Unit::operator+=(int rhs)
{
	if (this->_hp)
 	{
		if (this->_hp + rhs >= this->_max_hp)
			this->_hp = this->_max_hp;
		else if (this->_hp + rhs <= 0)
		{
			this->_hp = 0;
			this->die();
		}
		else
			this->_hp += rhs;
	}
}

void				Unit::operator-=(int rhs)
{
	if (this->_hp)
 	{
		if (this->_hp - rhs >= this->_max_hp)
			this->_hp = this->_max_hp;
		else if (this->_hp - rhs <= 0)
		{
			this->_hp = 0;
			this->die();
		}
		else
			this->_hp -= rhs;
	}
}

//--------------------------------------------------------------------/ GETTERS/
int					Unit::getIndex() const
{
	return this->_index;
}

std::string const &	Unit::getType() const
{
	return this->_type;
}

int					Unit::getX() const
{
	return this->_x;
}

int					Unit::getY() const
{
	return this->_y;
}

int					Unit::getDam() const
{
	return this->_damage;
}

int					Unit::getCHP() const
{
	return this->_hp;
}

int					Unit::getMHP() const
{
	return this->_max_hp;
}

//------------------------------------------------------------------/ FUNCTIONS/
void				Unit::die()
{
	this->_hp = 0;
	std::cout << "Unit #" << this->_index << " (" << this->_type << ") died." << std::endl;
}

void				Unit::move(int x, int y)
{
	if (this->_hp)
 	{
	std::cout <<  "Unit #" << this->_index <<  " (" 
			  << this->_type <<  ") is moving from " 
			  << this->_x  <<  "/" << this->_y
			  <<  " to " << x <<  "/" << y 
			  <<  "." << std::endl;
	this->_x = x;
	this->_y = y;
	}
}

void				Unit::attack( Unit & target ) const
{
	if (this->_hp)
 	{
		std::cout <<  "Unit #" << this->_index <<  " (" 
			  << this->_type <<  ") damaged unit #"
			  << target.getIndex() 
			  << " (" << target.getType()
			  <<  ")." << std::endl;	
		target -= this->_damage;
	}
}
