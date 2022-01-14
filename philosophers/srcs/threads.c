#include "philo.h"

static void	protected_stop(t_philo *ph, long time)
{
	pthread_mutex_lock(&ph->mu->stop);
	if (time)
		print_log(ph, time, DIE);
	else
		print_log(ph, 0, ALL_FED);
	ph->info->stop = 1;
	pthread_mutex_unlock(&ph->mu->stop);
}

static void	*monitor(void *arg)
{
	t_philo *ph;
	long	time;

	ph = (t_philo *)arg;
	while (!ph->info->stop)
	{
		pthread_mutex_lock(&ph->mu->eat_or_die[ph->id]);
		time = get_time();
		if (time > ph->t_last_meal + ph->info->t_death)
			protected_stop(ph, time);
		pthread_mutex_unlock(&ph->mu->eat_or_die[ph->id]);
		if (!ph->info->stop && ph->info->nb_ph_fed == ph->info->nb_ph)
			protected_stop(ph, 0);
		usleep(1000);
	}
	return (NULL);
}

static void	*routine(void *arg)
{
	t_philo		*ph;
	pthread_t	th;
	
	ph = (t_philo *)arg;
	ph->t_start = get_time();
	ph->t_last_meal = ph->t_start;
	if (pthread_create(&th, NULL, &monitor, ph))
		return (NULL);
	while (!ph->info->stop)
		philo_life(ph);
	pthread_join(th, NULL);
	return (NULL);
}

int	create_threads(t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < ph->info->nb_ph)
		if (pthread_create(&ph[i].th, NULL, &routine, &ph[i]))
			return (0);
	return (1);
}

int	join_threads(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->info->nb_ph)
		if (pthread_join(ph[i++].th, NULL))
			return (0);
	return (1);
}
