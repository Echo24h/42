#include "philo.h"

void	destroy_mutex(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->nb_philo)
	{
		pthread_mutex_destroy(&ctx->mutex_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&ctx->mutex_log);
	pthread_mutex_destroy(&ctx->mutex_random);
}
