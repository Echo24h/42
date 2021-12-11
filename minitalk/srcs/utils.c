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
