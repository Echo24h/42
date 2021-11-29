#include "cplx.h"

t_cplx	get_cplx(long double re, long double im)
{
	t_cplx	z;

	z.re = re;
	z.im = im;
	return (z);
}

t_cplx	get_next_cplx(t_cplx z, t_cplx c)
{
	t_cplx	next_z;

	next_z.re = z.re * z.re - z.im * z.im + c.re;
	next_z.im = 2 * z.im * z.re + c.im;
	return (next_z);
}
