#include "fractol.h"

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
	if (var->palette > 1)
		var->palette = 0;
	draw_fractal(var);
}

void	reset_fractal(t_var *var)
{
	var->iteration_max = 50;
	var->limits = get_limits(MAX_RE, MIN_RE, MAX_IM, MIN_IM);
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
		add_to_iteration_max(var, 1);
	else if (button == 2)
		add_to_iteration_max(var, -1);
	return (1);
}
