/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:04:50 by ydanset           #+#    #+#             */
/*   Updated: 2022/06/01 11:04:51 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long	get_time(void)
{
	long			ms;
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	ms = time.tv_sec * 1000;
	ms += time.tv_usec * 1e-3;
	return (ms);
}

long	time_diff(long start, long end)
{
	return (end - start);
}
