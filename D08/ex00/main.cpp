// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 11:09:41 by gmarais           #+#    #+#             //
//   Updated: 2015/01/15 11:09:41 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <list>
#include "easyfind.hpp"

int		main()
{
	std::list<int>	lst;
	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);

	
	std::cout << "Searching 2 in list: 0 1 2 3 4" << std::endl;
	if (easyfind(lst, 2))
		std::cout << "Value found!" << std::endl;
	else
		std::cout << "catched error (value not found)" << std::endl;
	std::cout << "Searching 5 in list: 0 1 2 3 4" << std::endl;
	if (easyfind(lst, 5))
		std::cout << "Value  found" << std::endl;
	else
		std::cout << "catched error (value not found)" << std::endl;
	return 0;
}
