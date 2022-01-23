#include "philo_bonus.h"

int	on_error(char *msg, int code)
{
	printf("Error: %s\n", msg);
	return (code);
}

void	exit_error(char *msg)
{
	printf("Error: %s\n", msg);
	exit(1);
}
