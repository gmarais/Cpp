// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 03:18:08 by gmarais           #+#    #+#             //
//   Updated: 2015/01/09 03:18:08 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ClapTrap.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
ClapTrap::ClapTrap(std::string name) : _instance("ClapTrap"), _name(name)
{
	std::cout << "New ClapTrap : " << this->_name << std::endl;
}

ClapTrap::ClapTrap() : _instance("ClapTrap")
{
	std::cout << "New ClapTrap : " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "New ClapTrap : " << this->_name << std::endl;
	*this = src;
}


ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destroyed : " << this->_name << std::endl;
}

//-------------------------------------------------------------------/ GETTERS /
	int			ClapTrap::getHitPoints() const
	{
		return this->_hit_points;
	}

	int			ClapTrap::getMaxHitPoints() const
	{
		return this->_max_hit_points;
	}

	int			ClapTrap::getEnergyPoints() const
	{
		return this->_energy_points;
	}

	int			ClapTrap::getMaxEnergyPoints() const
	{
		return this->_max_energy_points;
	}

	int			ClapTrap::getLevel() const
	{
		return this->_level;
	}

	std::string	ClapTrap::getName() const
	{
		return this->_name;
	}

	int			ClapTrap::getMeleeAttackDamage() const
	{
		return this->_melee_attack_damage;
	}

	int			ClapTrap::getRangedAttackDamage() const
	{
		return this->_ranged_attack_damage;
	}

	int			ClapTrap::getArmorReduction() const
	{
		return this->_armor_damage_reduction;
	}

//-----------------------------------------------------------------/ FUNCTIONS /
void	ClapTrap::rangedAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " attacks " << target << " at range, causing \033[1;31m"
		<< this->_ranged_attack_damage << "\033[0;0m points of damage !" << std::endl;
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " attacks " << target << " at melee, causing \033[1;31m"
		<< this->_melee_attack_damage << "\033[0;0m points of damage !" << std::endl;
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ClapTrap::laserInfernoAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " attacks " << target << " with a laser inferno attack, causing \033[1;31m"
		<< this->_ranged_attack_damage * 2 << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<" << this->_instance << "><" << this->_name
		<< "> Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa" << std::endl;
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ClapTrap::electricAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " attacks " << target << " with an electric attack, causing \033[1;31m"
		<< (int)(this->_ranged_attack_damage * 1.25) << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<" << this->_instance << "><" << this->_name
		<< "> Dadadada. It's electric!" << std::endl;
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ClapTrap::buttAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " attacks " << target << " with a butt attack, causing \033[1;31m"
		<< (int)(this->_melee_attack_damage / 10) << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<" << this->_instance << "><" << this->_name
		<< "> Do not look behind my curtain!" << std::endl;
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ClapTrap::MinionTrap(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< " attacks " << target << " with a minion trap attack, causing \033[1;31m"
		<< (int)(this->_ranged_attack_damage * 1.10) << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<" << this->_instance << "><" << this->_name
		<< "> Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew-pew!" << std::endl;
	}
	else
		std::cout << this->_instance << " " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points = (
		(this->_hit_points + this->_armor_damage_reduction >= (int)amount)
		? this->_hit_points + this->_armor_damage_reduction - amount
		: 0
	);
	std::cout << this->_instance << " " << this->_name
	<< " receives \033[1;31m" << amount << "\033[0;0m points of damage !" << std::endl;
	if (this->_hit_points)
	{
		std::cout << this->_instance << " " << this->_name
		<< "> That looks like it hurt!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hit_points = (
		(this->_hit_points + amount <= (unsigned int)this->_max_hit_points)
		? this->_hit_points + amount
		: this->_max_hit_points
	);
	std::cout << this->_instance << " " << this->_name
	<< " was repaired for \033[1;32m" << amount << "\033[0;0m points of damage !" << std::endl;
	std::cout << "<" << this->_instance << "><" << this->_name
	<< "> AYE! does this mean I can start dancing? Pleeeeeeaaaaase?" << std::endl;
}

//-----------------------------------------------------------------/ OPERATORS /
ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs)
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
