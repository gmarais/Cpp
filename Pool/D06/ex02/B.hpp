// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   B.hpp                                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 05:47:03 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 05:47:03 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _B_CLASS_
# define _B_CLASS_

# include <iostream>
# include "Base.hpp"

class	B : public Base
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
	B();
	B(B const & src);
	~B();
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	B &	operator=(B const & rhs);

};

#endif
