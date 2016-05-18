// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   A_Printable.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 03:21:11 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 01:38:46 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

# include "A_Printable.hpp"
# include "Tools.hpp"

//--------------------------------------------------------------/ STATICS INIT /

//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
A_Printable::A_Printable() :
	_color(WHITE),
	_font_style(0)
{
	this->_position.x = 0;
	this->_position.y = 0;
	getmaxyx(stdscr, this->_scr_wh.y,  this->_scr_wh.x);
}

A_Printable::A_Printable(v2 & position, int color) :
	_color(color),
	_font_style(0),
	_position(position)
{
	getmaxyx(stdscr, this->_scr_wh.y, this->_scr_wh.x);
}

A_Printable::A_Printable(A_Printable const & src)
{
	*this = src;
}


A_Printable::~A_Printable()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
const v2	&A_Printable::getScreenWH(void) const
{
	return this->_scr_wh;
}


void		A_Printable::resetScreenWidthHeight()
{
	getmaxyx(stdscr, this->_scr_wh.y, this->_scr_wh.x);
}

const v2		&A_Printable::getPosition(void) const
{
	return		this->_position;
}

void		A_Printable::setPosition(int x, int y)
{
	this->_position.x = x;
	this->_position.y = y;
}

int			A_Printable::getColor(void) const
{
	return this->_color;
}

void		A_Printable::setColor(int color)
{
	this->_color = color;
}

int			A_Printable::getFontStyle(void) const
{
	return this->_font_style;
}

void		A_Printable::setFontStyle(int flag)
{
	this->_font_style = flag;
}


//-----------------------------------------------------------------/ FUNCTIONS /
void	A_Printable::printStrPosition(std::string str, v2 & position) const
{
	move(position.y, position.x);
	printw(str.c_str());
}

void	A_Printable::printInCenter(std::string str, int height_from_center) const
{
	v2	position;

	position.x = this->getScreenWH().x / 2 - str.length() / 2;
	position.y = this->getScreenWH().y / 2 - height_from_center;
	this->printStrPosition(str, position);
}

void	A_Printable::enableAttr(void) const
{
	if (this->_font_style)
		attron(COLOR_PAIR(this->_color) | this->_font_style);
	else
		attron(COLOR_PAIR(this->_color));
}

void	A_Printable::disableAttr(void) const
{
	if (!this->_font_style)
		attroff(COLOR_PAIR(this->_color) | this->_font_style);
	else
		attroff(COLOR_PAIR(this->_color));
}

//-----------------------------------------------------------------/ OPERATORS /
A_Printable &	A_Printable::operator=(A_Printable const & rhs)
{
	this->_color = rhs.getColor();
	this->_position = rhs.getPosition();
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
