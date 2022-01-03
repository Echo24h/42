#include "libft.h"
#include <fcntl.h>

void	print_average(char *nb_els, char *file)
{
	int				i;
	int				n;
	int				fd;
	int				max;
	int				min;
	long long int	sum;
	char			*line;

	ft_printf("%3s => ", nb_els);
	fd = open(file, O_RDONLY);
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
	printf("average: %4d | min: %4d | max: %4d\n", (int)(sum / i), min, max);
}

int	main()
{
	print_average("3", "results_3.txt");
	print_average("5", "results_5.txt");
	print_average("100", "results_100.txt");
	print_average("500", "results_500.txt");
	return (0);
}
