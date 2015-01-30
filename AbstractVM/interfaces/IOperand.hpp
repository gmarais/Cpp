// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   IOperand.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/29 15:43:19 by gmarais           #+#    #+#             //
//   Updated: 2015/01/29 15:43:19 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _IOperand_CLASS_
# define _IOperand_CLASS_

class IOperand
{
public:
//---------------------------------------------------------/ GETTERS & SETTERS /
	virtual int					getPrecision( void ) const = 0; // Precision of the type of the instance
	virtual eOperandType		getType( void ) const = 0; // Type of the instance
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual std::string const &	toString( void ) const = 0; // String representation of the instance
	virtual						~IOperand( void ) {}
//-----------------------------------------------------------------/ OPERATORS /
	virtual IOperand const *	operator+( IOperand const & rhs ) const = 0; // Sum
	virtual IOperand const *	operator-( IOperand const & rhs ) const = 0; // Difference
	virtual IOperand const *	operator*( IOperand const & rhs ) const = 0; // Product
	virtual IOperand const *	operator/( IOperand const & rhs ) const = 0; // Quotient
	virtual IOperand const *	operator%( IOperand const & rhs ) const = 0; // Modulo
};

#endif
