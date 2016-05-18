#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 21:07:10 by gmarais           #+#    #+#              #
#    Updated: 2015/01/14 11:47:38 by gmarais          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = iter

SRC = iter.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: all
all: $(NAME)

$(NAME) : $(OBJ)
	@g++ -o $(NAME) $(OBJ)
	@echo "\033[1;32mfile $(NAME) created.\033[0m"

$(OBJ) : $(SRC)
	@g++ -Wall -Wextra -Werror -c $?

.PHONY: clean
clean:
	@rm -f $(OBJ)
	@echo "\033[1;31mObjects removed.\033[0m"

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;31mfile $(NAME) removed.\033[0m"

.PHONY: re
re: fclean all
