NAME = ClassIdentifier

SRCS = main.cpp Base.cpp

OBJS = $(SRCS:.cpp=.o)

XX = -c++ -std=c++98

CXXFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp Base.hpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
