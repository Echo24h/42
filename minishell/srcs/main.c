#include "minishell.h"
#include "libft.h"

# define PROMPT "minishell> "

/*
	must ensure that :
		- env variables must not start by a digit
		- env variables consist of alpha, numeric and/or '_' characters
*/
int	main(int ac, char **av, char **env)
{
	char	*line;
	char	**local_env;
	
	local_env = copy_strs(env);
	if (!local_env)
		return(error("malloc() failed", EXIT_FAILURE));
	line = readline(PROMPT);
	while (line)
	{
		expand(&line, local_env);
		
		free(line);
		line = readline(PROMPT);
	}

	free_strs(local_env);
	return (0);
}

