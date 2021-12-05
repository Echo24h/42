#include "fractol.h"

int	mandelbrot(t_var *var, long double c_r, long double c_i)
{
	int		i;
	long double	z_r;
	long double	z_i;
	long double	z_r_square;
	long double	z_i_square;

	i = 0;
	z_r = 0;
	z_i = 0;
	z_r_square = z_r * z_r;
	z_i_square = z_i * z_i;
	while (z_r_square + z_i_square < 4 && i < var->iteration_max)
	{
		z_i = z_r * z_i;
		z_i += z_i;
		z_i += c_i;
		z_r = z_r_square - z_i_square + c_r;
		z_r_square = z_r * z_r;
		z_i_square = z_i * z_i;
		i++;
	}
	var->module = sqrt(z_r_square + z_i_square);
	return (i);
}

int	julia(t_var *var, long double c_r, long double c_i)
{
	int		i;
	long double	z_r;
	long double	z_i;
	long double	z_r_square;
	long double	z_i_square;

	i = 0;
	z_r = c_r;
	z_i = c_i;
	c_r = var->julia_point_r;
	c_i = var->julia_point_i;
	z_r_square = z_r * z_r;
	z_i_square = z_i * z_i;
	while (z_r_square + z_i_square < 2 && ++i < var->iteration_max)
	{
		z_i = z_r * z_i;
		z_i += z_i;
		z_i += c_i;
		z_r = z_r_square - z_i_square + c_r;
		z_r_square = z_r * z_r;
		z_i_square = z_i * z_i;
	}
	return (i);
}

int	burning_ship(t_var *var, long double c_r, long double c_i)
{
	int		i;
	long double	z_r;
	long double	z_i;
	long double	z_r_square;
	long double	z_i_square;

	i = 0;
	z_r = 0;
	z_i = 0;
	z_r_square = z_r * z_r;
	z_i_square = z_i * z_i;
	while (z_r_square + z_i_square < 4 && ++i < var->iteration_max)
	{
		z_i = fabsl(2 * z_r * z_i);
		z_i += c_i;
		z_r = z_r_square - z_i_square + c_r;
		z_r_square = z_r * z_r;
		z_i_square = z_i * z_i;
	}
	return (i);
}