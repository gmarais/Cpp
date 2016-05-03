// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   tools.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:43:16 by gmarais           #+#    #+#             //
//   Updated: 2015/03/25 16:44:06 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "Tools.hpp"

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

double ft_atod(std::string str)
{
	std::stringstream ss;
	double nb;
	ss << str;
	ss >> nb;
	return nb;
}

int ft_atoi(std::string str)
{
	std::stringstream ss;
	int nb;
	ss << str;
	ss >> nb;
	return nb;
}

std::string ft_dtoa(double nb)
{
	std::ostringstream sstream;
	sstream << nb;
	return sstream.str();
}

bool ft_isANumber(std::string str)
{
	std::string::size_type	start = 0;
	std::string::size_type posnbr = str.find_first_of("0123456789", start);
	if (posnbr == std::string::npos)
		return false;
	std::string::size_type pos = str.find_first_not_of("-0123456789. ", start);
	size_t n = std::count(str.begin(), str.end(), '.');
	if (pos != std::string::npos || n > 1)
		return false;
	size_t nMinus = std::count(str.begin(), str.end(), '-');
	if (nMinus > 1)
		return false;
	if (nMinus > 0)
	{
		std::string::size_type posMinus = str.find_first_of("-", start);
		if (posnbr < posMinus)
			return false;
	}
	return true;
}

void ft_ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
}

void ft_rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}