// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 00:52:24 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 00:52:24 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <fstream>
#include <string>
#include "replaceAll.cpp"

int		main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string		filename = av[1];
		std::string		fileoutput = av[1];
		std::string		s1 = av[2];
		std::string		s2 = av[3];
		std::ifstream	infile;
		std::ofstream	outfile((char *)(fileoutput.append(".replace")).c_str());
		std::string 	line;

		infile.open((char *)filename.c_str());
		if (infile.fail())
		{
			std::cerr << "Error opening file." << std::endl;
			return 1;
		}
		while (!infile.eof())
		{
			std::getline(infile, line);
			outfile << replaceAll(line, s1, s2) << std::endl;
		}
	}
	else
	{
		std::cout << "Usage : " << av[0] << " filename s1 s2" << std::endl;
	}
}
