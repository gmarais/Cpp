// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScreenDisplay.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 04:54:51 by gmarais           #+#    #+#             //
//   Updated: 2015/01/12 02:09:53 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ScreenDisplay.hpp"

//--------------------------------------------------------------/ STATICS INIT /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
ScreenDisplay::ScreenDisplay() :
	A_Printable(),
	_borders_drawn(0),
	_current_screen(0),
	_past_time(0),
	_frames_number(g_frame_rate)
{
	initscr();				// init the screen
	this->resetScreenWidthHeight();
	start_color();			// enables use of colors
	curs_set(0);			// hide the cursor
	keypad(stdscr, true);	// enable use of arrowkeys etc
	noecho(); 				// dont show char typed on the cursor location
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

ScreenDisplay::ScreenDisplay(ScreenDisplay const & src) :
	A_Printable(src)
{
	*this = src;
}


ScreenDisplay::~ScreenDisplay()
{
}

//---------------------------------------------------------/ GETTERS & SETTERS /
int			ScreenDisplay::getCurrentScreen() const
{
	return this->_current_screen;
}

int			ScreenDisplay::setCurrentScreen(int id_screen)
{
	return this->_current_screen = id_screen;
}

void		ScreenDisplay::setPlayer(A_Player *player)
{
	this->_player = player;
}

//-----------------------------------------------------------------/ FUNCTIONS /
void		ScreenDisplay::render(void)
{
	if (!this->_current_screen)
		this->gameStart();
	else if (this->_current_screen == 1)
		this->gameRun();
	else
		this->gameOver();
}

void		ScreenDisplay::gameStart()
{
	this->setColor(GREEN);
	this->setFontStyle(A_BOLD);
	this->enableAttr();
	this->printInCenter("Game Start", 0);
	this->disableAttr();
	this->setColor(WHITE);
	this->enableAttr();
	this->printInCenter("< Press Enter > ", -2);
	this->setFontStyle(0);
	while (getch() != '\n');
	this->_current_screen = 1;
	nodelay(stdscr, true);	// wait for player input
	clear();
}

void		ScreenDisplay::renderGameBorders()
{
	v2	*cursor = new v2;
	std::string hor_bar(this->getScreenWH().x - 2, '-');
	cursor->y = 0;
	cursor->x = 0;
	this->printStrPosition("+", *cursor);
	cursor->x = this->getScreenWH().x - 1;
	this->printStrPosition("+", *cursor);
	cursor->x = 1;
	this->printStrPosition(hor_bar, *cursor);
	for (int i = 1; i < this->getScreenWH().y - 1 ; i++)
	{
		cursor->y = i;
		cursor->x = 0;
		this->printStrPosition("|", *cursor);
		cursor->x = this->getScreenWH().x - 1;
		this->printStrPosition("|", *cursor);
	}
	cursor->y = this->getScreenWH().y - 5;
	cursor->x = 0;
	this->printStrPosition("+", *cursor);
	cursor->x = this->getScreenWH().x - 1;
	this->printStrPosition("+", *cursor);
	cursor->x = 1;
	this->printStrPosition(hor_bar, *cursor);
	cursor->y = this->getScreenWH().y - 1;
	cursor->x = 0;
	this->printStrPosition("+", *cursor);
	cursor->x = this->getScreenWH().x - 1;
	this->printStrPosition("+", *cursor);
	cursor->x = 1;
	this->printStrPosition(hor_bar, *cursor);
	cursor->x = 30;
	cursor->y = this->getScreenWH().y - 1;
	this->printStrPosition("+", *cursor);
	cursor->y = this->getScreenWH().y - 2;
	this->printStrPosition("|", *cursor);
	cursor->y = this->getScreenWH().y - 3;
	this->printStrPosition("|", *cursor);
	cursor->y = this->getScreenWH().y - 4;
	this->printStrPosition("|", *cursor);
	cursor->y = this->getScreenWH().y - 5;
	this->printStrPosition("+", *cursor);
	delete cursor;
	this->_borders_drawn = 1;
}

void		ScreenDisplay::gameRun()
{
	v2	*cursor = new v2;
	std::string str;

	this->_frames_number++;
	this->renderGameBorders();
	cursor->y = this->getScreenWH().y - 3;
	cursor->x = 3;
	time((time_t *)(&g_curr_time));
	str = std::ctime((time_t *)(&g_curr_time));
	if (g_curr_time != this->_past_time)
	{
		g_frame_rate = (this->_frames_number + g_frame_rate) / 2;
		this->_frames_number = 0;
		this->_past_time = g_curr_time;
	}
	str.resize(30);
	this->printStrPosition(str, *cursor);
	cursor->x = 30;
	this->printStrPosition("|", *cursor);
	cursor->x = 35;
	this->printStrPosition("[Stats] ", *cursor);
	cursor->x = 48;
	this->setColor(RED);
	this->setFontStyle(A_BOLD);
	this->enableAttr();
	move(cursor->y, cursor->x);
	printw("COORD: %d - %d   Life: %d   FPS: %d", this->_player->getPosition().x, this->_player->getPosition().y, this->_player->getLife(), g_frame_rate);
	this->disableAttr();
	cursor->x = this->getScreenWH().x - 1;
	this->printStrPosition("|", *cursor);
	this->checkForEndConditions();
	delete cursor;
}

void		ScreenDisplay::checkForEndConditions()
{

	if (!this->_player->getLife())
	{
		this->_current_screen = 2;
			usleep(50000);
	}
}

void		ScreenDisplay::gameOver()
{
	clear();
	nodelay(stdscr, false);	// wait for player input
	this->setColor(RED);
	this->setFontStyle(A_BOLD);
	this->enableAttr();
	this->printInCenter("Game Over", 0);
	this->disableAttr();
	this->setColor(WHITE);
	this->enableAttr();
	this->printInCenter("< Press Enter > ", -2);
	this->setFontStyle(0);
	while (getch() != '\n');
	this->_current_screen = 1;
}

//-----------------------------------------------------------------/ OPERATORS /
ScreenDisplay &	ScreenDisplay::operator=(ScreenDisplay const & rhs)
{
	A_Printable::operator=(rhs);
	return *this;
}
//-------------------------------------------------------------/ OUTSIDE SCOPE /
