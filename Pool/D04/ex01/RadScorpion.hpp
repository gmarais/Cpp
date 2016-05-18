// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   RadScorpion.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 05:29:06 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _RadScorpion_CLASS_
#define _RadScorpion_CLASS_

#include <iostream>
#include "Enemy.hpp"

class	RadScorpion : public Enemy
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
	RadScorpion();
	RadScorpion(RadScorpion const & src);
	~RadScorpion();
//-----------------------------------------------------------------/ OPERATORS /
	RadScorpion &	operator=(RadScorpion const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	void			takeDamage(int amount);

};

#endif
