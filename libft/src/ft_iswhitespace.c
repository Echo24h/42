#include "libft.h"

int	ft_iswhitespace(int c)
{
	if (c == '\v' || c == '\n' || c== '\t' ||
		c== '\r' || c== '\f' || c== ' ')
		return (1);
	return (0);
}