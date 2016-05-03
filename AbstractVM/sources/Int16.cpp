// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int16.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Int16.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Int16::Int16() : TOperand<int16_t>(INT16, 0, -32768, 32767, static_cast<int>(INT16))
{
}

Int16::Int16(double n) : TOperand<int16_t>(INT16, n, -32768, 32767, static_cast<int>(INT16))
{
}

Int16::Int16(Int16 const & src) : TOperand<int16_t>( src )
{
	*this = src;
}


Int16::~Int16()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
IOperand const *Int16::CreateNew(double const value) const
{
	return new Int16(value);
}

//-----------------------------------------------------------------/ OPERATORS /
Int16 &	Int16::operator=(Int16 const & rhs)
{
	TOperand::operator=(rhs);
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
