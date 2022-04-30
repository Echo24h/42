#include "minishell.h"

int	builtin_echo(char **args)
{
	int	i;
	int	has_option_n;

	i = 1;
	has_option_n = 0;
	if (!my_strcmp(args[i], "-n"))
	{
		has_option_n = 1;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (!has_option_n)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
