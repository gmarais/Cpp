// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   iter.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/14 10:43:02 by gmarais           #+#    #+#             //
//   Updated: 2015/01/14 11:45:49 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>

template <typename V>
void	swap(V& a, V& b)
{
	V	tmp = a;
	a= b;
	b = tmp;
}

template <typename T>
T		max(T v1, T v2)
{
	if (v1 != v2)
	{
		if (v1 < v2)
			return v2;
		return v1;
	}
	return 0;
}

template <typename T>
T		min(T v1, T v2)
{
	if (v1 != v2)
	{
		if (v1 > v2)
			return v2;
		return v1;
	}
	return 0;
}


int		main()
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}
