/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:43 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 13:11:35 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	player_check(char *str)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (str[i])
	{
		if (is_player(str[i]))
			player++;
		i++;
	}
	return (player);
}

int	check_incorect_map(char **map)
{
	int	i;
	int	player;

	i = -1;
	player = 0;
	while (map[++i] && !is_empty_line(map[i]))
	{
		if (!is_map(map[i]))
			return (print_and_return_error("Invalid map"));
		player += player_check(map[i]);
	}
	while (map[i])
	{
		if (!is_empty_line(map[i]))
			return (print_and_return_error("Words after map"));
		i++;
	}
	if (player != 1)
		return (print_and_return_error("Invalid player"));
	return (0);
}

int	only_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_border(char **map)
{
	int	i;
	int	last;

	i = 0;
	last = 0;
	if (!only_wall(map[i]))
		return (print_and_return_error("Invalid border 1"));
	i++;
	while (map[i + 1])
	{
		last = ft_strlen(map[i]) - 1;
		if (map[i][0] != '1' || map[i][last] != '1')
			return (print_and_return_error("Invalid border 2"));
		i++;
	}
	if (!only_wall(map[i]))
		return (print_and_return_error("Invalid border 3"));
	return (0);
}
