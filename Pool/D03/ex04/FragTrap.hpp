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
#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
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
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap const & src);
	~FragTrap();
//-----------------------------------------------------------------/ OPERATORS /
	FragTrap &	operator=(FragTrap const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	void	vaulthunter_dot_exe(std::string const & target);
};

#endif
