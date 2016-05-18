// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 23:52:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/08 23:52:10 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _ScavTrap_CLASS_
#define _ScavTrap_CLASS_

#include "FragTrap.hpp"
#include <iostream>

class	ScavTrap
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
	int			_hit_points;
	int			_max_hit_points;
	int			_energy_points;
	int			_max_energy_points;
	int			_level;
	std::string	_name;
	int			_melee_attack_damage;
	int			_ranged_attack_damage;
	int			_armor_damage_reduction;
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap();
//-----------------------------------------------------------------/ OPERATORS /
	ScavTrap &	operator=(ScavTrap const & rhs);
//------------------------------------------------------------------/ GETTERSS /
	int			getHitPoints() const;
	int			getMaxHitPoints() const;
	int			getEnergyPoints() const;
	int			getMaxEnergyPoints() const;
	int			getLevel() const;
	std::string	getName() const;
	int			getMeleeAttackDamage() const;
	int			getRangedAttackDamage() const;
	int			getArmorReduction() const;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	void		rangedAttack(std::string const & target);
	void		meleeAttack(std::string const & target);
	void		laserInfernoAttack(std::string const & target);
	void		electricAttack(std::string const & target);
	void		buttAttack(std::string const & target);
	void		MinionTrap(std::string const & target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		challengeNewcomer() const;
};

#endif
