// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   split.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:43:16 by gmarais           #+#    #+#             //
//   Updated: 2015/01/28 12:44:42 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <vector>

template<typename T>
std::vector<T>	split(const T & str, const T & delimiters)
{
	std::vector<T> v;
	typename T::size_type start = 0;
	typename T::size_type pos = str.find_first_of(delimiters, start);
	while(pos != T::npos)
	{
		if(pos != start)
			v.emplace_back(str, start, pos - start);
		start = pos + 1;
		pos = str.find_first_of(delimiters, start);
	}
	if(start < str.length())
		v.emplace_back(str, start, str.length() - start);
	return v;
}
