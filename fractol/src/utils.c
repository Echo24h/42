#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

float	ft_atof(char *s)
{
	float	res;
	float	x;
	int		neg;

	res = 0;
	neg = 0;
	if (*s == '-')
	{
		neg = 1;
		s++;
	}
	while (*s && ft_isdigit(*s))
		res = res * 10 + *s++ - 48; 
	if (*s == '.' || *s == ',')
		s++;
	x = 0.1;
	while (*s && ft_isdigit(*s))
	{
		res = res + x * (*s++ - 48);
		x *= 0.1;
	}
	if (neg)
		return (-res);
	return (res);
}

void	mmmmOkYouGuysAreFreeToGo(t_var *var)
{
	if (IMG)
		mlx_destroy_image(MLX, IMG);
	if (WIN)
		mlx_destroy_window(MLX, WIN);
	free(var);
}

unsigned int	rgb_to_int(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}
