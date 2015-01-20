// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 16:06:42 by gmarais           #+#    #+#             //
/*   Updated: 2015/01/17 16:29:56 by brandazz         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include "MonitorController.hpp"

int		main(int ac, char** av)
{
	MonitorController monitor_controller(ac, av);
	return (monitor_controller.run());
}
