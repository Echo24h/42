CC			=	c++
CFLAGS		=	-std=c++98 -Wall -Wextra -Werror 
NAME		=	prog

SRCS		=	main.cpp	\

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

run: re
	./$(NAME)

debug: re
	$(CC) $(CFLAGS) -g -o $(NAME) $(SRCS)

# use "leaks -atExit -- ./$(NAME)" or "valgrind ./$(NAME)"
leaks: re
	valgrind ./$(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re debug run
