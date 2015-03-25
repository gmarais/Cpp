// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   split.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:43:16 by gmarais           #+#    #+#             //
//   Updated: 2015/03/25 16:44:06 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <vector>

std::vector<std::string>	ft_split(const std::string & str, const std::string & delimiters)
{
	std::vector<std::string>		v;
	std::string::size_type	start = 0;
	std::string::size_type	pos = str.find_first_of(delimiters, start);
	while (pos != std::string::npos)
	{
		if (pos != start)
			v.push_back(str.substr(start, pos - start));
		start = pos + 1;
		pos = str.find_first_of(delimiters, start);
	}
	if (start < str.length())
		v.push_back(str.substr(start, str.length() - start));
	return v;
}
