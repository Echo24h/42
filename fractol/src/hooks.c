#include "fractol.h"

void	print_limits(t_var *var)
{
	printf("\ncurr_max_re: %f\n", var->limits.curr_max_re);
	printf("curr_min_re: %f\n", var->limits.curr_min_re);
	printf("curr_max_im: %f\n", var->limits.curr_max_im);
	printf("curr_min_im: %f\n\n", var->limits.curr_min_im);
}

int	key_hook(int keycode, void *param)
{
	t_var	*var;

	var = (t_var *)param;
	if (keycode == 126)
		var->zoom = 1;
	if (keycode == 125)
		var->unzoom = 1;
	return (1);
}

int	mouse_hook(int button, int x,int y, void *param)
{
	t_var	*var;

	var = (t_var *)param;
	if (button == 4)
		var->zoom = 1;
	else if (button == 5)
		var->unzoom = 1;
	return (1);
}

void	handle_zoom(t_var *var)
{
	double	dt;
	double	dr;
	double	db;
	double	dl;

	mlx_mouse_get_pos(WIN, &(var->mouse_x), &(var->mouse_y));
	dt = var->mouse_y * var->step_y;
	dr = (W - var->mouse_x) * var->step_x;
	db = (H - var->mouse_y) * var->step_y;
	dl = var->mouse_x * var->step_x;
	var->limits = get_limits(var->limits.curr_max_re - (dr / var->zoom_speed),
		var->limits.curr_min_re + (dl / var->zoom_speed),
		var->limits.curr_max_im - (dt / var->zoom_speed),
		var->limits.curr_min_im + (db / var->zoom_speed));
	//print_limits(var);
}

void	handle_unzoom(t_var *var)
{
	double	dh;
	double	dv;

	dh = (W / 2) * var->step_x;
	dv = (H / 2) * var->step_y;
	var->limits = get_limits(var->limits.curr_max_re + (dh / var->zoom_speed),
		var->limits.curr_min_re - (dh / var->zoom_speed),
		var->limits.curr_max_im + (dv / var->zoom_speed),
		var->limits.curr_min_im - (dv / var->zoom_speed));
}

int	loop_hook(void *param)
{
	t_var	*var;

	var = (t_var *)param;
	if (var->zoom)
	{
		handle_zoom(var);
		draw_fractal(var);
		var->zoom = 0;
	}
	else if (var->unzoom)
	{
		handle_unzoom(var);
		draw_fractal(var);
		var->unzoom = 0;
	}
	return (1);
}