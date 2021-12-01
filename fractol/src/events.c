#include "fractol.h"

void	handle_zoom(t_var *var)
{
	long double	dt;
	long double	dr;
	long double	db;
	long double	dl;

	var->count_scroll++;
	if (var->count_scroll == 1)
		return ;
	var->count_scroll = 0;
	mlx_mouse_get_pos(WIN, &(var->mouse_x), &(var->mouse_y));
	dt = var->mouse_y * var->step_y;
	dr = (W - var->mouse_x) * var->step_x;
	db = (H - var->mouse_y) * var->step_y;
	dl = var->mouse_x * var->step_x;
	var->limits = get_limits(var->limits.curr_max_re - (dr / var->zoom_speed),
		var->limits.curr_min_re + (dl / var->zoom_speed),
		var->limits.curr_max_im - (dt / var->zoom_speed),
		var->limits.curr_min_im + (db / var->zoom_speed));
	var->iteration_max += 3;
	draw_fractal(var);
}

void	handle_unzoom(t_var *var)
{
	long double	dh;
	long double	dv;

	var->count_scroll++;
	if (var->count_scroll == 1)
		return ;
	var->count_scroll = 0;
	dh = (W / 2) * var->step_x;
	dv = (H / 2) * var->step_y;
	var->limits = get_limits(var->limits.curr_max_re + (dh / var->zoom_speed),
		var->limits.curr_min_re - (dh / var->zoom_speed),
		var->limits.curr_max_im + (dv / var->zoom_speed),
		var->limits.curr_min_im - (dv / var->zoom_speed));
	if (var->iteration_max > 51)
		var->iteration_max -= 2;
	else if (var->iteration_max == 51)
		var->iteration_max = 50;
	draw_fractal(var);
}

void	handle_move(t_var *var, int direction)
{
	if (direction == TOP)
	{
		var->limits.curr_max_im = var->limits.curr_max_im + var->dist_y / 10;
		var->limits.curr_min_im = var->limits.curr_min_im + var->dist_y / 10;
	}
	else if (direction == RIGHT)
	{
		var->limits.curr_max_re = var->limits.curr_max_re + var->dist_x / 10;
		var->limits.curr_min_re = var->limits.curr_min_re + var->dist_x / 10;
	}
	else if (direction == BOTTOM)
	{
		var->limits.curr_max_im = var->limits.curr_max_im - var->dist_y / 10;
		var->limits.curr_min_im = var->limits.curr_min_im - var->dist_y / 10;
	}
	else if (direction == LEFT)
	{
		var->limits.curr_max_re = var->limits.curr_max_re - var->dist_x / 10;
		var->limits.curr_min_re = var->limits.curr_min_re - var->dist_x / 10;
	}
	draw_fractal(var);
}

void	add_to_iteration_max(t_var *var, int n)
{
	var->iteration_max += n;
	if (var->iteration_max < 1)
		var->iteration_max = 1;
	draw_fractal(var);
}
