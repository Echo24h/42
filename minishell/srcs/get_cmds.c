#include "minishell.h"

static void	init_redir(t_redir **redir, t_list *token)
{
	t_token	*tok;

	*redir = malloc(sizeof(t_redir) * 1);
	if (!*redir)
		exit_error("cannot allocate memory", EXIT_FAILURE);
	tok = token->content;
	(*redir)->type = tok->type;
	(*redir)->word = NULL;
}

static int	add_redir(t_cmd *cmd, t_list **tokens)
{
	t_token	*tok;
	t_list	*new;
	t_redir	*redir;

	init_redir(&redir, *tokens);
	*tokens = (*tokens)->next;
	if (!*tokens)
	{
		free(redir);
		return (error("missing word after redirection", 0));
	}
	tok = (*tokens)->content;
	if (tok->type != WORD)
	{
		free(redir);
		return (error("missing word after redirection", 0));
	}
	redir->word = ft_strdup(tok->val);
	if (!redir->word)
		exit_error("cannot allocate memory", EXIT_FAILURE);
	new = ft_lstnew(redir);
	if (!new)
		exit_error("cannot allocate memory", EXIT_FAILURE);
	if (redir->type == REDIR_LL || redir->type == REDIR_L)
		ft_lstadd_back(&cmd->redir_in, new);
	else
		ft_lstadd_back(&cmd->redir_out, new);
	return (1);
}

static void	init_cmd(t_cmd **cmd)
{
	*cmd = malloc(sizeof(t_cmd) * 1);
	if (!*cmd)
		exit_error("cannot allocate memory", EXIT_FAILURE);
	(*cmd)->args = NULL;
	(*cmd)->redir_in = NULL;
	(*cmd)->redir_out = NULL;
}

static t_cmd	*get_next_cmd(t_list **tokens)
{
	t_cmd	*cmd;
	t_token	*tok;

	init_cmd(&cmd);
	tok = (*tokens)->content;
	while (*tokens && tok->type != PIPE)
	{
		if (tok->type == WORD)
		{
			cmd->args = strs_append(cmd->args, tok->val);
			if (!cmd->args)
				exit_error("cannot allocate memory", EXIT_FAILURE);
		}
		else if (!add_redir(cmd, tokens))
		{
			free_cmd(cmd);
			return (NULL);
		}
		*tokens = (*tokens)->next;
		if (*tokens)
			tok = (*tokens)->content;
	}
	if (*tokens)
	{
		if (!(*tokens)->next)
			; // handle pipe at end of line?
		*tokens = (*tokens)->next;
	}
	return (cmd);
}

t_list	*get_cmds(t_list *tokens)
{
	t_list	*cmds;
	t_list	*new;
	t_cmd	*cmd;

	cmds = NULL;
	while (tokens)
	{
		cmd = get_next_cmd(&tokens);
		if (!cmd)
		{
			ft_lstclear(&cmds, &free_cmd);
			return (NULL);
		}
		new = ft_lstnew(cmd);
		if (!new)
			exit_error("cannot allocate memory", EXIT_FAILURE);
		ft_lstadd_back(&cmds, new);
	}
	return (cmds);
}
