// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Marine.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: exam <marvin@42.fr>                        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 22:51:13 by exam              #+#    #+#             //
//   Updated: 2015/01/09 23:02:59 by exam             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#ifndef _MARINE_CLASS_HPP_
#define _MARINE_CLASS_HPP_
#include <iostream>
#include <string>
#include "Unit.class.hpp"

class Marine : public Unit
{
private:
//----------------------------------------------------------/ PRIVATE VARIABLES/
	int		_armor;
//----------------------------------------------------------/ PRIVATE FUNCTIONS/
protected:
//--------------------------------------------------------/ PROTECTED VARIABLES/
//--------------------------------------------------------/ PROTECTED FUNCTIONS/
public:
//-----------------------------------------------------------/ PUBLIC VARIABLES/
//-----------------------------------------------------/ CONSTRUCTS & DESTRUCTS/
	Marine();
	Marine(int x, int y);
	Marine(Marine & src);
	~Marine();
//------------------------------------------------------------------/ OPERATORS/
	Marine &			operator=(const Marine & src);
//--------------------------------------------------------------------/ GETTERS/
//-----------------------------------------------------------/ PUBLIC FUNCTIONS/
	void stimpack( void );
	void die();
	void move(int x, int y);
};

#endif
