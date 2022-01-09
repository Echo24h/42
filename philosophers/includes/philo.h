#ifndef PHILO_H
# define PHILO_H

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

# define NOT_READY 1
# define READY 0
# define TAKEN '0'
# define AVAILABLE '1'
# define TAKE_FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DIE 4

typedef struct s_status
{
	int				n;
	long			t_last_meal;
	int				forks;
}	t_status;

typedef struct s_ctx
{
	int				n;
	long			t_start;
	int				nb_philo;
	long			t_death;
	long			t_eat;
	long			t_sleep;
	int				nb_meal_per_philo;
	char			*forks;
	int				*philo;
	int				end_simulation;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_log;
	pthread_mutex_t	mutex_random;
}	t_ctx;

void	msleep(long ms);
long	get_time(void);
long	time_diff(long start, long end);
void	print_log(t_ctx *ctx, long time, int n, int action);

// parse
int		parse(int ac, char **av, t_ctx *ctx);

// utils
int		ft_atoi(const char *str);
void	set_int_array(int *array, int value, int size);

// dev
void	print_forks(t_ctx *ctx);
void	print_ctx(t_ctx *ctx);

#endif