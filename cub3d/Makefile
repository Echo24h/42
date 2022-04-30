# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 04:39:29 by jbettini          #+#    #+#              #
#    Updated: 2022/04/07 01:20:14 by jbettini         ###   ########.fr        #
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

# IF NEEDED at 42 on MacOS10 Install :
#  rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update
#  brew install readline
#LIBS	=	-L/Users/$(USER)/.brew/opt/readline/lib -lreadline -Llibft -lft
#HEADERS	=	-I$(I_DIR) -I/Users/$(USER)/.brew/opt/readline/include

# @HOME on MacOS12 Monterey
LIBS	=	-Llibft -lft
HEADERS	=	-I$(I_DIR) -Ilibft/includes

SRC	= 	main.c \

OBJ	=	$(SRC:%.c=%.o)

OBJ_PFX = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME): $(OBJ_PFX)
	@make -C libft
	@printf $(BLUE)
	$(CC) -o $(NAME) $(OBJ_PFX) $(LIBS)
	@printf $(NC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf $(CYAN)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@printf $(NC)

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