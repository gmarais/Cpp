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

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
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
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	void	challengeNewcomer() const;
};

#endif
