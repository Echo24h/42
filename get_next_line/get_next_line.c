#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*extraction;
	int			n;
	char		*line;

	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	while (!extract(buff, &extraction))
	{
		line = ft_strjoin(&line, &extraction);
		n = read(fd, buff, BUFFER_SIZE);
		if (!line || n == -1)
			return (NULL);
		buff[n] = '\0';
		if (!n && !buff[0])
			return (NULL);
	}
	line = ft_strjoin(&line, &extraction);
	if (!line)
		return (NULL);
	return (line);
}
