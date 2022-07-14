/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:43 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 12:54:28 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	**init_map(char **chars_map)
{
	int	**new_map;
	int	len_max;
	int	i;

	i = -1;
	len_max = get_max_len(chars_map);
	new_map = malloc(sizeof(int *) * (ft_strslen(chars_map)));
	while (chars_map[++i])
		new_map[i] = dup_str_to_tab(chars_map[i], len_max);
	return (new_map);
}

void	init_another_pos(t_var *v, int pos, int j, int i)
{
	if (pos == 'W')
	{
		v->player = get_vec2(j + 0.5, i + 0.5);
		v->player_dir = get_vec2(-1, 0);
		v->camera = get_vec2(0, -0.66);
	}
	else if (pos == 'E')
	{
		v->player = get_vec2(j + 0.5, i + 0.5);
		v->player_dir = get_vec2(1, 0);
		v->camera = get_vec2(0, 0.66);
	}
}

void	init_player(t_var *v)
{
	int	i;
	int	j;

	i = -1;
	while (++i < v->map_h)
	{
		j = -1;
		while (++j < v->map_w)
		{
			if (v->map[i][j] == 'N')
			{
				v->player = get_vec2(j + 0.5, i + 0.5);
				v->player_dir = get_vec2(0, -1);
				v->camera = get_vec2(0.66, 0);
			}
			else if (v->map[i][j] == 'S')
			{
				v->player = get_vec2(j + 0.5, i + 0.5);
				v->player_dir = get_vec2(0, 1);
				v->camera = get_vec2(-0.66, 0);
			}
			else if (v->map[i][j] == 'W' || v->map[i][j] == 'E')
				init_another_pos(v, v->map[i][j], i, j);
		}
	}
}

int	parse_map_and_init(t_var *v, char **map_before_parse)
{
	char	**map;

	if (!map_before_parse)
		return (print_and_return_error("Invalid Map"));
	else if (check_incorect_map(map_before_parse))
		return (1);
	map = replace_ws(map_before_parse);
	if (check_border(map))
		return (1);
	v->map_h = ft_strslen(map);
	v->map_w = get_max_len(map);
	v->map = init_map(map);
	init_player(v);
	ft_free_strs(map);
	return (0);
}
