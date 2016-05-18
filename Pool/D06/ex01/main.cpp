// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 03:17:56 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 03:17:56 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "Data.hpp"

int		main()
{
	void	*serialized;
	Data	*deserialized;
	serialized = serialize();
	deserialized = deserialize(serialized);
	std::cout << deserialized->s1 << std::endl;
	std::cout << deserialized->n << std::endl;
	std::cout << deserialized->s2 << std::endl;
	delete reinterpret_cast<char*>(serialized);
	delete deserialized;
	return 0;
}
