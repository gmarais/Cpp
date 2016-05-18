// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 04:58:04 by gmarais           #+#    #+#             //
//   Updated: 2015/01/09 04:58:04 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "NinjaTrap.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
NinjaTrap::NinjaTrap(std::string name)
{
	this->_hit_points = 60;
	this->_max_hit_points = 60;
	this->_energy_points = 120;
	this->_max_energy_points = 120;
	this->_level = 1;
	this->_name = name;
	this->_melee_attack_damage = 60;
	this->_ranged_attack_damage = 5;
	this->_armor_damage_reduction = 0;
	this->_instance = "NINJ4-TP";
	std::cout  << "<NINJ4-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: NINJ4-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}

NinjaTrap::NinjaTrap()
{
	this->_hit_points = 60;
	this->_max_hit_points = 60;
	this->_energy_points = 120;
	this->_max_energy_points = 120;
	this->_level = 1;
	this->_name = "Ninjatrap";
	this->_melee_attack_damage = 60;
	this->_ranged_attack_damage = 5;
	this->_armor_damage_reduction = 0;
	this->_instance = "NINJ4-TP";
	std::cout  << "<NINJ4-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: NINJ4-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src)
{
	*this = src;
	std::cout  << "<NINJ4-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: NINJ4-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}


NinjaTrap::~NinjaTrap()
{
	std::cout << "<" << this->_instance << "><" << this->_name
	<< "> Itai!" << std::endl;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void	NinjaTrap::ninjaShoebox(std::string target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " Grabs his shoes and put them on his hands and  then attacks "
		<< target << " with unexpected precision, causing \033[1;31m"
		<< this->_melee_attack_damage * 3 << "\033[0;0m points of damage !" << std::endl;
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " Grabs his shoes and throw them violently at "
		<< target.getName() << " with unexpected precision, causing \033[1;31m"
		<< this->_ranged_attack_damage * 3 << "\033[0;0m points of damage !" << std::endl;
		target.takeDamage(this->_ranged_attack_damage * 3);
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	NinjaTrap::ninjaShoebox(FragTrap & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " Grabs his shoes and put them on his head distracting the FR4G-TP and then attacks "
		<< target.getName() << " with unexpected rapidity and teeth, causing \033[1;31m"
		<< this->_melee_attack_damage * 3 << "\033[0;0m points of damage !" << std::endl;
		target.takeDamage(this->_melee_attack_damage * 3);
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " Grabs his shoes and put them on SC4V-TP head then attacks "
		<< target.getName() << " with unexpected violence, causing \033[1;31m"
		<< this->_melee_attack_damage * 3 << "\033[0;0m points of damage !" << std::endl;
		target.takeDamage(this->_melee_attack_damage * 3);
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	NinjaTrap::ninjaShoebox(SuperTrap & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " Grabs his shoes fill them with rainbow and throw them at "
		<< target.getName() << " with unexpected grace, causing \033[1;31m"
		<< this->_ranged_attack_damage * 10 << "\033[0;0m points of damage !" << std::endl;
		target.takeDamage(this->_ranged_attack_damage * 10);
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " Grabs his shoes fill them with water and throw them at "
		<< target.getName() << " with unexpected precision, causing \033[1;31m"
		<< this->_ranged_attack_damage * 3 << "\033[0;0m points of damage !" << std::endl;
		target.takeDamage(this->_ranged_attack_damage * 3);
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

//-----------------------------------------------------------------/ OPERATORS /
NinjaTrap &	NinjaTrap::operator=(NinjaTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
