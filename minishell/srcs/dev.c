#include "libft.h"
#include "minishell.h"

void	print_tokens(t_list *tokens)
{
	t_token	*tok;

	while (tokens)
	{
		tok = tokens->content;
		if (tok->type == WORD)
			ft_printf("%s\n", tok->val);
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
		tokens = tokens->next;
	}
}