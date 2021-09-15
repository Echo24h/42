#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;

	res = 0;
	neg = 0;
	while (*str && ft_iswhitespace(*str))
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
