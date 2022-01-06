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

float	ft_atof(char *s)
{
	float	res;
	float	x;

	res = 0;
	while (*s && ft_isdigit(*s))
		res = res * 10 + *s++ - 48;
	if (*s == '.' || *s == ',')
		s++;
	x = 0.1;
	while (*s && ft_isdigit(*s))
	{
		res = res + x * (*s++ - 48);
		x *= 0.1;
	}
	return (res);
}
