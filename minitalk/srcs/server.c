#include "minitalk.h"

# define BUFFER_SIZE 1024

void	display_byte(char *byte)
{
	int	i;

	if (!byte)
		return ;
	i = 0;
	while (i < 8)
		write(1, &byte[i++], 1);
	write(1, "\n", 1);
}

char	read_byte(char *byte)
{
	unsigned int	c;
	int				n;

	c = 0;
	n = 8;
	while (n--)
		c += (byte[n] - '0') * (1 << (7 - n));
	return (c);
}

char	*ft_append_char_to_str(char *str, char c)
{
	int		i;
	char	*res;

	if (!str)
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = c;
		res[1] = '\0';
		//ft_printf("in res: %s\n", res);
		return (res);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	free(str);
	//ft_printf("in res: %s\n", res);
	return (res);
}

int		addto_byte(char bit, pid_t client_pid)
{
	static int		i = 0;
	static char		byte[8];
	static char		*msg = NULL;
	unsigned char	c;

	byte[i++] = bit;
	if (i > 7)
	{
		//display_byte(byte);
		c = read_byte(byte);
		msg = ft_append_char_to_str(msg, c);
		if (c == '\0')
		{
			ft_printf(msg);
			//free(msg);
			//msg = NULL;
			//ft_printf("sending sigusr1\n");
			kill(client_pid, SIGUSR1);
			return (0);
		}
		i = 0;
	}
	return (1);
}

void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t	client_pid = 0;

	if (!client_pid)
	{
		if (!info->si_pid)
		{
			ft_printf("error : si_pid = 0\n"); // error
		}
		else
			client_pid = info->si_pid;
	}
	if (signum == SIGUSR1)
	{
		//ft_printf("add byte 0\n");
		if (!addto_byte('0', client_pid))
			client_pid = 0;
	}
	else
	{
		//ft_printf("add byte 1\n");
		if (!addto_byte('1', client_pid))
			client_pid = 0;
	}
	//ft_printf("sending sigusr2\n");
	if (client_pid)
		kill(client_pid, SIGUSR2);
}

int	main(int ac, char **av)
{
	struct sigaction	setup_sigusr1;
	struct sigaction	setup_sigusr2;
	sigset_t			block_mask;

	ft_printf("%d\n", (int)getpid());

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGUSR1);
	sigaddset(&block_mask, SIGUSR2);

	setup_sigusr1.sa_sigaction = &sigusr_handler;
	setup_sigusr1.sa_mask = block_mask;
	setup_sigusr1.sa_flags = SA_SIGINFO;
	
	setup_sigusr2.sa_sigaction = &sigusr_handler;
	setup_sigusr2.sa_mask = block_mask;
	setup_sigusr2.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &setup_sigusr1, NULL);
	sigaction(SIGUSR2, &setup_sigusr2, NULL);

	while (1)
		pause();
	return (0);
}
