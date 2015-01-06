// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Brain.cpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 19:07:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 19:07:11 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <sstream>
#include "Brain.hpp"

//-----------------------------------------------------/ STATIC VARIABLES INIT /

//------------------------------------------------------/ CONSTRUCT / DESTRUCT /
	Brain::Brain()
	{
	}

	Brain::~Brain()
	{
	}

//-----------------------------------------------------------------/ FUNCTIONS /
	std::string	Brain::identify() const
	{
		std::stringstream  ss;
		ss << (void *)this;
		return ss.str();
	}
