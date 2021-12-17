#include "libft.h"
#include <fcntl.h>

int	main()
{
	char	*line;
	int	fd;
	long long int	sum;
	int		i;

	fd = open("results.txt", O_RDONLY);
	sum = 0;
	i = 0;
	while ((line = get_next_line(fd)))
	{
		i++;
		sum += ft_atoi(line);
	}
	close(fd);
	printf("%lld\n", sum / i);
	return (0);
}
