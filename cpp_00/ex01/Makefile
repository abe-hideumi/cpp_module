
NAME = phonebook

SRCS = main.cpp\
		command.cpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

RED = \033[31m
YELLOW = \033[33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(CPPFLAGS) -o $@ $^

clean:
	@echo "$(YELLOW)[Clean]$(RESET) Remove object files..."
	@rm -f $(OBJS)

fclean:
	@echo "$(RED)[Fclean]$(RESET) Remove all build artifacts..."
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
