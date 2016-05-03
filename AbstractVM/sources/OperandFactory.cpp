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
IOperand const *	OperandFactory::createInt8( std::string const & value ) const
{
	return new Int8(ft_atod(value));
}

IOperand const *	OperandFactory::createInt16( std::string const & value ) const
{
	return new Int16(ft_atod(value));
}

IOperand const *	OperandFactory::createInt32( std::string const & value ) const
{
	return new Int32(ft_atod(value));
}

IOperand const *	OperandFactory::createFloat( std::string const & value ) const
{
	return new Float(ft_atod(value));
}

IOperand const *	OperandFactory::createDouble( std::string const & value ) const
{
	return new Double(ft_atod(value));
}

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
	switch (type)
	{
		case INT8:
			return (this->createInt8(value));
		case INT16:
			return (this->createInt16(value));
		case INT32:
			return (this->createInt32(value));
		case FLOAT:
			return (this->createFloat(value));
		case DOUBLE:
			return (this->createDouble(value));
	}
	return NULL;
}

//-----------------------------------------------------------------/ OPERATORS /
OperandFactory &	OperandFactory::operator=(OperandFactory const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
