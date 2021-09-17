#include "ft_printf.h"
#include "libft.h"

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

int	print_str(char *str, t_opts opts)
{
	int		count_char;

	str = str ? ft_strdup(str) : ft_strdup("(null)");
	if (opts.precision != -1)
		str = ft_substr(str, 0, opts.precision);
	count_char = ft_strlen(str);
	if (opts.flags.minus)
		ft_putstr(str);
	while (count_char < opts.width)
	{
		if (opts.flags.zero && !opts.flags.minus)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count_char++;
	}
	if (!opts.flags.minus)
		ft_putstr(str);
	free(str);
	return (count_char);
}

int	print_ptr(void *ptr, t_opts opts)
{
	return (0);
}

int	print_int(int x, t_opts opts)
{
	return (0);
}

int	print_uint(unsigned int x, t_opts opts)
{
	return (0);
}

int	print_hexa(unsigned int x, int maj, t_opts opts)
{
	return (0);
}

int	print_percentage(t_opts opts)
{
	return (0);
}

int	print_var(const char **format, va_list *ap)
{
	t_opts	opts;
	
	opts = get_opts(format);
	if (**format == 'c')
		return (print_char(va_arg(*ap, int), opts));
	else if (**format == 's')
		return (print_str(va_arg(*ap, char *), opts));
	else if (**format == 'p')
		return (print_ptr(va_arg(*ap, void *), opts));
	else if (**format == 'd' || **format == 'i')
		return (print_int(va_arg(*ap, int), opts));
	else if (**format == 'u')
		return (print_uint(va_arg(*ap, unsigned int), opts));
	else if (**format == 'x')
		return (print_hexa(va_arg(*ap, int), 0, opts));
	else if (**format == 'X')
		return (print_hexa(va_arg(*ap, int), 1, opts));
	else if (**format == '%')
		return (print_percentage(opts));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count_char;

	count_char = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count_char += print_var(&format, &ap);
		}
		else
		{
			ft_putchar(*format);
			count_char++;
		}
		if(*format)
			format++;
	}
	va_end(ap);
	return (count_char);
}