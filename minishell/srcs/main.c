#include "minishell.h"

# define PROMPT "minishell> "

int	on_error(char *msg, int code)
{
	printf("Error: %s\n", msg);
	return (code);
}

int	main(int ac, char **av)
{
	char	*s;

	s = readline(PROMPT);
	if (!s)
		return (on_error("readline()", EXIT_FAILURE));
	printf("%s\n", s);
	free(s);
	//system("leaks minishell");
	return (EXIT_SUCCESS);
}