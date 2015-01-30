
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror
LDFLAGS =
CXXFLAGS += -I./ -I./classes -I./interfaces

NAME = {ExecName}
SRC = {sources}

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
