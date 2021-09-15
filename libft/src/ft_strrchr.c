#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	i = ft_strlen(s);
	while (i--)
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	return (NULL);
}
