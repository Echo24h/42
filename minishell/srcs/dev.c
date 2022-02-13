#include "minishell.h"

void	print_tokens(t_list *tokens)
{
	t_token	*tok;

	ft_printf("TOKENS\n");
	while (tokens)
	{
		tok = tokens->content;
		if (tok->type == WORD)
			ft_printf("word: %s\n", tok->val);
		else if (tok->type == PIPE)
			ft_printf("pipe\n");
		else if (tok->type == REDIR_L)
			ft_printf("<\n");
		else if (tok->type == REDIR_LL)
			ft_printf("<<\n");
		else if (tok->type == REDIR_R)
			ft_printf(">\n");
		else if (tok->type == REDIR_RR)
			ft_printf(">>\n");
		else
			ft_printf("token has invalid type\n");
		tokens = tokens->next;
	}
}

void	print_redir(void *ptr)
{
	t_redir	*redir;

	redir = ptr;
	if (redir->type == REDIR_RR)
		ft_printf(">> %s\n", redir->word);
	else if (redir->type == REDIR_R)
		ft_printf("> %s\n", redir->word);
	else if (redir->type == REDIR_LL)
		ft_printf("<< %s\n", redir->word);
	else if (redir->type == REDIR_L)
		ft_printf("< %s\n", redir->word);
	else
		print_error("redir has invalid type\n");
}

void	print_cmd(void *ptr)
{
	t_cmd	*cmd;

	cmd = ptr;
	ft_printf("NEW CMD\n");
	printf("--- args ---\n");
	print_strs(cmd->args);
	printf("--- redir_in ---\n");
	ft_lstiter(cmd->redir_in, &print_redir);
	printf("--- redir_out ---\n");
	ft_lstiter(cmd->redir_out, &print_redir);
}
