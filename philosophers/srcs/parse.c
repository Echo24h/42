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
	ctx->end_simulation = 0;
	ctx->n = 0;
	ctx->t_start = 0;
	if (ctx->nb_philo != 0 && ctx->nb_meal_per_philo != 0)
	{
		ctx->philo = malloc(sizeof(char) * ctx->nb_philo);
		if (!ctx->philo)
			return (0);
		set_int_array(ctx->philo, NOT_READY, ctx->nb_philo);
	}
	return (1);
}