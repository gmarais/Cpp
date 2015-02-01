// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/27 16:43:16 by gmarais           #+#    #+#             //
//   Updated: 2015/01/28 12:44:42 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "AbstractVM.hpp"

int		main(int ac, char** av)
{
	AbstractVM	vm(ac -1, ++av);
	return vm.run();
}
