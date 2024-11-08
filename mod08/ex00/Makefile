NAME	= easyfind

SRC 	= main.cpp

OBJ		= $(SRC:.cpp=.o)

CPP		= -c++ -std=c++98
CFLAGS	= -Werror -Wall -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Makefile easyfind.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
