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

int	philo_is_dead(t_ctx *ctx, t_philo_status *status)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (time_diff(status->t_last_meal, time) > ctx->t_death)
	{
			print_log(ctx, time_diff(ctx->start_time, time), status->n, DIE);
			return (1);
	}
	return (0);
}

void	philo_eat(t_ctx *ctx, t_philo_status *status)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	print_log(ctx, time_diff(ctx->start_time, time), status->n, EAT);
	usleep(1e3 * ctx->t_eat);
	status->forks = 0;
	pthread_mutex_lock(&ctx->lock);
	ctx->forks[status->n - 1] = AVAILABLE;
	ctx->forks[status->n % ctx->nb_philo] = AVAILABLE;
	pthread_mutex_unlock(&ctx->lock);
	gettimeofday(&status->t_last_meal, NULL);
}

void	philo_sleep(t_ctx *ctx, t_philo_status *status)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	print_log(ctx, time_diff(ctx->start_time, time), status->n, SLEEP);
	usleep(1e3 * ctx->t_sleep);
}

void	philo_try_to_take_forks(t_ctx *ctx, t_philo_status *status)
{
	struct timeval	time;

	pthread_mutex_lock(&ctx->lock);
	gettimeofday(&time, NULL);
	if (ctx->forks[status->n - 1] == AVAILABLE)
	{
		print_log(ctx, time_diff(ctx->start_time, time), status->n, TAKE_FORK);
		ctx->forks[status->n - 1] = TAKEN;
		status->forks++;
	}
	if (ctx->forks[status->n % ctx->nb_philo] == AVAILABLE)
	{
		print_log(ctx, time_diff(ctx->start_time, time), status->n, TAKE_FORK);
		ctx->forks[status->n % ctx->nb_philo] = TAKEN;
		status->forks++;
	}
	pthread_mutex_unlock(&ctx->lock);
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
	status.forks = 0;
	while (!everyone_is_ready(ctx))
		continue ;
	gettimeofday(&status.t_last_meal, NULL); // check error ?
	printf("Philo %d is born !\n", status.n);
	while (!ctx->stop)
	{
		if (philo_is_dead(ctx, &status))
			ctx->stop = 1;
		philo_try_to_take_forks(ctx, &status);
		if (status.forks == 2)
		{
			philo_eat(ctx, &status);
			philo_sleep(ctx, &status);
		}
	}
	return (NULL);
}

// need to check errors
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