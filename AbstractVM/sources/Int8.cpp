// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int8.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Int8.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Int8::Int8() : TOperand<int8_t>(INT8, 0, -128, 127, static_cast<int>(INT8))
{
}

Int8::Int8(double n) : TOperand<int8_t>(INT8, n, -128, 127, static_cast<int>(INT8))
{
}

Int8::Int8(Int8 const & src) : TOperand<int8_t>( src )
{
	*this = src;
}


Int8::~Int8()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
IOperand const *Int8::CreateNew(double const value) const
{
	return new Int8(value);
}

//-----------------------------------------------------------------/ OPERATORS /
Int8 &	Int8::operator=(Int8 const & rhs)
{
	TOperand::operator=(rhs);
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
