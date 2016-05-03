// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int8.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Int8_CLASS_
# define _Int8_CLASS_

# include <stdint.h>
# include "eOperandType.hpp"
# include "TOperand.hpp"

class	Int8 : public TOperand<int8_t>
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	virtual IOperand const *CreateNew(double const value) const;

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Int8( void );
	Int8( double n );
	Int8( Int8 const & src );
	virtual ~Int8( void );
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	Int8 &	operator=( Int8 const & rhs );
};

#endif
