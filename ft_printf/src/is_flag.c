#include "ft_printf.h"

int	is_flag(char c)
{
	if (c == '+' || c == '-' || c == '0' ||
		c == ' ' || c == '#')
		return (1);
	return (0);
}
