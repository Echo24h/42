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

void	send_bit(pid_t server_pid, char *client_message)
{
	static char		*msg = NULL;
	static pid_t	pid = 0;
	static int		i = 0;
	static char		buff[8];

	printf("%d\n", i);
	if (!msg)
		msg = ft_strdup(client_message);
	if (!msg)
		; // error malloc
	if (!pid)
		pid = server_pid;
	if (i % 8 == 0)
	{
		set_buff(buff, msg[i / 8]);
		display_buff(buff);
	}
	if (buff[i % 8] == '0')
	{
		ft_printf("sending sigusr1\n");
		kill(pid, SIGUSR1);
	}
	else
	{
		ft_printf("sending sigusr2\n");
		kill(pid, SIGUSR2);
	}
	i++;
}

void	sigusr1_handler(int signum)
{
	ft_printf("The data has been received successfully!\n");
	exit(0);
}

void	sigusr2_handler(int signum)
{
	send_bit(0, 0);
}

int	main(int ac, char **av)
{
	int					i;
	int					j;
	pid_t				server_pid;
	struct sigaction	setup_sigusr1;
	struct sigaction	setup_sigusr2;
	sigset_t			block_mask;

	if (!parse(ac, av, &server_pid))
		return (1); // error

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGUSR1);
	sigaddset(&block_mask, SIGUSR2);

	setup_sigusr1.sa_handler = &sigusr1_handler;
	setup_sigusr1.sa_mask = block_mask;
	setup_sigusr1.sa_flags = 0;
	sigaction(SIGUSR1, &setup_sigusr1, NULL);

	setup_sigusr2.sa_handler = &sigusr2_handler;
	setup_sigusr2.sa_mask = block_mask;
	setup_sigusr2.sa_flags = 0;
	sigaction(SIGUSR2, &setup_sigusr2, NULL);

	send_bit(server_pid, av[2]);

	while (1)
		pause();
	return (0);
}
