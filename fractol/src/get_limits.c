#include "fractol.h"

t_limits	get_limits(long double max_re, long double min_re, long double max_im, long double min_im)
{
	t_limits limits;

	limits.curr_max_re = max_re;
	limits.curr_min_re = min_re;
	limits.curr_max_im = max_im;
	limits.curr_min_im = min_im;
	return (limits);
}