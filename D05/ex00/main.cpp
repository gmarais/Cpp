// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/12 22:12:01 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 22:12:01 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Bureaucrat.hpp"

int		main()
{

	std::cout << "trying to do: " << "Bureaucrat Zoe(\"Zoe\", 0);" << std::endl;
	try
	{
		Bureaucrat Zoe("Zoe", 0);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl;
	}
	std::cout << "trying to do: " << "Bureaucrat Bob(\"bob\", 160);" << std::endl;
	try
	{
		Bureaucrat Bob("bob", 160);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception catched : " << e.what() << std::endl;
	}
	std::cout << "Creating a bureaucrat named Jojo with a grade of 3" << std::endl;
	Bureaucrat jojo("Jojo", 3);
	std::cout << "incrementing the grade 3 times" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		try
		{
			jojo.incrGrade();
			std::cout << jojo << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "Exception catched : " << e.what() << std::endl;
		}
	}
	std::cout << "Creating a bureaucrat named Polo with a grade of 148" << std::endl;
	Bureaucrat polo("Polo", 148);
	std::cout << "Decrementing the grade 3 times" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		try
		{
			polo.decrGrade();
			std::cout << polo << std::endl;
		}
		catch (std::exception & e)
		{
			std::cout << "Exception catched : " << e.what() << std::endl;
		}
	}
	return 0;
}
