// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Pony.hpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 11:29:16 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 11:29:16 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>

#ifndef _PONY_
#define _PONY_

class Pony
{
	public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	Pony(std::string pony_name);
	~Pony();
	void		run();
	static int	getNumberOfPonies();

	private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	static int	_number_of_ponies;
	std::string	_pony_name;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
};

#endif
