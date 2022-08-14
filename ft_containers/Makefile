CC			=	c++
CFLAGS		=	-std=c++98 #-Wall -Wextra -Werror 
NAME		=	prog

SRCS		=	main.cpp	\

all: $(NAME)

$(NAME): ft

run: ft
	./$(NAME)

ft:
	$(CC) -DFT -o $(NAME) $(SRCS)

std:
	$(CC) -DSTD -o $(NAME) $(SRCS)

test:
	./test.sh

# use "leaks -atExit -- ./$(NAME)" or "valgrind ./$(NAME)"
leaks: ft
	valgrind ./$(NAME)

clean:
	rm -rf $(NAME) test_ft.out test_std.out

fclean: clean

re: fclean all

.PHONY: all clean fclean re ft std test run
