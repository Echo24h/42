CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror
NAME		=	push_swap
I_DIR		=	includes

SRCS		=	srcs/main.c	\
				srcs/parsing.c	\
				srcs/swap.c	\
				srcs/push.c	\
				srcs/rotate.c	\
				srcs/reverse_rotate.c	\
				srcs/utils_0.c	\
				srcs/utils_1.c	\
				srcs/dev.c	\
				srcs/sorts.c	\
				srcs/quick_sort.c	\

OBJS		=	$(SRCS:%.c=%.o)

all: $(NAME)

libft/libft.a:
	make -C libft

$(NAME): libft/libft.a $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -I$(I_DIR) -Llibft -lft

average: all
	./get_average.sh
	$(CC) -o print_average srcs/print_average.c -Llibft -lft -I$(I_DIR)
	./print_average
	@rm -f print_average

20: all
	./$(NAME) `ruby -e "puts (0..19).to_a.shuffle.join(' ')"`

21: all
	./$(NAME) `ruby -e "puts (0..20).to_a.shuffle.join(' ')"`

100: all
	./$(NAME) `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`

500: all
	./$(NAME) `ruby -e "puts (0..499).to_a.shuffle.join(' ')"`

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re average 20 21 100 500