NAME = ClassIdentifier

SRCS = main.cpp Base.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = -clang++ -std=c++98

CXXFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

PHONY: all clean fclean re
