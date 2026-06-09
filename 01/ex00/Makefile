NAME = Zombie

SRCS = main.cpp\
		newZombie.cpp\
		randomChump.cpp\
		Zombie.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

# Colors
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
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

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[Fclean]$(RESET) Remove all build artifacts..."

re: fclean all

.PHONY: all clean fclean re
