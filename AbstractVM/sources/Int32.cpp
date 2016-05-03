// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int32.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Int32.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Int32::Int32() : TOperand<int32_t>(INT32, 0, -2147483648, 2147483647, static_cast<int>(INT32))
{
}

Int32::Int32(double n) : TOperand<int32_t>(INT32, n, -2147483648, 2147483647, static_cast<int>(INT32))
{
}

Int32::Int32(Int32 const & src) : TOperand<int32_t>( src )
{
	*this = src;
}


Int32::~Int32()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
IOperand const *Int32::CreateNew(double const value) const
{
	return new Int32(value);
}

//-----------------------------------------------------------------/ OPERATORS /
Int32 &	Int32::operator=(Int32 const & rhs)
{
	TOperand::operator=(rhs);
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
