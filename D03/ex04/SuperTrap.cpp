// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 05:39:29 by gmarais           #+#    #+#             //
//   Updated: 2015/01/09 05:39:29 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SuperTrap.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
SuperTrap::SuperTrap(std::string name)
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 120;
	this->_max_energy_points = 120;
	this->_level = 1;
	this->_name = name;
	this->_melee_attack_damage = 60;
	this->_ranged_attack_damage = 20;
	this->_armor_damage_reduction = 5;
	this->_instance = "NINJ4-TP";
	std::cout  << "<NINJ4-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: NINJ4-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}

SuperTrap::SuperTrap()
{
}

SuperTrap::SuperTrap(SuperTrap const & src)
{
	*this = src;
}


SuperTrap::~SuperTrap()
{
}

//-----------------------------------------------------------------/ FUNCTIONS /
void	SuperTrap::rangedAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "FR4G-TP" << " " << this->_name
		<< " attacks " << target << " at range, causing \033[1;31m"
		<< this->_ranged_attack_damage << "\033[0;0m points of damage !" << std::endl;
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	SuperTrap::meleeAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "NINJ4-TP" << " " << this->_name
		<< " attacks " << target << " at melee, causing \033[1;31m"
		<< this->_melee_attack_damage << "\033[0;0m points of damage !" << std::endl;
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

//-----------------------------------------------------------------/ OPERATORS /
SuperTrap &	SuperTrap::operator=(SuperTrap const & rhs)
{
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
