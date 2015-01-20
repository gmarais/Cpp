// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Movable.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 01:56:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 17:32:51 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Movable_CLASS_
# define _I_Movable_CLASS_

# include <iostream>

class	I_Movable
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Movable();
	I_Movable(I_Movable const & src);

public:

//---------------------------------------------------------/ GETTERS / SETTERS /
	virtual void	setDir(int x, int y) = 0;
	virtual void	setSpeed(float speed) = 0;

//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual ~I_Movable();

//----------------------------------------------------------/ PUBLIC FUNCTIONS /

	virtual	void	move(void) = 0;

//-----------------------------------------------------------------/ OPERATORS /
	I_Movable &	operator=(I_Movable const & rhs);

};

#endif
