#include "philo_bonus.h"

static void	take_forks(t_philo *ph)
{
	printf("try to take forks\n");
	sem_wait(ph->sem->forks);
	printf("took first fork\n");
	print_log(ph, get_time(), TAKE_FORK);
	sem_wait(ph->sem->forks);
	printf("took second fork\n");
	print_log(ph, get_time(), TAKE_FORK);
}

static void	put_forks_back(t_philo *ph)
{
	sem_post(ph->sem->forks);
	sem_post(ph->sem->forks);
}

static void	philo_eat(t_philo *ph)
{
	long	time;

	sem_wait(ph->sem->eat_or_die);
	time = get_time();
	print_log(ph, time, EAT);
	ph->t_last_meal = time;
	sem_post(ph->sem->eat_or_die);
	ph->nb_meal++;
	if (ph->nb_meal == ph->info->nb_meal_per_ph)
		sem_post(ph->sem->ph_fed);
	msleep(ph->info->t_eat);
}

static void	philo_sleep(t_philo *ph)
{
	print_log(ph, get_time(), SLEEP);
	msleep(ph->info->t_sleep);
}

void	philo_life(t_philo *ph)
{
	printf("first steps in this cruel world...\n");
	take_forks(ph);
	printf("managed to get forks, will he eat?\n");
	philo_eat(ph);
	printf("damn boys he did it, he is well fed!\n");
	put_forks_back(ph);
	philo_sleep(ph);
	print_log(ph, get_time(), THINK);
	if (ph->info->nb_ph % 2)
		usleep(100);
}