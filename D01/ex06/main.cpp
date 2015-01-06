// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp	                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/07 00:02:48 by gmarais           #+#    #+#             //
//   Updated: 2015/01/07 00:02:48 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "HumanA.cpp"
#include "HumanB.cpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
