NAME = Bureaucrat

SRCS = main.cpp Bureaucrat.cpp Form.cpp

INC = Bureaucrat.hpp Form.hpp

OBJS = $(addprefix $(DIR_OBJS)/, $(SRCS:.cpp=.o))

DIR_OBJS = .obj

CXX = c++ -std=c++98

CXXFLAGS = -Wall -Wextra -Werror 

all: $(DIR_OBJS) $(NAME)

$(NAME): $(OBJS) 
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo $@ fet

$(DIR_OBJS):	
	@mkdir -p $(DIR_OBJS)

$(DIR_OBJS)/%.o : %.cpp $(INC) Makefile
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo $< a $@

clean:
	@rm -rf $(DIR_OBJS)
	@echo $@

fclean: clean
	@rm -rf $(NAME)
	@echo $@

re: fclean all
