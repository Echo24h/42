#include "philo_bonus.h"

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
			print_last_log(ph->info, ph->sem, ph->id, time);
			ph->alive = 0;
			sem_post(ph->sem->stop);
		}
		sem_post(ph->sem->eat_or_die);
		usleep(100);
	}
	return (NULL);
}

int	task(t_info *info, int id)
{
	t_philo	ph;

	if (!init_philo(&ph, info, id))
		exit_error("Failed to initialize philo");
	if (pthread_create(&ph.th, NULL, &monitor, &ph))
		exit_error("Failed to create thread");
	while (ph.alive)
		philo_life(&ph);
	pthread_join(ph.th, NULL);
	delete_philo(&ph);
	//printf("process %d exit\n", id);
	exit(0);
}

int	create_processes(pid_t *pids, t_info *info)
{
	int	i;

	info->t_start = get_time();
	i = 0;
	while (i < info->nb_ph)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			task(info, i);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < info->nb_ph)
	{
		pids[i] = fork();
		if (pids[i] == 0)
			task(info, i);
		i += 2;
	}
	return (1);
}

int	wait_processes(pid_t *pids, int nb_ph)
{
	int	i;

	i = 0;
	while (i < nb_ph)
		waitpid(pids[i++], NULL, 0);
	return (1);
}

void	kill_processes(pid_t *pids, int nb_ph)
{
	int	i;

	i = 0;
	while (i < nb_ph)
	{
		kill(pids[i], SIGTERM);
		i++;
	}
}