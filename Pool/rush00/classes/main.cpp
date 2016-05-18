// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/10 18:58:02 by gmarais           #+#    #+#             //
//   Updated: 2015/01/18 21:42:39 by gmarais          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#include "Tools.hpp"
#include "A_Player.hpp"
#include "A_Enemy.hpp"
#include "A_Ship.hpp"
#include "A_Projectile.hpp"
#include "A_Movable.hpp"
#include "A_Physical.hpp"
#include "A_Shape.hpp"
#include "A_Printable.hpp"
#include "KeyHook.hpp"
#include "ScreenDisplay.hpp"
#include "A_Squad.hpp"

clock_t g_frame_rate = 100;
clock_t g_curr_time = 0;

int		main(void)
{
 	ScreenDisplay	screen;
 	KeyHook			*keyhook;
 	A_Player		*player;
 	A_Squad			*players;
 	A_Projectile	*proj;
 	t_rows			*rows = new t_rows[4]();
	t_row			p1;
	t_row			p2;
	t_row			p3;
	t_row			e1;
	t_row			e2;
	t_row			e3;
 	t_rows			*player_shape = new t_rows[4]();
 	v2				fake_pos;
 	v2				player_pos;
 	v2				weapon;
	SquadLink		*tmp;

 	player_shape[0] = &p1;
 	player_shape[1] = &p2;
 	player_shape[2] = &p3;
 	player_shape[0]->data = "/\\-";
 	player_shape[1]->data = "] - D";
 	player_shape[2]->data= "\\/-";
 	player_shape[0]->indent = 2;
 	player_shape[1]->indent = 0;
 	player_shape[2]->indent = 2;
 	weapon.x = 3;
 	weapon.y = 0;
 	fake_pos.x = -1;
 	fake_pos.y = -1;
 	player_pos.x = screen.getScreenWH().x / 2;
 	player_pos.y = screen.getScreenWH().y / 2;
	rows[0] = &e1;
	rows[1] = &e2;
	rows[2] = &e3;
 	rows[0]->data = "o";
 	rows[1]->data = "";
 	rows[2]->data = "o";
 	rows[0]->indent = 0;
 	rows[1]->indent = 0;
 	rows[2]->indent = 0;
 	std::string		str = "Bob";
 	std::string		str2 = "Benoit";

  	screen.render();
  	players = new A_Squad();
  	proj = new A_Projectile(str2, 2, 3, 1, rows, RED, fake_pos, 0);
  	player = new A_Player(str, 10, proj, players, weapon, GREEN, 0.25, 3, 3, player_shape, GREEN, player_pos, 0.05);
  	keyhook	= new KeyHook(player, &screen);
  	screen.setPlayer(player);
  	while (screen.getCurrentScreen() != 2)
 	{
  		screen.render();
  		keyhook->resolveKey();
		tmp = players->getShips();
		while (tmp)
		{
			((A_Player *)(tmp->curr))->fire();
			((A_Player *)(tmp->curr))->move();
			tmp->curr->render();
			tmp = tmp->next;
		}
		tmp = players->getProjectiles();
		while (tmp)
		{
			((A_Projectile *)(tmp->curr))->move();
			tmp->curr->render();
			tmp = tmp->next;
		}
  		refresh();
		usleep(10000);
		clear();
  	}
  	delete keyhook;
  	delete player;
  	screen.render();
  	endwin();
	return 0;
}

// ENEMY
//enemy_shape[0]->data = "-/|";
//enemy_shape[1]->data = "(c (";
//enemy_shape[2]->data = "-\\|";
//enemy_shape[0]->indent = 0;
//enemy_shape[1]->indent = 0;
//enemy_shape[2]->indent = 0;
