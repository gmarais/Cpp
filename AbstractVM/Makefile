# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/29 20:39:09 by gmarais           #+#    #+#              #
#    Updated: 2015/01/29 20:39:09 by gmarais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror
LDFLAGS =
CXXFLAGS += -I./ -I./classes -I./interfaces

NAME = avm
SRC = main.cpp \
split.cpp \
classes/AbstractVM.cpp \
classes/OperandFactory.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ $(LDFLAGS)
	@echo "\033[1;32m$(NAME) created!\033[0;0m";

clean:
	@rm -f $(OBJ)
	@echo "\033[1;31m$(NAME) objects removed!\033[0;0m";

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31m$(NAME) executable removed!\033[0;0m";

re: fclean all
