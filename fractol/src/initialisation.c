#include "fractol.h"

int	init_mlx(t_var *var)
{
	MLX = mlx_init();
	if (!MLX)
	{
		free(var);
		return (0);
	}
	WIN = mlx_new_window(MLX, W, H, "fract-ol");
	IMG = mlx_new_image(MLX, W, H);
	if (!WIN || !IMG)
	{
		mmmmOkYouGuysAreFreeToGo(var);
		return (0);
	}
	IMG_DATA = mlx_get_data_addr(IMG, &(var->bpp), &(var->size_line), &(var->endian));
	if (!IMG_DATA)
	{
		mmmmOkYouGuysAreFreeToGo(var);
		return (0);
	}
	return (1);
}

int	init_var(t_var *var)
{
	MLX = NULL;
	WIN = NULL;
	IMG = NULL;
	IMG_DATA = NULL;
	var->iteration_max = 40;
	var->zoom_speed = 3;
	var->palette = 0;
	var->count_scroll = 0;
	var->count_unzoom = 0;
	if (var->fractal == JULIA)
	{
		var->limits = get_limits(JULIA_MAX_RE, JULIA_MIN_RE, JULIA_MAX_IM, JULIA_MIN_IM);
		var->allow_julia_variation = 0;
		var->julia_step_x = (fabs(MAX_RE) + fabs(MIN_RE)) / W;
		var->julia_step_y = (fabs(MAX_IM) + fabs(MIN_IM)) / H;
		printf("%Lf + %Lfi\n", var->julia_point_r, var->julia_point_i);
	}
	else if (var->fractal == MANDELBROT)
		var->limits = get_limits(MAX_RE, MIN_RE, MAX_IM, MIN_IM);
	else if (var->fractal == BURNING_SHIP)
		var->limits = get_limits(BURNING_SHIP_MAX_RE, BURNING_SHIP_MIN_RE, BURNING_SHIP_MAX_IM, BURNING_SHIP_MIN_IM);
	return (1);
}