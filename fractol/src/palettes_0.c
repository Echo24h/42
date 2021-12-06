/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:45:18 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/06 08:45:34 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	palette_0(t_var *var, int nb_iteration)
{
	t_rgb	rgb;

	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.3 * nb_iteration + 3) * 127 + 128;
	rgb.g = sin(0.05 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.05 * nb_iteration + 1) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	palette_1(t_var *var, int nb_iteration)
{
	t_rgb	rgb;

	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.05 * nb_iteration) * 127 + 128;
	rgb.g = sin(0.3 * nb_iteration + 1) * 127 + 128;
	rgb.b = sin(0.3 * nb_iteration) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	palette_2(t_var *var, int nb_iteration)
{
	t_rgb	rgb;

	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.05 * nb_iteration) * 127 + 128;
	rgb.g = sin(0.1 * nb_iteration + 1) * 127 + 128;
	rgb.b = sin(0.1 * nb_iteration + 2) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	palette_3(t_var *var, int nb_iteration)
{
	t_rgb	rgb;

	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.2 * nb_iteration + 3) * 127 + 128;
	rgb.g = sin(0.02 * nb_iteration + 1) * 127 + 128;
	rgb.b = sin(0.2 * nb_iteration + 2) * 127 + 128;
	return (rgb_to_int(rgb));
}
