// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssaultTerminator.hpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 06:10:43 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 06:10:43 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _AssaultTerminator_CLASS_
#define _AssaultTerminator_CLASS_

#include <iostream>

class	AssaultTerminator
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
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const & src);
	~AssaultTerminator();
//-----------------------------------------------------------------/ OPERATORS /
	AssaultTerminator &	operator=(AssaultTerminator const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /

};

#endif
