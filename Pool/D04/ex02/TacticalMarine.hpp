// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TacticalMarine.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 07:10:24 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 07:10:24 by gmarais          ###   ########.fr       //
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
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	TacticalMarine &	operator=(TacticalMarine const & rhs);

};

#endif
