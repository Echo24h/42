#include <mlx.h>
#include "fractol.h"

int	main()
{
	t_var	*var;
	int		color = 0xffd700; 
	int		pixel;
	int		x;
	int		y;

	var = malloc(sizeof(t_var) * 1);
	if (!var)
		return (1);

	MLX = mlx_init();
	WIN = mlx_new_window(MLX, W, H, "fractol");

	IMG = mlx_new_image(MLX, W, H);
	IMG_DATA = mlx_get_data_addr(IMG, &(var->bpp), &(var->size_line), &(var->endian));

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			pixel = y * var->size_line + x * 4;
			IMG_DATA[pixel + 3] = (color >> 24);
			IMG_DATA[pixel + 2] = (color >> 16) & 0xFF;
			IMG_DATA[pixel + 1] = (color >> 8) & 0xFF;
			IMG_DATA[pixel] = (color) & 0xFF;
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	
	mlx_loop(MLX);
	printf("EH ouais bitch\n");
	return (0);
}