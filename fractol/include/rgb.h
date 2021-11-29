#ifndef RGB_H
# define RGB_H

#include <stdio.h>

typedef struct	s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

t_rgb			int_to_rgb(int color);
unsigned int	rgb_to_int(t_rgb rgb);
void			print_rgb(t_rgb rgb);
t_rgb			get_rgb(unsigned int r, unsigned int g, unsigned int b);

#endif