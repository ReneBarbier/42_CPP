NAME = Span

SRC = main.cpp Span.cpp

OBJ = $(SRC:.cpp=.o)

CPP= -c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Makefile Span.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: all clean fclean re
