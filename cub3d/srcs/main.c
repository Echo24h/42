#include "cub3d.h"

int	main(int ac, char **av)
{
	t_var	var;
	t_map	map;
	t_info	info;

	if (!av[1] || parse_map(&map, av[1]))
		return (1); // parse error
	init_info(&info);
	if (!init_var(&var, &map, &info))
		return (1); // mlx error
	set_hooks(&var);
	mlx_loop(var.mlx);
	printf("working on it :)\n");
	return (0);
}
