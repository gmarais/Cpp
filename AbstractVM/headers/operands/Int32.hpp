// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int32.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Int32_CLASS_
# define _Int32_CLASS_

# include <stdint.h>
# include "eOperandType.hpp"
# include "TOperand.hpp"

class	Int32 : public TOperand<int32_t>
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
	Int32( void );
	Int32( double n );
	Int32( Int32 const & src );
	virtual ~Int32( void );
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	Int32 &	operator=( Int32 const & rhs );
};

#endif
