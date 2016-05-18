// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AssaultTerminator.cpp                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 07:10:24 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 07:10:24 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AssaultTerminator.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
AssaultTerminator::AssaultTerminator()
{
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	*this = src;
}


AssaultTerminator::~AssaultTerminator()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
AssaultTerminator &	AssaultTerminator::operator=(AssaultTerminator const & rhs)
{
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
