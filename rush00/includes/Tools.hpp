// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Tools.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: cdescat <cdescat@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/11 02:33:00 by cdescat           #+#    #+#             //
//   Updated: 2015/01/11 19:20:45 by cdescat          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _TOOLS_
# define _TOOLS_

# include <iostream>
# include <time.h>

typedef struct	s_v2
{
	int			x;
	int 		y;
}				v2;

typedef struct	s_row
{
	std::string	data;
	int			indent;
}				t_row;

typedef t_row	*t_rows;

extern clock_t g_frame_rate;
extern clock_t g_curr_time;

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

#endif
