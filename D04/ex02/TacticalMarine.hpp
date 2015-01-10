// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TacticalMarine.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 06:10:43 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 06:10:43 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _TacticalMarine_CLASS_
#define _TacticalMarine_CLASS_

#include <iostream>

class	TacticalMarine
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
	TacticalMarine();
	TacticalMarine(TacticalMarine const & src);
	~TacticalMarine();
//-----------------------------------------------------------------/ OPERATORS /
	TacticalMarine &	operator=(TacticalMarine const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /

};

#endif
