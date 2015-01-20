// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   I_Printable.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 01:56:10 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 18:24:00 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _I_Printable_CLASS_
# define _I_Printable_CLASS_

# include <iostream>
# include "Tools.hpp"

class	I_Printable
{

private:
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED FUNCTIONS /


public:
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /

//-------------------------------------------------------------------/ GETTERS /
	virtual v2			&getPosition(void) const = 0;
	virtual	int			getColor(void) const = 0;
	virtual	void		enableAttr(void) const = 0;
	virtual void		setColor(int color) = 0;

//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual void	render(void) = 0;











//-----------------------------------------------------------------/ OPERATORS /
	I_Printable &	operator=(I_Printable const & rhs);
	
};

#endif
