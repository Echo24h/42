CC			=	gcc
CFLAGS		=	
NAME		=	libftprintf.a
SRC_DIR		=	src
OBJ_DIR		=	src/obj
I_DIR		=	include

SRC			=	ft_printf.c \
				is_flag.c	\
				get_opts.c	\
				print_char.c	\
				print_str.c	\
				print_ptr.c	\
				print_int.c	\
				print_percentage.c	\
				print_uint.c	\
				print_hexa.c

OBJ				=	$(SRC:%.c=%.o)
OBJ_PFX			=	$(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

libft/libft.a:
	make -C libft bonus

$(NAME): libft/libft.a $(OBJ_PFX)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ_PFX)

bonus: all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

run: all
	$(CC) -o run main.c -L. -lftprintf -I$(I_DIR)
	./run
	@rm -f run

clean:
	make -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C libft fclean
	rm -f $(NAME) && rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus run make_libft