// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScreenDisplay.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 04:54:51 by gmarais           #+#    #+#             //
//   Updated: 2015/01/11 20:46:47 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _ScreenDisplay_CLASS_
# define _ScreenDisplay_CLASS_

# include <iostream>
# include <ncurses.h>
# include <ctime>
# include <unistd.h>
# include "Tools.hpp"
# include "A_Printable.hpp"
# include "A_Player.hpp"
# include <stdlib.h>
# include <stdio.h>

class	ScreenDisplay : public A_Printable
{
private:
//---------------------------------------------------------/ PRIVATE VARIABLES /
	bool		_borders_drawn;
	int			_current_screen;
	clock_t		_past_time;
	int			_player_life;
	A_Player	*_player;
	int			_frames_number;
//---------------------------------------------------------/ PRIVATE FUNCTIONS /
	void		renderGameBorders();
	int			setCurrentScreen(int id_screen);
	void		checkForEndConditions();

public:
//----------------------------------------------------------/ PUBLIC VARIABLES /
//------------------------------------------------------/ CONSTRUCT & DESTRUCT /
	ScreenDisplay();
	ScreenDisplay(ScreenDisplay const & src);
	~ScreenDisplay();
//---------------------------------------------------------/ GETTERS & SETTERS /
	int				getCurrentScreen() const;
	void			setPlayer(A_Player *player);
//----------------------------------------------------------/ PUBLIC FUNCTIONS /
	virtual void	render(void);
	void			gameStart();
	void			gameOver();
	void			gameRun();
//-----------------------------------------------------------------/ OPERATORS /
	ScreenDisplay &	operator=(ScreenDisplay const & rhs);

};

#endif
