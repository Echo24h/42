#include "libft.h"
#include "utils.h"

int		get_len_addr(uintptr_t addr, int precision)
{
	int	len;

	if (!addr && precision == 0)
		return (0);
	if (!addr)
		return (1);
	len = 0;
	while (addr)
	{
		addr /= 16;
		len++;
	}
	return (len);
}

void	print_addr(uintptr_t addr, int precision, int len_addr, int x)
{
	if (x == 1)
	{
		ft_putstr("0x");
		if (!len_addr && precision == 0)
			return ;
		while (precision-- > len_addr)
			ft_putchar('0');
	}
	if (addr >= 0 && addr <= 15)
		ft_putchar("0123456789abcdef"[addr]);
	else
	{
		print_addr(addr / 16, precision, len_addr, 0);
		print_addr(addr % 16, precision, len_addr, 0);
	}
}

int	print_ptr(void *ptr, t_opts opts)
{
	int	count_char;
	int	len_addr;;
	uintptr_t addr = (uintptr_t)ptr;

	len_addr = get_len_addr(addr, opts.precision);
	count_char = (opts.precision > len_addr) ? 2 + opts.precision : 2 + len_addr;
	if (opts.flags.minus || opts.flags.zero)
		print_addr(addr, opts.precision, len_addr, 1);
	while (count_char < opts.width)
	{
		if (opts.flags.zero && !opts.flags.minus)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count_char++;
	}
	if (!opts.flags.minus && !opts.flags.zero)
		print_addr(addr, opts.precision, len_addr, 1);
	return (count_char);
}
