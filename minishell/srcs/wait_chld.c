#include "minishell.h"

void	wait_chld(t_var *var)
{
	int	status;

	//printf("nb_chld: %d\n", var->nb_chld);
	if (!var->nb_chld)
		return ;
	waitpid(var->last_chld_pid, &status, 0);
	close(STDIN_FILENO);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			write(STDOUT_FILENO, "Quit: 3", 7);
		write(STDOUT_FILENO, "\n", 1);
		var->exit_status = 128 + WTERMSIG(status);
	}
	else
		var->exit_status = status;
	while (wait(NULL) > 0)
		;
}

/*
	i = 0;
	sig = -1;
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
*/