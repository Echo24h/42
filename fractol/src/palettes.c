#include "fractol.h"

unsigned int	palette_0(t_var *var, int nb_iteration)
{
	t_rgb	rgb;

	if (nb_iteration == var->iteration_max)
		return (0x0);
	rgb.r = sin(0.2 * nb_iteration + 3) * 127 + 128;
	rgb.g = sin(0.2 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.2 * nb_iteration + 1) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	palette_1(t_var *var, int nb_iteration)
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0xff);
	if (var->iteration_max > 255)
		rgb.r = 255;
	else
		rgb.r = var->iteration_max;
	rgb.g = sin(0.8 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.8 * nb_iteration + 1) * 127 + 128;
	return (rgb_to_int(rgb));
}

unsigned int	palette_2(t_var *var, int nb_iteration) // not implemented
{
	t_rgb	rgb;
	
	if (nb_iteration == var->iteration_max)
		return (0xffffff);
	rgb.r = 0;
	rgb.g = sin(0.8 * nb_iteration + 2) * 127 + 128;
	rgb.b = sin(0.8 * nb_iteration + 1) * 127 + 128;
	return (rgb_to_int(rgb));
}