#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>

# define W 540
# define H 480

# define MLX 		var->mlx
# define WIN 		var->win
# define IMG 		var->img
# define IMG_DATA 	var->img_data

typedef struct	s_var
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;

	int		endian;
	int		bpp;
	int 	size_line;
}	t_var;

#endif