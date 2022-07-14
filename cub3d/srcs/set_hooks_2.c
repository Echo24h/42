/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:49 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 12:26:34 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_var *v, t_vec2 dir)
{
	t_vec2	next_pos;

	next_pos = add_vec2(v->player, mult_vec2(dir, MOVE_SPEED));
	if (v->map[(int)next_pos.y][(int)next_pos.x] != WALL)
		v->player = next_pos;
}

void	rotate_player(t_var *v, int direction)
{
	if (direction == CLOCKWISE)
	{
		v->player_dir = rotate_vec2(v->player_dir, ROTATE_SPEED);
		v->camera = rotate_vec2(v->camera, ROTATE_SPEED);
	}
	else if (direction == ANTICLOCKWISE)
	{
		v->player_dir = rotate_vec2(v->player_dir, -ROTATE_SPEED);
		v->camera = rotate_vec2(v->camera, -ROTATE_SPEED);
	}
}

int	exit_game(t_var *v)
{
	int	i;

	i = 0;
	while (i < v->map_h)
		free(v->map[i++]);
	free(v->map);
	mlx_destroy_image(v->mlx, v->txtr[NO].img);
	mlx_destroy_image(v->mlx, v->txtr[SO].img);
	mlx_destroy_image(v->mlx, v->txtr[EA].img);
	mlx_destroy_image(v->mlx, v->txtr[WE].img);
	mlx_destroy_image(v->mlx, v->screen.img);
	mlx_destroy_window(v->mlx, v->win);
	system("leaks cub3d");
	exit(0);
	return (0);
}

int	mouse_motion_hook(int x, int y, t_var *v)
{
	v->redisplay = 1;
	if (v->key.left != PRESSED && (x < v->old_mouse_x || x == v->mouse_x_min))
		rotate_player(v, ANTICLOCKWISE);
	else if (v->key.right != PRESSED && \
		(x > v->old_mouse_x || x == v->mouse_x_max))
		rotate_player(v, CLOCKWISE);
	else
		v->redisplay = 0;
	v->mouse_x = x;
	v->mouse_y = y;
	v->old_mouse_x = v->mouse_x;
	return (0);
}

void	handle_key(t_var *v)
{
	if (v->key.z == PRESSED)
		move_player(v, v->player_dir);
	if (v->key.s == PRESSED)
		move_player(v, inv_vec2(v->player_dir));
	if (v->key.d == PRESSED)
		move_player(v, get_vec2(-v->player_dir.y, v->player_dir.x));
	if (v->key.q == PRESSED)
		move_player(v, get_vec2(v->player_dir.y, -v->player_dir.x));
	if (v->key.left == PRESSED)
		rotate_player(v, ANTICLOCKWISE);
	if (v->key.right == PRESSED)
		rotate_player(v, CLOCKWISE);
}
