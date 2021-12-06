#include "fractol.h"

int	exit_prog(t_var *var)
{
	mmmmOkYouGuysAreFreeToGo(var);
	system("leaks fractol");
	exit(0);
	return (1);
}

void	reset_fractal(t_var *var)
{
	var->iteration_max = 40;
	if (var->fractal == MANDELBROT)
		var->limits = get_limits(MAX_RE, MIN_RE, MAX_IM, MIN_IM);
	else if (var->fractal == JULIA)
		var->limits = get_limits(JULIA_MAX_RE, JULIA_MIN_RE, JULIA_MAX_IM, JULIA_MIN_IM);
	else if (var->fractal == BURNING_SHIP)
		var->limits = get_limits(BURNING_SHIP_MAX_RE, BURNING_SHIP_MIN_RE, BURNING_SHIP_MAX_IM, BURNING_SHIP_MIN_IM);
	draw_fractal(var);
}
