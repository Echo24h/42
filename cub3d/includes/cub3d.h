#ifndef CUB3D_H
# define CUB3D_H

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
	/* next vars are for dev */
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
}	t_var;

#endif