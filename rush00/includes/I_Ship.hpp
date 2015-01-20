// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Ship.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 01:56:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 17:31:50 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Ship_CLASS_
# define _I_Ship_CLASS_

# include <iostream>

# include "A_Movable.hpp"
# include "A_Physical.hpp"

class	I_Ship : public A_Movable, public A_Physical
{

private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	I_Ship(void);
	I_Ship(I_Ship const & src);

public:

//---------------------------------------------------------/ GETTERS / SETTERS /
	virtual void	getName(void) const = 0;
	virtual void	getLife(void) const = 0;
	virtual void	getFireRate(void) const = 0;
//	virtual void	getProjectileType(void) const = 0;

//------------------------------------------------------/ CONSTRUCT & DESTRUCT /

	virtual ~I_Ship(void);

//----------------------------------------------------------/ PUBLIC FUNCTIONS /

	virtual void	fire(void) const = 0;
	virtual void	takeDamage(int damage) = 0;

//-----------------------------------------------------------------/ OPERATORS /

	I_Ship &	operator=(I_Ship const & rhs);

};

#endif
