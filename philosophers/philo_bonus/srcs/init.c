#include "philo_bonus.h"

static int	check_params(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (0);
	if (!str_is_number(av[1]) || !str_is_number(av[2])
		|| !str_is_number(av[3]) || !str_is_number(av[4]))
		return (0);
	if (ac == 6 && !str_is_number(av[5]))
		return (0);
	return (1);
}

static int	check_info(int ac, t_info *info)
{
	if (info->nb_ph < 0 || info->t_death < 0
		|| info->t_eat < 0 || info->t_sleep < 0)
		return (0);
	if (ac == 6 && info->nb_meal_per_ph < 0)
		return (0);
	return (1);
}

int	init_info(int ac, char **av, t_info *info)
{
	if (!check_params(ac, av))
		return (0);
	info->nb_ph = ft_atoi(av[1]);
	info->t_death = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->nb_meal_per_ph = -1;
	if (ac == 6)
		info->nb_meal_per_ph = ft_atoi(av[5]);
	if (!check_info(ac, info))
		return (0);
	info->stop = 0;
	info->nb_ph_fed = 0;
	info->t_start = 0;
	return (1);
}

