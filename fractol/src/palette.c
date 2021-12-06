/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:44:50 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/06 08:44:55 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	palette(t_var *var, int nb_iteration)
{
	if (var->palette == 0)
		return (palette_1(var, nb_iteration));
	else if (var->palette == 1)
		return (rainbow_1(var, nb_iteration));
	else if (var->palette == 2)
		return (palette_0(var, nb_iteration));
	else if (var->palette == 3)
		return (palette_3(var, nb_iteration));
	else if (var->palette == 4)
		return (grey(var, nb_iteration));
	else if (var->palette == 5)
		return (smooth_red(var, nb_iteration));
	else if (var->palette == 6)
		return (zebra(var, nb_iteration));
	else if (var->palette == 7)
		return (rainbow_0(var, nb_iteration));
	else if (var->palette == 8)
		return (palette_2(var, nb_iteration));
	return (0);
}
