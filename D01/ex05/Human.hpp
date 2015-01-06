// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Human.hpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 19:07:54 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 19:07:54 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Brain.cpp"

#ifndef _HUMAN_
#define _HUMAN_

class Human
{
	public:
//----------------------------------------------------------/ PUBLIC VARIABLES /

//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	Human();
	~Human();
	std::string	identify() const;
	const Brain& getBrain();

	private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	Brain const _brain;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

};

#endif
