// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int16.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Int16_CLASS_
# define _Int16_CLASS_

# include <stdint.h>
# include "eOperandType.hpp"
# include "TOperand.hpp"

class	Int16 : public TOperand<int16_t>
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Int16( void );
	Int16( double n );
	Int16( Int16 const & src );
	virtual ~Int16( void );
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual IOperand const *CreateNew(double const value) const;
//-----------------------------------------------------------------/ OPERATORS /
	Int16 &	operator=( Int16 const & rhs );
};

#endif
