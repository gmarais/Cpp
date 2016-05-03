// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Float.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Float_CLASS_
# define _Float_CLASS_

# include <stdint.h>
# include "eOperandType.hpp"
# include "TOperand.hpp"

class	Float : public TOperand<float>
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
	Float( void );
	Float( double n );
	Float( Float const & src );
	virtual ~Float( void );
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual IOperand const *CreateNew(double const value) const;
//-----------------------------------------------------------------/ OPERATORS /
	Float &	operator=( Float const & rhs );
};

#endif
