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

t_philo	*init_philo(t_info *info, t_sem *sem, int id)
{
	t_philo	*ph;

	ph = malloc(sizeof(t_philo) * 1);
	if (!ph)
		return (NULL);
	ph->id = id;
	ph->nb_meal = 0;
	ph->info = info;
	ph->t_last_meal = info->t_start;
	if (!init_sem(sem, info))
		return (NULL);
	return (ph);
}

int	process_routine(t_info *info, t_sem *sem, int id)
{
	t_philo	*ph;

	ph = init_philo(info, sem, id);
	if (!ph)
		exit_error("Failed to initialize philo");
	// launch monitor

	sleep(id);
	printf("Hello from process %d\n", id);

	close_sem(sem);
	free(ph);
	exit(0);
}

int	create_processes(t_info *info, t_sem *sem, pid_t *pids)
{
	int	i;

	i = 0;
	while (i < info->nb_ph)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			process_routine(info, sem, i);
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

int	main2(int ac, char **av)
{
	t_info	info;
	pid_t	*pids;
	sem_t	*forks;
	t_sem	sem;

	srand(time(NULL));
	if (!init_info(ac, av, &info))
		return (on_error("Invalid parameters", EXIT_FAILURE));
	if (info.nb_ph != 0 && info.nb_meal_per_ph != 0)
	{
		pids = malloc(sizeof(pid_t) * info.nb_ph);
		if (!pids)
			return (on_error("Failed to malloc", EXIT_FAILURE));
		if (!init_sem(&sem, &info))
			return (on_error("Failed semaphores initialization", EXIT_FAILURE));
		create_processes(&info, &sem, pids);

		sem_wait(sem.stop);
		// then kill all processes
		wait_processes(&info, pids);
		printf("All processes finished\n");
			
		close_sem(&sem);
		unlink_sem();
	}
	if (info.nb_meal_per_ph == 0)
		printf("Everyone is happy and has le ventre rempli !\n");
	return (EXIT_SUCCESS);
}

# define N 2

int	routine(int n)
{
	sleep(n % 5);
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
	i = 0;
	while (i < N)
		waitpid(pids[i++], NULL, 0);
	printf("Hello from main process\n");
}
