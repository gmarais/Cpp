// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 00:22:33 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 02:11:49 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Peon.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Peon::Peon()
{
}

Peon::Peon(std::string name) :
Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & src) :
Victim(src)
{
	*this = src;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void	Peon::getPolymorphed() const
{
	std::cout << this->_name << "  has been turned into a pink pony !"
			  << std::endl;
}

//-----------------------------------------------------------------/ OPERATORS /
Peon &	Peon::operator=(Peon const & rhs)
{
	Victim::operator=(rhs);
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
