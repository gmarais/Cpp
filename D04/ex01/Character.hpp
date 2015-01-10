// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:20:32 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Character_CLASS_
#define _Character_CLASS_

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class	Character
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string	_name;
	int			_ap;
	AWeapon		*_weapon;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Character(std::string const & name);
	Character();
	Character(Character const & src);
	~Character();
//-----------------------------------------------------------------/ OPERATORS /
	Character &	operator=(Character const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	std::string const &	getName() const;
	int					getAP() const;
	AWeapon				*getWeapon() const;
	void				recoverAP();
	void				equip(AWeapon*);
	void				attack(Enemy*);

};

std::ostream &	operator<<(std::ostream & os, Character & s);

#endif
