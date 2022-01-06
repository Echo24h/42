#include "philo.h"

void	print_log(t_ctx *ctx, float time, int n, int action)
{
	pthread_mutex_lock(&ctx->lock);
	ft_putms(time);
	ft_putchar(' ');
	ft_putnbr(n);
	if (action == TAKE_FORK)
		ft_putstr(" has taken a fork\n");
	else if (action == EAT)
		ft_putstr(" is eating\n");
	else if (action == SLEEP)
		ft_putstr(" is sleeping\n");
	else if (action == THINK)
		ft_putstr(" is thinking\n");
	else if (action == DIE)
		ft_putstr(" died\n");
	pthread_mutex_unlock(&ctx->lock);
}
