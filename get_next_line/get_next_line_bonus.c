/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:28:40 by ydanset           #+#    #+#             */
/*   Updated: 2021/11/02 16:53:41 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*error(char **line)
{
	if (*line)
		free(*line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buff[NB_FILES_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			n;
	int			found_line;

	if (fd >= NB_FILES_MAX || fd < 0)
		return (NULL);
	line = NULL;
	found_line = 0;
	while (!found_line)
	{
		found_line = extract_line(buff[fd], &line);
		if (found_line == -1)
			return (error(&line));
		if (!found_line)
		{
			n = read(fd, buff[fd], BUFFER_SIZE);
			if (!n && *line)
				found_line = 1;
			else if (!n || n == -1)
				return (error(&line));
			buff[fd][n] = '\0';
		}
	}
	return (line);
}
