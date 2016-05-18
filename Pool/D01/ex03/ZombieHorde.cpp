// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.cpp	                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 16:55:07 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 16:55:07 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "ZombieHorde.hpp"

//-----------------------------------------------------/ STATIC VARIABLES INIT /

//------------------------------------------------------/ CONSTRUCT / DESTRUCT /
ZombieHorde::ZombieHorde(int N) :
_zombies_number(N)
{
	this->_horde = new Zombie[N];
	std::cout << "A " << this->_zombies_number << " zombies horde was created." << std::endl;
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->_horde;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void	ZombieHorde::announce()
{
	for (int i = 0; i < this->_zombies_number; i++)
	{
		(this->_horde[i]).announce();
	}
}
