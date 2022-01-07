#include "philo.h"

void	msleep(long ms)
{
	long	t_start;
	long	t;

	t = 0;
	t_start = get_time();
	while (t < ms)
		t = get_time() - t_start;
}
