#include "philo_bonus.h"

void	msleep(long ms)
{
	long	t_start;

	t_start = get_time();
	while (get_time() < t_start + ms)
		usleep(500);
}