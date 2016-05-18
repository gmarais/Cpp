// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Player.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 05:26:28 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _A_Player_CLASS_
#define _A_Player_CLASS_

# include <iostream>

# include "A_Projectile.hpp"
# include "A_Squad.hpp"
# include "A_Ship.hpp"

class	A_Player : public A_Ship
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
//	virtual	void	smartBomb(void) const;

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	A_Player();
	A_Player(std::string name, int life, A_Projectile *projectile, A_Squad *squad,
			 v2 weapon, int shcolor, float fire_rate, int height, int width,
			 t_rows *rows, int bucolor, v2 position, float speed);
	A_Player(A_Player const & src);
	virtual ~A_Player();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	A_Player &	operator=(A_Player const & rhs);

};

#endif
