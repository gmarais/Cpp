// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ISquad.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 06:51:42 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 07:02:34 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _ISquad_CLASS_
#define _ISquad_CLASS_

#include <iostream>

class ISquad
{
public:
	virtual ~ISquad() {}
	virtual int getCount() const = 0;
	virtual ISpaceMarine* getUnit(int) = 0;
	virtual int push(ISpaceMarine*) = 0;
};

#endif
