#ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
#ARG=`ruby -e 'min=1; max=10; A = Array(min..max); A.shuffle.each{ |n| print "#{n} "}'`; ./push_swap $ARG | ./checker_Mac $ARG
#`ruby -e 'min=1; max=10; A = Array(min..max); A.shuffle.each{ |n| print "#{n} "}'`

CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror
NAME		=	push_swap
I_DIR		=	includes
L_DIR		=	libs
LIBS		=	-lft

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

OBJS		=	$(SRCS:%.c=%.o)

all: $(NAME)

$(L_DIR)/libft.a:
	make bonus -C $(L_DIR)/libft
	cp -f $(L_DIR)/libft/libft.a $(L_DIR)

$(NAME): $(OBJS) $(L_DIR)/libft.a
	$(CC) -o $(NAME) $(OBJS) -I$(I_DIR) -L$(L_DIR) $(LIBS)

average: all
	./get_average.sh
	$(CC) -o print_average srcs/print_average.c -L$(L_DIR) $(LIBS) -I$(I_DIR)
	./print_average

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

clean:
	make clean -C $(L_DIR)/libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(L_DIR)/libft
	rm -f $(L_DIR)/libft.a 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re average