#include "philo.h"

int	parse(int ac, char **av, t_ctx *ctx)
{
	if (ac != 5 && ac != 6)
		return (0);
	ctx->nb_philo = ft_atoi(av[1]);
	ctx->t_death = ft_atoi(av[2]);
	ctx->t_eat = ft_atoi(av[3]);
	ctx->t_sleep = ft_atoi(av[4]);
	ctx->nb_meal_per_philo = -1;
	if (ac == 6)
		ctx->nb_meal_per_philo = ft_atoi(av[5]);
	
	// check if prec. values produce errors
	ctx->forks = malloc(sizeof(char) * ctx->nb_philo);
	if (!ctx->forks)
		return (on_error(0));
	memset(ctx->forks, AVAILABLE, ctx->nb_philo);
	ctx->philo = malloc(sizeof(char) * ctx->nb_philo);
	if (!ctx->philo)
		return (on_error(0));
	memset(ctx->philo, NOT_READY, ctx->nb_philo);
	ctx->stop = 0;
	ctx->n = 1;
	return (1);
}