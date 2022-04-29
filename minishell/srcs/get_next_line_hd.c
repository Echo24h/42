#include "minishell.h"

char	*get_next_line_hd(int fd)
{
	char	c;
	char	*line;

	line = NULL;
	c = 'J'; // le J C le S
	while (read(fd, &c, 1) > 0 && c != '\n')
		line = ft_append_char(line, c);
	if (!line && c == '\n')
		line = ft_strdup("");
	if (c != '\n')
		write(STDIN_FILENO, "\n", 1);
	return (line);
}
