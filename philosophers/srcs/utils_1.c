#include "philo.h"

int		ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}

void	ft_putms(float nbr)
{
	int	i;

	ft_putnbr(nbr);
	nbr = nbr - (int)nbr;
	i = 0;
	ft_putchar('.');
	while (i < 3)
	{
		nbr *= 10;
		ft_putchar((int)nbr % 10 + 48);
		i++;
	}
}