// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Squad.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 01:56:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 03:25:53 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Squad_CLASS_
# define _I_Squad_CLASS_

# include <iostream>

# include "A_Projectile.hpp"
# include "A_Ship.hpp"

class	I_Squad
{
private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /



protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Squad(void);
	I_Squad(I_Squad const & src);

public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /

	virtual ~I_Squad(void);
	virtual A_Ship		*getShips(void) const = 0;
	virtual void		addShip(A_Physical *ship) = 0;
	virtual A_Projectile	*getProjectiles(void) const = 0;
	virtual void		addProjectile(A_Projectile *projectile) = 0;
	virtual void		removeShip(int index) = 0;
	virtual void		deleteShipList(void) = 0;

//----------------------------------------------------------/ PUBLIC FUNCTIONS /



//-----------------------------------------------------------------/ OPERATORS /
	I_Squad &	operator=(I_Squad const & rhs);

};

#endif
