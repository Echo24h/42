CC			=	gcc
CFLAGS		=	#-Wall -Wextra -Werror
NAME		=	minitalk
SERVER		=	server
CLIENT		=	client
SRC_DIR		=	srcs
OBJ_DIR		=	srcs/objs
I_DIR		=	includes
L_DIR		=	libs

SRC			=	utils.c
SRC_PFX		=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ			=	$(SRC:%.c=%.o)
OBJ_PFX		=	$(addprefix $(OBJ_DIR)/, $(OBJ))

SRC_SRV		=	server.c
OBJ_SRV		=	$(SRC_SRV:%.c=%.o)
OBJ_SRV_PFX	=	$(addprefix $(OBJ_DIR)/, $(OBJ_SRV))

SRC_CLIENT		=	client.c
OBJ_CLIENT		=	$(SRC_CLIENT:%.c=%.o)
OBJ_CLIENT_PFX	=	$(addprefix $(OBJ_DIR)/, $(OBJ_CLIENT))

all: $(NAME)

$(NAME): $(L_DIR)/libft.a $(OBJ_PFX) $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SRV_PFX)
	$(CC) -o $(SERVER) $(OBJ_SRV_PFX) $(OBJ_PFX) -L$(L_DIR) -lft -I$(I_DIR)

$(CLIENT): $(OBJ_CLIENT_PFX)
	$(CC) -o $(CLIENT) $(OBJ_CLIENT_PFX) $(OBJ_PFX) -L$(L_DIR) -lft -I$(I_DIR)

$(L_DIR)/libft.a:
	make -C $(L_DIR)/libft
	cp -f $(L_DIR)/libft/libft.a $(L_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(I_DIR)

run: all
	./server

clean:
	make clean -C $(L_DIR)/libft
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(L_DIR)/libft
	rm -f $(L_DIR)/libft.a
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re $(NAME)