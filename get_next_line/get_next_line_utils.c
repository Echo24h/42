#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void 		*ft_calloc(size_t count, size_t size)
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

static void	ft_strcpy(char *buff, char *src)
{
	if (*src == '\n')
		src++;
	while (*src)
		*buff++ = *src++;
	*buff = '\0';
}

char		*ft_strjoin(char **s1, char **s2)
{
	char	*res;
	int		i;
	int		j;

	if (!*s1 || !*s2)
		return (NULL);
	res = malloc(ft_strlen(*s1) + ft_strlen(*s2) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while ((*s1)[++i])
		res[i] = (*s1)[i];
	j = -1;
	while ((*s2)[++j])
		res[i + j] = (*s2)[j];
	res[i + j] = '\0';
	free(*s1);
	free(*s2);
	return (res);
}

int			extract(char *buff, char **extraction)
{
	int	i; 
	int	j;
	int found_line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	found_line = (buff[i] == '\n') ? 1 : 0;
	i += found_line;
	*extraction = malloc(i + 1);
	if (!*extraction)
		return (-1);
	j = -1;
	while (++j < i)
		(*extraction)[j] = buff[j];
	(*extraction)[j] = '\0';
	ft_strcpy(buff, &buff[i]);
	return (found_line);
}
