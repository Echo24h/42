#include "libft.h"

static int	is_whitespace(int c)
{
	if (c == '\v' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

long long int	ft_atoi_long_long(const char *str)
{
	long long int	res;
	int	neg;

	res = 0;
	neg = 0;
	while (*str && is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (ft_isdigit(*str))
		res = res * 10 - ((int)*(str++) - 48);
	if (neg)
		return (res);
	return (-res);
}