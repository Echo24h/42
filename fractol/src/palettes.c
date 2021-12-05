#include "fractol.h"

unsigned int	rainbow3(t_var *var, int nb_iteration);


unsigned int	test(t_var *var, int nb_iteration)
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.3 * nb_iteration + 3) * 127 + 128;
	rgb.g = sin(0.05 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.05 * nb_iteration + 1) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	palette(t_var *var, int nb_iteration)
{
	if (var->palette == 0)
		return (test(var, nb_iteration));
	else if (var->palette == 1)
		return (rainbow(var, nb_iteration));
	else if (var->palette == 2)
		return (rainbow3(var, nb_iteration));
	else if (var->palette == 3)
		return (brain_fuck(var, nb_iteration));
	else if (var->palette == 4)
		return (brain_fuck(var, nb_iteration));
	return (0);
}

unsigned int	brain_fuck(t_var *var, int nb_iteration)
{
	t_rgb	rgb;

	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.2 * nb_iteration) + var->iteration_max * 0.5;
	rgb.g = sin(0.2 * nb_iteration + 2) * 255 - var->iteration_max * 0.5;
	rgb.b = sin(0.2 * nb_iteration + 1) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	grey(t_var *var, int nb_iteration) //
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.3 * nb_iteration) * 127 + 128;
	rgb.g = sin(0.3 * nb_iteration) * 127 + 128;
	rgb.b = sin(0.3 * nb_iteration) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	smooth_red(t_var *var, int nb_iteration) //
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = nb_iteration * 255 / var->iteration_max;
	rgb.g = 0;
	rgb.b = 0;
	return (rgb_to_int(rgb));
}

unsigned int	rainbow(t_var *var, int nb_iteration) //
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.3 * nb_iteration + 3) * 127 + 128;
	rgb.g = sin(0.3 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.3 * nb_iteration + 1) * 127 + 128;
	rgb.b = (rgb.b + var->iteration_max) % 256;
	return (rgb_to_int(rgb));
}

unsigned int	rainbow2(t_var *var, int nb_iteration) //
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.3 * nb_iteration + 3) * 127 + 128;
	rgb.g = sin(0.3 * nb_iteration + 2) * 127 + 128;
	rgb.b = var->iteration_max % 256;
	return (rgb_to_int(rgb));
}

unsigned int	rainbow3(t_var *var, int nb_iteration)
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.4 * nb_iteration) * 127 + 128;
	rgb.g = sin(0.5 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.6 * nb_iteration + 1) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	zebra(t_var *var, int nb_iteration)
{
	if ((var->iteration_max - nb_iteration) % 2)
		return (0xffffff);
	else
		return (0x0);
}

unsigned int	color1(t_var *var, int nb_iteration)
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.3 * nb_iteration + 1) * 127 + 128;
	rgb.g = sin(0.3 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.3 * nb_iteration) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	color2(t_var *var, int nb_iteration)
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.3 * nb_iteration + 2) * 127 + 128;
	rgb.g = sin(0.3 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.3 * nb_iteration) * 127 + 128;
	return (rgb_to_int(rgb));
}


/*
unsigned int	test(t_var *var, int nb_iteration)
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.05 * nb_iteration) * 127 + 128;
	rgb.g = sin(0.3 * nb_iteration + 1) * 127 + 128;
	rgb.b = sin(0.3 * nb_iteration) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	test(t_var *var, int nb_iteration)
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.05 * nb_iteration) * 127 + 128;
	rgb.g = sin(0.1 * nb_iteration + 1) * 127 + 128;
	rgb.b = sin(0.1 * nb_iteration + 2) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	test(t_var *var, int nb_iteration)
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.2 * nb_iteration + 3) * 127 + 128;
	rgb.g = sin(0.02 * nb_iteration + 1) * 127 + 128;
	rgb.b = sin(0.2 * nb_iteration + 2) * 127 + 128;
	return (rgb_to_int(rgb));
}


unsigned int	test(t_var *var, int nb_iteration)
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.3 * nb_iteration + 3) * 127 + 128;
	rgb.g = sin(0.05 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.05 * nb_iteration + 1) * 127 + 128;
	return (rgb_to_int(rgb));
}

*/