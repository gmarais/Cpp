// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/08 19:23:47 by gmarais           #+#    #+#             //
//   Updated: 2015/01/08 19:23:47 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _FragTrap_CLASS_
#define _FragTrap_CLASS_

#include <iostream>
#include <cstdlib>
#include <ctime>

class	FragTrap
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
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	virtual ~FragTrap();
//-----------------------------------------------------------------/ OPERATORS /
	FragTrap &	operator=(FragTrap const & rhs);
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
	virtual void	rangedAttack(std::string const & target);
	virtual void	meleeAttack(std::string const & target);
	virtual void	laserInfernoAttack(std::string const & target);
	virtual void	electricAttack(std::string const & target);
	virtual void	buttAttack(std::string const & target);
	virtual void	MinionTrap(std::string const & target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
	void	vaulthunter_dot_exe(std::string const & target);
};

#endif
