#include "philo.h"

int	everyone_is_ready(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->nb_philo)
	{
		if (ctx->philo[i] == NOT_READY)
			return (0);
		i++;
	}
	return (1);
}

void	*philo_life(void *arg)
{
	t_ctx			*ctx;
	t_philo_status	status;

	ctx = (t_ctx *)arg;
	pthread_mutex_lock(&ctx->lock);
	status.n = ctx->n;
	ctx->philo[ctx->n - 1] = READY;
	ctx->n++;
	pthread_mutex_unlock(&ctx->lock);
	while (!everyone_is_ready(ctx))
		continue ;
	printf("Philo %d is born !\n", status.n);
	return (NULL);
}

int	main(int ac, char **av)
{
	int			i;
	t_ctx		ctx;
	pthread_t	*th;

	if (pthread_mutex_init(&ctx.lock, NULL) != 0)
		return (on_error(EXIT_FAILURE));
	if (!parse(ac, av, &ctx))
		return (EXIT_FAILURE);
	print_ctx(&ctx);
	th = malloc(sizeof(pthread_t) * ctx.nb_philo);
	if (!th)
		return (on_error(EXIT_FAILURE)); // need free
	if (gettimeofday(&ctx.start_time, NULL) == -1)
		return (on_error(EXIT_FAILURE)); // need free
	i = 0;
	while (i < ctx.nb_philo)
	{
		if (pthread_create(&th[i], NULL, &philo_life, &ctx) != 0)
			return (on_error(EXIT_FAILURE)); // need free
		i++;
	}
	i = 0;
	while (i < ctx.nb_philo)
	{
		if (pthread_join(th[i], NULL) != 0)
			return (on_error(EXIT_FAILURE)); // need free
		i++;
	}
	pthread_mutex_destroy(&ctx.lock);
	printf("The end boyss\n");
	return (EXIT_SUCCESS);
}