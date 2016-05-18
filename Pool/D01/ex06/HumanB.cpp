// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 23:23:06 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 23:23:06 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "HumanB.hpp"

//-----------------------------------------------------/ STATIC VARIABLES INIT /

//------------------------------------------------------/ CONSTRUCT / DESTRUCT /
	HumanB::HumanB(std::string name) : _name(name)
	{
	}

	HumanB::~HumanB()
	{
	}

//-----------------------------------------------------------------/ FUNCTIONS /
	void	HumanB::attack()
	{
		std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
	}

	void	HumanB::setWeapon(Weapon& weapon)
	{
		this->_weapon = &weapon;
	}
