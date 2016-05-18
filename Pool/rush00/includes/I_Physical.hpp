// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Physical.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 01:56:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 17:16:44 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Physical_CLASS_
#define _I_Physical_CLASS_

#include <iostream>
#include "A_Shape.hpp"
#include "Tools.hpp"

class	I_Physical : public A_Shape
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Physical();
	I_Physical(I_Physical const & src);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual ~I_Physical();


//----------------------------------------------------------/ PUBLIC FUNCTIONS /

	virtual bool	collide(v2 *pos) const = 0;
	virtual bool	collide(A_Shape &shape) const = 0;

//-----------------------------------------------------------------/ OPERATORS /
	I_Physical &	operator=(I_Physical const & rhs);

};

#endif
