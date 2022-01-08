#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	is_whitespace(int c)
{
	if (c == '\v' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	neg;

	res = 0;
	neg = 0;
	while (*str && is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (ft_isdigit(*str))
		res = res * 10 - ((int)*(str++) - 48);
	if (neg)
		return (res);
	return (-res);
}

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

static char	*get_next_line(int fd)
{
	char	c;
	char	*line;
	int		n;

	line = NULL;
	while ((n = read(fd, &c, 1)) > 0 && c != '\n')
	{
		line = ft_append_char(line, c);
		if (!line)
			return (NULL);
	}
	if (n > 0)
	{
		line = ft_append_char(line, c);
		if (!line)
			return (NULL);
	}
	if (n == -1)
		return (NULL);
	return (line);
}

void	print_average(char *nb_els, char *file)
{
	int				i;
	int				n;
	int				fd;
	int				max;
	int				min;
	long long int	sum;
	char			*line;

	printf("%3s => ", nb_els);
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
