#ifndef MICRO_PAINT_H
#define MICRO_PAINT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	c;	
}	t_rect;

#endif