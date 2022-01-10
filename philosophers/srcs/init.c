#include "philo.h"

void	init_status(t_ctx *ctx, t_status *status)
{
	status->next_action = TAKE_FORKS;
	pthread_mutex_lock(&ctx->mutex_random);
	status->n = ctx->n;
	status->right_fork = status->n;
	status->left_fork = (status->n + 1) % ctx->nb_philo;
	ctx->philo[ctx->n] = READY;
	ctx->n += 1;
	pthread_mutex_unlock(&ctx->mutex_random);
}

int	init_mutex(t_ctx *ctx)
{
	int	i;

	ctx->mutex_forks = malloc(sizeof(pthread_mutex_t) * ctx->nb_philo);
	if (!ctx->mutex_forks)
		return (0);
	i = 0;
	while (i < ctx->nb_philo)
	{
		if (pthread_mutex_init(&ctx->mutex_forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&ctx->mutex_log, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&ctx->mutex_random, NULL) != 0)
		return (0);
	return (1);
}
