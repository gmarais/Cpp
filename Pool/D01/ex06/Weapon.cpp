// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 22:52:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 22:52:10 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Weapon.hpp"

//-----------------------------------------------------/ STATIC VARIABLES INIT /

//------------------------------------------------------/ CONSTRUCT / DESTRUCT /
	Weapon::Weapon(std::string type) : _type(type)
	{
	}

	Weapon::~Weapon()
	{
	}

	std::string const&	Weapon::getType()
	{
		std::string const&	ref_type = this->_type;

		return ref_type;
	}

	void				Weapon::setType(std::string type)
	{
		this->_type = type;
	}

//-----------------------------------------------------------------/ FUNCTIONS /
