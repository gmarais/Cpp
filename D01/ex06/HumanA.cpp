// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 23:23:06 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 23:23:06 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "HumanA.hpp"

//-----------------------------------------------------/ STATIC VARIABLES INIT /

//------------------------------------------------------/ CONSTRUCT / DESTRUCT /
	HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
	{
	}

	HumanA::~HumanA()
	{
	}

//-----------------------------------------------------------------/ FUNCTIONS /
	void	HumanA::attack()
	{
		std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
	}
