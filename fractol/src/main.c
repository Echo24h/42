#include "fractol.h"
#include "cplx.h"

t_limits	get_limits(double max_re, double min_re, double max_im, double min_im)
{
	t_limits limits;

	limits.curr_max_re = max_re;
	limits.curr_min_re = min_re;
	limits.curr_max_im = max_im;
	limits.curr_min_im = min_im;
	return (limits);
}

void	set_steps(t_var *var)
{
	double	dist_x;
	double	dist_y;

	dist_x = fabs(var->limits.curr_max_re - var->limits.curr_min_re);
	dist_y = fabs(var->limits.curr_max_im - var->limits.curr_min_im);
	var->step_x = dist_x / W;
	var->step_y = dist_y / H;
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

int	get_pixel_color(t_var *var, t_cplx c)
{
	int	colors[] = {
		0xff0000,
		0x00ff00,
		0x0000ff,
		0x00f00f,
		0xf0f000
	};
	t_cplx	z;
	int	i = 0;

	z = get_cplx(0, 0);
	while (pow(z.re, 2) + pow(z.im, 2) < 4 && ++i < var->iteration_max)
	{
		z = pow2_cplx(z);
		z = add_cplx(z, c);
	}
	if (i == var->iteration_max)
		return (0x0);
	return (colors[i % 5]);
}

void	draw_fractal(t_var *var)
{
	int		color;
	int		x;
	int		y;
	t_cplx	c;

	set_steps(var);
	c = get_cplx(var->limits.curr_min_re, var->limits.curr_max_im);
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			//print_cplx(c);
			//printf(" | (%d, %d)\n", x, y);
			color = get_pixel_color(var, c);
			put_pixel(var, x, y, color);
			x++;
			c = get_cplx(c.re + var->step_x, c.im);
		}
		y++;
		c = get_cplx(var->limits.curr_min_re, c.im - var->step_y);
	}
	//print_limits(var);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
}

int	main()
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
	var->zoom = 0;
	var->unzoom = 0;
	var->zoom_speed = 2;
	
	draw_fractal(var);

	mlx_key_hook(WIN, key_hook, var);
	mlx_mouse_hook(WIN, mouse_hook, var);
	mlx_loop_hook (MLX, loop_hook, var);

	mlx_loop(MLX);
	printf("EH ouais bitch\n");
	return (0);
}