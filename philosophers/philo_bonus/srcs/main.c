#include "philo_bonus.h"

void	clean(t_philo *ph)
{
	return ;
}

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

int	launch_monitor(t_philo *ph)
{
	return (1);
}

int	init_philo(t_philo *ph, t_info *info, int id)
{
	ph->id = id;

}

int	process_routine(t_info *info, int id)
{
	int		id;
	t_philo	ph;

	if (!init_philo(&ph, info, id))
		exit_error("Failed to initialize philo");
	forks = sem_open("/forks", O_CREAT);
	sleep(n % 5);
	printf("Hello from process %d : %d\n", n);
	exit(0);
}

int	create_processes(t_info *info, pid_t *pids)
{
	int	i;

	i = 0;
	while (i < info->nb_ph)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			process_routine(i);
		i++;
	}
	return (1);
}

int	wait_processes(t_info *info, pid_t *pids)
{
	int	i;

	i = 0;
	while (i < info->nb_ph)
		waitpid(pids[i++], NULL, 0);
	return (1);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*ph;
	pid_t	*pids;
	sem_t	*forks;

	srand(time(NULL));
	if (!init_info(ac, av, &info))
		return (on_error("Invalid parameters", EXIT_FAILURE));
	if (info.nb_ph != 0 && info.nb_meal_per_ph != 0)
	{
		pids = malloc(sizeof(pid_t) * info.nb_ph);
		if (!pids)
			return (on_error("Failed to malloc", EXIT_FAILURE));
		forks = sem_open("/forks", O_CREAT, 0666, info.nb_ph);
		if (forks == SEM_FAILED)
			return (on_error("Failed to instance semaphore", EXIT_FAILURE));
		create_processes(&info, pids);
		wait_processes(&info, pids);
		printf("All processes finished\n");
		sem_close(forks);
		sem_unlink("/forks");
	}
	if (info.nb_meal_per_ph == 0)
		printf("Everyone is happy and has le ventre rempli !\n");
	return (EXIT_SUCCESS);
}

/*
# define N 2

int	routine(int n)
{
	printf("Hello from process %d\n", n);
	exit(0);
}

int	main()
{
	int	i;
	pid_t	pids[N];

	i = 0;
	while (i < N)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			routine(i);
		i++;
	}
	printf("Hello from main process\n");
}
*/