// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NinjaTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 04:58:04 by gmarais           #+#    #+#             //
//   Updated: 2015/01/09 04:58:04 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _NinjaTrap_CLASS_
#define _NinjaTrap_CLASS_

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	NinjaTrap : public ClapTrap
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
	NinjaTrap(std::string name);
	NinjaTrap();
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap();
//-----------------------------------------------------------------/ OPERATORS /
	NinjaTrap &	operator=(NinjaTrap const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	void	ninjaShoebox(std::string target);
	void	ninjaShoebox(ClapTrap & target);
	void	ninjaShoebox(FragTrap & target);
	void	ninjaShoebox(ScavTrap & target);
	void	ninjaShoebox(NinjaTrap & target);
};

#endif
