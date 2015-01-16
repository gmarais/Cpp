// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   easyfind.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/15 11:09:59 by gmarais           #+#    #+#             //
//   Updated: 2015/01/15 11:09:59 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _easyfind_CLASS_
# define _easyfind_CLASS_

# include <iostream>
# include <iterator>
# include <algorithm>

template <typename T>
bool	easyfind(T &cnt, int seek) {
	if (find(cnt.begin(), cnt.end(), seek) == cnt.end())
		return (0);
	return (1);
}

#endif
