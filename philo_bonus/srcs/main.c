#include "philo_bonus.h"

int	on_error(char *msg, int code)
{
	printf("Error: %s\n", msg);
	return (code);
}

int	create_processes()
{
	return (1);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	t_info	info;
	t_philo	*ph;

	if (!init_info(ac, av, &info))
		return (on_error("Invalid parameters", EXIT_FAILURE));
	if (ph->info->nb_ph != 0 && ph->info->nb_meal_per_ph != 0)
		return (EXIT_SUCCESS);
	if (ph->info->nb_meal_per_ph == 0)
		printf("Everyone is happy and has le ventre rempli !\n");
	return (EXIT_SUCCESS);
}
