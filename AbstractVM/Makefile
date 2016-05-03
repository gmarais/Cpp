# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/29 20:39:09 by gmarais           #+#    #+#              #
#    Updated: 2015/03/25 17:00:57 by gmarais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror
LDFLAGS =
CXXFLAGS += -I./ -I./headers -I./headers/operands

NAME = avm
SRC = main.cpp \
sources/Tools.cpp \
sources/Exception.cpp \
sources/Command.cpp \
sources/AbstractVM.cpp \
sources/Int8.cpp \
sources/Int16.cpp \
sources/Int32.cpp \
sources/Float.cpp \
sources/Double.cpp \
sources/OperandFactory.cpp

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
