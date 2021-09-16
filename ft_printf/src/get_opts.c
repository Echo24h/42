#include "ft_printf.h"
#include "libft.h"

void	get_width(const char **format, t_opts *opts)
{
	if (!ft_isdigit(**format))
		return ;
	opts->width = 0;
	while (**format && ft_isdigit(**format))
	{
		opts->width = opts->width * 10 + (**format - 48);
		(*format)++;
	}
	if (opts->width < 0) // avoiding error when width specified is larger than INT_MAX
		opts->width *= -1;
}

void	get_precision(const char **format, t_opts *opts)
{
	int	precision;

	if (**format != '.')
		return ;
	(*format)++;
	opts->precision = 0;
	while (**format && ft_isdigit(**format))
	{
		opts->precision = opts->precision * 10 + (**format - 48);

		(*format)++;
	}
	if (opts->precision < 0) // avoiding error when precision specified is larger than INT_MAX
		opts->precision *= -1;
}


void	get_flags(const char **format, t_opts *opts)
{
	while (**format && is_flag(**format))
	{
		if (**format == ' ')
			opts->flags.blank = 1;
		else if (**format == '-')
			opts->flags.minus = 1;
		else if (**format == '+')
			opts->flags.plus = 1;
		else if (**format == '0')
			opts->flags.zero = 1;
		else
			opts->flags.hashtag = 1;
		(*format)++;
	}
}

t_opts	inst_opts()
{
	t_opts	opts;
	
	opts.width = -1;
	opts.precision = -1;
	opts.flags.minus = 0;
	opts.flags.plus = 0;
	opts.flags.zero = 0;
	opts.flags.blank = 0;
	opts.flags.hashtag = 0;
	return (opts);
}

t_opts	get_opts(const char **format)
{
	t_opts	opts;

	opts = inst_opts();
	printf("here baby : %c\n", **format);
	print_opts(opts);
	get_flags(format, &opts);
	get_width(format, &opts);
	get_precision(format, &opts);
	printf("\nAnd now here ;) : %c\n", **format);
	print_opts(opts);
	return (opts);
}