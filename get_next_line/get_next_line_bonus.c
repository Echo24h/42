#include "get_next_line_bonus.h"

int	get_next_line(int fd, char **line)
{
	static char	buff[NB_FILES_MAX][BUFFER_SIZE + 1];
	char		*extraction;
	int			count;

	if (!line || BUFFER_SIZE <= 0 || fd < 0 || fd > NB_FILES_MAX - 1)
		return (-1);
	*line = malloc(1);
	if (!*line)
		return (-1);
	(*line)[0] = '\0';
	while (!extract(buff[fd], &extraction))
	{
		*line = ft_strjoin(line, &extraction);
		count = read(fd, buff[fd], BUFFER_SIZE);
		if (!line || count == -1)
			return (-1);
		buff[fd][count] = '\0';
		if (!count && !buff[fd][0])
			return (0);
	}
	*line = ft_strjoin(line, &extraction);
	if (!*line)
		return (-1);
	return (1);
}