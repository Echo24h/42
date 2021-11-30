#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include "cplx.h"
#include "rgb.h"
#include "X.h"

# define W 810
# define H 720
# define MAX_RE 0.6
# define MIN_RE -2.1
# define MAX_IM 1.2
# define MIN_IM -1.2
# define TOP 1
# define RIGHT 2
# define BOTTOM 3
# define LEFT 4
# define MANDELBROT 0
# define JULIA 1

# define MLX 		var->mlx
# define WIN 		var->win
# define IMG 		var->img
# define IMG_DATA 	var->img_data

typedef struct	s_limits
{
	long double	curr_max_re;
	long double	curr_min_re;
	long double	curr_max_im;
	long double	curr_min_im;
}	t_limits;

typedef struct	s_var
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_data;
	double			max_step_x;
	double			max_step_y;
	long double		step_x;
	long double		step_y;
	long double		dist_x;
	long double		dist_y;
	t_limits		limits;
	long double		zoom_speed;
	int				palette;
	int				mouse_x;
	int				mouse_y;
	int				iteration_max;
	int				fractal;
	int				allow_julia_variation;
	int				endian;
	int				bpp;
	int 			size_line;
}	t_var;

void		draw_fractal(t_var *var);
t_limits	get_limits(long double max_re, long double min_re, long double max_im, long double min_im);
void		print_limits(t_var *var);
void		set_dists(t_var *var);
int			exit_prog(t_var *var);

// hooks
int 		key_hook(int keycode, void *param);
int			mouse_hook(int button, int x,int y, void *param);

// events
void		handle_zoom(t_var *var);
void		handle_unzoom(t_var *var);
void		handle_move(t_var *var, int direction);
void		add_to_iteration_max(t_var *var, int n);

// palettes
unsigned int	palette_0(t_var *var, int nb_iteration);
unsigned int	palette_1(t_var *var, int nb_iteration);

#endif