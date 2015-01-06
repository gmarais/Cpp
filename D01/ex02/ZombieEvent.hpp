// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ZombieEvent.hpp	                                :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 15:03:48 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 15:03:48 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Zombie.cpp"

#ifndef _ZOMBIE_EVENT_
#define _ZOMBIE_EVENT_

class ZombieEvent
{
	public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	ZombieEvent();
	~ZombieEvent();
	void	setZombieType(std::string type);
	Zombie*	newZombie(std::string name);
	void	randomChump();

	private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string			_zombie_type;
	static std::string	_consonants;
	static std::string	_vowels;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	std::string	_randomNameGenerator();

};

#endif
