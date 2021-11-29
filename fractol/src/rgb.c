#include "rgb.h"

void	print_rgb(t_rgb rgb)
{
	printf("(%u, %u, %u)\n", rgb.r, rgb.g, rgb.b);
}

t_rgb	int_to_rgb(int color)
{
	t_rgb	rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}

unsigned int	rgb_to_int(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_rgb	get_rgb(unsigned int r, unsigned int g, unsigned int b)
{
	t_rgb rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}