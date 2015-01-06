// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.cpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 11:27:58 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 11:27:58 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Pony.hpp"

//-----------------------------------------------------/ STATIC VARIABLES INIT /
int Pony::_number_of_ponies = 0;

//------------------------------------------------------/ CONSTRUCT / DESTRUCT /
Pony::Pony(std::string pony_name) :
_pony_name(pony_name)
{
	this->_number_of_ponies++;
	std::cout << "Pony " << this->_pony_name << " is born." << std::endl;
}

Pony::~Pony()
{
	this->_number_of_ponies--;
	std::cout << this->_pony_name << " died." << std::endl;
}

//-------------------------------------------------------------------/ GETTERS /
int	Pony::getNumberOfPonies()
{
	return Pony::_number_of_ponies;
}

//--------------------------------------------------------------------/ OTHERS /
void		Pony::run()
{
	std::cout << this->_pony_name << " starts running." << std::endl;
}

//-------------------------------------------------------------------/ PRIVATE /
