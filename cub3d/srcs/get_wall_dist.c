/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:31:30 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 12:32:07 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_side(int *side, t_vec2 step, int side_hit)
{
	if (side_hit == VERTICAL && step.x > 0)
		*side = EA;
	else if (side_hit == VERTICAL && step.x < 0)
		*side = WE;
	else if (side_hit == HORIZONTAL && step.y > 0)
		*side = SO;
	else if (side_hit == HORIZONTAL && step.y < 0)
		*side = NO;
}

static double	calc_wall_dist(int side_hit, t_vec2 side_dist, t_vec2 unit_dist)
{
	if (side_hit == VERTICAL)
		return (side_dist.x - unit_dist.x);
	return (side_dist.y - unit_dist.y);
}

static t_vec2
	normishit(t_var *v, t_vec2 ray_dir, t_vec2 *unit_dist, t_vec2 *step)
{
	if (ray_dir.x > 0)
		step->x = 1;
	else
		step->x = -1;
	if (ray_dir.y > 0)
		step->y = 1;
	else
		step->y = -1;
	unit_dist->x = sqrt(1 + ((ray_dir.y / ray_dir.x) \
		* (ray_dir.y / ray_dir.x)));
	unit_dist->y = sqrt(1 + ((ray_dir.x / ray_dir.y) \
		* (ray_dir.x / ray_dir.y)));
	return (get_first_side_dist(v, ray_dir, *unit_dist));
}

double	get_wall_dist(t_var *v, t_vec2 ray_dir, int *side)
{
	t_vec2	step;
	t_vec2	curr_cell;
	t_vec2	unit_dist;
	t_vec2	side_dist;
	int		side_hit;

	curr_cell = get_vec2((int)v->player.x, (int)v->player.y);
	side_dist = normishit(v, ray_dir, &unit_dist, &step);
	while (v->map[(int)curr_cell.y][(int)curr_cell.x] != WALL)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += unit_dist.x;
			curr_cell.x += step.x;
			side_hit = VERTICAL;
		}
		else
		{
			side_dist.y += unit_dist.y;
			curr_cell.y += step.y;
			side_hit = HORIZONTAL;
		}
	}
	get_side(side, step, side_hit);
	return (calc_wall_dist(side_hit, side_dist, unit_dist));
}
