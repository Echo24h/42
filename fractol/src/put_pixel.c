/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 08:46:47 by ydanset           #+#    #+#             */
/*   Updated: 2021/12/06 08:47:03 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_var *var, int x, int y, int color)
{
	int	index_pixel;

	index_pixel = y * var->size_line + x * 4;
	if (var->endian == 1)
	{
		var->img_data[index_pixel] = (color >> 24);
		var->img_data[index_pixel + 1] = (color >> 16) & 0xFF;
		var->img_data[index_pixel + 2] = (color >> 8) & 0xFF;
		var->img_data[index_pixel + 3] = (color) & 0xFF;
	}
	else
	{
		var->img_data[index_pixel] = (color) & 0xFF;
		var->img_data[index_pixel + 1] = (color >> 8) & 0xFF;
		var->img_data[index_pixel + 2] = (color >> 16) & 0xFF;
		var->img_data[index_pixel + 3] = (color >> 24);
	}
}
