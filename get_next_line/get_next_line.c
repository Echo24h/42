/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:04:52 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/30 22:10:23 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	int			n;
	int			found_line;

	line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	found_line = 0;
	while (!found_line)
	{
		found_line = extract_line(buff, &line);
		if (found_line == -1)
			return (NULL);
		if (!found_line)
		{
			n = read(fd, buff, BUFFER_SIZE);
			if (!n || n == -1)
				return (NULL);
			buff[n] = '\0';
		}
	}
	return (line);
}
