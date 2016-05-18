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
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Zombie.hpp"

std::string	Zombie::_consonants = "bcdfghjklmnpqrstvwxz";
std::string	Zombie::_vowels = "aeiouy";

Zombie::Zombie(std::string name, std::string type) :
_name(name),
_type(type)
{
	std::cout << "Zombie " << this->_name
	<< " created with type " << this->_type
	<< "." << std::endl;	
}

Zombie::Zombie()
{
	this->_name = this->_randomNameGenerator();
	this->_type = "";
	std::cout << "Zombie " << this->_name
	<< " created with no type specified." << std::endl;	
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

std::string	Zombie::_randomNameGenerator()
{
	static int 			counter = 0;
	bool				coin;
	int					size;
	std::string			name;

	std::srand(std::time(0) + counter);
	counter++;
	coin = (std::rand() % 2) ? true : false;
	size = 3 + std::rand() % 8;
	name.resize(size);
	for (int i = 0; i < size; i++)
	{
		if (coin)
			name[i] = (i % 2) ? this->_consonants[(int)(std::rand() % 20)] : this->_vowels[(int)(std::rand() % 5)];
		else
			name[i] = (i % 2) ? this->_vowels[(int)(std::rand() % 6)] : this->_consonants[(int)(std::rand() % 19)];
	}
	return name;
}
