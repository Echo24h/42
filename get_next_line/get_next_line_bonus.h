/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydanset <ydanset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:28:26 by ydanset           #+#    #+#             */
/*   Updated: 2021/11/02 16:03:02 by ydanset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define NB_FILES_MAX 42

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int			extract_line(char *buff, char **line);
char		*ft_strjoin(char **s1, char **s2);
char		*get_next_line(int fd);
void		*ft_calloc(size_t count, size_t size);

#endif
