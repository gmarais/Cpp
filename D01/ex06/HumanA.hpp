// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   HumanA.hpp	                                        :+:      :+:    :+:   //
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

#ifndef _HUMAN_A_
#define _HUMAN_A_

class HumanA
{
	public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void	attack();

//----------------------------------------------------------/ PUBLIC VARIABLES /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	
	private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string	_name;
	Weapon&		_weapon;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

};

#endif
