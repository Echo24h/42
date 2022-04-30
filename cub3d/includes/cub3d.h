#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "mlx.h"

# define W 500
# define H 500

typedef struct	s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_rgb;

typedef struct	s_map
{
	char	**map;
	t_rgb	color_ceil;
	t_rgb	color_floor;
	/* next vars are for dev, to be replaced later with textures */
	t_rgb	color_ea;
	t_rgb	color_no;
	t_rgb	color_we;
	t_rgb	color_so;
	/* --- */
}	t_map;

typedef struct	s_info
{

}	t_info;

typedef struct	s_var
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		endian;
	int		bpp;
	int		size_line;
	t_map	*map;
	t_info	*info;
}	t_var;

//	parse_map.c
int		parse_map(t_map *map, char *map_file);

//	set_hooks.c
void	set_hooks(t_var *var);

//	init.c
int		init_var(t_var *var, t_map *map, t_info *info);
int		init_info(t_info *info);

#endif