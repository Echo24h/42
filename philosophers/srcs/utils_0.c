#include "philo.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_whitespace(int c)
{
	if (c == '\v' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while (ft_isdigit(*str))
		res = res * 10 + ((int)*(str++) - 48);
	return (res);
}

void	set_int_array(int *array, int value, int size)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < size)
		array[i++] = value;
}
