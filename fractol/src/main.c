/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:43:28 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/06 09:01:07 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	print_options(void)
{
	printf("Yo, voilà la liste des fractales disponibles :\n");
	printf(" - mandelbrot\n");
	printf(" - julia\n");
	printf(" - burning_ship\n\n");
	printf("For julia you can also precise the starting point");
	printf(" => ./fractol julia z.r z.i\n");
	printf("Note that you have to wrap the param in \"\" ");
	printf("if it is a negative value\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_var	*var;

	var = malloc(sizeof(t_var) * 1);
	if (!var)
		return (1);
	if (!parse_params(var, ac, av))
	{
		free(var);
		return (print_options());
	}
	init_var(var);
	if (!init_mlx(var))
		return (1);
	draw_fractal(var);
	mlx_key_hook(var->win, key_hook, var);
	mlx_mouse_hook(var->win, mouse_hook, var);
	mlx_hook(var->win, DestroyNotify, 0, exit_prog, var);
	if (var->fractal == JULIA)
		mlx_hook(var->win, MotionNotify, 0, mouse_motion_hook, var);
	mlx_loop(var->mlx);
	return (0);
}
