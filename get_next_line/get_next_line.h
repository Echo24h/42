#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int			get_next_line(int fd, char **line);
int			extract(char buff[BUFFER_SIZE + 1], char **extraction);
char		*ft_strjoin(char **s1, char **s2);

#endif