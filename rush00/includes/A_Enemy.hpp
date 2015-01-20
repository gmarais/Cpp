// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Enemy.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 20:56:04 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _A_Enemy_CLASS_
#define _A_Enemy_CLASS_

#include <iostream>
#include "A_Ship.hpp"
#include "A_Movable.hpp"

class	A_Enemy : public A_Ship
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
	A_Enemy();
	A_Enemy(A_Enemy const & src);
	~A_Enemy();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual	void	play(void) = 0;
	void			basicIA();

//-----------------------------------------------------------------/ OPERATORS /
	A_Enemy &	operator=(A_Enemy const & rhs);

};

#endif
