// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Float.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Float.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Float::Float() : TOperand<float>(FLOAT, 0, -32768, 32767, static_cast<int>(FLOAT))
{
}

Float::Float(double n) : TOperand<float>(FLOAT, n, -32768, 32767, static_cast<int>(FLOAT))
{
}

Float::Float(Float const & src) : TOperand<float>( src )
{
	*this = src;
}


Float::~Float()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
IOperand const *Float::CreateNew(double const value) const
{
	return new Float(value);
}

//-----------------------------------------------------------------/ OPERATORS /
Float &	Float::operator=(Float const & rhs)
{
	TOperand::operator=(rhs);
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
