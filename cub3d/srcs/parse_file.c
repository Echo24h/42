/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:42 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 11:58:32 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	char	**file_to_strs(char	*path_file)
{
	char	*line;
	char	**file;
	int		fd;
	t_list	*tmp;

	tmp = NULL;
	line = NULL;
	fd = open(path_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "", ft_strlen(line)))
			ft_lstadd_back(&tmp, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	file = ft_lst_to_dpt(tmp);
	ft_lstclear(&tmp, &free);
	close(fd);
	return (file);
}

char	**get_map(char **file)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i] && !is_map(file[i]))
		i++;
	if (!file[i])
		return (NULL);
	map = malloc(sizeof(char *) * (ft_strslen(file) - i + 1));
	while (file[i])
		map[j++] = ft_strdup(file[i++]);
	map[j] = 0;
	return (map);
}

char	**get_textures(char **file)
{
	char	**textures;
	int		i;

	i = 0;
	while (file[i] && !is_map(file[i]))
		i++;
	textures = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (file[++i] && !is_map(file[i]))
		textures[i] = ft_strdup(file[i]);
	textures[i] = 0;
	return (textures);
}

int	check_empty_line_on_map(char *path_file)
{
	char	*line;
	int		fd;
	int		check;

	line = NULL;
	check = 1;
	fd = open(path_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check && is_map(line))
			check = 0;
		else if (!check && !ft_strncmp(line, "", ft_strlen(line)))
		{
			free(line);
			return (print_and_return_error("Invalid map"));
		}
		free(line);
	}
	close(fd);
	return (0);
}

int	parse_file(t_var *v, char *map_file)
{
	char	**file;
	char	**map;
	char	**textures;

	if (!map_file)
		return (print_and_return_error("Missing parameter"));
	else if (!valide_file_name(map_file))
		return (print_and_return_error("Invalid file name"));
	init_struct(v);
	if (check_empty_line_on_map(map_file))
		return (1);
	file = file_to_strs(map_file);
	textures = get_textures(file);
	map = get_map(file);
	if (parse_textures(v, textures) || parse_map_and_init(v, map))
	{
		ft_free_strs(textures);
		ft_free_strs(map);
		return (1);
	}
	ft_free_strs(textures);
	ft_free_strs(map);
	ft_free_strs(file);
	return (0);
}
