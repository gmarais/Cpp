# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brandazz <brandazz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/17 14:32:37 by brandazz          #+#    #+#              #
#    Updated: 2015/01/18 19:48:31 by gmarais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/usr/X11/lib -lXext -lX11 -lncurses

CXXFLAGS += -I./ -I./classes -I./interfaces -I/usr/X11/include

NAME = ft_gkrellm

SRC = main.cpp							\
	  tools.cpp							\
	  interfaces/interfaces.cpp			\
	  classes/MonitorController.cpp		\
	  classes/HostnameModule.cpp		\
	  classes/OSInfoModule.cpp			\
	  classes/DateModule.cpp			\
	  classes/CPUModule.cpp				\
	  classes/RamModule.cpp				\
	  classes/XMonitorDisplay.cpp		\
	  classes/NCursesMonitorDisplay.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDFLAGS)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
