#include "minishell.h"

int	builtin_pwd(void)
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
