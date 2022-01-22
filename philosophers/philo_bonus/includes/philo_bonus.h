#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

# define TAKE_FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

typedef struct s_sem
{
	sem_t		*forks;
	sem_t		*stop;
	sem_t		*eat_or_die;
	sem_t		*log;
	sem_t		*ph_fed;
}	t_sem;

typedef struct s_info
{
	int		nb_ph;
	long	t_death;
	long	t_sleep;
	long	t_eat;
	int		nb_meal_per_ph;
	long	t_start;
}	t_info;

typedef struct s_philo
{
	pthread_t	th;
	int			id;
	int			nb_meal;
	long		t_last_meal;
	t_info		*info;
	t_sem		*sem;
	int			alive;
}	t_philo;

typedef struct s_data
{
	int		stop;
	t_info	*info;
	t_sem	*sem;
}	t_data;

// msleep
void	msleep(long ms);

// time
long	get_time(void);
long	time_diff(long start, long end);

// print_log
void	print_log(t_philo *ph, long time, int action);

// init
int		init_info(int ac, char **av, t_info *info);

// utils
int		ft_atoi(const char *str);
int		str_is_number(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);

// sem
void	unlink_sem(void);
void	close_sem(t_sem *sem);
int		init_sem(t_sem *sem, t_info *info);
int		init_sem_eat_or_die(t_sem *sem, int id);
void	delete_sem_eat_or_die(t_sem *sem, int id);

// philo_life
void	philo_life(t_philo *ph);

#endif
