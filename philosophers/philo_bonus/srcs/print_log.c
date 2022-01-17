#include "philo_bonus.h"

void	print_log(t_philo *ph, long time, int action)
{
	long	timestamps;
	int		n;

	n = ph->id + 1;
	if (!ph->info->stop)
	{
		timestamps = time_diff(ph->info->t_start, time);
		if (action == TAKE_FORK)
			printf("%ld %d has taken a fork\n", timestamps, n);
		else if (action == EAT)
			printf("%ld %d is eating\n", timestamps, n);
		else if (action == SLEEP)
			printf("%ld %d is sleeping\n", timestamps, n);
		else if (action == THINK)
			printf("%ld %d is thinking\n", timestamps, n);
	}
}
