#include "minitalk.h"

void	set_buff(char *buff, unsigned int c)
{
	int	n;

	n = 8;
	while (n--)
	{
		buff[n] = c % 2 + 48;
		c /= 2;
	}
}

int	parse(int ac, char **av, pid_t *server_pid)
{
	if (ac != 3)
		return (0);
	*server_pid = ft_atoi(av[1]);
	return (1);
}

// SIGUSR1 => 0
// SIGUSR2 => 1
int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	buff[8];
	pid_t	server_pid;

	ft_printf("I'm the client boy!\n");
	if (!parse(ac, av, &server_pid))
		return (1); // error
	printf("Server PID : %d\n", (int)server_pid);
	i = 0;
	while (av[2][i])
	{
		set_buff(buff, av[2][i]);
		display_buff(buff);
		j = 0;
		while (j < 8)
		{
			if (buff[j] == '0')
			{
				printf("sending sigusr1 | ");
				kill(server_pid, SIGUSR1);
			}
			else
			{
				printf("sending sigusr2 | ");
				kill(server_pid, SIGUSR2);
			}
			printf("there, %c\n", buff[j]);
			j++;
		}
		i++;
	}
	/*
	i = 0;
	while (i++ < 8)
		kill(server_pid, SIGUSR1);
	*/
	return (0);
}
