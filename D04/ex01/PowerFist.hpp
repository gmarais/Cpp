// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   PowerFist.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:36:38 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _PowerFist_CLASS_
#define _PowerFist_CLASS_

#include <iostream>
#include "AWeapon.hpp"

class	PowerFist : public AWeapon
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
	PowerFist();
	PowerFist(PowerFist const & src);
	~PowerFist();
//-----------------------------------------------------------------/ OPERATORS /
	PowerFist &	operator=(PowerFist const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual void	attack() const;

};

#endif
