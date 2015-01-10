// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Sorcerer.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 00:22:19 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 02:29:37 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Sorcerer_CLASS_
#define _Sorcerer_CLASS_

#include <iostream>
#include "Victim.hpp"

class	Sorcerer
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string	_name;
	std::string	_title;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	Sorcerer();

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const & src);
	~Sorcerer();
//-----------------------------------------------------------------/ OPERATORS /
	Sorcerer &	operator=(Sorcerer const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	std::string	getName() const;
	std::string	getTitle() const;
	void		polymorph(Victim const & v);

};

std::ostream &	operator<<(std::ostream & os, Sorcerer & s);

#endif
