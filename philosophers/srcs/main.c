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
	long	time;

	time = get_time();
	if (time_diff(status->t_last_meal, time) > ctx->t_death)
	{
		print_log(ctx, time_diff(ctx->start_time, time), status->n, DIE);
		return (1);
	}
	return (0);
}

void	philo_eat(t_ctx *ctx, t_philo_status *status)
{
	long	time;

	time = get_time();
	print_log(ctx, time_diff(ctx->start_time, time), status->n, EAT);
	status->t_last_meal = time;
	msleep(ctx->t_sleep);
	status->forks = 0;
	pthread_mutex_lock(&ctx->lock_forks);
	ctx->forks[status->n - 1] = AVAILABLE;
	ctx->forks[status->n % ctx->nb_philo] = AVAILABLE;
	pthread_mutex_unlock(&ctx->lock_forks);
}

void	philo_sleep(t_ctx *ctx, t_philo_status *status)
{
	long	time;

	time = get_time();
	print_log(ctx, time_diff(ctx->start_time, time), status->n, SLEEP);
	msleep(ctx->t_sleep);
}

void	philo_try_to_take_forks(t_ctx *ctx, t_philo_status *status)
{
	long	time;

	pthread_mutex_lock(&ctx->lock_forks);
	time = get_time();
	if (ctx->forks[status->n - 1] == AVAILABLE)
	{
		ctx->forks[status->n - 1] = TAKEN;
		status->forks++;
		print_log(ctx, time_diff(ctx->start_time, time), status->n, TAKE_FORK);
	}
	if (ctx->forks[status->n % ctx->nb_philo] == AVAILABLE)
	{
		ctx->forks[status->n % ctx->nb_philo] = TAKEN;
		status->forks++;
		print_log(ctx, time_diff(ctx->start_time, time), status->n, TAKE_FORK);
	}
	pthread_mutex_unlock(&ctx->lock_forks);
}

void	*philo_life(void *arg)
{
	t_ctx			*ctx;
	t_philo_status	status;
	
	ctx = (t_ctx *)arg;
	status.forks = 0;
	pthread_mutex_lock(&ctx->lock_forks);
	status.n = ctx->n;
	ctx->philo[ctx->n - 1] = READY;
	ctx->n++;
	pthread_mutex_unlock(&ctx->lock_forks);
	while (!everyone_is_ready(ctx))
		continue ;
	pthread_mutex_lock(&ctx->lock);
	if (!ctx->start_time)
		ctx->start_time = get_time();
	pthread_mutex_unlock(&ctx->lock);
	status.t_last_meal = get_time();
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
// check errors on gettimeofday returns ?
int	main(int ac, char **av)
{
	int			i;
	t_ctx		ctx;
	pthread_t	*th;

	if (pthread_mutex_init(&ctx.lock_forks, NULL) != 0)
		return (on_error(EXIT_FAILURE));
	if (pthread_mutex_init(&ctx.lock_print, NULL) != 0)
		return (on_error(EXIT_FAILURE));
	if (pthread_mutex_init(&ctx.lock, NULL) != 0)
		return (on_error(EXIT_FAILURE));
	if (!parse(ac, av, &ctx))
		return (EXIT_FAILURE);
	print_ctx(&ctx);
	th = malloc(sizeof(pthread_t) * ctx.nb_philo);
	if (!th)
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
	pthread_mutex_destroy(&ctx.lock_forks);
	pthread_mutex_destroy(&ctx.lock_print);
	pthread_mutex_destroy(&ctx.lock);
	printf("The end boyss\n");
	return (EXIT_SUCCESS);
}
