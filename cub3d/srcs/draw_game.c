/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:34 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 12:27:03 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// used in get_wall_dist.c
t_vec2	get_first_side_dist(t_var *v, t_vec2 ray_dir, t_vec2 unit_dist)
{
	t_vec2	side_dist;

	if (ray_dir.x > 0)
		side_dist.x = ((int)(v->player.x + 1) - v->player.x) * unit_dist.x;
	else
		side_dist.x = (v->player.x - (int)v->player.x) * unit_dist.x;
	if (ray_dir.y > 0)
		side_dist.y = ((int)(v->player.y + 1) - v->player.y) * unit_dist.y;
	else
		side_dist.y = (v->player.y - (int)v->player.y) * unit_dist.y;
	return (side_dist);
}

int	get_wall_height(t_var *v, t_vec2 ray_dir, int *txtr_x, int *side)
{
	double	wall_dist;
	t_vec2	wall_hit;
	t_vec2	wall_vec;

	wall_dist = get_wall_dist(v, ray_dir, side);
	wall_hit = add_vec2(v->player, mult_vec2(ray_dir, wall_dist));
	wall_vec = get_vec2(wall_hit.x - v->player.x, wall_hit.y - v->player.y);
	wall_dist = wall_vec.x * v->player_dir.x \
		+ wall_vec.y * v->player_dir.y;
	if (*side == NO || *side == SO)
		*txtr_x = (int)((wall_hit.x - (int)wall_hit.x) * v->txtr[*side].w);
	else
		*txtr_x = (int)((wall_hit.y - (int)wall_hit.y) * v->txtr[*side].w);
	return (H * 0.75 / wall_dist);
}

unsigned int
	get_txtr_color(t_img txtr, int y, int txtr_x, double txtr_step_y)
{
	unsigned int	color;
	int				txtr_y;

	txtr_y = (int)(y * txtr_step_y);
	return (get_pixel_color(txtr, txtr_x, txtr_y));
}

void	draw_ray(t_var *v, int ray_x, t_vec2 ray_dir)
{
	int		wall_height;
	int		side;
	int		txtr_x;
	int		wall_start_y;
	int		y;

	wall_height = get_wall_height(v, ray_dir, &txtr_x, &side);
	wall_start_y = (H - wall_height) / 2;
	y = 0;
	while (y < wall_start_y)
		put_pixel(&v->screen, ray_x, y++, v->color[CEIL]);
	while (y < H && y < wall_start_y + wall_height)
	{
		put_pixel(&v->screen, ray_x, y,
			get_pixel_color(v->txtr[side], txtr_x,
				(y - wall_start_y) * ((double)v->txtr[side].h / wall_height)));
		y++;
	}
	while (y < H)
		put_pixel(&v->screen, ray_x, y++, v->color[FLOOR]);
}

void	draw_game(t_var *v)
{
	int		ray_x;
	double	camera_x;
	t_vec2	ray_dir;

	ray_x = 0;
	while (ray_x < W)
	{
		camera_x = 2 * (double)ray_x / W - 1;
		ray_dir = add_vec2(v->player_dir, mult_vec2(v->camera, camera_x));
		ray_dir = norm_vec2(ray_dir);
		draw_ray(v, ray_x, ray_dir);
		ray_x++;
	}
}
