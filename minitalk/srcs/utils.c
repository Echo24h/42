#include "minitalk.h"

void	display_buff(char *buff)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (buff[i] == '\0')
			ft_printf("x");
		else
			ft_printf("%c", buff[i]);
		i++;
	}
	ft_printf("\n");
}

char	*uint_to_binary(unsigned int nb)
{
	char	*bits;
	int		i;

	bits = malloc(sizeof(char) * 33);
	bits[32] = '\0';	
	i = 32;
	while (i--)
	{
		bits[i] = nb % 2 + 48;
		nb /= 2;
	}
	return (bits);
}

unsigned int	binary_to_uint(char *bits)
{
	unsigned int	nb;
	int				i;

	nb = 0;
	i = 0;
	while (bits[i])
	{
		nb = nb * 2 + bits[i] - 48;
		i++;
	}
	return (nb);
}
