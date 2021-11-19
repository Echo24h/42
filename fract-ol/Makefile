CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	fract-ol
I_DIR	=	include
L_DIR	=	lib
LIB		=	-lmlx

SRC		=	src/main.c	\

OBJ		=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -I$(I_DIR) -L$(L_DIR) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

run: all
	./$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm  -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re