// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   NCursesMonitorDisplay.cpp                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/17 16:36:37 by gmarais           #+#    #+#             //
//   Updated: 2015/01/18 21:11:22 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <ncurses.h>
#include <unistd.h>
#include <algorithm>
#include "NCursesMonitorDisplay.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
NCursesMonitorDisplay::NCursesMonitorDisplay()
{
}

NCursesMonitorDisplay::NCursesMonitorDisplay(int max_index) :
	_col_width(50), _max_index(max_index)
{
	this->_cursor[0] = 0;
	this->_cursor[1] = 0;
	initscr();
	start_color();
	curs_set(0);
	keypad(stdscr, true);
	noecho();
	cbreak();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);
    init_pair(8, COLOR_BLACK, COLOR_RED);
    init_pair(9, COLOR_BLACK, COLOR_GREEN);
    init_pair(10, COLOR_BLACK, COLOR_BLUE);
    init_pair(11, COLOR_BLACK, COLOR_YELLOW);
    init_pair(12, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(13, COLOR_BLACK, COLOR_CYAN);
}

NCursesMonitorDisplay::NCursesMonitorDisplay(NCursesMonitorDisplay const & src)
{
	*this = src;
}


NCursesMonitorDisplay::~NCursesMonitorDisplay()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
int		NCursesMonitorDisplay::getColor() const
{
	return this->_color;
}

void	NCursesMonitorDisplay::setColor(int color)
{
	this->_color = color;
}

int		NCursesMonitorDisplay::getFontStyle() const
{
	return this->_font_style;
}

void	NCursesMonitorDisplay::setFontStyle(int flag)
{
	this->_font_style = flag;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void	NCursesMonitorDisplay::generateFrame(size_t index)
{
	this->_index = index;
}

void	NCursesMonitorDisplay::generateChart( std::vector<int> data)
{
	if (data.size() == 0) return;
	int		max_value = *std::max_element(data.begin(), data.end());
	for (std::vector<int>::iterator it = data.begin(); it != data.end(); ++it)
	{
		this->_chart.push_back(
			std::string(static_cast<int>( static_cast<float>(*it) / static_cast<float>(max_value) * static_cast<float>(this->_col_width - 4) ), ' ')
		);
	}
}

void	NCursesMonitorDisplay::generateText(std::string text)
{
	for(unsigned int i = 0; i < text.size(); i++)
	{
		if (i % (this->_col_width - 4) == 0)
		{
			this->_text.push_back(text.substr(i, this->_col_width - 4));
		}
	}
}

void	NCursesMonitorDisplay::render()
{
	int				block_height;
	static int		biggest_block = 0;
	unsigned int	column_number;
	bool			chart_margin = true;

	getmaxyx(stdscr, this->_screen_height, this->_screen_width);
	column_number = this->_screen_width / this->_col_width;
	if (column_number < 1)
		column_number = 1;
	if (!(this->_index % column_number))
	{
		this->_cursor[1] += biggest_block;
		biggest_block = 0;
	}
	block_height = this->_text.size() + this->_chart.size() + 4;
	if (block_height > biggest_block)
	{
		biggest_block = block_height;
	}
	if (static_cast<unsigned int>(this->_cursor[1] + block_height) <= this->_screen_height
		&& static_cast<unsigned int>(this->_cursor[0] + this->_col_width) <= this->_screen_width)
	{
		this->_cursor[0] = (this->_index % column_number) * this->_col_width;
		this->_color = R_BLUE;
		this->printStrToCursor("+" + std::string((this->_col_width - 2), '-') + "+");
		for (size_t i = 1; i < static_cast<size_t>(block_height); ++i)
		{
			this->_cursor[1]++;
			this->_cursor[0] = (this->_index % column_number) * this->_col_width;
			this->printStrToCursor("|");
			this->_cursor[0] += 2;
			if (this->_text.size() == 0 && this->_chart.size() != 0)
			{
				if (chart_margin == true)
				{
					chart_margin = false;
				}
				else
				{
					this->_color = R_YELLOW;
					this->printStrToCursor(this->_chart.front());
					this->_chart.pop_front();
				}
			}
			else if (i >= 2 && this->_text.size() > 0)
			{
				this->_color = GREEN;
				this->printStrToCursor(this->_text.front());
				this->_text.pop_front();
			}
			this->_cursor[0] = ((this->_index % column_number) * this->_col_width) + this->_col_width - 1;
			this->_color = R_BLUE;
			this->printStrToCursor("|");
		}
		this->_cursor[1]++;
		this->_cursor[0] = (this->_index % column_number) * this->_col_width;
		this->_color = R_BLUE;
		this->printStrToCursor("+" + std::string((this->_col_width - 2), '-') + "+");
		this->_cursor[1] -= (block_height);
	}
	this->_text.clear();
	this->_chart.clear();
	if (this->_index >= this->_max_index)
	{
		this->_cursor[0] = 0;
		this->_cursor[1] = 0;
		biggest_block = 0;
		refresh();
		sleep(1);
		erase();
	}
}

bool	NCursesMonitorDisplay::getStatus()
{
	return false;
}

//-------------------------------------------------------------------/ PRIVATE /
void	NCursesMonitorDisplay::enableAttr() const
{
	if (this->_font_style)
		attron(COLOR_PAIR(this->_color) | this->_font_style);
	else
		attron(COLOR_PAIR(this->_color));
}

void	NCursesMonitorDisplay::disableAttr() const
{
    if (!this->_font_style)
        attroff(COLOR_PAIR(this->_color) | this->_font_style);
    else
        attroff(COLOR_PAIR(this->_color));
}

void	NCursesMonitorDisplay::printStrToCursor(std::string str) const
{
	this->enableAttr();
	move(this->_cursor[1], this->_cursor[0]);
	printw(str.c_str());
	this->disableAttr();
}

//-----------------------------------------------------------------/ OPERATORS /
NCursesMonitorDisplay &	NCursesMonitorDisplay::operator=(NCursesMonitorDisplay const & rhs)
{
	static_cast<void>(rhs);
	// @TODO : COPY ATTRIBUTES HERE.
	return *this;
}

//-------------------------------------------------------------/ OUTSIDE SCOPE /
