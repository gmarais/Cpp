// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISpaceMarine.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 06:51:42 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 06:51:42 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _ISpaceMarine_CLASS_
#define _ISpaceMarine_CLASS_

#include <iostream>

class	ISpaceMarine
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
	ISpaceMarine();
	ISpaceMarine(ISpaceMarine const & src);
	~ISpaceMarine();
//-----------------------------------------------------------------/ OPERATORS /
	ISpaceMarine &	operator=(ISpaceMarine const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /

};

#endif
