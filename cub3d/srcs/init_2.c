/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:39 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 13:09:54 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_minimap(t_var *v)
{
	v->minimap.h = H / 4;
	v->minimap.w = W / 4;
	v->minimap_radius = MINIMAP_RADIUS;
	v->minimap.img = mlx_new_image(v->mlx, v->minimap.w, v->minimap.h);
	if (!v->minimap.img)
		return (1);
	v->minimap.data = mlx_get_data_addr(v->minimap.img, &v->minimap.bpp, \
		&v->minimap.size_line, &v->minimap.endian);
	v->minimap.path = NULL;
	return (0);
}

void	get_mouse_x_limits(t_var *v)
{
	int	x;
	int	y;

	mlx_mouse_move(v->win, -10000, 0);
	mlx_mouse_get_pos(v->win, &x, &y);
	v->mouse_x_min = x;
	mlx_mouse_move(v->win, 10000, 0);
	mlx_mouse_get_pos(v->win, &x, &y);
	v->mouse_x_max = x;
}

void	init_key(t_key *key)
{
	key->z = RELEASED;
	key->s = RELEASED;
	key->q = RELEASED;
	key->d = RELEASED;
	key->left = RELEASED;
	key->right = RELEASED;
}
