// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   replaceAll.cpp	                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 01:50:51 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 01:50:51 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>

std::string		replaceAll(std::string str, const std::string& s1, const std::string& s2)
{
	std::size_t start_pos = 0;
	while ((start_pos = str.find(s1, start_pos)) != std::string::npos)
	{
		str.replace(start_pos, s1.length(), s2);
		start_pos += s2.length();
	}
	return str;
}
