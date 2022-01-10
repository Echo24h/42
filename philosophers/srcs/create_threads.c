#include "philo.h"

int	create_threads(t_ctx *ctx, pthread_t **th)
{
	int	i;

	*th = malloc(sizeof(pthread_t) * ctx->nb_philo);
	if (!*th)
		return (0);
	i = 0;
	while (i < ctx->nb_philo)
	{
		if (pthread_create(&(*th)[i], NULL, &philo_life, ctx) != 0)
			return (0);
		i++;
	}
	return (1);
}
