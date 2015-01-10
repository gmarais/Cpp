// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 19:23:47 by gmarais           #+#    #+#             //
//   Updated: 2015/01/08 19:23:47 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "FragTrap.hpp"
typedef  void (FragTrap::*FragTrapMember)(std::string const & target);

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
FragTrap::FragTrap(std::string name)
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 100;
	this->_max_energy_points = 100;
	this->_level = 1;
	this->_name = name;
	this->_melee_attack_damage = 30;
	this->_ranged_attack_damage = 20;
	this->_armor_damage_reduction = 5;
	this->_instance = "FR4G-TP";
	std::cout  << "<FR4G-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: FR4G-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}

FragTrap::FragTrap()
{
	this->_hit_points = 100;
	this->_max_hit_points = 100;
	this->_energy_points = 100;
	this->_max_energy_points = 100;
	this->_level = 1;
	this->_name = "Fragtrap";
	this->_melee_attack_damage = 30;
	this->_ranged_attack_damage = 20;
	this->_armor_damage_reduction = 5;
	this->_instance = "FR4G-TP";
	std::cout  << "<FR4G-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: FR4G-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout  << "<FR4G-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: FR4G-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "<" << this->_instance << "><" << this->_name
	<< "> Crit-i-cal!" << std::endl;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	FragTrapMember	_attacks[] = {
		&FragTrap::rangedAttack,
		&FragTrap::meleeAttack,
		&FragTrap::laserInfernoAttack,
		&FragTrap::electricAttack,
		&FragTrap::buttAttack,
		&FragTrap::MinionTrap
	};
	int				index;
	static int		counter = 0;

	counter++;
	std::srand(std::time(0) + counter);
	if (this->_energy_points >= 25)
	{
		this->_energy_points -= 25;
		index = std::rand() % 5;
		(this->*(_attacks[index]))(target);
	}
	else
	{
		if (this->_energy_points > 0)
			std::cout << this->_name << " is out of energy..." << std::endl;
		else
			std::cout << this->_name << " has not enough energy..." << std::endl;
	}
}

//-----------------------------------------------------------------/ OPERATORS /
FragTrap &	FragTrap::operator=(FragTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
