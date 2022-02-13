#include "minishell.h"
#include "cmds.h"

void	free_token(void *ptr)
{
	t_token	*tok;

	tok = ptr;
	free(tok->val);
	free(tok);
}

static void	free_redir(void *ptr)
{
	t_redir	*redir;

	redir = ptr;
	free(redir->word);
	free(redir);
}

void	free_cmd(void *ptr)
{
	t_cmd	*cmd;

	cmd = ptr;
	free_strs(cmd->args);
	ft_lstclear(&cmd->redir_in, &free_redir);
	ft_lstclear(&cmd->redir_out, &free_redir);
	free(cmd);
}
