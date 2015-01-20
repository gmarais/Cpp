// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Enemy.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 01:56:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 16:53:08 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Enemy_CLASS_
#define _I_Enemy_CLASS_

#include <iostream>
#include "A_Ship.hpp"

class	I_Enemy : public A_Ship
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Enemy();
	I_Enemy(I_Enemy const & src);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual 		~I_Enemy();
	virtual	void	play(void) = 0;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	I_Enemy &	operator=(I_Enemy const & rhs);

};

#endif
