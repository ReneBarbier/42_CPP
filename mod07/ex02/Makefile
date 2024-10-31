NAME	= Array

SRC 	= main.cpp
OBJ		= $(SRC:.cpp=.o)

CXX		= -c++ -std=c++98
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Array.hpp Makefile
	$(CXX) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
