// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 05:47:05 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 05:47:05 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	identify_from_reference(Base & p)
{
	try
	{
		A & cast_A = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)cast_A;
	}
	catch (const std::exception &e)
	{
		try
		{
			B & cast_B = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
			(void)cast_B;
		}
		catch (const std::exception &e)
		{
			try
			{
				C & cast_C = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
				(void)cast_C;
			}
			catch (const std::exception &e)
			{
			}
		}
	}
}

void	identify_from_pointer(Base * p)
{
	A	*cast_A = dynamic_cast<A*>(p);
	B	*cast_B = dynamic_cast<B*>(p);
	C	*cast_C = dynamic_cast<C*>(p);

	if (cast_A)
		std::cout << "A" << std::endl;
	if (cast_B)
		std::cout << "B" << std::endl;
	if (cast_C)
		std::cout << "C" << std::endl;
}

Base * generate(void)
{
	int		choice;

	std::srand(std::time(NULL));
	choice = std::rand() % 3;
	if (!choice)
		return new A();
	else if (choice == 1)
		return new B();
	else
		return new C();
}

int		main()
{
	Base *child = generate();
	identify_from_pointer(child);
	identify_from_reference(*child);
	return 0;
}
