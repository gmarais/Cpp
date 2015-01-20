// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Physical.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 22:35:58 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _A_Physical_CLASS_
# define _A_Physical_CLASS_

# include <iostream>

# include "Tools.hpp"
# include "A_Shape.hpp"

class	A_Physical : public A_Shape
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
	A_Physical();
	A_Physical(int height, int width, t_rows *rows, int color, v2 position);
	A_Physical(A_Physical const & src);
	~A_Physical();

//-------------------------------------------------------------------/ GETTERS /



//----------------------------------------------------------/ PUBLIC FUNCTIONS /

	virtual bool	collide(v2 *pos) const;
	virtual bool	collide(A_Shape &shape) const;

//-----------------------------------------------------------------/ OPERATORS /
	A_Physical &	operator=(A_Physical const & rhs);

};

#endif
