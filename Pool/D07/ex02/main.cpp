// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 12:45:58 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 16:43:48 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <exception>
#include "Array.hpp"
#include "Array.cpp"

int		main()
{
	Array<std::string>	bob(static_cast<unsigned int>(5));

	bob[0] = "Ceci est une ligne";
	bob[1] = "Ceci est une deuxieme ligne";
	bob[2] = "Ceci egalement";
	bob[3] = "voila ta compris";
	bob[4] = "gg";

	try
	{
		for (unsigned int i = 0; i < bob.size(); i++)
		{
			std::cout << bob[i] << std::endl;
		}
		std::cout << bob[42] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception is thrown and catched!" << std::endl;
	}
	return 0;
}
