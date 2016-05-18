// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:36:28 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 02:47:58 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int		main()
{
	Sorcerer ganfald("Ganfald", "leudislaiksik");
	Peon bob("bob");
	Peon johan("johan");
	Victim luc("luc");
	Victim loic("loic");

	bob = johan;
	loic = luc;
	std::cout << luc << std::endl;
	std::cout << loic << std::endl;
	std::cout << bob << std::endl;
	std::cout << johan << std::endl;
	ganfald.polymorph(bob);
	ganfald.polymorph(johan);
	ganfald.polymorph(luc);

	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);


	return 0;
}
