// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   tools.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:43:16 by gmarais           #+#    #+#             //
//   Updated: 2015/02/09 17:52:53 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _TOOLS_
# define _TOOLS_

# include <string>
# include <sstream>
# include <iostream>
# include <vector>
# include <algorithm>

std::vector<std::string> ft_split(const std::string & str, const std::string & delimiters);
double ft_atod(std::string str);
int ft_atoi(std::string str);
std::string ft_dtoa(double nb);
void ft_ltrim(std::string &s);
void ft_rtrim(std::string &s);
bool ft_isANumber(std::string str);

#endif
