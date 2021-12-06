#include "fractol.h"

void	parse_julia_starting_point(t_var *var, int ac, char **av)
{
	if (ac > 3)
	{
		var->julia_point_r = ft_atof(av[2]);
		var->julia_point_i = ft_atof(av[3]);
	}
	else
	{
		var->julia_point_r = 0.3;
		var->julia_point_i = 0.5;
	}
}

int	parse_params(t_var *var, int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (!ft_strcmp(av[1], "mandelbrot"))
		var->fractal = MANDELBROT;
	else if (!ft_strcmp(av[1], "julia"))
	{
		var->fractal = JULIA;
		parse_julia_starting_point(var, ac, av);
	}
	else if (!ft_strcmp(av[1], "burning_ship"))
		var->fractal = BURNING_SHIP;
	else
		return (0);
	return (1);
}