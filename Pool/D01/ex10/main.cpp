// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 06:54:48 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 06:54:48 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <fstream>
#include <string>

int 	main(int ac, char **av)
{
	std::string		line;

	if (ac != 1)
	{
		for (int i=1; i < ac; i++)
		{
			std::ifstream	infile;

			infile.open(av[i]);
			if (infile.fail())
			{
				std::cerr << "Error opening file." << std::endl;
				return 1;
			}
			while (!infile.eof())
			{
				std::getline(infile, line);
				if (!infile.eof())
					std::cout << line << std::endl;
				else
					std::cout << line;
			}

		}
	}
	else
	{
		while (1)
		{
			std::cin >> line;
			std::cout << line << std::endl;
		}
	}
	return 0;
}
