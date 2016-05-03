// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Double.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 20:07:08 by gmarais           #+#    #+#             //
//   Updated: 2016/04/26 20:07:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Double_CLASS_
# define _Double_CLASS_

# include <stdint.h>
# include "eOperandType.hpp"
# include "TOperand.hpp"

class	Double : public TOperand<double>
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
	Double( void );
	Double( double n );
	Double( Double const & src );
	virtual ~Double( void );
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	Double &	operator=( Double const & rhs );
};

#endif
