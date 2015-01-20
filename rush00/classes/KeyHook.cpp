// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   KeyHook.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 14:43:44 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 00:06:21 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "KeyHook.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
KeyHook::KeyHook()
{
}

KeyHook::KeyHook(A_Player *player, ScreenDisplay *screen) :
	_player(player),
	_screen(screen)
{
}

KeyHook::KeyHook(KeyHook const & src)
{
	(void)src;
	*this = src;
}


KeyHook::~KeyHook()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /

//-----------------------------------------------------------------/ FUNCTIONS /
bool		KeyHook::checkVerticalArrowKey(int	keycode)
{
	if (keycode == KEY_DOWN)
	{
		this->_player->setDir(0, 1);
		return true;
	}
	else if (keycode == KEY_UP)
	{
		this->_player->setDir(0, -1);
		return true;
	}
	return false;
}

bool		KeyHook::checkHorizontalArrowKey(int	keycode)
{
	if (keycode == KEY_LEFT)
	{
		this->_player->setDir(-1, 0);
		return true;
	}
	else if (keycode == KEY_RIGHT)
	{
		this->_player->setDir(1, 0);
		return true;
	}
	return false;
}

void		KeyHook::resolveKey()
{
	int		keycode = getch();

	if (!checkVerticalArrowKey(keycode) && !checkHorizontalArrowKey(keycode))
		(void)keycode;
	if (keycode == '\n')
	{
		this->_player->takeDamage(100);
	}
//	if (keycode == 'b')
//		this->_player->smartBomb();
}

//-----------------------------------------------------------------/ OPERATORS /
KeyHook &	KeyHook::operator=(KeyHook const & rhs)
{
	(void)rhs;
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
