// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 00:22:27 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 02:32:49 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Victim.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Victim::Victim()
{
}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called "
			  << this->_name << " just popped !"
			  << std::endl;
}

Victim::Victim(Victim const & src)
{
	*this = src;
}


Victim::~Victim()
{
	std::cout << "Victim " << this->_name
			  << " just died for no apparent reason !"
			  << std::endl;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void		Victim::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a cute little sheep !"
			  << std::endl;
}

std::string	Victim::getName() const
{
	return this->_name;
}

//-----------------------------------------------------------------/ OPERATORS /
Victim &	Victim::operator=(Victim const & rhs)
{
	this->_name = rhs.getName();
	return *this;
}

std::ostream &	operator<<(std::ostream & os, Victim & v)
{
	return os << "I'm "
			  << v.getName()
			  << ", and I like otters !"
			  << std::endl;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
