CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror
NAME		=	minishell
SRC_DIR		=	srcs
OBJ_DIR		=	srcs/objs
I_DIR		=	includes

SRC			=	main.c	\
				expand.c
SRC_PFX		=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ			=	$(SRC:%.c=%.o)
OBJ_PFX		=	$(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_PFX)
	make -C libft
	$(CC) -o $(NAME) $(OBJ_PFX) -lncurses -lreadline -Llibft -lft

debug: $(OBJ_PFX)
	make -C libft
	$(CC) -g -o $(NAME)-debug $(SRC_PFX) -lncurses -lreadline -Llibft -lft -I$(I_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(I_DIR) -o $@ -c $<

run: all
	./$(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re run
