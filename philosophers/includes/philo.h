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
# define TAKE_FORKS 0
# define TAKE_FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_status
{
	int				n;
	long			t_last_meal;
	int				left_fork;
	int				right_fork;
	int				next_action;
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
void	*philo_life(void *arg);
void	destroy_mutex(t_ctx *ctx);
void	set_t_start(t_ctx *ctx);
void	init_status(t_ctx *ctx, t_status *status);
int		init_mutex(t_ctx *ctx);
int		create_threads(t_ctx *ctx, pthread_t **th);
int		everyone_is_happy(t_ctx *ctx);
int		everyone_is_ready(t_ctx *ctx);
int		join_threads(t_ctx *ctx, pthread_t *th);

// parse
int		parse(int ac, char **av, t_ctx *ctx);

// utils
int		ft_atoi(const char *str);
void	set_int_array(int *array, int value, int size);

// dev
void	print_ctx(t_ctx *ctx);

#endif