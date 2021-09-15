#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	int		size;

	if (!s)
		return (NULL);
	if (!len)
		return (ft_calloc(1, 1));
	if (start >= ft_strlen(s))
		return (calloc(1, 1));
	size = (len > ft_strlen(s) - start) ? ft_strlen(s) - start + 1 : len + 1;
	res = malloc(size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
