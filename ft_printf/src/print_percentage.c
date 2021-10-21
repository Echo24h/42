/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:35:19 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/18 17:35:20 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

int	print_percentage(t_opts opts)
{
	int	count_char;

	count_char = 1;
	if (opts.flags.minus)
		ft_putchar('%');
	while (count_char < opts.width)
	{
		if (opts.flags.zero && !opts.flags.minus)
			ft_putchar('0');
		else
			ft_putchar(' ');
		count_char++;
	}
	if (!opts.flags.minus)
		ft_putchar('%');
	return (count_char);
}
