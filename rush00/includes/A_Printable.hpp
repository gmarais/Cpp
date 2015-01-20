// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Printable.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 20:51:09 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _A_Printable_CLASS_
# define _A_Printable_CLASS_

# include <iostream>
# include <ncurses.h>
# include "Tools.hpp"

class	A_Printable
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	int		_color;
	int		_font_style;
	v2		_position;
	v2		_scr_wh;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /
	void	printStrPosition(std::string str, v2 & position) const;
	void	printInCenter(std::string str, int height_from_center) const;

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	A_Printable();
	A_Printable(v2 & position ,int color);
	A_Printable(A_Printable const & src);
	virtual	~A_Printable();
//---------------------------------------------------------/ GETTERS & SETTERS /
	virtual const v2	&getPosition(void) const;
	virtual void		setPosition(int x, int y);
	virtual	int			getColor(void) const;
	virtual void		setColor(int color);
	virtual	int			getFontStyle(void) const;
	virtual void		setFontStyle(int flag);
	void				resetScreenWidthHeight();
	const v2			&getScreenWH(void) const;
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual void	render(void) = 0;
	virtual	void	enableAttr(void) const;
	void			disableAttr(void) const;
//-----------------------------------------------------------------/ OPERATORS /
	A_Printable &	operator=(A_Printable const & rhs);

};

#endif
