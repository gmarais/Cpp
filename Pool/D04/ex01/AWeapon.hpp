// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AWeapon.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:05:56 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _AWeapon_CLASS_
#define _AWeapon_CLASS_

#include <iostream>

class	AWeapon
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string	_name;
	int			_apcost;
	int			_damage;

//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	AWeapon();

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	AWeapon(std::string const & name, int apcost, int damage);
	AWeapon(AWeapon const & src);
	~AWeapon();
//-----------------------------------------------------------------/ OPERATORS /
	AWeapon &	operator=(AWeapon const & rhs);
//-------------------------------------------------------------------/ GETTERS /
	std::string const &	getName() const;
	int					getAPCost() const;
	int					getDamage() const;

//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual void	attack() const = 0;

};

#endif
