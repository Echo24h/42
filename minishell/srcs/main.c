#include "minishell.h"
#include "libft.h"
#include "cmds.h"

# define PROMPT "minishell> "

/*
	to do :
		- make a custom prompt
		- research potential parsing errors and handle it

	must ensure that :
		- env variables must not start by a digit
		- env variables consist of alpha, numeric and/or '_' characters
		- quotes are closed, handle that in parsing
*/
int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**local_env;
	t_list	*cmds;
	
	local_env = copy_strs(env);
	if (!local_env)
		exit_error("cannot allocate memory", EXIT_FAILURE);
	line = readline(PROMPT);
	while (line)
	{
		expand_ev(&line, local_env);
		ft_printf("ev expansion: %s\n", line);
		cmds = parse(line);
		ft_lstiter(cmds, &print_cmd);
		ft_lstclear(&cmds, &free_cmd);
		free(line);
		line = readline(PROMPT);
	}
	free_strs(local_env);
	system("leaks minishell");
	return (0);
}
