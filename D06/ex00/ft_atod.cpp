// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ft_atod.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/13 22:38:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/13 22:38:10 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>

#define IS_WHITE_SPACE(x) ((x > 8 && x < 14) || (x == 32))

int		ft_strlen(char *str)
{
	int		count = 0;
	while (str[count])
		count++;
	return count;
}

bool	ft_isDigit(char c)
{
	return (c > 47 && c < 58);
}

double	ft_pow(double nbr, int exp)
{
	double val = nbr;

	while (--exp)
	{
		nbr *= val;
	}
	return nbr;
}

double		ft_atod(char *str)
{
	double		res = 0;
	int			dec = 0;
	int			index;
	double		sign = 1.0;

	for (index = 0; str[index] && (IS_WHITE_SPACE(str[index]) || str[index] == '-' || str[index] == '+'); index++)
		if (str[index] == '-')
			sign *= -1;
	while (str[index] && ft_isDigit(str[index]))
	{
		res *= 10.0;
		res += static_cast<double>(str[index] - 48);
		index++;
	}
	if (str[index] == '.' && ft_isDigit(str[index + 1]))
	{
		index++;
		while (str[index] && ft_isDigit(str[index]))
		{
			dec++;
			res += static_cast<double>(str[index] - 48) / ft_pow(10, dec);
			index++;
		}
	}
	return res * sign;
}
