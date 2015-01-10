// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperTrap.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/09 05:39:29 by gmarais           #+#    #+#             //
//   Updated: 2015/01/09 05:39:29 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _SuperTrap_CLASS_
#define _SuperTrap_CLASS_

#include <iostream>
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class	SuperTrap : public FragTrap, NinjaTrap
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
	SuperTrap();
	SuperTrap(std::string name);
	SuperTrap(SuperTrap const & src);
	~SuperTrap();
//-----------------------------------------------------------------/ OPERATORS /
	SuperTrap &	operator=(SuperTrap const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	void	rangedAttack(std::string const & target);
	void	meleeAttack(std::string const & target);

};

#endif
