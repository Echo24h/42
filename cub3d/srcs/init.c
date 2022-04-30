#include "cub3d.h"

int	init_var(t_var *var, t_map *map, t_info *info)
{
	var->map = map;
	var->info = info;
	var->mlx = mlx_init();
	if (var->mlx)
		return (1);
	var->win = mlx_new_window(var->mlx, W, H, "cub3d");
	var->img = mlx_new_image(var->mlx, W, H);
	if (!var->win || !var->img)
		return (1);
	var->img_data = mlx_get_data_addr(var->img, &var->bpp, &var->size_line, &var->endian);
	return (0);
}

int	init_info(t_info *info)
{
	return (0);
}
