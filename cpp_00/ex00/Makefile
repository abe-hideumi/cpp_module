
NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
# End Generation Here
clean:
	@rm -f $(OBJS)
	@echo ".o files have been removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable file has been removed"
re: fclean all

.PHONY: all clean fclean re
