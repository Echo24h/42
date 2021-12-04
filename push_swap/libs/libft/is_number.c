#include "libft.h"

int	is_number(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}
