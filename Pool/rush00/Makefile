#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 21:07:10 by gmarais           #+#    #+#              #
#    Updated: 2015/01/12 00:20:42 by cdescat          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_retro

SRCSDIR = classes/

SRCS = main.cpp \
	ScreenDisplay.cpp \
	A_Printable.cpp \
	A_Enemy.cpp \
	A_Movable.cpp \
	A_Physical.cpp \
	A_Player.cpp \
	A_Printable.cpp \
	A_Projectile.cpp \
	A_Shape.cpp \
	A_Ship.cpp \
	A_Squad.cpp \
	KeyHook.cpp \
	ScreenDisplay.cpp

OBJSDIR = bins/

OBJS = $(addprefix $(OBJSDIR), $(SRCS:%.cpp=%.o))

CXX = g++

LINKS = -lncurses

FLAGS = -g -Wall -Wextra -Werror -I interfaces -I includes

.PHONY: all clean fclean re

all: $(OBJSDIR) $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) -o $(NAME) $^  $(LINKS)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(OBJSDIR)%.o: $(SRCSDIR)%.cpp
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
