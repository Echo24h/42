#include "minishell.h"
#include "cmds.h"

t_list	*parse(char *line)
{
	t_list	*tokens;
	t_list	*cmds;

	tokens = get_tokens(line);
	if (!tokens)
		return (NULL);
	cmds = get_cmds(tokens);
	ft_lstclear(&tokens, &free_token);
	return (cmds);
}
