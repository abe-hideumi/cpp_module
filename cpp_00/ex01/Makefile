
NAME = phonebook

SRCS = main.cpp\
		utils.cpp\
		contact.cpp\
		phonebook.cpp\

OBJS = $(SRCS:.cpp=.o)

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

RED = \033[31m
YELLOW = \033[33m
GREEN = \033[32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(GREEN)[Build]$(RESET) Successfully built $(NAME)"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW)[Clean]$(RESET) Remove object files..."

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@echo "$(RED)[Fclean]$(RESET) Remove all build artifacts..."

re: fclean all

.PHONY: all clean fclean re
