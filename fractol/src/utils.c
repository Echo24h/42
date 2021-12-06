/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:47:21 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/06 08:50:02 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	mmmm_ok_you_guys_are_free_to_go(t_var *var)
{
	if (var->img)
		mlx_destroy_image(var->mlx, var->img);
	if (var->win)
		mlx_destroy_window(var->mlx, var->win);
	free(var);
}

unsigned int	rgb_to_int(t_rgb rgb)
{
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}
