NAME = Bureaucrat

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

INC = Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp

OBJS = $(addprefix $(DIR_OBJS)/, $(SRCS:.cpp=.o))

DIR_OBJS = .obj

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

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
