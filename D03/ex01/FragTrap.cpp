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
FragTrap::FragTrap(std::string name) :
_hit_points(100),
_max_hit_points(100),
_energy_points(100),
_max_energy_points(100),
_level(1),
_name(name),
_melee_attack_damage(30),
_ranged_attack_damage(20),
_armor_damage_reduction(5)
{
	std::cout  << "<FR4G-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: FR4G-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}

FragTrap::FragTrap() :
_hit_points(100),
_max_hit_points(100),
_energy_points(100),
_max_energy_points(100),
_level(1),
_name("Fragtrap"),
_melee_attack_damage(30),
_ranged_attack_damage(20),
_armor_damage_reduction(5)
{
	std::cout  << "<FR4G-TP><" << this->_name
	<< "> Booting sequence complete. Hello! I am your new steward bot. "
	<< "Designation: FR4G-TP, Hyperion Robot, Class C. "
	<< "Please adjust factory settings to meet your needs before deployment."
	<< std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "<FR4G-TP><" << this->_name
	<< "> Crit-i-cal!" << std::endl;
}

//-------------------------------------------------------------------/ GETTERS /
	int			FragTrap::getHitPoints() const
	{
		return this->_hit_points;
	}

	int			FragTrap::getMaxHitPoints() const
	{
		return this->_max_hit_points;
	}

	int			FragTrap::getEnergyPoints() const
	{
		return this->_energy_points;
	}

	int			FragTrap::getMaxEnergyPoints() const
	{
		return this->_max_energy_points;
	}

	int			FragTrap::getLevel() const
	{
		return this->_level;
	}

	std::string	FragTrap::getName() const
	{
		return this->_name;
	}

	int			FragTrap::getMeleeAttackDamage() const
	{
		return this->_melee_attack_damage;
	}

	int			FragTrap::getRangedAttackDamage() const
	{
		return this->_ranged_attack_damage;
	}

	int			FragTrap::getArmorReduction() const
	{
		return this->_armor_damage_reduction;
	}

//-------------------------------------------------------------------/ ATTACKS /
void	FragTrap::rangedAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "FR4G-TP " << this->_name
		<< " attacks " << target << " at range, causing \033[1;31m"
		<< this->_ranged_attack_damage << "\033[0;0m points of damage !" << std::endl;
	}
	else
		std::cout << "FR4G-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "FR4G-TP " << this->_name
		<< " attacks " << target << " at melee, causing \033[1;31m"
		<< this->_melee_attack_damage << "\033[0;0m points of damage !" << std::endl;
	}
	else
		std::cout << "FR4G-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	FragTrap::laserInfernoAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "FR4G-TP " << this->_name
		<< " attacks " << target << " with a laser inferno attack, causing \033[1;31m"
		<< this->_ranged_attack_damage * 2 << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<FR4G-TP><" << this->_name
		<< "> Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa" << std::endl;
	}
	else
		std::cout << "FR4G-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	FragTrap::electricAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "FR4G-TP " << this->_name
		<< " attacks " << target << " with an electric attack, causing \033[1;31m"
		<< (int)(this->_ranged_attack_damage * 1.25) << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<FR4G-TP><" << this->_name
		<< "> Dadadada. It's electric!" << std::endl;
	}
	else
		std::cout << "FR4G-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	FragTrap::buttAttack(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "FR4G-TP " << this->_name
		<< " attacks " << target << " with a butt attack, causing \033[1;31m"
		<< (int)(this->_melee_attack_damage / 10) << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<FR4G-TP><" << this->_name
		<< "> Do not look behind my curtain!" << std::endl;
	}
	else
		std::cout << "FR4G-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
}

void	FragTrap::MinionTrap(std::string const & target)
{
	if (this->_hit_points)
	{
		std::cout << "FR4G-TP " << this->_name
		<< " attacks " << target << " with a minion trap attack, causing \033[1;31m"
		<< (int)(this->_ranged_attack_damage * 1.10) << "\033[0;0m points of damage !" << std::endl;
		std::cout << "<FR4G-TP><" << this->_name
		<< "> Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew-pew!" << std::endl;
	}
	else
		std::cout << "FR4G-TP " << this->_name << " has 0 hp and cannot attack..." << std::endl;
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

void	FragTrap::takeDamage(unsigned int amount)
{
	this->_hit_points = (
		(this->_hit_points + this->_armor_damage_reduction >= (int)amount)
		? this->_hit_points + this->_armor_damage_reduction - amount
		: 0
	);
	std::cout << "FR4G-TP " << this->_name
	<< " receives \033[1;31m" << amount << "\033[0;0m points of damage !" << std::endl;
	if (this->_hit_points)
	{
		std::cout << "<FR4G-TP><" << this->_name
		<< "> That looks like it hurt!" << std::endl;
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	this->_hit_points = (
		(this->_hit_points + amount <= (unsigned int)this->_max_hit_points)
		? this->_hit_points + amount
		: this->_max_hit_points
	);
	std::cout << "FR4G-TP " << this->_name
	<< " was repaired for \033[1;32m" << amount << "\033[0;0m points of damage !" << std::endl;
	std::cout << "<FR4G-TP><" << this->_name
	<< "> AYE! does this mean I can start dancing? Pleeeeeeaaaaase?" << std::endl;
}

//-----------------------------------------------------------------/ OPERATORS /
FragTrap &	FragTrap::operator=(FragTrap const & rhs)
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
