/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:35 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 13:22:05 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_border(t_var *v)
{
	int		i;
	int		j;
	double	x;
	int		dist;
	t_vec2	center;

	center = get_vec2(v->minimap.w / 2, v->minimap.h / 2);
	x = (v->minimap.h - 5) * 0.5;
	x = x * x;
	i = 0;
	while (i < v->minimap.h)
	{
		j = 0;
		while (j < v->minimap.w)
		{
			dist = (center.x - i) * (center.x - i) + \
				(center.y - j) * (center.y - j);
			if (dist >= x - 200 && dist <= x + 200)
				put_pixel(&v->minimap, i, j, 0x52202020);
			j++;
		}
		i++;
	}
}

void	draw_grid(t_var *v)
{
	int		i;
	int		j;
	double	coef_x;
	double	coef_y;
	t_vec2	pixel_pos;

	i = -1;
	coef_x = v->minimap_radius * 2 / v->minimap.w;
	coef_y = v->minimap_radius * 2 / v->minimap.h;
	while (++i < v->minimap.h)
	{
		j = -1;
		while (++j < v->minimap.w)
		{
			pixel_pos = get_vec2(j * coef_x, i * coef_y);
			pixel_pos = add_vec2(get_vec2(v->player.x - v->minimap_radius, \
				v->player.y - v->minimap_radius), pixel_pos);
			if (pixel_pos.x < 0 || pixel_pos.y < 0 || \
				pixel_pos.x > v->map_w || pixel_pos.y > v->map_h)
				continue ;
			else if (pixel_pos.x - (int)pixel_pos.x < 0.2 || \
				pixel_pos.y - (int)pixel_pos.y < 0.2)
				put_pixel(&v->minimap, j, i, 0xff010101);
		}
	}
}

void	draw_map(t_var *v)
{
	int		i;
	int		j;
	t_vec2	coef;
	t_vec2	pixel_pos;

	i = -1;
	coef.x = v->minimap_radius * 2 / v->minimap.w;
	coef.y = v->minimap_radius * 2 / v->minimap.h;
	while (++i < v->minimap.h)
	{
		j = -1;
		while (++j < v->minimap.w)
		{
			pixel_pos = get_vec2(j * coef.x, i * coef.y);
			pixel_pos = add_vec2(get_vec2(v->player.x - v->minimap_radius, \
				v->player.y - v->minimap_radius), pixel_pos);
			if (pixel_pos.x < 0 || pixel_pos.y < 0 || \
				pixel_pos.x > v->map_w || pixel_pos.y > v->map_h)
				put_pixel(&v->minimap, j, i, 0xff0000ff);
			else if (v->map[(int)pixel_pos.y][(int)pixel_pos.x] == WALL)
				put_pixel(&v->minimap, j, i, 0xA9A9A9);
			else
				put_pixel(&v->minimap, j, i, 0xFFFFFF);
		}
	}
}

void	make_minimap_round(t_var *v)
{
	int		i;
	int		j;
	double	x;
	int		dist;
	t_vec2	center;

	center = get_vec2(v->minimap.w / 2, v->minimap.h / 2);
	x = (v->minimap.h - 5) * 0.5;
	x = x * x;
	i = 0;
	while (i < v->minimap.h)
	{
		j = 0;
		while (j < v->minimap.w)
		{
			dist = (center.x - i) * (center.x - i) \
				+ (center.y - j) * (center.y - j);
			if ((double)dist > x)
				put_pixel(&v->minimap, i, j, 0xff000000);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_var *v)
{
	draw_map(v);
	draw_grid(v);
	draw_circle(&v->minimap, v->minimap.w / 2, v->minimap.h / 2, 4);
	make_minimap_round(v);
	draw_minimap_border(v);
}
