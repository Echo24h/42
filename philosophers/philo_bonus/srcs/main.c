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

t_philo	*init_philo(t_info *info, t_sem *sem, int id)
{
	t_philo	*ph;

	ph = malloc(sizeof(t_philo) * 1);
	if (!ph)
		return (NULL);
	ph->id = id;
	ph->nb_meal = 0;
	ph->alive = 1;
	ph->info = info;
	ph->t_last_meal = info->t_start;
	//if (!init_sem(sem, info))
	//	return (NULL);
	ph->sem = sem;
	if (!init_sem_eat_or_die(sem, id))
		return (NULL);
	return (ph);
}

void	*monitor_all_fed(void *arg)
{
	t_data	*data;
	long	time;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i < data->info->nb_ph && !data->stop)
	{
		sem_wait(data->sem->ph_fed);
		i++;
	}
	sem_post(data->sem->stop);
	return (NULL);
}

void	*monitor(void *arg)
{
	t_philo	*ph;
	long	time;

	ph = (t_philo *)arg;
	while (ph->alive)
	{
		sem_wait(ph->sem->eat_or_die);
		time = get_time();
		if (time > ph->t_last_meal + ph->info->t_death)
		{
			print_log(ph, time, DIE);
			ph->alive = 0;
		}
		sem_post(ph->sem->eat_or_die);
	}
	return (NULL);
}

int	process_routine(t_info *info, int id)
{
	t_philo	*ph;
	t_sem	sem;

	if (!init_sem(&sem, info))
		exit_error("Failed to initialize sem");
	ph = init_philo(info, &sem, id);
	if (!ph)
		exit_error("Failed to initialize philo");
	if (pthread_create(&ph->th, NULL, &monitor_all_fed, &ph))
		exit_error("Failed to create thread");
	while (ph->alive)
	{
		printf("living ma life\n");
		philo_life(ph);
	}
	pthread_join(ph->th, NULL);
	sem_post(sem.stop);
	close_sem(&sem);
	delete_sem_eat_or_die(&sem, id);
	free(ph);
	printf("process %d exit\n", id);
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
			process_routine(info, i);
		i++;
		usleep(100);
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

void	kill_processes(t_info *info, pid_t *pids)
{
	int	i;

	i = 0;
	while (i < info->nb_ph)
	{
		kill(pids[i], SIGTERM);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_info		info;
	pid_t		*pids;
	t_sem		sem;
	pthread_t	th;
	t_data		data;

	if (!init_info(ac, av, &info))
		return (on_error("Invalid parameters", EXIT_FAILURE));
	if (info.nb_ph != 0 && info.nb_meal_per_ph != 0)
	{
		pids = malloc(sizeof(pid_t) * info.nb_ph);
		if (!pids)
			return (on_error("Failed to malloc", EXIT_FAILURE));
		if (!init_sem(&sem, &info))
			return (on_error("Failed semaphores initialization", EXIT_FAILURE));
		sem_wait(sem.log);
		printf("mdr\n");
		sem_post(sem.log);
		data.info = &info;
		data.sem = &sem;
		data.stop = 0;
		printf("before creating process\n");
		create_processes(&info, &sem, pids);
		pthread_create(&th, NULL, &monitor_all_fed, &data);
		printf("\nwent here\n\n");
		sem_wait(sem.stop);
		printf("simul stop\n");
		data.stop = 1;
		kill_processes(&info, pids);
		wait_processes(&info, pids);
		printf("All processes finished\n");
		free(pids);
		pthread_join(th, NULL);
		close_sem(&sem);
		unlink_sem();
	}
	if (info.nb_meal_per_ph == 0)
		printf("Everyone is happy and has le ventre rempli !\n");
	return (EXIT_SUCCESS);
}

# define N 2

void	*routine1(void *arg)
{
	int	*x;
	int	i;

	x = (int *)arg;
	printf("Hello from thread %d\n", *x);
	sleep(4);
	return (NULL);
}

void	*routine2(void *arg)
{
	int	*x;

	x = (int *)arg;
	printf("Hello from thread %d\n", *x);
	sleep(1);
	return (NULL);
}

int	main2()
{
	int	i;
	int	x;
	int y;
	pthread_t	th1;
	pthread_t	th2;
	pid_t	pids[N];

	x = 1;
	y = 2;
	pthread_create(&th1, NULL, &routine1, &x);
	pthread_create(&th2, NULL, &routine2, &y);
	if (!pthread_join(th1, NULL) || !pthread_join(th2, NULL))
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
