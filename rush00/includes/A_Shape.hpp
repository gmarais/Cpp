// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Shape.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 22:23:06 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _A_Shape_CLASS_
#define _A_Shape_CLASS_

# include <iostream>

# include "Tools.hpp"
# include "A_Printable.hpp"

class	A_Shape : public A_Printable
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	int		_height;
	int		_width;
	t_rows	*_rows;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /


//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	A_Shape();
	A_Shape(int height, int width, t_rows *rows, int color, v2 position);
	A_Shape(A_Shape const & src);
	~A_Shape();
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	int		getHeight(void) const;
	int		getWidth(void) const;
	t_rows	*getRows(void) const;
	virtual void	render(void);
//-----------------------------------------------------------------/ OPERATORS /
	A_Shape &	operator=(A_Shape const & rhs);

};

#endif
