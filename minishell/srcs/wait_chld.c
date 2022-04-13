#include "minishell.h"

/*
void	wait_chld(t_var *var)
{
	int	i;
	int	status;
	int	sig;

	sig = -1;
	i = 0;
	while (i < var->nb_chld)
	{
		waitpid(-1, &status, 0);
		if (WIFSIGNALED(status))
		{
			sig = WTERMSIG(status);
			if (sig == SIGQUIT)
				write(STDOUT_FILENO, "Quit: 3", 7);
			write(STDOUT_FILENO, "\n", 1);
			var->exit_status = 128 + sig;
		}
		i++;
	}
	if (sig == -1)
		var->exit_status = status;
}
*/

void	wait_chld(t_var *var)
{
	int	i;
	int	status;
	int	sig;

	sig = -1;
	i = 0;
	while (i < var->nb_chld)
	{
		waitpid(-1, &status, 0);
		if (WIFSIGNALED(status))
			sig = WTERMSIG(status);
		i++;
	}
	if (sig == -1)
		var->exit_status = status;
	else
	{
		if (sig == SIGQUIT)
			write(STDOUT_FILENO, "Quit: 3", 7);
		write(STDOUT_FILENO, "\n", 1);
		var->exit_status = 128 + sig;
	}
}
