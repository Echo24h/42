#ifndef CPLX_H
# define CPLX_H

#include <stdio.h>

typedef struct s_cplx
{
	long double re;
	long double im;
}	t_cplx;

t_cplx	get_cplx(long double re, long double im);
t_cplx	get_next_cplx(t_cplx z, t_cplx c);

#endif