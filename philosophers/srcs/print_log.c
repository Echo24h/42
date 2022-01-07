#include "philo.h"

void	print_log(t_ctx *ctx, long time, int n, int action)
{
	pthread_mutex_lock(&ctx->lock_print);
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
	pthread_mutex_unlock(&ctx->lock_print);
}
