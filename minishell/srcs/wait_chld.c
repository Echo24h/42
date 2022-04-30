#include "minishell.h"

void	wait_chld(t_var *var)
{
	int	status;

	waitpid(var->last_chld_pid, &status, 0);
	close(STDIN_FILENO); // close last pipe_fd[0]
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
