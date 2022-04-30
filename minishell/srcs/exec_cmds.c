#include "minishell.h"

char	**get_paths(char **env)
{
	char	**paths;
	char	*tmp;

	tmp = get_ev_value("PATH", env);
	paths = ft_split(tmp, ':');
	free(tmp);
	return (paths);
}

int	has_access(char *cmd_name)
{
	if (!access(cmd_name, F_OK | X_OK))
		return (1);
	return (0);
}

char	*get_cmd_path(char *cmd_name, char **env)
{
	char	*cmd_path;
	char	*cmd_pfx;
	char	**paths;
	int		i;

	if (ft_strchr(cmd_name, '/') && has_access(cmd_name))
		return (ft_strdup(cmd_name));
	if (ft_strchr(cmd_name, '/') && !has_access(cmd_name))
		return (NULL);
	cmd_path = NULL;
	paths = get_paths(env);
	cmd_pfx = ft_strjoin("/", cmd_name);
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd_pfx);
		if (!access(cmd_path, F_OK | X_OK))
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	free_strs(paths);
	free(cmd_pfx);
	return (cmd_path);
}

int	set_cmd_path(char **cmd_path, char *cmd_name, char **env)
{
	*cmd_path = get_cmd_path(cmd_name, env);
	if (!*cmd_path)
	{
		print_error(ft_strdup(cmd_name), "command not found");
		return (1);
	}
	return (0);
}

int	is_builtin(char *cmd_name)
{
	if (!my_strcmp(cmd_name, "cd") || !my_strcmp(cmd_name, "echo")
		|| !my_strcmp(cmd_name, "pwd") || !my_strcmp(cmd_name, "export")
		|| !my_strcmp(cmd_name, "unset") || !my_strcmp(cmd_name, "env")
		|| !my_strcmp(cmd_name, "exit"))
		return (1);
	return (0);
}

int	exec_builtin(char **args, t_var *var)
{
	if (!my_strcmp(args[0], "cd"))
		return (0);
	else if (!my_strcmp(args[0], "echo"))
		return (0);
	else if (!my_strcmp(args[0], "pwd"))
		return (builtin_pwd());
	else if (!my_strcmp(args[0], "export"))
		return (0);
	else if (!my_strcmp(args[0], "unset"))
		return (0);
	else if (!my_strcmp(args[0], "env"))
		return (builtin_env(var));
	else if (!my_strcmp(args[0], "exit"))
		return (builtin_exit(args, var));
	return (0);
}

void	exec_in_chld(t_cmd *cmd, t_var *var, int pipe_fd[2])
{
	char	*cmd_path;
	pid_t	pid;

	var->nb_chld++;
	pid = fork();
	if (pid == -1)
	{
		var->nb_chld--;
		print_error(ft_strdup("fork"), strerror(errno));
	}
	if (!pid)
	{
		set_sig(SIGINT, SIG_DFL);
		set_sig(SIGQUIT, SIG_DFL);
		if (pipe_fd)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1], STDOUT_FILENO);
			close(pipe_fd[1]);
		}
		if (redirect_stdin(cmd->redir_in) || redirect_stdout(cmd->redir_out))
			exit(EXIT_FAILURE);
		if (!cmd->args)
			exit(EXIT_SUCCESS);
		if (is_builtin(cmd->args[0]))
			exit(exec_builtin(cmd->args, var));
		if (set_cmd_path(&cmd_path, cmd->args[0], var->local_env))
			exit(CMD_NOT_FOUND);
		if (execve(cmd_path, cmd->args, var->local_env) == -1)
			print_error(ft_strdup("execve"), strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (!pipe_fd)
		var->last_chld_pid = pid;
}

void	exec_simple_cmd(t_cmd *cmd, t_var *var)
{
	if (expand_ev(cmd, var))
		return ;
	if (cmd->args && is_builtin(cmd->args[0]))
	{
		var->is_simple_builtin_cmd = 1;
		if (redirect_stdin(cmd->redir_in) || redirect_stdout(cmd->redir_out))
		{
			var->exit_status = EXIT_FAILURE;
			return ;
		}
		var->exit_status = exec_builtin(cmd->args, var);
	}
	else
		exec_in_chld(cmd, var, NULL);
}

void	exec_multiple_cmds(t_list *cmds, t_var *var)
{
	int		pipe_fd[2];

	if (expand_ev(cmds->content, var))
		exec_multiple_cmds(cmds->next, var);
	else if (cmds->next)
	{
		if (pipe(pipe_fd) == -1)
		{
			print_error(ft_strdup("pipe"), strerror(errno));
			return ;
		}
		exec_in_chld(cmds->content, var, pipe_fd);
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		exec_multiple_cmds(cmds->next, var);
	}
	else
		exec_in_chld(cmds->content, var, NULL);
}

void	exec_cmds(t_list *cmds, t_var *var)
{
	tty_show_ctrl();
	if (!cmds)
		return ;
	if (handle_hd(cmds))
		return ;
	set_sig(SIGINT, SIG_IGN);
	var->is_simple_builtin_cmd = 0;
	if (cmds->next)
		exec_multiple_cmds(cmds, var);
	else
		exec_simple_cmd(cmds->content, var);
}
