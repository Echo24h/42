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

void	handle_width(unsigned int nbr, t_opts opts, int len_nbr)
{
	int	x;

	x = (opts.flags.hashtag && nbr) ? 2 : 0;
	while (opts.width-- > len_nbr + x)
		ft_putchar('0');
}

void	ft_putuint_hexa(unsigned int nbr, t_opts opts, int first_entry, int maj)
{
	int	len_nbr;

	if (first_entry)
	{
		if (nbr == 0 && opts.precision == 0)
			return ;
		if (opts.flags.hashtag && nbr)
			maj ? ft_putstr("0X") : ft_putstr("0x");
		len_nbr = get_len_uint_hexa(nbr, opts.precision);
		while (opts.precision-- > len_nbr)
			ft_putchar('0');
		if (opts.flags.zero)
			handle_width(nbr, opts, len_nbr);
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
	if (opts.flags.hashtag && nbr)
		count_char += 2;
	if (opts.flags.minus)
		ft_putuint_hexa(nbr, opts, 1, maj);
	while (count_char < opts.width)
	{
		if (!opts.flags.zero)
			ft_putchar(' ');
		count_char++;
	}
	if (!opts.flags.minus)
		ft_putuint_hexa(nbr, opts, 1, maj);
	return (count_char);
}
