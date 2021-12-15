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

int		parse(int ac, char **av, pid_t *server_pid)
{
	if (ac != 3)
		return (0);
	*server_pid = ft_atoi(av[1]);
	return (1);
}

void	sigusr1_handler(int signum)
{
	ft_printf("The data has been received successfully!\n");
}

int	main(int ac, char **av)
{
	int					i;
	int					j;
	char				buff[8];
	pid_t				server_pid;
	struct sigaction	setup_sigusr1;

	if (!parse(ac, av, &server_pid))
		return (1); // error

	setup_sigusr1.sa_handler = &sigusr1_handler;
	sigemptyset(&setup_sigusr1.sa_mask);
	sigaddset(&setup_sigusr1.sa_mask, SIGUSR1);
	setup_sigusr1.sa_flags = 0;
	sigaction(SIGUSR1, &setup_sigusr1, NULL);

	i = 0;
	while (av[2][i])
	{
		set_buff(buff, av[2][i]);
		//display_buff(buff);
		j = 0;
		while (j < 8)
		{
			//ft_printf("sending signal\n");
			if (buff[j] == '0')
			{
				//ft_printf("sending sigusr1\n");
				kill(server_pid, SIGUSR1);
			}
			else
			{
				//ft_printf("sending sigusr2\n");
				kill(server_pid, SIGUSR2);
			}
			//ft_printf("after pause\n");
			usleep(100);
			//printf("\n");
			j++;
		}
		i++;
	}
	i = 0;
	while (i++ < 8)
	{
		//ft_printf("sending sigusr1\n");
		kill(server_pid, SIGUSR1);
		usleep(100);
	}
	return (0);
}
