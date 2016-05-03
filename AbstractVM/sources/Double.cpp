// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Double.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Double.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
Double::Double() : TOperand<double>(DOUBLE, 0, -2147483648, 2147483647, static_cast<int>(DOUBLE))
{
}

Double::Double(double n) : TOperand<double>(DOUBLE, n, -2147483648, 2147483647, static_cast<int>(DOUBLE))
{
}

Double::Double(Double const & src) : TOperand<double>( src )
{
	*this = src;
}


Double::~Double()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
IOperand const *Double::CreateNew(double const value) const
{
	return new Double(value);
}

//-----------------------------------------------------------------/ OPERATORS /
Double &	Double::operator=(Double const & rhs)
{
	TOperand::operator=(rhs);
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
