#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[NB_FILES_MAX][BUFFER_SIZE + 1];
	char		*extraction;
	int			n;
	char		*line;

	if (fd >= NB_FILES_MAX)
		return (NULL);
	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	while (!extract(buff[fd], &extraction))
	{
		line = ft_strjoin(&line, &extraction);
		n = read(fd, buff[fd], BUFFER_SIZE);
		if (!line || n == -1)
			return (NULL);
		buff[fd][n] = '\0';
		if (!n && !buff[fd][0])
			return (NULL);
	}
	line = ft_strjoin(&line, &extraction);
	if (!line)
		return (NULL);
	return (line);
}