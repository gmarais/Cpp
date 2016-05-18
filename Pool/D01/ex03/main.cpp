// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 16:55:56 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 16:55:56 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "ZombieHorde.cpp"

int		main()
{
	std::cout << "ZombieHorde my_horde(5);" << std::endl;
	ZombieHorde my_horde(5);

	std::cout << "my_horde.announce();" << std::endl;
	my_horde.announce();
	std::cout << "End of the program ZombieHorde will be destroyed." << std::endl;
	return 1;
}
