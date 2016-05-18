// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.cpp	                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 15:04:29 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 15:04:29 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "ZombieEvent.hpp"

std::string	ZombieEvent::_consonants = "bcdfghjklmnpqrstvwxz";
std::string	ZombieEvent::_vowels = "aeiouy";

ZombieEvent::ZombieEvent()
{

}

ZombieEvent::~ZombieEvent()
{
	
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->_zombie_type = type;
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	return new Zombie(name, this->_zombie_type);
}

std::string	ZombieEvent::_randomNameGenerator()
{
	bool				coin;
	int					size;
	std::string			name;

	std::srand(std::time(0));
	coin = (std::rand() % 2) ? true : false;
	size = 3 + std::rand() % 8;
	name.resize(size);
	for (int i = 0; i < size; i++)
	{
		if (coin)
			name[i] = (i % 2) ? this->_consonants[(int)(std::rand() % 20)] : this->_vowels[(int)(std::rand() % 5)];
		else
			name[i] = (i % 2) ? this->_vowels[(int)(std::rand() % 6)] : this->_consonants[(int)(std::rand() % 20)];
	}
	return name;
}

void	ZombieEvent::randomChump()
{
	Zombie random_zombie(this->_randomNameGenerator(), this->_zombie_type);

	random_zombie.announce();
}
