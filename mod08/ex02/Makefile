NAME = Mutant

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

CPP = -c++ -std=c++98

CFLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $ Makefile MutantStack.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
