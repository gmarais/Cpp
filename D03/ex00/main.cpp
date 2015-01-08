// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 19:26:28 by gmarais           #+#    #+#             //
//   Updated: 2015/01/08 19:26:28 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include "FragTrap.hpp"

int		main()
{
	FragTrap	toto("Toto");
	FragTrap	*totocopy = new FragTrap();
	FragTrap	bob("Bob");

	std::cout << "--------Assigning toto to default Claptrap--------" << std::endl;
	*totocopy = toto;
	std::cout << "--------Destroying the copy--------" << std::endl;
	delete totocopy;
	toto.vaulthunter_dot_exe("minion");
	toto.vaulthunter_dot_exe("minion");
	toto.vaulthunter_dot_exe("minion");
	toto.vaulthunter_dot_exe("minion");
	toto.vaulthunter_dot_exe("minion");
	toto.vaulthunter_dot_exe("your mama!!!");
	bob.buttAttack("you");

	std::cout << "--------NOW DO 99999 DAMAGES to bob--------" << std::endl;
	bob.takeDamage(99999);
	std::cout << "--------GETTING bob's hit points--------" << std::endl;
	std::cout << bob.getHitPoints() << std::endl;
	std::cout << "--------Asking bob to process an attack on toto--------" << std::endl;
	bob.vaulthunter_dot_exe("toto");
	std::cout << "--------NOW DO 75 DAMAGES to toto that has 5 armor--------" << std::endl;
	toto.takeDamage(75);
	std::cout << "--------GETTING toto's hit points--------" << std::endl;
	std::cout << toto.getHitPoints() << std::endl;
	std::cout << "--------Repairing toto for 25 hp--------" << std::endl;
	toto.beRepaired(25);
	std::cout << "--------GETTING toto's hit points--------" << std::endl;
	std::cout << toto.getHitPoints() << std::endl;
	std::cout << "--------Repairing toto for 99999 hp--------" << std::endl;
	toto.beRepaired(99999);
	std::cout << "--------GETTING toto's hit points--------" << std::endl;
	std::cout << toto.getHitPoints() << std::endl;
	
	return 0;
}
