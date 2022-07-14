/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:37 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 13:05:33 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_circle(t_img *img, int x, int y, int radius)
{
	int	i;
	int	j;
	int	dist;

	i = 0;
	while (i < W)
	{
		j = 0;
		while (j < H)
		{
			dist = (x - i) * (x - i) + (y - j) * (y - j);
			if (dist <= radius * radius + 4)
				put_pixel(img, i, j, INDIAN_RED);
			if (dist >= radius * radius - 4 && dist <= radius * radius + 4)
				put_pixel(img, i, j, INDIAN_RED);
			j++;
		}
		i++;
	}
}
