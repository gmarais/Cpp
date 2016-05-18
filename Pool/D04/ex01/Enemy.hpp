// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:06:56 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Enemy_CLASS_
#define _Enemy_CLASS_

#include <iostream>

class	Enemy
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
	int			_hp;
	std::string	_type;
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Enemy(int hp, std::string const & type);
	Enemy();
	Enemy(Enemy const & src);
	virtual ~Enemy();
//-----------------------------------------------------------------/ OPERATORS /
	Enemy &	operator=(Enemy const & rhs);
//-------------------------------------------------------------------/ GETTERS /
	std::string const &	getType() const;
	int					getHP() const;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual void	takeDamage(int amount);

};

#endif
