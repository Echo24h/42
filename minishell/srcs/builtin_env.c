#include "minishell.h"

int	builtin_env(t_var *var)
{
	int	i;

	if (!var->local_env)
	{
		ft_putendl_fd("env is NULL, what the fuck did you do", STDOUT_FILENO);
		return (0);
	}
	i = 0;
	while (var->local_env[i])
		ft_putendl_fd(var->local_env[i++], STDOUT_FILENO);
	return (0);
}
