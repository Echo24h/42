/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:42:14 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/06 08:42:43 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, void *param)
{
	t_var	*var;

	var = (t_var *)param;
	if (keycode == 126)
		handle_move(var, TOP);
	else if (keycode == 125)
		handle_move(var, BOTTOM);
	else if (keycode == 123)
		handle_move(var, LEFT);
	else if (keycode == 124)
		handle_move(var, RIGHT);
	else if (keycode == 53)
		exit_prog(var);
	else if (keycode == 35)
		switch_palette(var);
	else if (keycode == 15)
		reset_fractal(var);
	else if (keycode == 9)
		var->allow_julia_variation = !var->allow_julia_variation;
	return (1);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_var	*var;

	if (!(x >= 0 && x < W && y >= 0 && y < H))
		return (1);
	var = (t_var *)param;
	if (button == 4)
		handle_zoom(var);
	else if (button == 5)
		handle_unzoom(var);
	else if (button == 1)
		add_to_iteration_max(var, 10);
	else if (button == 2)
		add_to_iteration_max(var, -10);
	return (1);
}

int	mouse_motion_hook(int x, int y, t_var *var)
{
	if (var->allow_julia_variation)
	{
		var->julia_point_r = x * var->julia_step_x + MIN_RE;
		var->julia_point_i = MAX_IM - y * var->julia_step_y;
		draw_fractal(var);
	}
	return (1);
}
