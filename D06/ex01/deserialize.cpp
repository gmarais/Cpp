// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   deserialize.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 03:18:31 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 03:18:31 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "Data.hpp"

Data * deserialize( void * raw )
{
	Data *result = new Data;
	result->s1 = reinterpret_cast<char*>(raw);
	result->s1.resize(8);
	result->s2 = &reinterpret_cast<char*>(raw)[16];
	result->s2.resize(8);
	result->n = reinterpret_cast<int*>(raw)[8];
	return result;
}
