#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>

typedef struct	s_flags
{
	int	minus;
	int	plus;
	int	zero;
	int	blank;
	int	hashtag;
}				t_flags;

typedef struct	s_opts
{
	int		width;
	int		precision;
	t_flags	flags;
}				t_opts;

int		ft_printf(const char *format, ...);
t_opts	get_opts(const char **format);
int		is_flag(char c);

// dev
void	print_flags(t_flags flags);
void	print_opts(t_opts opts);

#endif