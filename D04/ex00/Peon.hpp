// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Peon.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 00:22:33 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 02:11:41 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Peon_CLASS_
#define _Peon_CLASS_

#include <iostream>
#include "Victim.hpp"

class	Peon : public Victim
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	Peon();

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Peon(std::string name);
	Peon(Peon const & src);
	~Peon();
//-----------------------------------------------------------------/ OPERATORS /
	Peon &	operator=(Peon const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	void	getPolymorphed() const;

};

#endif
