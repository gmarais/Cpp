// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Projectile.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:12 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 22:52:09 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _A_Projectile_CLASS_
# define _A_Projectile_CLASS_

# include <iostream>

# include "Tools.hpp"
# include "A_Physical.hpp"
# include "A_Movable.hpp"

class	A_Projectile : public A_Physical, public A_Movable
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string	_name;
	int			_damage;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	A_Projectile();
	A_Projectile(std::string name, int damage, int height, int width, t_rows *rows, int color, v2 position, int speed);
	A_Projectile(A_Projectile const & src);
	~A_Projectile();
//---------------------------------------------------------/ GETTERS / SETTERS /
	virtual const std::string	&getName(void) const;
	virtual int			getDamage(void) const;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	A_Projectile &	operator=(A_Projectile const & rhs);

};

#endif
