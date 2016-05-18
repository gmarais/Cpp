// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ex04.cpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 18:45:19 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 18:45:19 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>

int		main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *str_ptr = &str;
	std::string& str_ref = str;

	std::cout << *str_ptr << std::endl;
	std::cout << str_ref << std::endl;
}
