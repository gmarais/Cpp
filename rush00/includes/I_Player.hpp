// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Player.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 01:56:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 17:19:42 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Player_CLASS_
# define _I_Player_CLASS_

# include <iostream>
# include "A_Ship.hpp"

class	I_Player : public A_Ship
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

	virtual	void	smartBomb(void) const = 0;

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Player();
	I_Player(I_Player const & src);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual ~I_Player();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /

	virtual	int		play() = 0;

//-----------------------------------------------------------------/ OPERATORS /
	I_Player &	operator=(I_Player const & rhs);

};

#endif
