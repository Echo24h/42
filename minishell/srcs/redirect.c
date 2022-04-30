#include "minishell.h"

int	redirect_stdout(t_redir *redir)
{
	int		fd;

	if (redir->type == REDIR_R)
		fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		print_error(ft_strdup(redir->filename), strerror(errno));
		return (1);
	}
	else
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (0);
}

int	redirect_stdin(t_redir *redir)
{
	int		fd;

	fd = open(redir->filename, O_RDONLY);
	if (fd == -1)
	{
		print_error(ft_strdup(redir->filename), strerror(errno));
		return (1);
	}
	else
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (0);
}

int	redirect(t_list *redirs, t_var *var)
{
	t_redir	*redir;

	while (redirs)
	{
		redir = redirs->content;
		if (expand_redir(redir, var))
			return (1);
		if (redir->type == REDIR_L || redir->type == REDIR_LL)
		{
			if (redirect_stdin(redir))
				return (1);
		}
		else if (redirect_stdout(redir))
			return (1);
		redirs = redirs->next;
	}
	return (0);
}
