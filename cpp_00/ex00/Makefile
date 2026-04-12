
NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RED = \033[31m
YELLOW = \033[33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	@echo "$(YELLOW)[Clean]$(RESET) Remove object files..."
	@rm -f $(OBJS)

fclean:
	@echo "$(RED)[Fclean]$(RESET) Remove all build artifacts..."
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
