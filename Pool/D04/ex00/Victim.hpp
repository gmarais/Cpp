// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Victim.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 00:22:27 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 02:29:13 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Victim_CLASS_
#define _Victim_CLASS_

#include <iostream>

class	Victim
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
	std::string	_name;
	std::string	_title;
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	Victim();

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Victim(std::string name);
	Victim(Victim const & src);
	virtual ~Victim();
//-----------------------------------------------------------------/ OPERATORS /
	Victim &		operator=(Victim const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	std::string		getName() const;
	virtual void	getPolymorphed() const;

};

std::ostream &	operator<<(std::ostream & os, Victim & v);

#endif
