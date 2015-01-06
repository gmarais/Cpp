// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanB.hpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 23:17:33 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 23:17:33 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#ifndef _WEAPON_
	#include "Weapon.cpp"
#endif

#ifndef _HUMAN_B_
#define _HUMAN_B_

class HumanB
{
	public:
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon& weapon);

//----------------------------------------------------------/ PUBLIC VARIABLES /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	
	private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string	_name;
	Weapon		*_weapon;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

};

#endif
