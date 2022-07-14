/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:42 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 12:27:10 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valide_file_name(char *filename)
{
	int		i;
	int		j;
	char	*tmp;

	tmp = ".cub";
	j = ft_strlen(tmp);
	i = ft_strlen(filename);
	if (i < 4)
		return (0);
	else if (!filename[i])
	{
		while (i && j)
		{
			if (filename[i] != tmp[j])
				return (0);
			i--;
			j--;
		}
	}
	return (1);
}
