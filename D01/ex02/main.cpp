// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/06 15:46:43 by gmarais           #+#    #+#             //
//   Updated: 2015/01/06 15:46:43 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "ZombieEvent.cpp"

int		main()
{
	Zombie	*jojo;

	ZombieEvent my_event;
	my_event.setZombieType("Yolo");
	jojo = my_event.newZombie("Josué");
	jojo->announce();
	delete jojo;
	my_event.setZombieType("Swag");
	my_event.randomChump();
	return 1;
}
