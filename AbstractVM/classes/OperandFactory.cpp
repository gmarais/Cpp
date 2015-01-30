// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OperandFactory.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/29 15:59:03 by gmarais           #+#    #+#             //
//   Updated: 2015/01/29 15:59:03 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OperandFactory.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
OperandFactory::OperandFactory()
{
}

OperandFactory::OperandFactory(OperandFactory const & src)
{
	*this = src;
}


OperandFactory::~OperandFactory()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
OperandFactory &	OperandFactory::operator=(OperandFactory const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
