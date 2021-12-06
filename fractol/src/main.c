#include "fractol.h"

static int	print_options(void)
{
	printf("Yo, voilà la liste des fractales disponibles :\n");
	printf(" - mandelbrot\n");
	printf(" - julia\n");
	printf(" - burning_ship\n\n");
	printf("For julia you can also precise the starting point => ./fractol julia z.r z.i\n");
	printf("Note that you have to wrap the param in "" if it is a negative value");
	return (0);
}

int	main(int ac, char **av)
{
	t_var	*var;

	var = malloc(sizeof(t_var) * 1);
	if (!var)
		return (1);
	if (!parse_params(var, ac, av))
	{
		free(var);
		return (print_options());
	}
	init_var(var);
	if (!init_mlx(var))
		return (1);
	draw_fractal(var);
	mlx_key_hook(WIN, key_hook, var);
	mlx_mouse_hook(WIN, mouse_hook, var);
	mlx_hook(WIN, DestroyNotify, 0, exit_prog, var);
	if (var->fractal == JULIA)
		mlx_hook(WIN, MotionNotify, 0, mouse_motion_hook, var);
	mlx_loop(MLX);
	return (0);
}
