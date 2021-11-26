#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>

# define W 810
# define H 720
# define MAX_RE 0.6
# define MIN_RE -2.1
# define MAX_IM 1.2
# define MIN_IM -1.2

# define MLX 		var->mlx
# define WIN 		var->win
# define IMG 		var->img
# define IMG_DATA 	var->img_data

typedef struct	s_limits
{
	double	curr_max_re;
	double	curr_min_re;
	double	curr_max_im;
	double	curr_min_im;
}	t_limits;

typedef struct	s_var
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	double		step_x;
	double		step_y;
	t_limits	limits;
	int			iteration_max;
	int			zoom;
	int			unzoom;
	int			endian;
	int			bpp;
	int 		size_line;
}	t_var;

#endif