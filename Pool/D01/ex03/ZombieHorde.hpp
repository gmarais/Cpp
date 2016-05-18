// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieHorde.hpp	                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 16:51:07 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 16:51:07 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Zombie.cpp"

#ifndef _CLASSNAME_
#define _CLASSNAME_

class ZombieHorde
{
	public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	ZombieHorde(int N);
	~ZombieHorde();
	void	announce();

	private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	Zombie			*_horde;
	int const		_zombies_number;

//---------------------------------------------------------/ PRIVATE FUNCTIONS /

};

#endif
