/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:42:49 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/06 08:48:42 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_mlx(t_var *var)
{
	var->mlx = mlx_init();
	if (!var->mlx)
	{
		free(var);
		return (0);
	}
	var->win = mlx_new_window(var->mlx, W, H, "fract-ol");
	var->img = mlx_new_image(var->mlx, W, H);
	if (!var->win || !var->img)
	{
		mmmm_ok_you_guys_are_free_to_go(var);
		return (0);
	}
	var->img_data = mlx_get_data_addr(var->img, &(var->bpp),
			&(var->size_line), &(var->endian));
	if (!var->img_data)
	{
		mmmm_ok_you_guys_are_free_to_go(var);
		return (0);
	}
	return (1);
}

int	init_var(t_var *var)
{
	var->mlx = NULL;
	var->win = NULL;
	var->img = NULL;
	var->img_data = NULL;
	var->iteration_max = 40;
	var->zoom_speed = 3;
	var->palette = 0;
	var->count_scroll = 0;
	var->count_unzoom = 0;
	if (var->fractal == JULIA)
	{
		var->limits = get_limits(JULIA_MAX_RE, JULIA_MIN_RE,
				JULIA_MAX_IM, JULIA_MIN_IM);
		var->allow_julia_variation = 0;
		var->julia_step_x = (fabs(MAX_RE) + fabs(MIN_RE)) / W;
		var->julia_step_y = (fabs(MAX_IM) + fabs(MIN_IM)) / H;
	}
	else if (var->fractal == MANDELBROT)
		var->limits = get_limits(MAX_RE, MIN_RE, MAX_IM, MIN_IM);
	else if (var->fractal == BURNING_SHIP)
		var->limits = get_limits(BURNING_SHIP_MAX_RE, BURNING_SHIP_MIN_RE,
				BURNING_SHIP_MAX_IM, BURNING_SHIP_MIN_IM);
	return (1);
}
