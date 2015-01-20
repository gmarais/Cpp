// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Movable.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:12 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 21:20:31 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _A_Movable_CLASS_
# define _A_Movable_CLASS_

# include <iostream>
# include <ncurses.h>

# include "Tools.hpp"
# include "A_Physical.hpp"

class	A_Movable
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /

	v2		_dir;
	float		_speed;
	int		_last_move;
	A_Physical	*_physical;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
	bool	_moved;
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//---------------------------------------------------------/ GETTERS / SETTERS /
	virtual const v2	&getDir(void) const;
	virtual float  	getSpeed(void) const;
	virtual void	setDir(int x, int y);
	virtual void	setSpeed(float speed);

//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	A_Movable();
	A_Movable(float speed, A_Physical *physical);
	A_Movable(A_Movable const & src);
	~A_Movable();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual	void	move(void);
//-----------------------------------------------------------------/ OPERATORS /
	A_Movable &	operator=(A_Movable const & rhs);

};

#endif
