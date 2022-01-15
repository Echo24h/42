#include "philo.h"

int	init_info(int ac, char **av, t_info *info)
{
	if (ac != 5 && ac != 6)
		return (0);
	info->nb_ph = ft_atoi(av[1]);
	info->t_death = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->nb_meal_per_ph = -1;
	if (ac == 6)
		info->nb_meal_per_ph = ft_atoi(av[5]);
	info->stop = 0;
	info->nb_ph_fed = 0;
	info->t_start = 0;
	return (1);
}

int	init_mutex(t_info *info, t_mutex *mu)
{
	int	i;

	if (pthread_mutex_init(&mu->log, NULL)
		|| pthread_mutex_init(&mu->nb_ph_fed, NULL))
		return (0);
	mu->forks = malloc(sizeof(pthread_mutex_t) * info->nb_ph);
	if (!mu->forks)
		return (0);
	mu->eat_or_die = malloc(sizeof(pthread_mutex_t) * info->nb_ph);
	if (!mu->eat_or_die)
		return (0);
	i = 0;
	while (i < info->nb_ph)
	{
		if (pthread_mutex_init(&mu->forks[i], NULL)
			|| pthread_mutex_init(&mu->eat_or_die[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

int	init_philo(t_philo **ph, t_info *info, t_mutex *mu)
{
	int		i;

	*ph = malloc(sizeof(t_philo) * info->nb_ph);
	if (!*ph)
		return (0);
	i = 0;
	while (i < info->nb_ph)
	{
		(*ph)[i].id = i;
		(*ph)[i].left_fork = (i + 1) % info->nb_ph;
		(*ph)[i].right_fork = i;
		(*ph)[i].nb_meal = 0;
		(*ph)[i].mu = mu;
		(*ph)[i].info = info;
		i++;
	}
	return (1);
}
