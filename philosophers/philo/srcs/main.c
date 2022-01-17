#include "philo.h"

void	clean(t_philo *ph, t_mutex *mu)
{
	int	i;

	i = 0;
	while (i < ph->info->nb_ph)
	{
		pthread_mutex_destroy(&mu->forks[i]);
		pthread_mutex_destroy(&mu->eat_or_die[i]);
		i++;
	}
	pthread_mutex_destroy(&mu->log);
	pthread_mutex_destroy(&mu->nb_ph_fed);
	free(mu->forks);
	free(mu->eat_or_die);
	free(ph);
}

int	on_error(char *msg, int code)
{
	printf("Error: %s\n", msg);
	return (code);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_mutex	mu;
	t_philo	*ph;

	if (!init_info(ac, av, &info))
		return (on_error("Invalid parameters", EXIT_FAILURE));
	if (!init_mutex(&info, &mu) || !init_philo(&ph, &info, &mu))
		return (on_error("Failed initialization", EXIT_FAILURE));
	if (ph->info->nb_ph != 0 && ph->info->nb_meal_per_ph != 0)
	{
		if (!create_threads(ph))
		{
			clean(ph, &mu);
			return (on_error("Failed to create the threads", EXIT_FAILURE));
		}
		join_threads(ph);
	}
	if (ph->info->nb_meal_per_ph == 0)
		printf("Everyone is happy and has le ventre rempli !\n");
	clean(ph, &mu);
	return (EXIT_SUCCESS);
}
