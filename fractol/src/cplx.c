#include "cplx.h"

void	print_cplx(t_cplx z)
{
	printf("z = %f + %fi", z.re, z.im);
}

t_cplx	get_cplx(double re, double im)
{
	t_cplx	z;

	z.re = re;
	z.im = im;
	return (z);
}

t_cplx	pow2_cplx(t_cplx z)
{
	return (get_cplx(pow(z.re, 2) - pow(z.im, 2), 2 * z.re * z.im));
}

t_cplx	add_cplx(t_cplx z1, t_cplx z2)
{
	t_cplx	z;

	z = get_cplx(z1.re + z2.re, z1.im +z2.im);
	return (z);
}
