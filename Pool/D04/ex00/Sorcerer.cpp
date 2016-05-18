// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 00:22:19 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 02:33:24 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Sorcerer.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ", "
			  << this->_title << ", is born !"
			  << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	this->_name = src.getName();
	this->_name = src.getTitle();
	*this = src;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", "
			  << this->_title << ", is dead. Consequences will never be the same !"
			  << std::endl;
}

//-----------------------------------------------------------------/ FUNCTIONS /
std::string	Sorcerer::getName() const
{
	return this->_name;
}

std::string	Sorcerer::getTitle() const
{
	return this->_title;
}

void		Sorcerer::polymorph(Victim const & v)
{
	v.getPolymorphed();
}


//-----------------------------------------------------------------/ OPERATORS /
Sorcerer &		Sorcerer::operator=(Sorcerer const & rhs)
{
	this->_name = rhs.getName();
	this->_name = rhs.getTitle();
	return *this;
}

std::ostream &	operator<<(std::ostream & os, Sorcerer & s)
{
	return os << "I am "
			  << s.getName() << ", "
			  << s.getTitle()
			  << ", and I like ponies !"
			  << std::endl;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
