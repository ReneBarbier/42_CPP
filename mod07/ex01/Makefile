NAME = iter

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

CXX = -clang++ -std=c++98

CXXFLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
