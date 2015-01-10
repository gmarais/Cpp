// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PlasmaRifle.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:36:24 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _PlasmaRifle_CLASS_
#define _PlasmaRifle_CLASS_

#include <iostream>
#include "AWeapon.hpp"

class	PlasmaRifle : public AWeapon
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	PlasmaRifle();
	PlasmaRifle(PlasmaRifle const & src);
	~PlasmaRifle();
//-----------------------------------------------------------------/ OPERATORS /
	PlasmaRifle &	operator=(PlasmaRifle const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual void	attack() const;

};

#endif
