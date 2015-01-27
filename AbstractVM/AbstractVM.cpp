// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AbstractVM.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:44:03 by gmarais           #+#    #+#             //
//   Updated: 2015/01/27 16:44:03 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AbstractVM.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
AbstractVM::AbstractVM()
{
}

AbstractVM::AbstractVM(AbstractVM const & src)
{
	*this = src;
}


AbstractVM::~AbstractVM()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
//-----------------------------------------------------------------/ FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
AbstractVM &	AbstractVM::operator=(AbstractVM const & rhs)
{
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
