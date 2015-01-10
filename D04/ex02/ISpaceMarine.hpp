// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISpaceMarine.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 07:44:31 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 07:44:31 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _ISpaceMarine_CLASS_
#define _ISpaceMarine_CLASS_

#include <iostream>

class	ISpaceMarine
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	ISpaceMarine();
	ISpaceMarine(ISpaceMarine const & src);
	~ISpaceMarine();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	ISpaceMarine &	operator=(ISpaceMarine const & rhs);

};

#endif
