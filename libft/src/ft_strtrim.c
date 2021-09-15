#include "libft.h"

int		is_in_set(const char *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;
	
	if (!s1 || !set || !*s1)
		return ((char *)s1);
	start = 0;
	while (is_in_set(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (is_in_set(set, s1[end]))
		end--;
	res = ft_substr(s1, start, end - start + 1);
	return (res);
}
