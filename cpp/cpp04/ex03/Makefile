CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
NAME		=	prog

SRCS		=	main.cpp	\
				AMateria.cpp	\
				Cure.cpp	\
				Ice.cpp	\
				MateriaSource.cpp	\
				Character.cpp	\

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
