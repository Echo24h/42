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

unsigned int	get_color(t_var *var, long double c_r, long double c_i)
{
	int	iteration;

	if (var->fractal == MANDELBROT)
		iteration = mandelbrot(var, c_r, c_i);
	else if (var->fractal == JULIA)
		iteration = julia(var, c_r, c_i);
	else if (var->fractal == BURNING_SHIP)
		iteration = burning_ship(var, c_r, c_i);
	return (palette(var, iteration));
}

void	draw_iteration_max(t_var *var)
{
		char	*s;
		char	*n;

		n = ft_itoa(var->iteration_max);
		s = ft_strjoin("Iterations : ", n);
		free(n);
		mlx_string_put(MLX, WIN, 10, 20, 0xffffff, s);
		free(s);
}

void	draw_fractal(t_var *var)
{
	int	x;
	int	y;
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
			//printf("%Lf + %Lfi | (%d, %d)\n", c_r, c_i, x, y);
			//sleep(10);
			put_pixel(var, x, y, get_color(var, c_r, c_i));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	draw_iteration_max(var);
}

int	parse_params(t_var *var, int ac, char **av)
{
	if (ac != 2)
		return (0); // error
	if (!ft_strcmp(av[1], "mandelbrot"))
		var->fractal = MANDELBROT;
	else if (!ft_strcmp(av[1], "julia"))
		var->fractal = JULIA;
	else if (!ft_strcmp(av[1], "burning_ship"))
		var->fractal = BURNING_SHIP;
	else
		return (0); // error
	return (1);
}

int	main(int ac, char **av)
{
	t_var	*var;
	int i;

	var = malloc(sizeof(t_var) * 1);
	if (!var)
		return (1);
	if (!parse_params(var, ac, av))
		return (1);
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, W, H, "fractol");

	IMG = mlx_new_image(MLX, W, H);
	IMG_DATA = mlx_get_data_addr(IMG, &(var->bpp), &(var->size_line), &(var->endian));

	var->limits = get_limits(MAX_RE, MIN_RE, MAX_IM, MIN_IM);
	var->iteration_max = 40;
	var->zoom_speed = 3;
	var->palette = 0;
	var->count_scroll = 0;
	if (var->fractal == JULIA)
	{
		var->allow_julia_variation = 0;
		var->limits = get_limits(JULIA_MAX_RE, JULIA_MIN_RE, JULIA_MAX_IM, JULIA_MIN_IM);
		var->julia_step_x = (fabs(MAX_RE) + fabs(MIN_RE)) / W;
		var->julia_step_y = (fabs(MAX_IM) + fabs(MIN_IM)) / H;
		var->julia_point_r = 0.3;
		var->julia_point_i = 0.5;
		var->count_unzoom = 0;
	}
	if (var->fractal == BURNING_SHIP)
		var->limits = get_limits(BURNING_SHIP_MAX_RE, BURNING_SHIP_MIN_RE, BURNING_SHIP_MAX_IM, BURNING_SHIP_MIN_IM);

	draw_fractal(var);
	/*
	i = 0;
	mlx_mouse_move(WIN, W / 2, H / 2);
	while (++i < 50)
		handle_zoom(var);
	i = 0;
	while (var->iteration_max > 50)
		handle_unzoom(var);
	draw_fractal(var);
	*/

	mlx_key_hook(WIN, key_hook, var);
	mlx_mouse_hook(WIN, mouse_hook, var);
	mlx_hook(WIN, DestroyNotify, 0, exit_prog, var);
	if (var->fractal == JULIA)
		mlx_hook(WIN, MotionNotify, 0, mouse_motion_hook, var);
	mlx_loop(MLX);

	printf("EH ouais bitch\n");
	return (0);
}
