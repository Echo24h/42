#include "fractol.h"

void	print_limits(t_var *var)
{
	printf("\ncurr_max_re: %Lf\n", var->limits.curr_max_re);
	printf("curr_min_re: %Lf\n", var->limits.curr_min_re);
	printf("curr_max_im: %Lf\n", var->limits.curr_max_im);
	printf("curr_min_im: %Lf\n\n", var->limits.curr_min_im);
}

t_limits	get_limits(long double max_re, long double min_re, long double max_im, long double min_im)
{
	t_limits limits;

	limits.curr_max_re = max_re;
	limits.curr_min_re = min_re;
	limits.curr_max_im = max_im;
	limits.curr_min_im = min_im;
	return (limits);
}

void	set_dists(t_var *var)
{
	var->dist_x = fabsl(var->limits.curr_max_re - var->limits.curr_min_re);
	var->dist_y = fabsl(var->limits.curr_max_im - var->limits.curr_min_im);
}

void	set_steps(t_var *var)
{
	var->step_x = var->dist_x / W;
	var->step_y = var->dist_y / H;
}

void	put_pixel(t_var *var, int x, int y, int color)
{
	int	index_pixel;

	index_pixel = y * var->size_line + x * 4;
	if (var->endian == 1)
	{
		IMG_DATA[index_pixel] = (color >> 24);
		IMG_DATA[index_pixel + 1] = (color >> 16) & 0xFF;
		IMG_DATA[index_pixel + 2] = (color >> 8) & 0xFF;
		IMG_DATA[index_pixel + 3] = (color) & 0xFF;
	}
	else
	{
		IMG_DATA[index_pixel] = (color) & 0xFF;
		IMG_DATA[index_pixel + 1] = (color >> 8) & 0xFF;
		IMG_DATA[index_pixel + 2] = (color >> 16) & 0xFF;
		IMG_DATA[index_pixel + 3] = (color >> 24);
	}
}

unsigned int	get_color(t_var *var, int nb_iteration)
{
	if (var->palette == 0)
		return (palette_0(var, nb_iteration));
	else if (var->palette == 1)
		return (palette_1(var, nb_iteration));
	return (0);
}

int	get_nb_iteration(t_var *var, t_cplx c)
{
	t_cplx	z;
	int	i;
	
	i = 0;
	
	if (var->fractal == MANDELBROT)
		z = get_cplx(0, 0);
	else if (var->fractal == JULIA)
		z = get_cplx(var->mouse_x, var->mouse_y);
	while (z.re * z.re + z.im * z.im < 4 && ++i < var->iteration_max)
		z = get_next_cplx(z, c);
	return (i);
}

void	draw_fractal(t_var *var)
{
	int		color;
	int		x;
	int		y;
	t_cplx	c;
	
	set_dists(var);
	set_steps(var);
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			c = get_cplx(x * var->step_x + var->limits.curr_min_re, var->limits.curr_max_im - y * var->step_y);
			color = get_color(var, get_nb_iteration(var, c));
			put_pixel(var, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
}

int	mouse_motion()
{
	return (1);
}

int	main(int ac, char **av)
{
	t_var	*var;

	var = malloc(sizeof(t_var) * 1);
	if (!var)
		return (1);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, W, H, "fractol");

	IMG = mlx_new_image(MLX, W, H);
	IMG_DATA = mlx_get_data_addr(IMG, &(var->bpp), &(var->size_line), &(var->endian));

	var->limits = get_limits(MAX_RE, MIN_RE, MAX_IM, MIN_IM);
	var->iteration_max = 50;
	var->zoom_speed = 2;
	var->palette = 0;
	var->max_step_x = (fabs(MAX_RE) + fabs(MIN_RE)) / W;
	var->max_step_x = (fabs(MAX_IM) + fabs(MIN_IM)) / H;
	var->fractal = MANDELBROT;
	var->allow_julia_variation = 0;

	draw_fractal(var);

	mlx_key_hook(WIN, key_hook, var);
	mlx_mouse_hook(WIN, mouse_hook, var);
	mlx_hook(WIN, DestroyNotify, StructureNotifyMask, exit_prog, var);
	// mlx_hook(WIN, MotionNotify, PointerMotionMask, mouse_motion, var);
	mlx_loop(MLX);

	printf("EH ouais bitch\n");
	return (0);
}
