NAME =	fixedPoint

SRCS =	main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJS =	$(SRCS:.cpp=.o)

CXX =	clang++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJS) Fixed.hpp Makefile
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
