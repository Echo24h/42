CC			=	c++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror
NAME		=	elonIcanHelp

SRCS		=	tests.cpp	\
				Account.cpp	\

OBJS		=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

run: re
	./$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re