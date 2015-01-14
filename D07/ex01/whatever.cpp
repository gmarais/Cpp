// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   whatever.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 11:49:49 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 14:19:23 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>

template <typename T>
void	iter(T* array, unsigned int length, void (*f)(T&))
{
	for (unsigned int i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

void	yolosquare(int& a)
{
	a *=a;
}

int		main()
{
	int	yolo[10] = {5, 6, 3, 7, 9, 2, 8, 1, 4, 0};

	for (unsigned int i = 0; i < 10; i++)
	{
		std::cout << yolo[i] << " | ";
	}
	std::cout << std::endl;
	iter(yolo, 10, &yolosquare);
	for (unsigned int i = 0; i < 10; i++)
	{	
		std::cout << yolo[i] << " | ";
	}
	std::cout << std::endl;
}
