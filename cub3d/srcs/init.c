/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:39 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 12:04:41 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_txtr(void *mlx, t_img *txtr, char *filename)
{
	char	*err_msg;
	char	*tmp;

	txtr->img = mlx_xpm_file_to_image(mlx, filename, &txtr->w, &txtr->h);
	if (!txtr->img)
	{
		err_msg = ft_strjoin("failed to load texture '", filename);
		tmp = err_msg;
		err_msg = ft_strjoin(err_msg, "'");
		free(tmp);
		print_error(err_msg);
		free(err_msg);
		return (1);
	}
	txtr->data = mlx_get_data_addr(txtr->img, &txtr->bpp, \
		&txtr->size_line, &txtr->endian);
	return (0);
}

int	init_txtr(t_var *v)
{
	if (load_txtr(v->mlx, &v->txtr[NO], "textures/wood.xpm")
		|| load_txtr(v->mlx, &v->txtr[SO], "textures/greystone.xpm")
		|| load_txtr(v->mlx, &v->txtr[EA], "textures/purplestone.xpm")
		|| load_txtr(v->mlx, &v->txtr[WE], "textures/redbrick.xpm"))
		return (1);
	return (0);
}

int	init_game_norm(t_var *v)
{
	v->old_mouse_x = v->mouse_x;
	v->redisplay = 1;
	v->t_last_frame = get_time();
	if (init_minimap(v))
		return (1);
	return (0);
}

int	init_game(t_var *v)
{
	v->mlx = mlx_init();
	if (!v->mlx)
	{
		print_error("mlx failure");
		return (1);
	}
	v->win = mlx_new_window(v->mlx, W, H, "cub3d");
	v->screen.img = mlx_new_image(v->mlx, W, H);
	if (!v->win || !v->screen.img)
	{
		print_error("mlx failure");
		return (1);
	}
	v->screen.data = mlx_get_data_addr(v->screen.img, &v->screen.bpp, \
		&v->screen.size_line, &v->screen.endian);
	init_key(&v->key);
	if (init_txtr(v))
		return (1);
	get_mouse_x_limits(v);
	mlx_mouse_move(v->win, W / 2, H / 2);
	mlx_mouse_get_pos(v->win, &v->mouse_x, &v->mouse_y);
	if (init_game_norm(v))
		return (1);
	return (0);
}
