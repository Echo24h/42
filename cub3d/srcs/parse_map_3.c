/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:43 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 13:13:40 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**delete_empty_eof(char **map)
{
	int		i;
	char	**new;

	i = 0;
	while (map[i] && !is_empty_line(map[i]))
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (map[++i] && !is_empty_line(map[i]))
		new[i] = ft_str_del_nl(map[i]);
	new[i] = 0;
	return (new);
}

char	*replace_and_dup(char *str)
{
	char	*new;
	int		i;

	i = -1;
	new = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[++i])
	{
		if (str[i] == ' ')
			new[i] = '1';
		else
			new[i] = str[i];
	}
	new[i] = 0;
	return (new);
}

char	**replace_ws(char **map)
{
	char	**new;
	int		i;

	i = -1;
	new = malloc(sizeof(char *) * (ft_strslen(map) + 1));
	while (map[++i])
		new[i] = replace_and_dup(map[i]);
	new[i] = 0;
	return (new);
}

int	get_max_len(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i++])
	{
		if (ft_strlen(map[i]) > len)
			len = ft_strlen(map[i]);
	}
	return (len);
}

int	*dup_str_to_tab(char *str, int len)
{
	int	*tab;
	int	i;

	i = -1;
	tab = malloc(sizeof(int) * len);
	while (str[++i] && i < len)
	{
		if (is_player(str[i]))
			tab[i] = str[i];
		else
			tab[i] = str[i] - 48;
	}
	while (i <= len)
		tab[i++] = 1;
	return (tab);
}
