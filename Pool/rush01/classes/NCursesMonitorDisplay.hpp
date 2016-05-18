// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NCursesMonitorDisplay.hpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 16:36:37 by gmarais           #+#    #+#             //
/*   Updated: 2015/01/17 21:58:27 by brandazz         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#ifndef _NCursesMonitorDisplay_CLASS_
# define _NCursesMonitorDisplay_CLASS_

# include <iostream>
# include <list>
# include "IMonitorDisplay.hpp"
enum e_colors
{
	WHITE,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	MAGENTA,
	CYAN,
	R_WHITE,
	R_RED,
	R_GREEN,
	R_BLUE,
	R_YELLOW,
	R_MAGENTA,
	R_CYAN
};

class	NCursesMonitorDisplay : public IMonitorDisplay
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	unsigned int	_screen_width;
	unsigned int	_screen_height;
	int				_color;
	int				_font_style;
	int				_cursor[2];
	int				_col_width;
	int				_index;
	int				_max_index;

	std::list<std::string>	_text;
	std::list<std::string>	_chart;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	int		getColor(void) const;
	void	setColor(int color);
	int		getFontStyle() const;
	void	setFontStyle(int flag);
	void	enableAttr() const;
	void	disableAttr() const;
	void	printStrToCursor(std::string str) const;

	NCursesMonitorDisplay();

protected:
//-------------------------------------------------------/ PROTECTED VARIABLES /
//-------------------------------------------------------/ PROTECTED FUNCTIONS /

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	NCursesMonitorDisplay(int max_index);
	NCursesMonitorDisplay(NCursesMonitorDisplay const & src);
	virtual ~NCursesMonitorDisplay();
//---------------------------------------------------------/ GETTERS & SETTERS /
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual void generateFrame(size_t index);
	virtual void generateChart( std::vector<int> data);
	virtual void generateText(std::string text);
	virtual void render();
	virtual bool getStatus();
//-----------------------------------------------------------------/ OPERATORS /
	NCursesMonitorDisplay &	operator=(NCursesMonitorDisplay const & rhs);

};

#endif
