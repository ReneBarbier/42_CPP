NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Compiled $@"

clean:
	@rm -f $(OBJ)
	@echo "Cleaned up object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned up binary files"

re: fclean all

.PHONY: all clean fclean re