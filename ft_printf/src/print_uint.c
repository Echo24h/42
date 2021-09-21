#include "libft.h"
#include "utils.h"

int		get_len_uint(unsigned int nbr, int precision)
{
	int	len;

	if (!nbr && precision == 0)
		return (0);
	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	ft_putuint(unsigned int nbr, t_opts opts, int len_nbr, int first_entry)
{
	if (first_entry)
	{
		if (nbr == 0 && opts.precision == 0)
			return ;
		while (opts.precision-- > len_nbr)
			ft_putchar('0');
	}
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		ft_putuint(nbr / 10, opts, len_nbr, 0);
		ft_putuint(nbr % 10, opts, len_nbr, 0);
	}
}

int	print_uint(unsigned int nbr, t_opts opts)
{
	int	count_char;
	int	len_nbr;

	len_nbr = get_len_uint(nbr, opts.precision);
	count_char = (opts.precision > len_nbr) ? opts.precision : len_nbr;
	if (opts.flags.minus)
		ft_putuint(nbr, opts, len_nbr, 1);
	while (count_char < opts.width)
	{
		if (opts.flags.zero && !opts.flags.minus && opts.precision == -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count_char++;
	}
	if (!opts.flags.minus)
		ft_putuint(nbr, opts, len_nbr, 1);
	return (count_char);
}
