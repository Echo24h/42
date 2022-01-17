#include "philo_bonus.h"

int	init_sem(t_sem *sem, t_info *info)
{
	sem->forks = sem_open("/forks", O_CREAT, 0666, info->nb_ph);
	if (sem->forks == SEM_FAILED)
		return (0);
	sem->stop = sem_open("/stop", O_CREAT, 0666, 0);
	if (sem->stop == SEM_FAILED)
		return (0);
	return (1);
}

void	close_sem(t_sem *sem)
{
	sem_close(sem->forks);
	sem_close(sem->stop);
}

void	unlink_sem(void)
{
	sem_unlink("/forks");
	sem_unlink("/stop");
}
