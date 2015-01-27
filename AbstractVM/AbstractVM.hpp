// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AbstractVM.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:44:03 by gmarais           #+#    #+#             //
//   Updated: 2015/01/27 16:44:03 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _AbstractVM_CLASS_
# define _AbstractVM_CLASS_

# include <iostream>

class	AbstractVM
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
	AbstractVM();
	AbstractVM(AbstractVM const & src);
	~AbstractVM();
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	AbstractVM &	operator=(AbstractVM const & rhs);

};

#endif
