CC		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror
NAME	=	fractol
I_DIR	=	include
L_DIR	=	lib
LIB		=	-lmlx

SRC		=	src/main.c	\
			src/cplx.c	\
			src/hooks.c	\
			src/events.c	\
			src/rgb.c	\

OBJ		=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -I$(I_DIR) -L$(L_DIR) $(LIB) -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

run: re
	make clean && ./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm  -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re