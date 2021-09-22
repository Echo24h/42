#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define NB_FILES_MAX 42

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int			extract(char buff[BUFFER_SIZE + 1], char **extraction);
char		*ft_strjoin(char **s1, char **s2);
int			get_next_line(int fd, char **line);

#endif