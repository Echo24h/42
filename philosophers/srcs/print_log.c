#include "philo.h"

void	print_log(t_ctx *ctx, long time, int n, int action)
{
	long	timestamps;
	int		i;

	pthread_mutex_lock(&ctx->mutex_log);
	if (!ctx->end_simulation)
	{
		n += 1;
		timestamps = time_diff(ctx->t_start, time);
		if (action == TAKE_FORK)
			printf("%ld %d has taken a fork\n", timestamps, n);
		else if (action == EAT)
			printf("%ld %d is eating\n", timestamps, n);
		else if (action == SLEEP)
			printf("%ld %d is sleeping\n", timestamps, n);
		else if (action == THINK)
			printf("%ld %d is thinking\n", timestamps, n);
		else if (action == DIE)
			printf("%ld %d died\n", timestamps, n);
	}
	pthread_mutex_unlock(&ctx->mutex_log);
}
