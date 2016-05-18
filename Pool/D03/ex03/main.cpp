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
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

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

	std::cout << "--------TESTING SCAVTRAP--------" << std::endl;
	ScavTrap	yolo("Yolo");
	std::cout << "--------Challenge new comer--------" << std::endl;
	yolo.challengeNewcomer();
	yolo.challengeNewcomer();
	yolo.challengeNewcomer();
	yolo.challengeNewcomer();
	yolo.challengeNewcomer();
	yolo.challengeNewcomer();
	std::cout << "--------get hit points--------" << std::endl;
	std::cout << yolo.getHitPoints() << std::endl;
	std::cout << "--------get armor--------" << std::endl;
	std::cout << yolo.getArmorReduction() << std::endl;
	std::cout << "--------NOW DO 75 DAMAGES to yolo that has 3 armor--------" << std::endl;
	yolo.takeDamage(75);
	std::cout << "--------get hit points--------" << std::endl;
	std::cout << yolo.getHitPoints() << std::endl;
	std::cout << "--------Repairing for 25 hp--------" << std::endl;
	yolo.beRepaired(25);
	std::cout << "--------get hit points--------" << std::endl;
	std::cout << yolo.getHitPoints() << std::endl;
	std::cout << "--------Attacking--------" << std::endl;
	yolo.rangedAttack("");
	yolo.meleeAttack("");
	yolo.laserInfernoAttack("");
	yolo.electricAttack("");
	yolo.buttAttack("");
	yolo.MinionTrap("");
	std::cout << "--------TESTING NINJATRAP--------" << std::endl;
	NinjaTrap	yuisenpai("Yui Senpai");
	NinjaTrap	fakesenpai("Fake Senpai");
	yuisenpai.ninjaShoebox("Jojo");
	yuisenpai.ninjaShoebox(yolo);
	yuisenpai.ninjaShoebox(toto);
	yuisenpai.ninjaShoebox(fakesenpai);
	std::cout << "--------DESTRUCTORS--------" << std::endl;
	return 0;
}
