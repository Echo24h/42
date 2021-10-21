/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:56:41 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/19 12:56:42 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	print_str(char *str, t_opts opts)
{
	int		count_char;

	if (str)
		str = ft_strdup(str);
	else
		str = ft_strdup("(null)");
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
