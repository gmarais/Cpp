#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 21:05:38 by gmarais           #+#    #+#              #
#    Updated: 2015/01/05 21:05:43 by gmarais          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = satanfoes

#INCLUDES =

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

.PHONY: all
all: $(NAME)
$(NAME) : $(SRC)
	@g++ -g -Wall -Wextra -Werror -c $? #-I $(INCLUDES)
	@g++ -g -o $(NAME) $(OBJ)
	@echo "\033[1;32mfile $(NAME) created.\033[0m"

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
