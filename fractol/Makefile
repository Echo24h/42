CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	fractol
I_DIR	=	include
L_DIR	=	lib
LIB		=	-lmlx -lft

SRC		=	src/main.c	\
			src/hooks.c	\
			src/events_0.c	\
			src/events_1.c	\
			src/palette.c	\
			src/palettes_0.c	\
			src/palettes_1.c	\
			src/utils.c	\
			src/fractals.c	\
			src/draw_fractal.c	\
			src/get_limits.c	\
			src/initialisation.c	\
			src/parsing.c	\
			src/put_pixel.c	\

OBJ		=	$(SRC:%.c=%.o)

all: $(L_DIR)/libft.a $(L_DIR)/libmlx.a $(NAME)

$(L_DIR)/libft.a:
	make bonus -C $(L_DIR)/libft
	cp -f $(L_DIR)/libft/libft.a $(L_DIR)

$(L_DIR)/libmlx.a:
	make -C $(L_DIR)/minilibx
	cp -f $(L_DIR)/minilibx/libmlx.a $(L_DIR)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -I$(I_DIR) -L$(L_DIR) $(LIB) -framework OpenGL -framework AppKit

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

run: re
	make clean && ./$(NAME) mandelbrot

clean:
	make clean -C $(L_DIR)/libft
	make clean -C $(L_DIR)/minilibx
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(L_DIR)/libft
	rm -f $(L_DIR)/libft.a $(L_DIR)/libmlx.a
	rm  -f $(NAME)

re: fclean all

.PHONY: all run clean fclean re make_libft make_mlx