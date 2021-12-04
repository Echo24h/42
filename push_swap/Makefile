CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror
NAME		=	push_swap
I_DIR		=	includes
L_DIR		=	libs
LIBS		=	-lft

SRCS		=	srcs/main.c	\
				srcs/dev.c	\

OBJS		=	$(SRCS:%.c=%.o)

all: $(NAME)

$(L_DIR)/libft.a:
	make bonus -C $(L_DIR)/libft
	cp -f $(L_DIR)/libft/libft.a $(L_DIR)

$(NAME): $(OBJS) $(L_DIR)/libft.a
	$(CC) -o $(NAME) $(OBJS) -I$(I_DIR) -L$(L_DIR) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

run: all
	./$(NAME) "1 5 8 9 2 4"

clean:
	make clean -C $(L_DIR)/libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(L_DIR)/libft
	rm -f $(L_DIR)/libft.a 
	rm -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re