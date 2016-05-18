// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Ship.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 05:29:26 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _A_Ship_CLASS_
# define _A_Ship_CLASS_

# include <iostream>
# include <ctime>

# include "A_Projectile.hpp"
# include "A_Movable.hpp"
# include "A_Squad.hpp"
# include "A_Physical.hpp"
# include "Tools.hpp"

class	A_Ship : public A_Movable, public A_Physical
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	std::string			_name;
	int					_life;
	const A_Projectile	*_projectile;
	const A_Squad		*_squad;
	v2					_weapon;
	int					_bullet_color;
	float				_fire_rate;
	bool				_firing;
	clock_t				_last_shot;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	A_Ship();
	A_Ship(std::string name, int life, A_Projectile *projectile, A_Squad *squad,
		   v2 weapon, int shcolor, float fire_rate, int height, int width,
		   t_rows *rows,int bucolor,v2 position, float speed);
	A_Ship(A_Ship const & src);
	~A_Ship();

//---------------------------------------------------------/ GETTERS / SETTERS /
	virtual std::string const	&getName(void) const;
	virtual int				getLife(void) const;
	virtual float			getFireRate(void) const;
	virtual void			setFiring(void);
	virtual bool			getFiring(void) const;
	virtual A_Projectile const	&getProjectile(void);
	virtual v2 const		&getWeapon(void) const;
	virtual void			setProjectile(A_Projectile *proj);
	virtual A_Squad			*getSquad(void);

//----------------------------------------------------------/ PUBLIC FUNCTIONS /

	virtual void	fire(void);
	virtual void	takeDamage(int damage);

//-----------------------------------------------------------------/ OPERATORS /
	A_Ship &	operator=(A_Ship const & rhs);

};

#endif
