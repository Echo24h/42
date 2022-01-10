#include "philo.h"

int	everyone_is_ready(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->nb_philo)
	{
		if (ctx->philo[i] == NOT_READY)
			return (0);
		i++;
	}
	return (1);
}

int	everyone_is_happy(t_ctx *ctx)
{
	int	i;

	if (ctx->nb_meal_per_philo == -1)
		return (0);
	i = 0;
	while (i < ctx->nb_philo)
	{
		if (ctx->philo[i] < ctx->nb_meal_per_philo)
			return (0);
		i++;
	}
	return (1);
}
