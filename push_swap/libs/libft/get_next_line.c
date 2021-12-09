#include "libft.h"

static char	*ft_append_char(char *str, char c)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!res)
		return (NULL);
	if (!str)
	{
		res[0] = c;
		res[1] = '\0';
		return (res);
	}
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = c;
	res[++i] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*line;
	int		n;

	line = NULL;
	while ((n = read(fd, &c, 1)) > 0 && c != '\n')
		if (!(line = ft_append_char(line, c)))
			return (NULL);
	if (n > 0)
		if (!(line = ft_append_char(line, c)))
			return (NULL);
	if (n == -1)
		return (NULL);
	return (line);
}