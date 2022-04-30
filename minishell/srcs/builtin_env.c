#include "minishell.h"

int	builtin_env(t_var *var)
{
	int	i;

	i = 0;
	while (var->local_env[i])
		ft_putendl_fd(var->local_env[i++], STDOUT_FILENO);
	return (0);
}
