#include "philo.h"

long	get_time(void)
{
	long			ms;
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	ms = time.tv_sec * 1000;
	ms += time.tv_usec * 1e-3;
	return (ms);
}

long	time_diff(long start, long end)
{
	return (end - start);
}
