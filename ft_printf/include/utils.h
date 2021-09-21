#ifndef UTILS_H
# define UTILS_H

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

t_opts	get_opts(const char **format);
int		is_flag(char c);
int		print_char(int c, t_opts opts);
int		print_str(char *str, t_opts opts);
int		print_ptr(void *ptr, t_opts opts);
int		print_int(int x, t_opts opts);
int		print_percentage(t_opts opts);
int		print_uint(unsigned int x, t_opts opts);
int		print_hexa(int nbr, t_opts opts, int maj);

// dev
void	print_flags(t_flags flags);
void	print_opts(t_opts opts);

#endif