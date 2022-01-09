#include "philo.h"

void	print_forks(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->nb_philo)
	{
		printf("%c ", ctx->forks[i]);
		i++;
	}
	printf("\n");
}

void	print_ctx(t_ctx *ctx)
{
	printf("%d\n", ctx->nb_philo);
	printf("%ld\n", ctx->t_death);
	printf("%ld\n", ctx->t_eat);
	printf("%ld\n", ctx->t_sleep);
	printf("%d\n", ctx->nb_meal_per_philo);
}