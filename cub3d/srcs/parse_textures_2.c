/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:44 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 11:29:33 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_color_error(char **to_free, char *msg, char *hexa_rgb)
{
	ft_free_strs(to_free);
	if (hexa_rgb)
		free(hexa_rgb);
	return (print_and_return_error(msg));
}

int	number_too_long(char **rgb)
{
	int	i;

	i = -1;
	while (rgb[++i])
	{
		if (ft_strlen(rgb[i]) > 8)
			return (1);
	}
	return (0);
}

int	multiple_comma(char *words)
{
	int	i;
	int	comma;

	i = -1;
	comma = 0;
	while (words[++i])
	{
		if (words[i] == ',')
			comma++;
	}
	if (comma > 2)
		return (1);
	return (0);
}
