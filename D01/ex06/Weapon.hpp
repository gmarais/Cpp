// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Weapon.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 22:50:15 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 22:50:15 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>

#ifndef _WEAPON_
#define _WEAPON_

class Weapon
{
	public:
//----------------------------------------------------------/ PUBLIC VARIABLES /

//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	Weapon(std::string type);
	~Weapon();
	std::string const&	getType();
	void				setType(std::string type);

	private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string	_type;

//---------------------------------------------------------/ PRIVATE FUNCTIONS /

};

#endif
