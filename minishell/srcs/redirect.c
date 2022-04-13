#include "minishell.h"

int	redirect_stdout(t_list *redir_out)
{
	int		fd;
	t_redir	*redir;

	while (redir_out)
	{
		redir = redir_out->content;
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
		redir_out = redir_out->next;
	}
	return (0);
}

int	redirect_stdin(t_list *redir_in)
{
	int		fd;
	t_redir	*redir;

	while (redir_in)
	{
		redir = redir_in->content;
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
		redir_in = redir_in->next;
	}
	return (0);
}
