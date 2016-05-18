// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SuperMutant.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 02:55:00 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 04:18:25 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _SuperMutant_CLASS_
#define _SuperMutant_CLASS_

#include <iostream>
#include "Enemy.hpp"

class	SuperMutant : public Enemy
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
	SuperMutant();
	SuperMutant(SuperMutant const & src);
	~SuperMutant();
//-----------------------------------------------------------------/ OPERATORS /
	SuperMutant &	operator=(SuperMutant const & rhs);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	void			takeDamage(int amount);

};

#endif
