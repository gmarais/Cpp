// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.cpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 19:08:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 19:08:10 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Human.hpp"

//-----------------------------------------------------/ STATIC VARIABLES INIT /

//------------------------------------------------------/ CONSTRUCT / DESTRUCT /
	Human::Human()
	{
	}

	Human::~Human()
	{
	}

//-----------------------------------------------------------------/ FUNCTIONS /
	const Brain&		Human::getBrain()
	{
		const Brain& brainref = this->_brain;
		return brainref;
	}

	std::string	Human::identify() const
	{
		return this->_brain.identify();
	}
