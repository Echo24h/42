/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:49 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 12:52:08 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_is_pressed(t_key key)
{
	if (key.z == PRESSED || key.s == PRESSED || key.q == PRESSED \
		|| key.d == PRESSED || key.left == PRESSED || key.right == PRESSED)
		return (1);
	return (0);
}

int	keypress_hook(int keycode, t_var *v)
{
	if (keycode == KEY_Z)
		v->key.z = PRESSED;
	else if (keycode == KEY_S)
		v->key.s = PRESSED;
	else if (keycode == KEY_Q)
		v->key.q = PRESSED;
	else if (keycode == KEY_D)
		v->key.d = PRESSED;
	else if (keycode == KEY_LEFT)
		v->key.left = PRESSED;
	else if (keycode == KEY_RIGHT)
		v->key.right = PRESSED;
	return (0);
}

int	keyrelease_hook(int keycode, t_var *v)
{
	if (keycode == KEY_ESC)
		exit_game(v);
	if (keycode == KEY_Z)
		v->key.z = RELEASED;
	else if (keycode == KEY_S)
		v->key.s = RELEASED;
	else if (keycode == KEY_Q)
		v->key.q = RELEASED;
	else if (keycode == KEY_D)
		v->key.d = RELEASED;
	else if (keycode == KEY_LEFT)
		v->key.left = RELEASED;
	else if (keycode == KEY_RIGHT)
		v->key.right = RELEASED;
	return (0);
}

int	loop_hook(t_var *v)
{
	long	t;

	t = get_time();
	if (time_diff(v->t_last_frame, t) > T_PER_FRAME && \
		(v->redisplay || key_is_pressed(v->key)))
	{
		handle_key(v);
		draw_game(v);
		draw_minimap(v);
		mlx_put_image_to_window(v->mlx, v->win, v->screen.img, 0, 0);
		mlx_put_image_to_window(v->mlx, v->win, v->minimap.img, 25, 25);
		v->t_last_frame = t;
		v->redisplay = 0;
	}
	return (0);
}

void	set_hooks(t_var *v)
{
	mlx_hook(v->win, MotionNotify, 0, &mouse_motion_hook, v);
	mlx_hook(v->win, KeyPress, 0, &keypress_hook, v);
	mlx_hook(v->win, KeyRelease, 0, &keyrelease_hook, v);
	mlx_hook(v->win, DestroyNotify, 0, &exit_game, v);
	mlx_loop_hook(v->mlx, &loop_hook, v);
}
