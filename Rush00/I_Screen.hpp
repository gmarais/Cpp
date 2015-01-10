// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Screen.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 20:42:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 20:42:11 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Screen_CLASS_
#define _I_Screen_CLASS_

#include <iostream>

class	I_Screen
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Screen();
	I_Screen(I_Screen const & src);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual ~I_Screen();
//-------------------------------------------------------------------/ GETTERS /
	virtual int		getScreenWidth() const = 0;
	virtual int		getScreenHeight() const = 0;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual void	printCenter(std::string const & str, int height) = 0;
	virtual void	printStr(std::string const & str, int const x, int const y) = 0;
//-----------------------------------------------------------------/ OPERATORS /
	I_Screen &	operator=(I_Screen const & rhs);

};

#endif
