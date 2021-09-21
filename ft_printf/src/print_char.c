#include "libft.h"
#include "utils.h"

int	print_char(int c, t_opts opts)
{
	int	count_char;

	count_char = 0;
	if (opts.flags.minus)
		ft_putchar(c);
	while (++count_char < opts.width)
		ft_putchar(' ');	
	if (!opts.flags.minus)
		ft_putchar(c);
	return (count_char);
}
