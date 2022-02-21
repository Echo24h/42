#include "minishell.h"

# define PROMPT "minishell> "

/*
	. get tokens, if prev token is not '<<' expand token value
	. '<<' should also expand each line read

	to do :
		- make a custom prompt
		- research potential parsing errors and handle it

	must ensure that :
		- env variables must not start by a digit
		- env variables consist of alpha, numeric and/or '_' characters
*/
int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**words;
	char	**local_env;
	t_list	*cmds;
	
	local_env = copy_strs(env);
	if (!local_env)
		return (error("cannot allocate memory", EXIT_FAILURE));
	line = readline(PROMPT);
	while (line)
	{
		cmds = parse(line);
		if (cmds)
		{
			expand_ev(cmds, env);
			;//exec_cmd(cmds->content, local_env);
		}
		ft_lstiter(cmds, &print_cmd);
		ft_lstclear(&cmds, &free_cmd);
		free(line);
		line = readline(PROMPT);
	}
	free_strs(local_env);
	system("leaks minishell");
	return (0);
}
