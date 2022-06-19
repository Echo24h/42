CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
NAME		=	convert

SRCS		=	main.cpp	\

OBJS		=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

run: re
	./$(NAME) 12

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
