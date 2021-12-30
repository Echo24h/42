#include "libft.h"
#include <fcntl.h>

int	main()
{
	char	*line;
	int	fd;
	long long int	sum;
	int				max;
	int				min;
	int		i;
	int		n;

	fd = open("results.txt", O_RDONLY);
	sum = 0;
	i = 0;
	line = get_next_line(fd);
	max = ft_atoi(line);
	min = ft_atoi(line);
	while (line)
	{
		n = ft_atoi(line);
		if (n < min)
			min = n;
		else if (n > max)
			max = n;
		sum += n;
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	printf("average: %lld | min: %d | max: %d\n", sum / i, min, max);
	return (0);
}
