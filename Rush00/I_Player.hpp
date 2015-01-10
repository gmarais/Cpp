// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Player.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 21:16:25 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 21:16:25 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// CONCEPT 4 * 3
//    /\-   -   -   -   x|
//   (- D                |
//    \/-   -   -   -   x|

#ifndef _I_Player_CLASS_
#define _I_Player_CLASS_

#include <iostream>

class	I_Player
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Player();
	I_Player(I_Player const & src);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual ~I_Player();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	I_Player &	operator=(I_Player const & rhs);

};

#endif
