#include "philo.h"

void	print_ctx(t_ctx *ctx)
{
	printf("%d\n", ctx->nb_philo);
	printf("%ld\n", ctx->t_death);
	printf("%ld\n", ctx->t_eat);
	printf("%ld\n", ctx->t_sleep);
	printf("%d\n", ctx->nb_meal_per_philo);
}

void	print_status(t_ctx *ctx, t_status *status)
{
	pthread_mutex_lock(&ctx->mutex_log);
	printf("n: %d | l_fork: %d | r_fork: %d\n", status->n + 1, status->left_fork, status->right_fork);
	pthread_mutex_unlock(&ctx->mutex_log);
}