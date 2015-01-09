// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 23:52:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/08 23:52:10 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScavTrap.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
ScavTrap::ScavTrap(std::string name)
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 50;
	this->_max_energy_points = 50;
	this->_level = 1;
	this->_name = name;
	this->_melee_attack_damage = 20;
	this->_ranged_attack_damage = 15;
	this->_armor_damage_reduction = 3;
	this->_instance = "SC4V-TP";
	std::cout  << "<SC4V-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: SC4V-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}

ScavTrap::ScavTrap()
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 50;
	this->_max_energy_points = 50;
	this->_level = 1;
	this->_name = "Scavtrap";
	this->_melee_attack_damage = 20;
	this->_ranged_attack_damage = 15;
	this->_armor_damage_reduction = 3;
	this->_instance = "SC4V-TP";
	std::cout  << "<SC4V-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: SC4V-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	std::cout  << "<SC4V-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: SC4V-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "<" << this->_instance << "><" << this->_name
	<< "> Arg!" << std::endl;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void	ScavTrap::challengeNewcomer() const
{
	std::string	challenges[] = {
		"Hey you! Take my challenge bring my maker 1 billion dollars within an hour.",
		"Hi i challenge you to lick the top of your nose with your tongue and look smart doing it.",
		"Hello stranger, i challenge you to eat a whole bowl of pop-corn with your arms tied in your back without dropping one pop-corn."
	};
	int				index;
	static int		counter = 0;

	counter++;
	std::srand(std::time(0) + counter);
	index = std::rand() % 3;
	std::cout << "<SC4V-TP><" << this->_name
	<< "> " << challenges[index] << std::endl;
}

//-----------------------------------------------------------------/ OPERATORS /
ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
