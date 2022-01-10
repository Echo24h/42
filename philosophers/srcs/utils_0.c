#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_whitespace(int c)
{
	if (c == '\v' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + ((int)*(str++) - 48);
	return (res);
}

void	set_int_array(int *array, int value, int size)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < size)
		array[i++] = value;
}

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
