#include "philo_bonus.h"

void	unlink_sem()
{
	sem_unlink("/forks");
	sem_unlink("/stop");
	sem_unlink("/log");
	sem_unlink("/ph_fed");
}

void	clean(t_philo *ph)
{
	return ;
}

void	*monitor_all_fed(void *arg)
{
	t_data	*data;
	long	time;
	int		i;

	data = (t_data *)arg;
	i = 0;
	while (i < data->info->nb_ph)
	{
		sem_wait(data->sem->ph_fed);
		i++;
		if (data->stop)
			return (NULL);
	}
	if (i == data->info->nb_ph)
		print_last_log(data->info, data->sem, 0, 0);
	sem_post(data->sem->stop);
	return (NULL);
}

void	stop_monitor_all_fed(t_data *data)
{
	data->stop = 1;
	sem_post(data->sem->ph_fed);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_sema		sem;
	pid_t		*pids;
	pthread_t	th;
	t_data		data;

	//unlink_sem();
	//exit(EXIT_SUCCESS);
	if (!init_info(ac, av, &info))
		return (on_error("Invalid parameters", EXIT_FAILURE));
	pids = malloc(sizeof(pid_t) * info.nb_ph);
	if (!pids)
		return (on_error("Malloc failed", EXIT_FAILURE));
	if (!init_sem(&sem, info.nb_ph))
		return (on_error("Failed semaphores initialization", EXIT_FAILURE));
	init_data(&data, &info, &sem);
	pthread_create(&th, NULL, &monitor_all_fed, &data);

	//printf("before creating process\n");
	create_processes(pids, &info);
	
	//printf("waiting for stop\n");
	sem_wait(sem.stop);
	//printf("stop simulation\n");
	stop_monitor_all_fed(&data);
	kill_processes(pids, info.nb_ph);
	wait_processes(pids, info.nb_ph);
	//printf("all processes finished\n");
	pthread_join(th, NULL);
	//printf("all_fed monitor finished\n");
	free(pids);
	delete_sem(&sem);
	//system("leaks philo_bonus");
	return (EXIT_SUCCESS);
}

/*
# define N 2

void	*routine(void *arg)
{
	int	*x;
	int	i;

	x = (int *)arg;
	printf("Hello from thread %d\n", *x);
	sleep(4);
	return (NULL);
}

void	*task(void *arg)
{
	int	*x;

	x = (int *)arg;
	printf("Hello from thread %d\n", *x);
	sleep(1);
	return (NULL);
}

int	main2()
{
	pid_t	pid;
	sem_t	*sem;

	sem = sem_open("/xd", O_CREAT, 764, 1);
	if (sem == SEM_FAILED)
		perror("open");
	pid = fork();
	if (pid == 0)
	{
		sem_wait(sem);
		printf("there\n");
		sem_post(sem);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, NULL, 0);
	if (sem_unlink("/xd"))
		perror("unlink");
	if (sem_close(sem))
		perror("close");
	return (EXIT_SUCCESS);
}
*/