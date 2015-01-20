// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   KeyHook.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 14:43:44 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 17:06:37 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _KeyHook_CLASS_
# define _KeyHook_CLASS_

# include <iostream>
# include "A_Player.hpp"
# include "ScreenDisplay.hpp"

class	KeyHook
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	A_Player		*_player;
	ScreenDisplay	*_screen;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	KeyHook();
	KeyHook(KeyHook const & src);
	KeyHook &	operator=(KeyHook const & rhs);

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	KeyHook(A_Player *player, ScreenDisplay* screen);
	~KeyHook();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	A_Player		*getPlayer() const;
	ScreenDisplay	*getScreen() const;
	bool			checkHorizontalArrowKey(int	keycode);
	bool			checkVerticalArrowKey(int keycode);
	void			resolveKey();
//-----------------------------------------------------------------/ OPERATORS /

};

#endif
