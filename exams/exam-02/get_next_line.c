#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# define BUFFER_SIZE 5

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	extract(char **line, char *buff)
{
	int		i;
	int		j;
	int		k;
	char	*new_line;
	int		found_line;

	if (!*line && !buff[0])
		return (0);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	found_line = (buff[i] == '\n') ? 1 : 0;
	new_line = malloc(sizeof(char) * (ft_strlen(*line) + i + 1 + found_line));
	if (!new_line)
		return (-1);
	j = 0;
	while (j < ft_strlen(*line))
	{
		new_line[j] = (*line)[j];
		j++;
	}
	k = 0;
	while (k < i + found_line)
	{
		new_line[j + k] = buff[k];
		k++;
	}
	new_line[j + k] = '\0';
	free(*line);
	*line = new_line;
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (found_line)
		i++;
	k = 0;
	while (buff[i])
		buff[k++] = buff[i++];
	buff[k] = '\0';
	return (found_line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			found_line;
	int			n;

	line = NULL;
	found_line = 0;
	while (!found_line)
	{
		found_line = extract(&line, buff);
		if (found_line == -1)
			return (NULL);
		if (!found_line)
		{
			n = read(fd, buff, BUFFER_SIZE);
			if (n == -1)
				return (NULL);
			if (n == 0)
				found_line = 1;
			buff[n] = '\0';
		}
	}
	return (line);
}

int	main(int ac, char **av)
{
	char	*line;
	int		fd;

	if (ac != 2)
		fd = 0;
	else
		fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	if (ac == 2)
		close(fd);
	return (0);
}