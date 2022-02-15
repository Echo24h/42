#include "mini_paint.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	error(char *msg, int code)
{
	write(STDOUT_FILENO, "Error: ", ft_strlen("Error: "));
	write(STDOUT_FILENO, msg, ft_strlen(msg));
	return (code);
}

char	**init_canvas(int width, int height, char bg_char)
{
	int	i;
	int	j;
	char	**canvas;

	canvas = malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (i < height)
		canvas[i++] = malloc(width + 1);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			canvas[i][j++] = bg_char;
		canvas[i][j] = '\0';
		i++;
	}
	canvas[i] = NULL;
	return (canvas);
}

void	print_canvas(char **canvas)
{
	int	i;

	i = 0;
	while (canvas[i])
	{
		write(STDOUT_FILENO, canvas[i], ft_strlen(canvas[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

float	get_dist(float x1, float y1, float x2, float y2)
{
	return (sqrtf(powf(x1 - x2, 2) + powf(y1 - y2, 2)));
}

int	is_in_circle(float x, float y, t_circle circle)
{
	if (get_dist(x, y, circle.x, circle.y) <= circle.radius)
		return (1);
	return (0);
}

int	is_border(float x, float y, t_circle circle)
{
	if (circle.radius - get_dist(x, y, circle.x, circle.y) < 1)
		return (1);
	return (0);
}

void	draw_circle(char **canvas, t_circle circle)
{
	int	i;
	int	j;

	i = 0;
	while (canvas[i])
	{
		j = 0;
		while (canvas[i][j])
		{
			if (circle.type == 'c')
			{
				if (is_in_circle(j, i, circle) && is_border(j, i, circle))
					canvas[i][j] = circle.c;
			}
			else 
			{
				if (is_in_circle(j, i, circle))
					canvas[i][j] = circle.c;
			}
			j++;
		}
		i++;
	}
}

int	circle_is_valid(t_circle circle)
{
	if (circle.type != 'c' && circle.type != 'C')
		return (0);
	if (circle.radius <= 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	FILE	*file;
	char	**canvas;
	int		width, height;
	char	bg_char;
	int		ret;
	t_circle	circle;

	if (ac != 2)
		return (error("argument\n", EXIT_FAILURE));
	file = fopen(av[1], "r");
	if (!file)
		return (error("Operation file corrupted\n", EXIT_FAILURE));
	if (fscanf(file, "%d %d %c\n", &width, &height, &bg_char) != 3)
		return (error("Operation file corrupted\n", EXIT_FAILURE));
	//printf("%d %d %c\n", width, height, bg_char);
	if (width <= 0 || width > 300 || height <= 0 || height > 300)
		return (error("Operation file corrupted\n", EXIT_FAILURE));
	canvas = init_canvas(width, height, bg_char);
	//print_canvas(canvas);
	while (1)
	{
		ret = fscanf(file, "%c %f %f %f %c\n", &circle.type, &circle.x, &circle.y, &circle.radius, &circle.c);
		if (ret == EOF)
			break ;
		if (ret != 5 || !circle_is_valid(circle))
			return (error("Operation file corrupted\n", EXIT_FAILURE));
		//print_circle(circle);
		draw_circle(canvas, circle);
	}
	print_canvas(canvas);
	//printf("------\n");
	//print_canvas(canvas);
	return (EXIT_SUCCESS);
}
