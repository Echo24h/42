CC			=	gcc
CFLAGS		=	
NAME		=	libftprintf.a
SRC_DIR		=	src
OBJ_DIR		=	src/obj
I_DIR		=	include

SRC			=	dev.c	\
				ft_printf.c \
				is_flag.c	\
				get_opts.c	\
				print_char.c	\
				print_str.c	\
				print_ptr.c	\
				print_int.c	\
				print_percentage.c	\
				print_uint.c	\
				print_hexa.c
				

SRC_BONUS	=	

OBJ				=	$(SRC:%.c=%.o)
OBJ_PFX			=	$(addprefix $(OBJ_DIR)/, $(OBJ))

OBJ_BONUS		=	$(SRC_BONUS:%.c=%.o)
OBJ_BONUS_PFX	=	$(addprefix $(OBJ_DIR)/, $(OBJ_BONUS))

all: $(NAME)

$(NAME): $(OBJ_PFX)
	cp lib/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ_PFX)

bonus: $(OBJ_BONUS_PFX)
	ar -rcs $(NAME) $(OBJ_BONUS_PFX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

run: all
	$(CC) -o run main.c -L. -lftprintf -I$(I_DIR)
	./run
	@rm -f run

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus run