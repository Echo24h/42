#include "micro_paint.h"

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

void	print_rect(t_rect rect)
{
	printf("%c %f %f %f %f %c\n", rect.type, rect.x, rect.y, rect.width, rect.height, rect.c);
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

int	is_in_rect(float x, float y, t_rect rect)
{
	if (x >= rect.x && x <= rect.x + rect.width
		&& y >= rect.y && y <= rect.y + rect.height)
		return (1);
	return (0);
}

int	is_border(float x, float y, t_rect rect)
{
	if (x - rect.x < 1.0 || rect.x + rect.width - x < 1.0
		|| y - rect.y < 1.0 || rect.y + rect.height - y < 1.0)
		return (1);
	return (0);
}

void	draw_rect(char **canvas, t_rect rect)
{
	int	i;
	int	j;

	i = 0;
	while (canvas[i])
	{
		j = 0;
		while (canvas[i][j])
		{
			if (rect.type == 'r')
			{
				if (is_in_rect(j, i, rect) && is_border(j, i, rect))
					canvas[i][j] = rect.c;
			}
			else 
			{
				if (is_in_rect(j, i, rect))
					canvas[i][j] = rect.c;
			}
			j++;
		}
		i++;
	}
}

int	rect_is_valid(t_rect rect)
{
	if (rect.type != 'r' && rect.type != 'R')
		return (0);
	if (rect.width <= 0 || rect.height <= 0)
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
	t_rect	rect;

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
		ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, &rect.width, &rect.height, &rect.c);
		if (ret == EOF)
			break ;
		if (ret != 6 || !rect_is_valid(rect))
			return (error("Operation file corrupted\n", EXIT_FAILURE));
		//print_rect(rect);
		draw_rect(canvas, rect);
	}
	print_canvas(canvas);
	//printf("------\n");
	//print_canvas(canvas);
	return (EXIT_SUCCESS);
}
