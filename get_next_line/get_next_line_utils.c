/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:05:10 by ydanset           #+#    #+#             */
/*   Updated: 2021/10/30 22:10:09 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count * size)
		res[i++] = '\0';
	return ((void *)res);
}

static void	ft_strcpy(char *buff, char *src)
{
	while (*src)
		*buff++ = *src++;
	*buff = '\0';
}

char	*ft_strjoin(char **s1, char **s2)
{
	char	*res;
	int		i;
	int		j;

	if (!*s1 || !*s2)
		return (NULL);
	res = malloc(ft_strlen(*s1) + ft_strlen(*s2) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while ((*s1)[++i])
		res[i] = (*s1)[i];
	j = -1;
	while ((*s2)[++j])
		res[i + j] = (*s2)[j];
	res[i + j] = '\0';
	free(*s1);
	free(*s2);
	return (res);
}

int	extract_line(char *buff, char **line)
{
	int	i;
	int	j;
	int	found_line;
	char	*line_extracted;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	found_line = 0;
	if (buff[i] == '\n')
		found_line = 1;
	line_extracted = ft_calloc(i + found_line + 1, 1);
	if (!line_extracted)
		return (-1);
	j = 0;
	while (j < i + found_line)
	{
		line_extracted[j] = buff[j];
		j++;
	}
	*line = ft_strjoin(line, &line_extracted);
	if (!line)
		return (-1);
	ft_strcpy(buff, &buff[i + found_line]);
	return (found_line);
}
