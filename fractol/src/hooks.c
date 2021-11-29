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
	{
		// free everything here
		mlx_destroy_image(MLX, IMG);
		mlx_destroy_window(MLX, WIN);
		exit(0);
	}
	else if (keycode == 24 || keycode == 69)
		add_to_iteration_max(var, 1);
	else if (keycode == 27 || keycode == 78)
		add_to_iteration_max(var, -1);
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
	return (1);
}
