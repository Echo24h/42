#ifndef CPLX_H
# define CPLX_H

#include <math.h>
#include <stdio.h>

typedef struct s_cplx
{
	double re;
	double im;
}	t_cplx;

void	print_cplx(t_cplx z);
t_cplx	get_cplx(double re, double im);
t_cplx	pow2_cplx(t_cplx z);
t_cplx	add_cplx(t_cplx z1, t_cplx z2);


#endif