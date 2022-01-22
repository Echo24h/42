#include "philo_bonus.h"

int	init_sem_eat_or_die(t_sem *sem, int id)
{
	char	*str_id;
	char	*sem_name;

	str_id = ft_itoa(id);
	if (!str_id)
		return (0);
	sem_name = ft_strjoin("/eat_or_die", str_id);
	if (!sem_name)
		return (0);
	sem->eat_or_die = sem_open(sem_name, O_CREAT, 0666, 1);
	free(sem_name);
	free(str_id);
	if (sem->eat_or_die == SEM_FAILED)
		return (0);
	return (1);
}

void	delete_sem_eat_or_die(t_sem *sem, int id)
{
	char	*str_id;
	char	*sem_name;

	sem_close(sem->eat_or_die);
	str_id = ft_itoa(id);
	if (str_id)
	{
		sem_name = ft_strjoin("/eat_or_die", str_id);
		sem_unlink(sem_name);
		free(sem_name);
	}
	free(str_id);
}

int	init_sem(t_sem *sem, t_info *info)
{
	sem->forks = sem_open("/my_forks", O_CREAT, 0666, info->nb_ph);
	if (sem->forks == SEM_FAILED)
		return (0);
	sem->stop = sem_open("/my_stop", O_CREAT, 0666, 0);
	if (sem->stop == SEM_FAILED)
		return (0);
	sem->log = sem_open("/my_log", O_CREAT, 0666, 1);
	if (sem->log == SEM_FAILED)
		return (0);
	sem->ph_fed = sem_open("/ph_fed", O_CREAT, 0666, 0);
	if (sem->ph_fed == SEM_FAILED)
		return (0);
	return (1);
}

void	close_sem(t_sem *sem)
{
	sem_close(sem->forks);
	sem_close(sem->stop);
	sem_close(sem->log);
	sem_close(sem->ph_fed);
}

void	unlink_sem(void)
{
	sem_unlink("/my_forks");
	sem_unlink("/my_stop");
	sem_unlink("/my_log");
	sem_unlink("/ph_fed");
}
