/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbettini <jbettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:58:44 by ydanset           #+#    #+#             */
/*   Updated: 2022/05/20 16:41:06 by jbettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_append_char(char *str, char c)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!res)
		return (NULL);
	if (!str)
	{
		res[0] = c;
		res[1] = '\0';
		return (res);
	}
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = c;
	res[++i] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	char	c;
	char	*line;

	if (read(fd, &c, 0) == -1)
		return (NULL);
	line = NULL;
	c = 'J';
	while (read(fd, &c, 1) > 0 && c != '\n')
		line = ft_append_char(line, c);
	if (!line && c == '\n')
		return (ft_strdup(""));
	return (line);
}
