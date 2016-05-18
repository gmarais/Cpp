// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 13:59:04 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 13:59:04 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>

#ifndef _ZOMBIE_
#define _ZOMBIE_

class Zombie
{
	public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	Zombie(std::string name, std::string type);
	~Zombie();
	void announce();

	private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string _name;
	std::string _type;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

};

#endif
