# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 04:39:29 by jbettini          #+#    #+#              #
#    Updated: 2022/06/01 13:05:25 by jbettini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC		=	"\033[0m"	# NO COLOR
BLACK	=	"\033[0;30m"   
RED		=	"\033[0;31m"
GREEN	=	"\033[0;32m"     
YELLOW	=	"\033[0;33m"
BLUE	=	"\033[0;34m"
CYAN	=	"\033[0;36m"

CC		=	gcc
CFLAGS	=	-g #-Wall -Wextra -Werror
NAME	=	cub3d
I_DIR	=	includes
SRC_DIR =	srcs
OBJ_DIR =	srcs/objs

LIBS	=	-Llibft -lft -Lminilibx -lmlx
HEADERS	=	-I$(I_DIR) -Ilibft/includes -Iminilibx

SRC	= 	main.c \
		draw_minimap.c \
		draw_game.c \
		draw.c \
		init.c \
		init_2.c \
		parse_file_2.c \
		parse_file.c \
		parse_map.c \
		parse_map_2.c \
		parse_map_3.c \
		parse_textures.c \
		parse_textures_2.c \
		parse_utils.c \
		parse.c \
		print_error.c \
		set_hooks_2.c \
		set_hooks.c \
		time.c \
		utils.c \
		vec2_0.c \
		vec2_1.c \
		get_wall_dist.c	\

OBJ	=	$(SRC:%.c=%.o)

OBJ_PFX = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_PFX)
	@make -j -C libft
	@printf $(BLUE)
	$(CC) -o $(NAME) $(OBJ_PFX) $(LIBS) -framework OpenGL -framework AppKit
	@printf $(NC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf $(CYAN)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@printf $(NC)

run: all
	./$(NAME) maps/map_0.cub

clean:
	@make clean -C libft
	@printf $(YELLOW)
	rm -rf $(OBJ_DIR)
	@printf $(NC)

fclean: clean
	@make fclean -C libft
	@printf $(YELLOW)
	rm -rf $(NAME)
	@printf $(NC)

re: fclean all

.PHONY: all run clean fclean re