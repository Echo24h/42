#include "philo.h"

void	print_log(float time, int n, int action)
{
	printf("%.6f %d ", time, n);
	if (action == TAKE_FORK)
		printf("has taken a fork\n");
	else if (action == EAT)
		printf("is eating\n");
	else if (action == SLEEP)
		printf("is sleeping\n");
	else if (action == THINK)
		printf("is thinking\n");
	else if (action == DIE)
		printf("died\n");
}
