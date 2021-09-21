#include "libft.h"
#include "utils.h"

int		get_len_uint_hexa(unsigned int nbr, int precision)
{
	int	len;

	if (!nbr && precision == 0)
		return (0);
	if (!nbr)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

void	ft_putuint_hexa(unsigned int nbr, t_opts opts, int first_entry, int maj)
{
	int	len_nbr;

	if (first_entry)
	{
		if (opts.flags.hashtag)
			maj ? ft_putstr("0X") : ft_putstr("0x");
		if (nbr == 0 && opts.precision == 0)
			return ;
		len_nbr = get_len_uint_hexa(nbr, opts.precision);
		while (opts.precision-- > len_nbr)
			ft_putchar('0');
	}
	if (nbr >= 0 && nbr <= 15)
		maj ? ft_putchar("0123456789ABCDEF"[nbr]) : ft_putchar("0123456789abcdef"[nbr]);
	else
	{
		ft_putuint_hexa(nbr / 16, opts, 0, maj);
		ft_putuint_hexa(nbr % 16, opts, 0, maj);
	}
}

int		print_hexa(unsigned int nbr, t_opts opts, int maj)
{
	int	count_char;
	int	len_nbr;

	len_nbr = get_len_uint_hexa(nbr, opts.precision);
	count_char = (opts.precision > len_nbr) ? opts.precision : len_nbr;
	if (opts.flags.hashtag)
		count_char += 2;
	if (opts.flags.minus)
		ft_putuint_hexa(nbr, opts, 1, maj);
	while (count_char < opts.width)
	{
		if (opts.flags.zero && !opts.flags.minus && opts.precision == -1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count_char++;
	}
	if (!opts.flags.minus)
		ft_putuint_hexa(nbr, opts, 1, maj);
	return (count_char);
}
