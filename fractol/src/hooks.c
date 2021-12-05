#include "fractol.h"
#include <unistd.h>

int	exit_prog(t_var *var)
{
	mlx_destroy_image(MLX, IMG);
	mlx_destroy_window(MLX, WIN);
	exit(0);
	return (1);
}

void	switch_palette(t_var *var)
{
	var->palette += 1;
	if (var->palette > 2)
		var->palette = 0;
	draw_fractal(var);
}

void	reset_fractal(t_var *var)
{
	var->iteration_max = 40;
	if (var->fractal == MANDELBROT)
		var->limits = get_limits(MAX_RE, MIN_RE, MAX_IM, MIN_IM);
	else if (var->fractal == JULIA)
		var->limits = get_limits(JULIA_MAX_RE, JULIA_MIN_RE, JULIA_MAX_IM, JULIA_MIN_IM);
	else if (var->fractal == BURNING_SHIP)
		var->limits = get_limits(BURNING_SHIP_MAX_RE, BURNING_SHIP_MIN_RE, BURNING_SHIP_MAX_IM, BURNING_SHIP_MIN_IM);
	draw_fractal(var);
}

int	key_hook(int keycode, void *param)
{
	t_var	*var;

	//printf("%d\n", keycode);
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

int	mouse_hook(int button, int x,int y, void *param)
{
	t_var	*var;

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
