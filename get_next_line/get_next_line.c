#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*extraction;
	int			count;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	*line = malloc(1);
	if (!*line)
		return (-1);
	(*line)[0] = '\0';
	while (!extract(buff, &extraction))
	{
		*line = ft_strjoin(line, &extraction);
		count = read(fd, buff, BUFFER_SIZE);
		if (!line || count == -1)
			return (-1);
		buff[count] = '\0';
		if (!count && !buff[0])
			return (0);
	}
	*line = ft_strjoin(line, &extraction);
	if (!*line)
		return (-1);
	return (1);
}
