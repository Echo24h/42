#include "minishell.h"

int	set_hd_filename(t_redir *redir)
{
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
		free(redir->filename);
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
	g.in_hd = 1;
	g.sigint_in_hd = 0;
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line_hd(STDIN_FILENO);
		if (g.sigint_in_hd || !line || !my_strcmp(redir->hd_keyword, line))
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	g.in_hd = 0;
	if (g.sigint_in_hd)
		return (1);
	close(fd);
	return (0);
}

int	handle_hd(t_list *cmds)
{
	t_list	*redirs;
	t_redir	*redir;

	while (cmds)
	{
		redirs = ((t_cmd *)(cmds->content))->redirs;
		while (redirs)
		{
			redir = redirs->content;
			if (redir->type == REDIR_LL)
			{
				delete_quotes(&redir->hd_keyword);
				if (read_hd(redir))
					return (1);
			}
			redirs = redirs->next;
		}
		cmds = cmds->next;
	}
	return (0);
}
