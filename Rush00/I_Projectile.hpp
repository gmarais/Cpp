// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Projectile.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 21:38:04 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 21:38:04 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Projectile_CLASS_
#define _I_Projectile_CLASS_

#include <iostream>

struct Projectile
{
	int		x;
	int		y;
	int		speed;		// If we can use usleep this is enough else we will need to relay on
	int		curr_loop	// processor speed and use a second variable: curr_loop
};

class	I_Projectile
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Projectile();
	I_Projectile(I_Projectile const & src);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual ~I_Projectile();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	I_Projectile &	operator=(I_Projectile const & rhs);

};

#endif
