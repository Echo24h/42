#include "minishell.h"

int	ft_pwd(void)
{
	char	*curr_path;

	curr_path = getcwd(NULL, 0);
	if (curr_path)
		ft_putendl_fd(curr_path, STDOUT_FILENO);
	else
		perror("getcwd");
	free(curr_path);
	return (0);
}

int	ft_env(t_var *var)
{
	int	i;

	i = 0;
	while (var->local_env[i])
		ft_putendl_fd(var->local_env[i++], STDOUT_FILENO);
	return (0);
}

int	ft_exit(char **args)
{
	return (0);
}

int	ft_export()
{
	return (0);
}

int	ft_unset()
{
	return (0);
}

int	ft_echo()
{
	return (0);
}

int	ft_cd()
{
	return (0);
}