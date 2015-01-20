// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 19:04:02 by gmarais           #+#    #+#             //
//   Updated: 2015/01/16 08:34:49 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "span.hpp"

int		main()
{
	span	sp1(5);
	span	sp2(5);

	try
	{
		std::cout << "Filling the span:" << std::endl;
		sp1.addNumber(0);
		sp1.addNumber(1);
		sp1.addNumber(5);
		sp1.addNumber(4);
		sp1.addNumber(3);
		// this line shall throw an error :
		std::cout << "Now adding one more element than possible in the span:" << std::endl;
		sp1.addNumber(42);
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Catched exception: " << e.what() << std::endl;
	}
	try
	{
		std::cout << "Shortest: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp1.longestSpan() << std::endl;
		// this line shall throw an error :
		std::cout << "Longest: " << sp2.longestSpan() << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Catched exception: " << e.what() << std::endl;
	}
	return 0;
}
