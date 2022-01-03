CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	push_swap
I_DIR		=	includes
SRCS_DIR	=	srcs
OBJS_DIR	=	srcs/objs

SRCS		=	main.c	\
				parsing.c	\
				swap.c	\
				push.c	\
				rotate.c	\
				reverse_rotate.c	\
				utils_0.c	\
				utils_1.c	\
				dev.c	\
				sorts.c	\
				quick_sort.c	\
				free.c	\
				handle_first_b_chunk.c	\
				mid_point_a_to_b.c	\

SRCS_PFX	=	$(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS		=	$(SRCS:%.c=%.o)
OBJS_PFX	=	$(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME)

libft/libft.a:
	make -C libft

$(NAME): libft/libft.a $(OBJS_PFX)
	$(CC) -o $(NAME) $(OBJS_PFX) -I$(I_DIR) -Llibft -lft

average: all
	./get_average.sh
	$(CC) -o print_average print_average.c -Llibft -lft -I$(I_DIR)
	./print_average
	@rm -f print_average results_3.txt results_5.txt results_100.txt results_500.txt

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

clean:
	make clean -C libft
	rm -rf $(OBJS_DIR)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re average