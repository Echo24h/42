#include "philo.h"

void	print_log(t_ctx *ctx, long time, int n, int action)
{
	int	i;

	pthread_mutex_lock(&ctx->mutex_log);
	if (!ctx->end_simulation)
	{
		if (action == TAKE_FORK)
			printf("%ld %d has taken a fork\n", time, n);
		else if (action == EAT)
			printf("%ld %d is eating\n", time, n);
		else if (action == SLEEP)
			printf("%ld %d is sleeping\n", time, n);
		else if (action == THINK)
			printf("%ld %d is thinking\n", time, n);
		else if (action == DIE)
			printf("%ld %d died\n", time, n);
		/*
		i = 0;
		while (i < ctx->nb_philo)
			printf("%d ", ctx->philo[i++]);
		printf("\n");
		*/
	}
	pthread_mutex_unlock(&ctx->mutex_log);
}
