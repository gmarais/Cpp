// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 18:58:02 by gmarais           #+#    #+#             //
//   Updated: 2015/01/10 18:58:02 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <ncurses.h>

int		main()
{
	int x, y;
	WINDOW	*win;
	std::string	str = "Hello world!";

	initscr();								// init the screen
	curs_set(0);							// hide the cursor
	nodelay(stdscr, true);					// wait for player input
	keypad(stdscr, true);					// enable use of arrowkeys etc
	noecho(); 								// dont show chat playe typed on the cursor location
	getch();								// basic function to get a player character input
	start_color();							// enables use of colors
	init_pair(1, COLOR_RED, 0);				// create a coor attribute to be enabled later
	attron(COLOR_PAIR(1));					// enable an attribute
	getmaxyx(stdscr, y, x);					// get the window Y/X
	move(y/2,x/2 - str.length() / 2);		// Move the cursor
	printw(str.c_str());					// printw like printf bot for screen
	attroff(COLOR_PAIR(1));					// disable attribute
	refresh();								// refresh the window
	endwin();								// end & free screen
	return 0;
}
