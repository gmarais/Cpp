// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Projectile.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 01:56:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 19:14:26 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Projectile_CLASS_
# define _I_Projectile_CLASS_

# include <iostream>


class	I_Projectile
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Projectile();
	I_Projectile(I_Projectile const & src);

//---------------------------------------------------------/ GETTERS / SETTERS /
	virtual std::string	&getName(void) const = 0;
	virtual int			getDamage(void) const = 0;

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual ~I_Projectile();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	I_Projectile &	operator=(I_Projectile const & rhs);

};

#endif
