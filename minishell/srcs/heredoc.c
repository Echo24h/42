#include "minishell.h"

int	set_hd_filename(t_redir *redir)
{
	int			fd;
	int			index;
	struct stat	buf;

	index = 0;
	redir->filename = index_str(".hd_minishell", index);
	while (stat(redir->filename, &buf) != -1 && index < 10000)
	{
		free(redir->filename);
		redir->filename = index_str(".hd_minishell", ++index);
	}
	if (index == 10000 && stat(redir->filename, &buf) != -1)
	{
		redir->filename = NULL;
		return (1);
	}
	return (0);
}

int	read_hd(t_redir *redir)
{
	int		fd;
	char	*line;

	if (set_hd_filename(redir))
	{
		print_error(NULL, "unable to create '.hd_minishell[x]' file, delete some of your local files which have the same filename in order to use minishell");
		return (1);
	}
	fd = open(redir->filename, O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
	{
		print_error(ft_strdup(redir->filename), strerror(errno));
		return (1);
	}
	while (1)
	{
		line = readline("> ");
		if (!line) // send EOF to heredoc
			break ;
		if (!my_strcmp(redir->hd_keyword, line))
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	close(fd);
	return (0);
}

int	handle_hd(t_list *cmds)
{
	t_list	*redir_in;
	t_redir	*redir;

	while (cmds)
	{
		redir_in = ((t_cmd *)(cmds->content))->redir_in;
		while (redir_in)
		{
			redir = redir_in->content;
			if (redir->type == REDIR_LL)
			{
				if (read_hd(redir))
					return (1);
			}
			redir_in = redir_in->next;
		}
		cmds = cmds->next;
	}
	return (0);
}
