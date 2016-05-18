// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 00:27:58 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 00:27:58 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "Pony.cpp"

void	ponyOnTheHeap()
{
	std::cout << "Pony	*my_pony = new Pony(\"Heapster\");" << std::endl;
	Pony	*my_pony = new Pony("Heapster");	
	std::cout << "Number of ponies : " << Pony::getNumberOfPonies() << std::endl;
	std::cout << "my_pony->run();" << std::endl;
	my_pony->run();
	std::cout << "End of function : delete has to be called..."
	<< std::endl
	<< "Otherwise Heapster would not be destroyed because he is on the heap"
	<< std::endl;
	delete my_pony;
}

void ponyOnTheStack()
{
	std::cout << "Pony	my_pony(\"Stacker\");" << std::endl;
	Pony	my_pony("Stacker");
	std::cout << "Number of ponies : " << Pony::getNumberOfPonies() << std::endl;
	std::cout << "my_pony.run();" << std::endl;
	my_pony.run();
	std::cout << "End of function no delete is called at all"
	<< std::endl
	<< "Stacker will die anyway because he is on the stack"
	<< std::endl;
}

int		main()
{
	std::cout << "Number of ponies : " << Pony::getNumberOfPonies() << std::endl;
	std::cout << "********** CALLING ponyOnTheHeap() **********" << std::endl;
	ponyOnTheHeap();
	std::cout << "Number of ponies : " << Pony::getNumberOfPonies() << std::endl;
	std::cout << "********** CALLING ponyOnTheStack() **********" << std::endl;
	ponyOnTheStack();
	std::cout << "Number of ponies : " << Pony::getNumberOfPonies() << std::endl;
	return 1;
}
