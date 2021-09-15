#include "libft.h"

void 	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count * size)
		res[i++] = '\0'; 
	return ((void *)res);
}