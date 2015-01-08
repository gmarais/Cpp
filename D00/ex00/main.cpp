// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/05 14:08:47 by gmarais           #+#    #+#             //
//   Updated: 2015/01/05 14:12:24 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "ft_strtoupper.cpp"

int main(int ac, char *av[])
{
	if (ac <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i=1; av[i]; i++)
		{
			std::cout << ft_strtoupper(av[i]);
		}
		std::cout << std::endl;
	}
	return 0;
}
