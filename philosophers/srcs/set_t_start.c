#include "philo.h"

void	set_t_start(t_ctx *ctx)
{
	pthread_mutex_lock(&ctx->mutex_random);
	if (!ctx->t_start)
		ctx->t_start = get_time();
	pthread_mutex_unlock(&ctx->mutex_random);
}
