#include "philo.h"

/*
int	philo_die_while_eating(t_ctx *ctx, t_status *status, long time)
{
	if (time + ctx->t_eat > status->t_last_meal + ctx->t_death)
	{
		if (!ctx->end_simulation)
			msleep(status->t_last_meal + ctx->t_death - time);
		print_log(ctx, get_time(), status->n, DIE);
		ctx->end_simulation = 1;
		return (1);
	}
	return (0);
}

int	philo_die_while_sleeping(t_ctx *ctx, t_status *status, long time)
{
	if (time + ctx->t_sleep > status->t_last_meal + ctx->t_death)
	{
		if (!ctx->end_simulation)
			msleep(status->t_last_meal + ctx->t_death - time);
		print_log(ctx, get_time(), status->n, DIE);
		ctx->end_simulation = 1;
		return (1);
	}
	return (0);
}
*/

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

int	everyone_is_happy(t_ctx *ctx)
{
	int	i;

	if (ctx->nb_meal_per_philo == -1)
		return (0);
	i = 0;
	while (i < ctx->nb_philo)
	{
		if (ctx->philo[i] < ctx->nb_meal_per_philo)
			return (0);
		i++;
	}
	return (1);
}

int	philo_is_dead(t_ctx *ctx, t_status *status)
{
	long	time;

	time = get_time();
	if (time_diff(status->t_last_meal, time) > ctx->t_death)
	{
		print_log(ctx, time, status->n, DIE);
		return (1);
	}
	return (0);
}

void	take_forks(t_ctx *ctx, t_status *status)
{
	pthread_mutex_lock(&ctx->mutex_forks[status->left_fork]);
	print_log(ctx, get_time(), status->n, TAKE_FORK);
	pthread_mutex_lock(&ctx->mutex_forks[status->right_fork]);
	print_log(ctx, get_time(), status->n, TAKE_FORK);
	status->next_action = EAT;
}

void	put_forks_back(t_ctx *ctx, t_status *status)
{
	pthread_mutex_unlock(&ctx->mutex_forks[status->left_fork]);
	pthread_mutex_unlock(&ctx->mutex_forks[status->right_fork]);
}

void	philo_eat(t_ctx *ctx, t_status *status)
{
	long	time;

	time = get_time();
	print_log(ctx, time, status->n, EAT);
	status->t_last_meal = time;
	ctx->philo[status->n] += 1;
	if (everyone_is_happy(ctx))
		ctx->end_simulation = 1;
	if (!ctx->end_simulation)
		msleep(ctx->t_eat);
	put_forks_back(ctx, status);
	status->next_action = SLEEP;
}

void	philo_sleep(t_ctx *ctx, t_status *status)
{
	print_log(ctx, get_time(), status->n, SLEEP);
	if (!ctx->end_simulation)
		msleep(ctx->t_sleep);
	status->next_action = THINK;
}

void	philo_think(t_ctx *ctx, t_status *status)
{
	print_log(ctx, get_time(), status->n, THINK);
	status->next_action = TAKE_FORKS;
}

void	init_status(t_ctx *ctx, t_status *status)
{
	status->next_action = TAKE_FORKS;
	pthread_mutex_lock(&ctx->mutex_random);
	status->n = ctx->n;
	status->right_fork = status->n;
	status->left_fork = (status->n + 1) % ctx->nb_philo;
	ctx->philo[ctx->n] = READY;
	ctx->n += 1;
	pthread_mutex_unlock(&ctx->mutex_random);
}

void	set_t_start(t_ctx *ctx)
{
	pthread_mutex_lock(&ctx->mutex_random);
	if (!ctx->t_start)
		ctx->t_start = get_time();
	pthread_mutex_unlock(&ctx->mutex_random);
}

void	*philo_life(void *arg)
{
	t_ctx		*ctx;
	t_status	status;
	
	ctx = (t_ctx *)arg;
	init_status(ctx, &status);
	while (!everyone_is_ready(ctx))
		continue ;
	set_t_start(ctx);
	status.t_last_meal = get_time();
	while (!ctx->end_simulation)
	{
		if (philo_is_dead(ctx, &status))
			ctx->end_simulation = 1;
		else if (status.next_action == EAT)
			philo_eat(ctx, &status);
		else if (status.next_action == SLEEP)
			philo_sleep(ctx, &status);
		else if (status.next_action == THINK)
			philo_think(ctx, &status);
		else if (status.next_action == TAKE_FORKS)
			take_forks(ctx, &status);
	}
	return (NULL);
}

int	init_mutex(t_ctx *ctx)
{
	int	i;

	ctx->mutex_forks = malloc(sizeof(pthread_mutex_t) * ctx->nb_philo);
	if (!ctx->mutex_forks)
		return (0);
	i = 0;
	while (i < ctx->nb_philo)
	{
		if (pthread_mutex_init(&ctx->mutex_forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&ctx->mutex_log, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&ctx->mutex_random, NULL) != 0)
		return (0);
	return (1);
}

void	destroy_mutex(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->nb_philo)
	{
		pthread_mutex_destroy(&ctx->mutex_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&ctx->mutex_log);
	pthread_mutex_destroy(&ctx->mutex_random);
}

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

void	free_everything(t_ctx *ctx, pthread_t *th)
{
	free(ctx->philo);
	free(ctx->mutex_forks);
	free(th);
}

int	on_error(char *msg, int code)
{
	printf("Error: %s\n", msg);
	return (code);
}

int	main(int ac, char **av)
{
	t_ctx		ctx;
	pthread_t	*th;

	if (!parse(ac, av, &ctx))
		return (on_error("in parse", EXIT_FAILURE));
	if (ctx.nb_philo == 0 || ctx.nb_meal_per_philo == 0)
		return (EXIT_SUCCESS);
	if (!init_mutex(&ctx) || !create_threads(&ctx, &th))
		return (on_error("in create", EXIT_FAILURE));
	if (!join_threads(&ctx, th))
		return (on_error("in join", EXIT_FAILURE));
	destroy_mutex(&ctx);
	free_everything(&ctx, th);
	printf("The end boyss\n");
	return (EXIT_SUCCESS);
}
