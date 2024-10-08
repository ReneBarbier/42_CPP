NAME = Bureaucrat

SRCS = main.cpp Bureaucrat.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = -c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJS) Bureaucrat.hpp Makefile
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
