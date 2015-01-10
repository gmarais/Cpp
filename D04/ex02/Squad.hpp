// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Squad.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 07:10:24 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 08:35:14 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _Squad_CLASS_
#define _Squad_CLASS_

#include <iostream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

struct	SquadLink
{
	ISpaceMarine	*curr;
	SquadLink		*next;
}

class	Squad : public ISquad
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	static int	_count;
	SquadLink	*_squad_list;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	Squad();
	Squad(Squad const & src);
	~Squad();
//-------------------------------------------------------------------/ GETTERS /
	int				getCount() const;
	ISpaceMarine*	getUnit(int N) const;
	int				push(ISpaceMarine*);
	void			remove(int N);
	void			deleteSquadList();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
//-----------------------------------------------------------------/ OPERATORS /
	Squad &	operator=(Squad const & rhs);

};

#endif
