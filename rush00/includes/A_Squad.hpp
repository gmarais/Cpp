// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Squad.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:12 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 03:26:42 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _A_Squad_CLASS_
# define _A_Squad_CLASS_

# include <iostream>
# include "Tools.hpp"
//# include "A_Ship.hpp"
# include "A_Projectile.hpp"
# include "A_Physical.hpp"

struct	SquadLink
{
	A_Physical		*curr;
	SquadLink		*next;
};

class	A_Squad
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	static int	_count;
	SquadLink	*_ships;
	SquadLink	*_projectiles;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	A_Squad();
	A_Squad(A_Squad const & src);
	~A_Squad();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	int						getCount() const;
	virtual SquadLink		*getShips(void) const;
	virtual int				addShip(A_Physical *ship);
	virtual SquadLink		*getProjectiles(void) const;
	virtual void			addProjectile(A_Projectile *projectile);
	virtual void			removeShip(int index);
	virtual void			deleteShipList(void);
	virtual void			removeProjectile(int index);
	virtual void			deleteProjectileList(void);
//-----------------------------------------------------------------/ OPERATORS /
	A_Squad &	operator=(A_Squad const & rhs);

};

#endif
