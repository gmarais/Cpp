// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.cpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 13:50:08 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 13:50:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) :
_name(name),
_type(type)
{
	std::cout << "Zombie " << this->_name
	<< " created with type " << this->_type
	<< "." << std::endl;	
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name
	<< " of type " << this->_type
	<< " destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << "<" << this->_name << " (" << this->_type
	<< ")> Braiiiiiiinnnssss..." << std::endl;
}
