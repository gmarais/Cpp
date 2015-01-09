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
	std::cout  << "<SC4V-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: SC4V-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
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
	std::cout << "<SC4V-TP><" << this->_name
	<< "> Crit-i-cal!" << std::endl;
}

//-------------------------------------------------------------------/ GETTERS /
	int			ScavTrap::getHitPoints() const
	{
		return this->_hit_points;
	}

	int			ScavTrap::getMaxHitPoints() const
	{
		return this->_max_hit_points;
	}

	int			ScavTrap::getEnergyPoints() const
	{
		return this->_energy_points;
	}

	int			ScavTrap::getMaxEnergyPoints() const
	{
		return this->_max_energy_points;
	}

	int			ScavTrap::getLevel() const
	{
		return this->_level;
	}

	std::string	ScavTrap::getName() const
	{
		return this->_name;
	}

	int			ScavTrap::getMeleeAttackDamage() const
	{
		return this->_melee_attack_damage;
	}

	int			ScavTrap::getRangedAttackDamage() const
	{
		return this->_ranged_attack_damage;
	}

	int			ScavTrap::getArmorReduction() const
	{
		return this->_armor_damage_reduction;
	}

//-------------------------------------------------------------------/ ATTACKS /
void	ScavTrap::rangedAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "SC4V-TP " << this->_name
		<< " attacks " << target << " at range, causing \033[1;31m"
		<< this->_ranged_attack_damage << "\033[0;0m points of damage !" << std::endl;
	}
	else
		std::cout << "SC4V-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "SC4V-TP " << this->_name
		<< " attacks " << target << " at melee, causing \033[1;31m"
		<< this->_melee_attack_damage << "\033[0;0m points of damage !" << std::endl;
	}
	else
		std::cout << "SC4V-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ScavTrap::laserInfernoAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "SC4V-TP " << this->_name
		<< " attacks " << target << " with a laser inferno attack, causing \033[1;31m"
		<< this->_ranged_attack_damage * 2 << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<SC4V-TP><" << this->_name
		<< "> Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa" << std::endl;
	}
	else
		std::cout << "SC4V-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ScavTrap::electricAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "SC4V-TP " << this->_name
		<< " attacks " << target << " with an electric attack, causing \033[1;31m"
		<< (int)(this->_ranged_attack_damage * 1.25) << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<SC4V-TP><" << this->_name
		<< "> Dadadada. It's electric!" << std::endl;
	}
	else
		std::cout << "SC4V-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ScavTrap::buttAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "SC4V-TP " << this->_name
		<< " attacks " << target << " with a butt attack, causing \033[1;31m"
		<< (int)(this->_melee_attack_damage / 10) << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<SC4V-TP><" << this->_name
		<< "> Do not look behind my curtain!" << std::endl;
	}
	else
		std::cout << "SC4V-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ScavTrap::MinionTrap(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "SC4V-TP " << this->_name
		<< " attacks " << target << " with a minion trap attack, causing \033[1;31m"
		<< (int)(this->_ranged_attack_damage * 1.10) << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<SC4V-TP><" << this->_name
		<< "> Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew-pew!" << std::endl;
	}
	else
		std::cout << "SC4V-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
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

void	ScavTrap::takeDamage(unsigned int amount)
{
	this->_hit_points = (
		(this->_hit_points + this->_armor_damage_reduction >= (int)amount)
		? this->_hit_points + this->_armor_damage_reduction - amount
		: 0
	);
	std::cout << "SC4V-TP " << this->_name
	<< " receives \033[1;31m" << amount << "\033[0;0m points of damage !" << std::endl;
	if (this->_hit_points)
	{
		std::cout << "<SC4V-TP><" << this->_name
		<< "> I can't feel my fingers! Gah! I don't have any fingers!" << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	this->_hit_points = (
		(this->_hit_points + amount <= (unsigned int)this->_max_hit_points)
		? this->_hit_points + amount
		: this->_max_hit_points
	);
	std::cout << "SC4V-TP " << this->_name
	<< " was repaired for \033[1;32m" << amount << "\033[0;0m points of damage !" << std::endl;
	std::cout << "<SC4V-TP><" << this->_name
	<< "> Health! Ooh, what flavor is red?" << std::endl;
}

//-----------------------------------------------------------------/ OPERATORS /
ScavTrap &	ScavTrap::operator=(ScavTrap const & rhs)
{
	this->_hit_points = rhs.getHitPoints();
	this->_max_hit_points = rhs.getMaxHitPoints();
	this->_energy_points = rhs.getEnergyPoints();
	this->_max_energy_points = rhs.getMaxEnergyPoints();
	this->_level = rhs.getLevel();
	this->_name = rhs.getName();
	this->_melee_attack_damage = rhs.getMeleeAttackDamage();
	this->_ranged_attack_damage = rhs.getRangedAttackDamage();
	this->_armor_damage_reduction = rhs.getArmorReduction();
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
