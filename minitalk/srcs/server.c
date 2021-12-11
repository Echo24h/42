#include "minitalk.h"

char	buff[8];

char	read_buffer(char *buff)
{
	unsigned int	c;
	int				n;

	c = 0;
	n = 8;
	while (n--)
		c += (buff[n] - '0') * (1 << (7 - n));
	return (c);
}

void	reset_buffer(char *buff)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		buff[i] = '\0';
		i++;
	}
}

void	addto_buffer(char *buff, char c)
{
	int	i;

	i = 0;
	while (i < 8 && buff[i])
		i++;
	if (i == 8)
	{
		ft_printf("%c", read_buffer(buff));
		reset_buffer(buff);
	}
	else
		buff[i] = c;
}

void	sigusr1_handler(int signum)
{
	ft_printf("In sigusr1 handler\n");
	addto_buffer(buff, '0');
	//signal(SIGUSR1, sigusr1_handler);
}

void	sigusr2_handler(int signum)
{
	ft_printf("In sigusr2 handler\n");
	addto_buffer(buff, '1');
	//signal(SIGUSR2, sigusr2_handler);
}

int	main(int ac, char **av)
{
	char	buff[8];

	ft_printf("%d\n", (int)getpid());
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);
	while (1)
		;
	return (0);
}
