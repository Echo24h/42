#include "minitalk.h"

# define BUFFER_SIZE 1024

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

void	addto_buffer(unsigned char c, siginfo_t *info)
{
	static int	i = 0;
	static char	buff[BUFFER_SIZE];

	buff[i++] = c;
	if (i == BUFFER_SIZE - 1 || c == '\0')
	{
		buff[i] = '\0';
		write(1, buff, ft_strlen(buff));
		if (buff[i - 1] == '\\' && buff[i - 2] != '\\')
		{
			buff[0] = '\\';
			i = 1;
		}
		else
			i = 0;
		write(1, "\n", 1);
	}
	if (c == '\0' && info->si_pid)
		kill(info->si_pid, SIGUSR1);
}

void	addto_byte(char bit, siginfo_t *info)
{
	static int	i = 0;
	static char	byte[8];

	byte[i++] = bit;
	if (i > 7)
	{
		addto_buffer(read_byte(byte), info);
		i = 0;
	}
}

void	sigusr1_handler(int signum, siginfo_t *info, void *context)
{
	addto_byte('0', info);
}

void	sigusr2_handler(int signum, siginfo_t *info, void *context)
{
	addto_byte('1', info);
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

	setup_sigusr1.sa_sigaction = &sigusr1_handler;
	setup_sigusr1.sa_mask = block_mask;
	setup_sigusr1.sa_flags = SA_SIGINFO;
	
	setup_sigusr2.sa_sigaction = &sigusr2_handler;
	setup_sigusr2.sa_mask = block_mask;
	setup_sigusr2.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &setup_sigusr1, NULL);
	sigaction(SIGUSR2, &setup_sigusr2, NULL);

	while (1)
		pause();
	return (0);
}
