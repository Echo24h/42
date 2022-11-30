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

re:
	@printf "Rebuild configuration ${NAME}...\n"
	@docker-compose --env-file ./srcs/.env -f ./srcs/docker-compose.yml up -d --build

clean: down
	@printf "Cleaning configuration ${NAME}...\n"
	@docker system prune -a
	@sudo rm -rf ~/data/wordpress/*
	@sudo rm -rf ~/data/mariadb/*

fclean:
	@printf "Total clean of all configurations docker\n"
	@docker stop $$(docker ps -qa)
	@docker system prune --all --force --volumes
	@docker network prune --force
	@docker volume prune --force
	@sudo rm -rf ~/data/wordpress/*
	@sudo rm -rf ~/data/mariadb/*

.PHONY : all build down re clean fclean
