#include "get_next_line.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	fd;
	int	fd2;
	int	fd3;
	char	*line;
	char	*line2;
	char	*line3;
	int	x;

	if (!ac)
		return (1);
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	x = 1;
	while (x)
	{
		line = get_next_line(5);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
		if (!line && !line2 && !line3)
			x = 0;
		printf("line: %s", line);
		if (!line)
			printf("\n");
		printf("line2: %s", line2);
		if (!line2)
			printf("\n");
		printf("line3: %s", line3);
		if (!line3)
			printf("\n");
		free(line);
		free(line2);
		free(line3);
		printf("\n");
	}
	close(fd);
	close(fd2);
	close(fd3);
	//system("leaks prog");
	return (0);
}
