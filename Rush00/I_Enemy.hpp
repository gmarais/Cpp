// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Enemy.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 21:16:25 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 21:16:25 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Enemy_CLASS_
#define _I_Enemy_CLASS_

#include <iostream>

class	I_Enemy
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Enemy();
	I_Enemy(I_Enemy const & src);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual ~I_Enemy();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	I_Enemy &	operator=(I_Enemy const & rhs);

};

#endif
