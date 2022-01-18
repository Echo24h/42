/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:18:14 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/06 08:59:51 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include "X.h"
# include "libft.h"

# define W 1000
# define H (W / 1.125)
# define MAX_RE 0.6
# define MIN_RE -2.1
# define MAX_IM 1.2
# define MIN_IM -1.2
# define JULIA_MAX_RE 1.5
# define JULIA_MIN_RE -1.5
# define JULIA_MAX_IM 1.33
# define JULIA_MIN_IM -1.33
# define BURNING_SHIP_MAX_RE 1.5
# define BURNING_SHIP_MIN_RE -2.5
# define BURNING_SHIP_MAX_IM 1.2
# define BURNING_SHIP_MIN_IM -2.35
# define TOP 1
# define RIGHT 2
# define BOTTOM 3
# define LEFT 4
# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2

typedef struct s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

typedef struct s_limits
{
	long double	curr_max_re;
	long double	curr_min_re;
	long double	curr_max_im;
	long double	curr_min_im;
}	t_limits;

typedef struct s_var
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_data;
	long double		julia_step_x;
	long double		julia_step_y;
	long double		step_x;
	long double		step_y;
	long double		dist_x;
	long double		dist_y;
	t_limits		limits;
	long double		zoom_speed;
	int				palette;
	int				mouse_x;
	int				mouse_y;
	int				count_scroll;
	int				count_unzoom;
	long double		julia_point_r;
	long double		julia_point_i;
	int				iteration_max;
	int				fractal;
	int				allow_julia_variation;
	int				endian;
	int				bpp;
	int				size_line;
}	t_var;

void			put_pixel(t_var *var, int x, int y, int color);
void			draw_fractal(t_var *var);
t_limits		get_limits(long double max_re, long double min_re,
					long double max_im, long double min_im);
int				mandelbrot(t_var *var, long double c_r, long double c_i);
int				julia(t_var *var, long double c_r, long double c_i);
int				burning_ship(t_var *var, long double c_r, long double c_i);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
int				mouse_motion_hook(int x, int y, t_var *var);
void			handle_zoom(t_var *var);
void			handle_unzoom(t_var *var);
void			handle_move(t_var *var, int direction);
void			add_to_iteration_max(t_var *var, int n);
void			switch_palette(t_var *var);
void			reset_fractal(t_var *var);
int				exit_prog(t_var *var);
unsigned int	palette(t_var *var, int nb_iteration);
unsigned int	palette_0(t_var *var, int nb_iteration);
unsigned int	palette_1(t_var *var, int nb_iteration);
unsigned int	palette_2(t_var *var, int nb_iteration);
unsigned int	palette_3(t_var *var, int nb_iteration);
unsigned int	grey(t_var *var, int nb_iteration);
unsigned int	smooth_red(t_var *var, int nb_iteration);
unsigned int	rainbow_0(t_var *var, int nb_iteration);
unsigned int	rainbow_1(t_var *var, int nb_iteration);
unsigned int	zebra(t_var *var, int nb_iteration);
void			parse_julia_starting_point(t_var *var, int ac, char **av);
int				parse_params(t_var *var, int ac, char **av);
int				init_mlx(t_var *var);
int				init_var(t_var *var);
int				ft_strcmp(char *s1, char *s2);
float			ft_atof(char *s);
void			mmmm_ok_you_guys_are_free_to_go(t_var *var);
unsigned int	rgb_to_int(t_rgb rgb);

#endif