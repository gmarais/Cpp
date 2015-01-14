// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 12:45:58 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 14:17:04 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Array.hpp"
#include "Array.cpp"

int		main()
{
	Array<std::string>	bob(static_cast<unsigned int>(5));

	bob[0] = "CACACAACACA";
	bob[1] = "je pense";
	bob[2] = "que";
	bob[3] = "ca va";
	bob[4] = "PETER LEL";
	for (unsigned int i = 0; i < bob.size(); i++)
	{
		std::cout << bob[i] << std::endl;
	}
	return 0;
}
