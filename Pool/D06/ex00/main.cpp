// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/13 21:56:48 by gmarais           #+#    #+#             //
//   Updated: 2015/01/13 21:56:48 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IS_WHITE_SPACE
#define IS_WHITE_SPACE(x) ((x > 8 && x < 14) || (x == 32))
#endif

#include <iostream>
#include <string>


double		ft_atod(char *str);
bool		ft_isDigit(char c);
int			ft_strlen(char *str);


std::string	ft_convertBackChrEscSeq(char c)
{
	std::string esc[256];

	for (int i = 0; i < 256; i++)
		esc[i] = "";
	esc['\0'] = static_cast<std::string>("\\0");
	esc['\a'] = static_cast<std::string>("\\a");
	esc['\b'] = static_cast<std::string>("\\b");
	esc['\t'] = static_cast<std::string>("\\t");
	esc['\n'] = static_cast<std::string>("\\n");
	esc['\v'] = static_cast<std::string>("\\v");
	esc['\f'] = static_cast<std::string>("\\f");
	esc['\r'] = static_cast<std::string>("\\r");

	if (c > 0 && esc[static_cast<int>(c)][0])
	{
		return esc[static_cast<int>(c)];
	}
	return static_cast<std::string>(&c);
}

char	ft_convertChrEscSeq(char *str)
{
	char esc[256];
	esc['0'] = '\0';
	esc['a'] = '\a';
	esc['b'] = '\b';
	esc['t'] = '\t';
	esc['n'] = '\n';
	esc['v'] = '\v';
	esc['f'] = '\f';
	esc['r'] = '\r';

	if (ft_strlen(str) == 2 && str[0] == '\\')
	{
		return esc[static_cast<int>(str[1])];
	}
	return str[0];
}

void	processCharCase(char *value)
{
	char c = ft_convertChrEscSeq(value);

	std::cout << "char: '" << value << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	processNumberCase(char *value)
{
	double	d = ft_atod(value);
	char	c = static_cast<char>(d);
	std::cout << "char: '" << ((d < 256 && d > -256) ? ft_convertBackChrEscSeq(c) : "impossible") << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << ((static_cast<float>(d) - static_cast<int>(d) > 0.0) ? "" : ".0" ) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(d) << ((static_cast<double>(d) - static_cast<int>(d) > 0.0) ? "" : ".0" ) << std::endl;
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!ft_isDigit(av[1][0]) && (ft_strlen(av[1]) == 1 || (ft_strlen(av[1]) == 2 && av[1][0] == '\\')))
		{
			processCharCase(av[1]);
		}
		else if (ft_atod(av[1]) || av[1][0] == '0')
		{
			processNumberCase(av[1]);
		}
		else
		{
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " <<  "impossible" << std::endl;
			std::cout << "float: " <<  "nan" << "f" << std::endl;
			std::cout << "double: " <<  "nan" << std::endl;
		}
	}
	return 0;
}
