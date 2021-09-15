#include "libft.h"

char 	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	res = ft_calloc(ft_strlen(s1) + 1, 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	return (res);
}
