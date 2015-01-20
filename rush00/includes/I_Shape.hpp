// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Shape.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 01:56:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 05:37:17 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Shape_CLASS_
# define _I_Shape_CLASS_

# include <iostream>

# include "A_Printable.hpp"
# include "Tools.hpp"

class	I_Shape : public A_Printable
{

private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Shape(void);
	I_Shape(I_Shape const & src);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	virtual ~I_Shape(void);


//-------------------------------------------------------------------/ GETTERS /



//----------------------------------------------------------/ PUBLIC FUNCTIONS /



//-----------------------------------------------------------------/ OPERATORS /
	I_Shape &	operator=(I_Shape const & rhs);

};

#endif
