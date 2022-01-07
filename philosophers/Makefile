CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror
NAME		=	philo
SRC_DIR		=	srcs
OBJ_DIR		=	srcs/objs
I_DIR		=	includes

SRC			=	main.c	\
				dev.c	\
				on_error.c	\
				parse.c	\
				print_log.c	\
				time.c	\
				utils_0.c	\
				utils_1.c	\
				msleep.c
SRC_PFX		=	$(addprefix $(SRC_DIR)/, $(SRC))

OBJ			=	$(SRC:%.c=%.o)
OBJ_PFX		=	$(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_PFX)
	$(CC) -o $(NAME) $(OBJ_PFX) -pthread

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR) -pthread

run: all
	./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run