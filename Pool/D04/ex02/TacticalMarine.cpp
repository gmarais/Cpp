// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TacticalMarine.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 07:10:24 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 07:10:24 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TacticalMarine.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
TacticalMarine::TacticalMarine()
{
}

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
	*this = src;
}


TacticalMarine::~TacticalMarine()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
TacticalMarine &	TacticalMarine::operator=(TacticalMarine const & rhs)
{
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
