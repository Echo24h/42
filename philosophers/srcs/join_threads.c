#include "philo.h"

int	join_threads(t_ctx *ctx, pthread_t *th)
{
	int	i;

	i = 0;
	while (i < ctx->nb_philo)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
