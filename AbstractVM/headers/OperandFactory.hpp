// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OperandFactory.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/29 15:59:03 by gmarais           #+#    #+#             //
//   Updated: 2015/01/29 15:59:03 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _OperandFactory_CLASS_
# define _OperandFactory_CLASS_

# include <iostream>
# include "Tools.hpp"
# include "IOperand.hpp"
# include "eOperandType.hpp"
# include "Int8.hpp"
# include "Int16.hpp"
# include "Int32.hpp"
# include "Float.hpp"
# include "Double.hpp"

class	OperandFactory
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	IOperand const *	createInt8( std::string const & value ) const;
	IOperand const *	createInt16( std::string const & value ) const;
	IOperand const *	createInt32( std::string const & value ) const;
	IOperand const *	createFloat( std::string const & value ) const;
	IOperand const *	createDouble( std::string const & value ) const;

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	OperandFactory();
	OperandFactory(OperandFactory const & src);
	virtual ~OperandFactory();
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
//-----------------------------------------------------------------/ OPERATORS /
	OperandFactory &	operator=(OperandFactory const & rhs);

};

#endif
