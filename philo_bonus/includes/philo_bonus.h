#ifndef PHILO_H
# define PHILO_H

#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>

# define TAKE_FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3

typedef struct s_info
{
	int		nb_ph;
	long	t_death;
	long	t_sleep;
	long	t_eat;
	int		nb_meal_per_ph;
	int		nb_ph_fed;
	int		stop;
	long	t_start;
}	t_info;

typedef struct s_philo
{
	pthread_t	th;
	int			id;
	int			left_fork;
	int			right_fork;
	int			nb_meal;	
	long		t_last_meal;
	t_info		*info;
}	t_philo;

// msleep
void	msleep(long ms);

// time
long	get_time(void);
long	time_diff(long start, long end);

// print_log
void	print_log(t_philo *ph, long time, int action);

// threads
int		create_threads(t_philo *ph);
void	join_threads(t_philo *ph);

// init
int		init_info(int ac, char **av, t_info *info);

// utils
int		ft_atoi(const char *str);
int		str_is_number(char *str);

#endif
