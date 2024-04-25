NAME = DogsAndCats

SRCS = AAnimal.cpp Dog.cpp Cat.cpp main.cpp Brain.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -Werror -Wextra -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJS) AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp Makefile
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re