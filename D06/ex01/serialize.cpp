// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   serialize.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 03:18:13 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 03:18:13 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "Data.hpp"

#include <cstdlib>
#include <ctime>

int			my_random()
{
	static int	count = 0;

	srand (std::time(NULL) + count);
	count++;
	return std::rand();
}

void *		serialize()
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	char	*serialized = new char [24];
	int		*integer_ptr = reinterpret_cast<int*>(&serialized[8]);

	for (int i = 0; i < 8; i++)
	{
		serialized[i] = alphanum[my_random() % 62];
	}
	*integer_ptr = my_random();
	for (int i = 16; i < 24; i++)
	{
		serialized[i] = alphanum[my_random() % 62];
	}
	return reinterpret_cast<void*>(serialized);
}

