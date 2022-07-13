CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
NAME		=	zombiiieee

SRCS		=	main.cpp	\
				Zombie.cpp	\
				newZombie.cpp	\
				randomChump.cpp	\

OBJS		=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

run: re
	./$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re