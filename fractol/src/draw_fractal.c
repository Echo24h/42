/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:35:01 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/06 08:36:18 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_dists(t_var *var)
{
	var->dist_x = fabsl(var->limits.curr_max_re - var->limits.curr_min_re);
	var->dist_y = fabsl(var->limits.curr_max_im - var->limits.curr_min_im);
}

static void	set_steps(t_var *var)
{
	var->step_x = var->dist_x / W;
	var->step_y = var->dist_y / H;
}

static unsigned int	get_color(t_var *var, long double c_r, long double c_i)
{
	int	iteration;

	if (var->fractal == MANDELBROT)
		iteration = mandelbrot(var, c_r, c_i);
	else if (var->fractal == JULIA)
		iteration = julia(var, c_r, c_i);
	else if (var->fractal == BURNING_SHIP)
		iteration = burning_ship(var, c_r, c_i);
	else
		iteration = 1;
	return (palette(var, iteration));
}

static void	draw_iteration_max(t_var *var)
{
	char	*s;
	char	*n;

	n = ft_itoa(var->iteration_max);
	s = ft_strjoin("Iterations : ", n);
	free(n);
	mlx_string_put(var->mlx, var->win, 10, 20, 0xffffff, s);
	free(s);
}

// why do i do H - 1 - y ? Because what the prank boy
void	draw_fractal(t_var *var)
{
	int			x;
	int			y;
	long double	c_r;
	long double	c_i;

	set_dists(var);
	set_steps(var);
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			c_r = x * var->step_x + var->limits.curr_min_re;
			c_i = var->limits.curr_max_im - y * var->step_y;
			put_pixel(var, x, H - 1 - y, get_color(var, c_r, c_i));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	draw_iteration_max(var);
}
