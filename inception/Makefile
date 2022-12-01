NAME = inception
all:
	@printf "Launch configuration ${NAME}...\n"
	@docker-compose --env-file ./srcs/.env -f ./srcs/docker-compose.yml up -d

build:
	@printf "Building configuration ${NAME}...\n"a
	@docker-compose --env-file ./srcs/.env -f ./srcs/docker-compose.yml up -d --build

down:
	@printf "Stopping configuration ${NAME}...\n"
	@docker-compose --env-file ./srcs/.env -f ./srcs/docker-compose.yml down

re: down build

clean: down
	@printf "Cleaning configuration ${NAME}...\n"
	@docker system prune -a

fclean: clean
	@printf "Deleting wordpress and mariadb data\n"
	@sudo rm -rf ~/data/wordpress/*
	@sudo rm -rf ~/data/mariadb/*

.PHONY : all build down re clean fclean
