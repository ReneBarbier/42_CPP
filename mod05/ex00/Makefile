NAME = Bureaucrat

SRCS = main.cpp Bureaucrat.cpp

INC = Bureaucrat.hpp

OBJS = $(addprefix $(DIR_OBJS)/, $(SRCS:.cpp=.o))

DIR_OBJS = .obj

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror 

all: $(DIR_OBJS) $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)

$(DIR_OBJS)/%.o : %.cpp $(INC) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -fr $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
