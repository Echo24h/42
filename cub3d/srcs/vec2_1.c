/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:19:44 by jbettini          #+#    #+#             */
/*   Updated: 2022/06/01 11:20:47 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	norm_vec2(t_vec2 v)
{
	t_vec2	res;
	double	magnitude;

	magnitude = sqrt(v.x * v.x + v.y * v.y);
	res.x = v.x / magnitude;
	res.y = v.y / magnitude;
	return (res);
}

t_vec2	inv_vec2(t_vec2 v)
{
	t_vec2	res;

	res.x = v.x * -1;
	res.y = v.y * -1;
	return (res);
}

t_vec2	rotate_vec2(t_vec2 v, double angle)
{
	t_vec2	res;

	res.x = v.x * cos(angle) - v.y * sin(angle);
	res.y = v.x * sin(angle) + v.y * cos(angle);
	return (res);
}
